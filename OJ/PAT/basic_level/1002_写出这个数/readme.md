1.	输入

	输入视作字符串，而不是整数

	*	因为输入上限是10^100，所以字符串长度最大为100

	*	将每个字符转化为数字，求和得到sigma  
		由于字符串长度最大为100，每一位最大数字是9，可得sigma最大为9×100=900

2.	输出

	建立一个字符串数组`num_pinyin`，每个元素是0~9的拼音

	```c
	const char *num_pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
	```

3.	普通解法

	输入求和得到sigma

	```c
	scanf("%s", us_num);
	while( us_num[i]!='\0' ){
		sigma += (us_num[i++]-'0');
	}
	```

	获取sigma各数位的数字

	```c
	p_hundreds = sigma / 100;
	sigma = sigma - p_hundreds*100;
	p_tens = sigma / 10;
	sigma = sigma - p_tens*10;
	p_units = sigma;
	```

	输出逻辑

	*	a. 从高到低，
	*	b. 高位非零，低位全打
	*	c. 高位为零，内嵌if，下一位作为高位，回到b

	```c
	if( 0!=p_hundreds )
		printf("%s %s %s", num_pinyin[p_hundreds], num_pinyin[p_tens], num_pinyin[p_units]);
	else
		if( 0!=p_tens )
			printf("%s %s", num_pinyin[p_tens], num_pinyin[p_units]);
		else
			printf("%s", num_pinyin[p_units]);
	```

4.	<b>高阶写法</b>

	参考[这里](https://www.nowcoder.com/profile/243727/codeBookDetail?submissionId=3313687)，如果掌握了`int(), str(), map(), sum()`，则可以用python写出更<b>精妙</b>的代码：

	```python
	num_pinyin = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']
	us_num = raw_input()

	us_num = map(int, us_num)
	sigma = sum(us_num)
	sigma = str(sigma)

	for i in range(len(sigma)):
		print num_pinyin[int(sigma[i])],
	```

	只有10行左右，而且逻辑清晰。我们也可以参考这个思路，改写C的代码。对应`sigma = str(sigma)`

	```c
	sprintf(us_num, "%d", sigma);
	```

	对应后两行，则有

	```c
	while(us_num[i+1]!='\0')
		printf("%s ", num_pinyin[us_num[i++]-'0']);
	printf("%s", num_pinyin[us_num[i]-'0']);
	```

#	参考

*	字符串数组的声明与初始化

	```c
	const char *num[]={"one", "two", "three"};
	```

*	获取字符串输入

	```c
	char num[10];
	gets(num);	//可能溢出
	fgets(num, 10, stdin);	//会保存作为输入确认的'\n'
	scanf("%s", num);	//遇到空格结束
	```

	python中字符串可以用单引号`'`，也可以用双引号`"`。

	用惯了python，就容易忘记C的语法要求。。C中单引号只能包裹字符，双引号包裹的是字符串。字符串是以空字符`'\0'`结尾的`char数组`。

*	`sprintf()`

	在`stdio.h`中声明。原型为
	
	```c
	int sprintf(char *str, const char *format, ...);
	```

	不同于`printf()`的打印输出，它的作用是将内容保存为字符串，类似于python中的`str()`函数，比如

	```c
	char us_num[10];
	int sigma = 12345；
	sprintf(us_num, "%d", sigma);
	printf("%s", us_num);
	```

	则`us_num`的内容就变成了"12345"。



	
