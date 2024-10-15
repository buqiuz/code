## SSH
ssh  user@ip/域名

执行后会提示你是否确认连接（第一次连接将是未识别状态）如果输入yes，则会在know_hosts文件中添加该主机

显然，这种通过密码的连接方式是不安全的，所以应该通过密钥来连接

ssh-keygen  -t  “密钥生成算法”   -C “注释”


`ssh-keygen` 是用于生成、管理和转换 SSH 密钥的工具。以下是一些常用的 `ssh-keygen` 参数及其解释：

### 常用参数

1. **-t** *type*:
   - 用于指定要生成的密钥类型。常见的类型包括：
     - `rsa`: RSA 密钥
     - `dsa`: DSA 密钥
     - `ecdsa`: ECDSA 密钥
     - `ed25519`: Ed25519 密钥
   - 示例: `ssh-keygen -t rsa`

2. **-b** *bits*:
   - 指定密钥的长度（以位为单位）。对于 RSA 密钥，常见的长度是 2048 或 4096。
   - 示例: `ssh-keygen -t rsa -b 4096`

3. **-C** *comment*:
   - 为密钥添加注释。通常用于识别密钥的用途或所有者。
   - 示例: `ssh-keygen -t rsa -C "user@example.com"`

4. **-f** *filename*:
   - 指定密钥文件的名称和路径。默认情况下，密钥会存储在用户主目录的 `.ssh` 目录下。
   - 示例: `ssh-keygen -t rsa -f ~/.ssh/my_rsa_key`

5. **-N** *new_passphrase*:
   - 为私钥设置密码短语。如果不希望为私钥设置密码短语，可以将其设置为空字符串。
   - 示例: `ssh-keygen -t rsa -N "mypassword"`

6. **-q**:
   - 安静模式，减少输出信息。
   - 示例: `ssh-keygen -t rsa -q`

7. **-e**:
   - 将 OpenSSH 私钥或公钥转换为 RFC 4716 SSH 公钥格式。
   - 示例: `ssh-keygen -e -f ~/.ssh/id_rsa.pub`

8. **-i**:
   - 将 RFC 4716 SSH 公钥格式转换为 OpenSSH 公钥格式。
   - 示例: `ssh-keygen -i -f rfc4716_key.pub`

9. **-p**:
   - 修改私钥的密码短语。
   - 示例: `ssh-keygen -p -f ~/.ssh/id_rsa`

10. **-l**:
    - 显示公钥文件的指纹。
    - 示例: `ssh-keygen -l -f ~/.ssh/id_rsa.pub`

### 生成 SSH 密钥的示例
以下是一个使用 `ssh-keygen` 生成 RSA 密钥对的示例，包含常用参数：

```sh
ssh-keygen -t ed25519 -b 4096 -C "user@example.com" -f ~/.ssh/my_rsa_key
```

以上命令生成一个 4096 位长的 RSA 密钥对，注释为 "user@example.com"，密钥文件保存为 `~/.ssh/my_rsa_key`，并设置了密码短语 "mypassword"。

这些参数可以根据具体需求进行调整，以生成和管理适合的 SSH 密钥。


## 关于~符号


在 Windows 系统中，`~` 这个符号并不像在 Unix/Linux 系统中那样直接代表用户的主目录。然而，在一些 Windows 下的工具和环境中（比如 Git Bash、WSL、或者一些兼容 Unix 命令的工具），`~` 符号可以用来表示当前用户的主目录。

### 示例

如果你在使用 Git Bash、WSL（Windows Subsystem for Linux）或其他类似的工具时，可以使用 `~` 来表示用户主目录。例如：

```bash
cd ~
```

这条命令会将你切换到当前用户的主目录。在这些环境中，`~` 会自动解析为类似于 `C:\Users\{用户名}` 的路径。

### Windows 原生命令行

在 Windows 原生的命令提示符（cmd.exe）和 PowerShell 中，`~` 不会自动解析为用户主目录。你需要使用环境变量 `%USERPROFILE%` 来表示用户的主目录。

例如，在命令提示符（cmd.exe）中，你可以使用以下命令来切换到用户主目录：

```cmd
cd %USERPROFILE%
```

在 PowerShell 中，可以使用以下命令：

```powershell
cd $HOME
```

### 总结

- **Git Bash/WSL 等环境**: `~` 可以用来表示用户主目录。
- **Windows 命令提示符（cmd.exe）**: 使用 `%USERPROFILE%` 表示用户主目录。
- **PowerShell**: 使用 `$HOME` 表示用户主目录。

在这些不同的环境中，选择合适的符号或变量来表示用户主目录可以帮助你更方便地导航和管理文件系统


## 将生成的 SSH 密钥对发送到服务器的步骤如下：

### 1. 生成 SSH 密钥对

首先，使用 `ssh-keygen` 命令生成 SSH 密钥对（如果尚未生成）。以下是一个示例命令：

