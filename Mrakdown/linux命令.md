
# linux命令

 在Linux系统中，命令的基本格式通常如下：

```sh
command [options] [arguments]
```

这里：

- `command` 是你要执行的命令，例如 ls、cd、mkdir 等。
- `[options]` 是命令的选项，用于修改命令的行为。例如，-l、-a、-r 等。
- `[arguments]`是命令的参数，例如文件名、目录名等。

## ls

>list

```sh
ls [-a -l -h] [directory]
```

- `-a`：all 显示所有文件，包括隐藏文件。
- `-l`：list 以列表形式显示文件和目录的详细信息。
- `-h`：human 以人类可读的格式显示文件大小，例如 KB、MB、GB 等。
- `directory`：要显示的目录，默认为当前目录。

注:

- `ls -l` 可以简写为 `ll`.
- `ls -a` 可以简写为 `la`. //可能不支持
- `ls -lh` 可以简写为 `llh`. //可能不支持

## pwd

>print working directory

```sh
pwd [-P -L]
```

- 显示当前工作目录的绝对路径。
- `-P`:phsical 显示物理路径，而非符号链接路径。
- `-L`:logical 显示符号链接路径，而非物理路径。

## cd

>change directory

```sh
cd [directory]
```

- `directory`：要切换到的目录。如果不指定目录，则默认切换到用户的主目录。
- `cd /`是回到根目录

## mkdir

>make directory

```sh
mkdir [-p] directory
```

- `-p`：parents 创建多级目录，如果父目录不存在则创建。
- `directory`：要创建的目录名。

## touch

>touch

```sh
touch file
```

- 创建一个空的文件，如果文件已经存在，则更新文件的访问和修改时间。

## cat

>concatenate and display files

```sh
cat file
```

- 显示文件内容。
- `cat file1 file2`：将多个文件的内容合并并显示到标准输出。
- `cat > file`：将标准输入的内容写入到文件中。
- `cat file1 > file2`：将文件1的内容覆盖写入到文件2中。
- `cat file1 >> file2`：将文件1的内容追加写入到文件2中。

## more(已过时)

>more

```sh
more file
```

- 用于分页查看文件内容，可以逐页滚动查看文件内容。

## less(推荐使用)

>less

```sh
less file
```

- 用于分页查看文件内容，可以上下滚动查看文件内容，比 more 更强大。
- `less` 命令支持搜索、高亮显示等更多功能。
- `less` 命令的常用操作包括：上下箭头键滚动，空格键翻页，`/` 键搜索，`q` 键退出等。
- `less` 命令的输出结果会显示在终端上，可以使用 `less` 命令查看文件内容。
- `less` 命令的输出结果可以分页显示，可以使用上下箭头键滚动查看文件内容。
- `less` 命令支持搜索，可以使用 `/` 键输入搜索关键字，然后按回车键进行搜索。
- `less` 命令支持高亮显示搜索结果，可以使用 `n` 键跳转到下一个匹配项，使用 `N` 键跳转到上一个匹配项。
- `less` 命令的输出结果可以保存到文件中，可以使用 `>` 键输入文件名，然后按回车键将输出结果保存到文件中。
- `less` 命令的输出结果可以分屏显示，可以使用 `v` 键进入编辑模式，然后按 `q` 键退出编辑模式。

## cp

>copy

```sh
cp [-r] source destination
```

- `-r`：recursive 递归复制目录及其内容。
- `source`：要复制的文件或目录。
- `destination`：复制到的目标位置。

## mv

>move

```sh
mv source destination
```

- 将文件或目录移动到目标位置。
- 还可以重命名。

## rm

>remove

```sh
rm [-r -f] file.....
```

- `-r`：recursive 递归删除目录及其内容。
- `-f`：force 强制删除，不提示确认。
- `file`：要删除的文件或目录。
- `*/#`: 支持通配符
  - `test*`
  - `*test`
  - `....`

## which

>which

```sh
which command
```

- 查找命令的绝对路径。

## find

>find

```sh
find directory <-name -size> "name"
```

- `directory`：起始路径。
- `-name`: 被查找文件名,可以使用通配符
- `-size`: 按文件大小查找
  - `-size +100M`：查找大于100M的文件
  - `-size -100M`：查找小于100M的文件
- 在指定目录下查找符合指定模式的文件或目录。

## echo

>echo

```sh
echo "string"
```

- 将字符串输出到标准输出。
- `` echo `pwd` ``：会将 `pwd` 命令的输出作为字符串输出。

## >和>>

>重定向符号

- `>`：将左边命令的结果覆盖写入文件，如果文件不存在则创建。
- `>>`：追加写入文件，如果文件不存在则创建。

## tail

>tail

```sh
tail [-n -f] file
```

- `-n`：number 显示文件的最后几行，默认为10行。
  - `-n 100`
  - `-n 1000`
- `-f`：follow 追踪文件的变化，实时显示文件的最后几行。

## grep

>global search regular expression(RE) and print out the line

```sh
grep [-n] "string" file
```

- 在文件中查找包含指定字符串的行。
- `-n`：number 显示匹配行的行号。
- `file`:可以作为管道符的输入端口。
- 经常与管道符配合使用,作为过滤器。

## |

>管道符号

- 将前一个命令的输出作为后一个命令的输入。
- `ls -l | grep "string"`：在 `ls -l` 的输出中查找包含指定字符串的行。

## su

>switch user

```sh
su [-] user
```

- 切换到其他用户。
- `-`:带上切换用户的环境变量，即完全成为该用户

## chmod

>change mode

```sh
chmod [-R] mode file
```

- `-R`：recursive 递归修改目录及其内容。

- `mode`：权限模式，例如 `755`、`644` 等。

```sh
chmod [u/g/o] [+-=] [rwx] file
```

- `u`：user 文件所有者。
- `g`：group 文件所属组。
- `o`：other 其他用户。
- `a`: all 所有用户。
- `+`：添加权限。
- `-`：移除权限。
- `=`：设置权限。
- `rwx`：读、写、执行权限。
- 默认是`a`
