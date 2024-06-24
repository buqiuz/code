#include "sql/stmt/stmt.h"

class Db;

/**
 * @brief Table dropping statement
 * @ingroup Statement
 * @details This class represents a 'drop table' statement, it is used for representing SQL statements that drop tables
 */
class DropTableStmt : public Stmt
{
public:
    DropTableStmt(const std::string &table_name)
        : table_name_(table_name)
    {}
    virtual ~DropTableStmt() = default;

    StmtType type() const override { return StmtType::DROP_TABLE; }

    const std::string &table_name() const { return table_name_; }

    static RC create(Db *db, const DropTableSqlNode &create_table, Stmt *&stmt);

private:
    std::string table_name_;
};







CREATE TABLE my_table (id int ,name int);
INSERT INTO my_table values (1, 2);
update my_table set name = 3 where id = 1;
select * from my_table;





#include "sql/stmt/drop_table_stmt.h"
#include "event/sql_debug.h"

RC DropTableStmt::create(Db *db, const DropTableSqlNode &create_table, Stmt *&stmt)
{
    stmt = new DropTableStmt(create_table.relation_name);
    sql_debug("drop table statement: table name %s", create_table.relation_name.c_str());
    return RC::SUCCESS;
}





#pragma once

#include "common/rc.h"

class SQLStageEvent;

/**
 * @brief Executor for dropping tables
 * @ingroup Executor
 */
class DropTableExecutor
{
public:
    DropTableExecutor() = default;
    virtual ~DropTableExecutor() = default;

    RC execute(SQLStageEvent *sql_event);
};








RC DropTableExecutor::execute(SQLStageEvent *sql_event)
{
    Stmt *stmt = sql_event->stmt();
    Session *session = sql_event->session_event()->session();
    ASSERT(stmt->type() == StmtType::DROP_TABLE,
           "drop table executor cannot run this command: %d",
           static_cast<int>(stmt->type()));

    DropTableStmt *drop_table_stmt = static_cast<DropTableStmt *>(stmt);

    const char *table_name = drop_table_stmt->table_name().c_str();
    RC rc = session->get_current_db()->drop_table(table_name);

    return rc;
}





class Db
{
public:
    Db() = default;
    ~Db();

    /**
     * @brief Initialize a database instance
     * @details Create a new database instance and initialize it according to the specified path and the initial configuration.
     *          This method initializes a database instance according to the specifications defined by dbpath.
     * @param name Database name
     * @param dbpath The path to the database, not necessarily existing, to be used for creating or locating the database.
     * @note The database instance is identified by dbpath/name. The dbpath/name cannot contain Hdbpath characters.
     */
    RC init(const char *name, const char *dbpath);

    RC create_table(const char *table_name, int attribute_count, const AttrInfoSqlNode *attributes);
    RC drop_table(const char *table_name);
};




/// @brief Drops a table
/// @param table_name Name of the table to drop
/// @return Return code indicating the result of the operation
RC Db::drop_table(const char *table_name)
{
    RC rc = RC::SUCCESS;
    // Check table_name
    if (opened_tables_.count(table_name) == 0) {
        LOG_WARN("%s has not exist.", table_name);
        return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    // Find table
    auto iter = opened_tables_.find(table_name);
    if (iter == opened_tables_.end()) {
        return RC::SCHEMA_TABLE_NOT_EXIST;
    }
    Table *table = iter->second;
    rc = table->drop(path_.c_str(), table_name);
    if(rc != RC::SUCCESS) return rc;
    opened_tables_.erase(iter); // Remove from the opened table list, destroy list if necessary
    delete table;

    LOG_INFO("drop table success. table name=%s", table_name);
    return RC::SUCCESS;
}





RC Table::drop(const char *base_dir, const char *table_name) {
    RC rc = sync(); // Synchronize buffer
    if (rc != RC::SUCCESS) return rc;

    // Attempt to remove the metadata file created by create_table
    std::string table_file_path = table_meta_file(base_dir, table_name);
    if (unlink(table_file_path.c_str()) != 0) {
        LOG_ERROR("Failed to remove meta file=%s, errno=%d", table_file_path.c_str(), errno);
        return RC::IOERR_UNLINK;
    }

    std::string data_file = table_data_file(base_dir, table_name);
    if (unlink(data_file.c_str()) != 0) {
        LOG_ERROR("Failed to remove data file=%s, errno=%d", data_file.c_str(), errno);
        return RC::IOERR_UNLINK;
    }

    // Remove any associated index files and their metadata
    const int index_num = table_meta_.index_num();
    for (int i = 0; i < index_num; i++) {
        ((BplusTreeIndex*)indexes_[i])->close();
        const IndexMeta* index_meta = table_meta_.index(i);
        std::string index_file = table_index_file(base_dir, table_name, index_meta->name());
        if (unlink(index_file.c_str()) != 0) {
            LOG_ERROR("Failed to remove index file=%s, errno=%d", index_file.c_str(), errno);
            return RC::IOERR_UNLINK;
        }
    }
    return RC::SUCCESS;
}
