# git

## git init

>初始化仓库

## 工作区，暂存区，版本库

>工作区：就是你在电脑里能看到的目录。
>暂存区：一般存放在.git目录下的index文件（`.git/index`）中，所以我们把暂存区有时也叫作索引（index）。
>版本库：工作区有一个隐藏目录.git，这个不算工作区，而是Git的版本库。

这三个区对应了三个命令 工作区->暂存区：`git add` 工作区->版本库：`git commit` 暂存区->版本库：`git commit -a`

## 文件状态

>`untracked` 未跟踪：新添加的文件（未被git跟踪的文件）
>`modified` 已修改：修改过的文件，仅仅是修改，没有进行其他的操作。
>`staged or added` 已暂存：把已修改的文件放在下次提交时要保存的清单中。

## git status

>查看文件状态

## git add

>将文件从工作区添加到暂存区

## git commit

>将暂存区的文件提交到版本库

```git
git commit -m " " -a 
```

- `-m`：提交信息
- `-a`：将所有已修改的文件提交到暂存区

## git log

>查看提交历史

- `git log --oneline`:一行显示
- `git reflog`:reference log,记录所有分支和移动的参考日志

## git rm

- `git rm --cached <file>`:删除暂存区的文件

- `git rm -f <file>`:删除工作区和暂存区的文件

## git reset

>用于回退分支状态

## git remote

>查看远程库信息

- `git remote -v`:verbose 显示所有远程仓库的详细信息
- `git remote add origin <url>`:添加远程库,其中origin是远程库的名字（默认是origin），`<url>`是远程库的地址
- `git push -u origin main`:设置跟踪关系,`--set-upstream`的简写,将远程仓库的main分支与本地仓库的main分支建立跟踪关系,之后就可以使用`git push`和`git pull`命令来推送和拉取本地仓库和远程仓库之间的代码了
- `git remote set-url origin <url>`:修改远程仓库的地址

## git branch

>创建分支

- `git branch <branch>`:创建分支
- `git branch -d <branch>`:删除分支
- `git branch -D <branch>`:强制删除分支
- `git branch -v`:查看分支的最新提交
- `git branch -vv`:查看本地分支与远程分支的跟踪关系

## git switch

>切换分支

- `git switch <branch>`:切换分支
- `git switch -c <branch>`:创建并切换分支
<!-- - `git switch -c <branch> origin/<branch>`:创建并切换分支,同时与远程分支建立跟踪关系 -->
- `git switch -c <branch> <commit>`:以一个提交commit来创建一个分支

>也可以在推送时使用`--set-upstream`的简写`-u`来建立跟踪关系