```sh
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

这将生成一对密钥，默认存储在 `~/.ssh/` 目录下。公钥通常命名为 `id_rsa.pub`，私钥为 `id_rsa`。

### 2. 将公钥发送到服务器

将公钥传输到服务器上的 `~/.ssh/authorized_keys` 文件中。可以使用 `ssh-copy-id` 命令完成此操作。以下是使用 `ssh-copy-id` 命令的步骤：

```sh
ssh-copy-id -i ~/.ssh/id_rsa.pub user@remote_host
```

其中：
- `-i ~/.ssh/id_rsa.pub` 指定公钥文件的位置。
- `user` 是远程服务器上的用户名。
- `remote_host` 是远程服务器的 IP 地址或主机名。

### 3. 手动将公钥添加到服务器

如果 `ssh-copy-id` 命令不可用，可以手动将公钥添加到服务器。以下是手动步骤：

1. 使用 `scp` 或其他工具将公钥文件复制到服务器：

   ```sh
   scp ~/.ssh/id_rsa.pub user@remote_host:/tmp/id_rsa.pub
   ```

2. 连接到服务器：

   ```sh
   ssh user@remote_host
   ```

3. 在服务器上，将公钥添加到 `~/.ssh/authorized_keys` 文件：

   ```sh
   mkdir -p ~/.ssh
   cat /tmp/id_rsa.pub >> ~/.ssh/authorized_keys
   chmod 600 ~/.ssh/authorized_keys
   rm /tmp/id_rsa.pub
   ```

### 验证连接

完成上述步骤后，断开与服务器的连接并尝试使用 SSH 密钥连接：

```sh
ssh user@remote_host
```

如果一切配置正确，你应该能够无密码地连接到服务器。

### 注意事项

1. **权限设置**: 确保 `~/.ssh` 目录和 `~/.ssh/authorized_keys` 文件具有正确的权限设置。通常，`~/.ssh` 目录的权限应为 `700`，`authorized_keys` 文件的权限应为 `600`。
2. **现有密钥**: 如果 `~/.ssh/authorized_keys` 文件已存在，不要覆盖它，而是将新的公钥附加到文件末尾。

这样，你就可以将生成的 SSH 密钥对发送到服务器并进行无密码 SSH 连接。





`chmod` 是 "change mode" 的缩写。这个命令用于在 Unix 和 Linux 系统上改变文件和目录的访问权限。通过 `chmod` 命令，用户可以设置谁可以读取、写入或执行某个文件或目录。

## chmod

### 基本用法

`chmod` 的基本语法如下：

```sh
chmod [选项] 模式 文件
```

其中，`模式` 可以用数字表示，也可以用符号表示。以下是一些常见的用法示例：

#### 使用数字表示法

数字表示法使用三位八进制数来设置文件权限。每一位分别表示文件所有者、所属组和其他用户的权限。常见的权限值如下：

- `4`：读权限（r）
- `2`：写权限（w）
- `1`：执行权限（x）

通过将这些值相加，可以设置多种权限组合。例如：

- `7`（4 + 2 + 1）：读、写、执行权限（rwx）
- `6`（4 + 2）：读、写权限（rw-）
- `5`（4 + 1）：读、执行权限（r-x）

例如，将文件的权限设置为所有者可以读写执行，所属组和其他用户只能读取：

```sh
chmod 755 文件名
```

#### 使用符号表示法

符号表示法使用字符表示权限的变化：

- `u`：文件所有者
- `g`：文件所属组
- `o`：其他用户
- `a`：所有用户（包括所有者、所属组和其他用户）
- `+`：添加权限
- `-`：移除权限
- `=`：设置权限

例如，将文件的权限设置为所有者可以读写，所属组和其他用户只能读取：

```sh
chmod u=rw,go=r 文件名
```

### 常用示例

1. **给所有用户添加执行权限**：
   
   ```sh
   chmod +x 文件名
   ```

2. **移除其他用户的写权限**：
   
   ```sh
   chmod o-w 文件名
   ```

3. **设置文件所有者可以读写执行，组用户和其他用户只能读**：
   
   ```sh
   chmod 755 文件名
   ```

4. **设置所有用户只能读取文件**：
   
   ```sh
   chmod 444 文件名
   ```

### 总结

`chmod` 命令通过数字或符号来设置文件和目录的权限，使用户可以灵活地控制文件的访问权限，以保证系统的安全性和文件的正确使用。

## 关于git用户


在 GitHub 中，`git` 用户是一个用于通过 SSH 协议进行所有 Git 操作的通用用户。这意味着，无论你在 GitHub 上的用户名是什么，当你通过 SSH 访问 GitHub 仓库时，都需要使用 `git` 作为用户名。这是 GitHub 的一个约定，用于简化和统一 SSH 访问配置。

### 理解 `git` 用户

- **通用用户**: `git` 用户并不对应于你在 GitHub 上的个人账户。它是一个通用的用户名，专门用于通过 SSH 协议进行 Git 操作。
- **安全性**: 使用 `git` 用户并结合你的 SSH 密钥进行身份验证，可以确保你的操作是安全的，GitHub 可以通过你的公钥识别你的身份。
- **统一性**: 无论你使用的是哪个仓库或者你在 GitHub 上的个人账户是什么，所有 SSH 操作都使用 `git` 作为用户名。这使得配置和使用变得一致和简便。

### 配置示例

假设你已经生成了 SSH 密钥对并将公钥添加到了 GitHub，接下来你需要在 `~/.ssh/config` 文件中进行配置：

```sh
# GitHub configuration
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_rsa_github
```

### 验证

你可以通过以下命令验证你的配置是否正确：

```sh
ssh -T git@github.com
```

如果配置正确，你会看到类似以下的输出：

```plaintext
Hi your_github_username! You've successfully authenticated, but GitHub does not provide shell access.
```

这种配置确保了每次你通过 SSH 访问 GitHub 仓库时，都会使用 `git` 作为用户名，并使用你配置的 SSH 密钥进行身份验证。这是 GitHub 的标准操作方式，旨在确保安全和简便。