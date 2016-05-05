#### asin 文件夹

* 要用三角函数之类的数学函数时需要`#include <math.h>`

* 但是直接用gcc编译时会有问题，需要链接`math`库，增加参数`-lm`

	gcc -o asin asin.c -lm

* asin() 返回的是弧度值

* 其他函数类同

#### atan 文件夹

* Makefile的编写: 在`-o`的那行加上参数`-lm`, 具体参见/atan/Makefile

