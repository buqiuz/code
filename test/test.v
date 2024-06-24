module i_cache (
    input wire clk, rst,
    //mips core
    input         cpu_inst_req     ,
    input         cpu_inst_wr      ,
    input  [1 :0] cpu_inst_size    ,
    input  [31:0] cpu_inst_addr    ,
    input  [31:0] cpu_inst_wdata   ,
    output [31:0] cpu_inst_rdata   ,
    output        cpu_inst_addr_ok ,
    output        cpu_inst_data_ok ,

    //axi interface
    output         cache_inst_req     ,
    output         cache_inst_wr      ,
    output  [1 :0] cache_inst_size    ,
    output  [31:0] cache_inst_addr    ,
    output  [31:0] cache_inst_wdata   ,
    input   [31:0] cache_inst_rdata   ,
    input          cache_inst_addr_ok ,
    input          cache_inst_data_ok 
);

    // Cache configuration
    parameter  INDEX_WIDTH  = 10, OFFSET_WIDTH = 2, WAY_NUM = 4;
    localparam TAG_WIDTH    = 32 - INDEX_WIDTH - OFFSET_WIDTH;
    localparam CACHE_DEEPTH = 1 << INDEX_WIDTH;
    
    // Cache storage elements
    reg                 cache_valid [WAY_NUM-1:0][CACHE_DEEPTH - 1 : 0];
    reg [TAG_WIDTH-1:0] cache_tag   [WAY_NUM-1:0][CACHE_DEEPTH - 1 : 0];
    reg [31:0]          cache_block [WAY_NUM-1:0][CACHE_DEEPTH - 1 : 0];

    // Address breakdown
    wire [OFFSET_WIDTH-1:0] offset;
    wire [INDEX_WIDTH-1:0] index;
    wire [TAG_WIDTH-1:0] tag;
    
    assign offset = cpu_inst_addr[OFFSET_WIDTH - 1 : 0];
    assign index = cpu_inst_addr[INDEX_WIDTH + OFFSET_WIDTH - 1 : OFFSET_WIDTH];
    assign tag = cpu_inst_addr[31 : INDEX_WIDTH + OFFSET_WIDTH];

    // Access cache lines
    wire [WAY_NUM-1:0] c_valid;
    wire [WAY_NUM-1:0][TAG_WIDTH-1:0] c_tag;
    wire [WAY_NUM-1:0][31:0] c_block;

    genvar i;
    generate
        for (i = 0; i < WAY_NUM; i = i + 1) begin : CACHE_WAY
            assign c_valid[i] = cache_valid[i][index];
            assign c_tag[i]   = cache_tag[i][index];
            assign c_block[i] = cache_block[i][index];
        end
    endgenerate

    // Determine hit or miss
    wire hit;
    wire [WAY_NUM-1:0] way_hit;
    assign way_hit = (c_valid & (c_tag == {WAY_NUM{tag}}));
    assign hit = |way_hit;

    // LRU replacement policy
    reg [WAY_NUM-2:0] lru_bits [CACHE_DEEPTH-1:0];

    // Determine the LRU way
    wire [WAY_NUM-1:0] lru_way;
    assign lru_way = (lru_bits[index] == 2'b00) ? 4'b0001 :
                     (lru_bits[index] == 2'b01) ? 4'b0010 :
                     (lru_bits[index] == 2'b10) ? 4'b0100 : 4'b1000;

    // FSM states
    parameter IDLE = 2'b00, RM = 2'b01;
    reg [1:0] state;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            case (state)
                IDLE: state <= (cpu_inst_req & ~hit) ? RM : IDLE;
                RM: state <= cache_inst_data_ok ? IDLE : RM;
            endcase
        end
    end

    // Read request, address received, and read finish flags
    wire read_req;
    reg addr_rcv;
    wire read_finish;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            addr_rcv <= 1'b0;
        end else if (cache_inst_req & cache_inst_addr_ok) begin
            addr_rcv <= 1'b1;
        end else if (read_finish) begin
            addr_rcv <= 1'b0;
        end
    end
    assign read_req = (state == RM);
    assign read_finish = cache_inst_data_ok;

    // Output to MIPS core
    assign cpu_inst_rdata   = hit ? c_block[way_hit] : cache_inst_rdata;
    assign cpu_inst_addr_ok = cpu_inst_req & hit | cache_inst_req & cache_inst_addr_ok;
    assign cpu_inst_data_ok = cpu_inst_req & hit | cache_inst_data_ok;

    // Output to AXI interface
    assign cache_inst_req   = read_req & ~addr_rcv;
    assign cache_inst_wr    = cpu_inst_wr;
    assign cache_inst_size  = cpu_inst_size;
    assign cache_inst_addr  = cpu_inst_addr;
    assign cache_inst_wdata = cpu_inst_wdata;

    // Write to Cache
    reg [TAG_WIDTH-1:0] tag_save;
    reg [INDEX_WIDTH-1:0] index_save;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            tag_save   <= 0;
            index_save <= 0;
        end else if (cpu_inst_req) begin
            tag_save   <= tag;
            index_save <= index;
        end
    end

    integer j;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for (j = 0; j < CACHE_DEEPTH; j = j + 1) begin
                cache_valid[0][j] <= 0;
                cache_valid[1][j] <= 0;
                cache_valid[2][j] <= 0;
                cache_valid[3][j] <= 0;
                lru_bits[j] <= 0;
            end
        end else if (read_finish) begin
            if (~|way_hit) begin // Miss
                for (j = 0; j < WAY_NUM; j = j + 1) begin
                    if (lru_way[j]) begin
                        cache_valid[j][index_save] <= 1'b1;
                        cache_tag[j][index_save] <= tag_save;
                        cache_block[j][index_save] <= cache_inst_rdata;
                        lru_bits[index_save] <= {lru_bits[index_save][0], j[0]};
                    end
                end
            end
        end
    end

endmodule
