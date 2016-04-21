## 1. 变量

* 变量的显示与设置: echo, unset

`$ echo $PATH` 显示PATH变量，`$`表示后面跟着变量. 也可以是 `${PATH}`、`${$HOME}`

```bash
$ var='a'	#不能有空格，可以用单引号/双引号把后面的内容包起来，也可以不包
$ echo var
var
$ echo $var
a
```

* 双引号与单引号的区别(都可以将有空格的变量包起来)

```bash
$ var="$LANG is language"		#保持原特性
$ echo $var
en_US.UTF-8 is language
$
$ var='$LANG is language'		#识别为字符
$ echo $var
$LANG is language
```

* `$` 与`\``反引号 --- 变量存储命令，相当于是命令的alias

```bash
$ var=$(uname -r)	#显示内核release版本号
3.13.0-79-generic
$ var=`uname -r`
3.13.0-79-generic
```

**一个例子: 进入内核的模块目录**

```bash
$ cd /lib/modules/`uname -r`/kernal
$ cd /lib/modules/$(uname -r)/kernal
$ cd /lib/modules/"$(uname -r)"/kernal
```

* 增加变量内容

```bash
$ var=a
$ echo $var
a
$ var="$var"bb
$ echo $var
abb
$
$ var=${var}ccc
$ echo $var
abbccc
$
$ var=($var)dddd
$ echo $var
(abbccc)dddd
```

* 变成环境变量, 使其子进程也可使用

```bash
$ var=a
$ echo $var
a
$ bash			#在当前bash下新开一个bash子进程
$ echo $var		#新的子进程里面没有$var

$ exit			#退出子进程，也可以按下[ctrl+d]
$ export var
$ bash
$ echo $var		#这下就有了
a
$ exit
```

* 通常大写为系统默认变量，小写为自行设置的变量，方便判断

* 取消变量

`$ unset var`



