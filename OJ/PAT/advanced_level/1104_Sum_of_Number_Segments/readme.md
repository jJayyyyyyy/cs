算法:

```
0.1     0.2     0.3     0.4
```

n=4，对于0.2，其index=i=2出现的次数

*   (0.1, 0.2) + (0.2)  i次

*   (0.2, 0.3) + (0.2, 0.3, 0.4)    `n-i`次

*   (0.1, 0.2, 0.3) + (0.1, 0.2, 0.3, 0.4)  `n-i`次，即前置0.1后也有`n-i`次

其中，(n-i)会出现i次。因此总的次数是

```
t = i + (n-i)*i
```

然而不知道为什么，这段代码无法通过最后两个case

```cpp
// codeblock_1
// ... definition for vars

for( i=1; i<=n; i++ ){
	cin>>num;
	t = i + (n-i)*i;
	sigma += num * t;
}
```

这段代码也无法通过最后两个case

```cpp
// codeblock_2
// 这段代码无法通过最后两个case

// ... definition for vars

for( i=1; i<=n; i++ ){
	cin>>num;
	sigma += num * ( i + (n-i)*i );
}
```

只有这样才行

```cpp
// codeblock_3
// ... definition for vars

for( i=1; i<=n; i++ ){
	cin>>num;
	sigma += num * i + num * i * (n-i);
	// sigma += num * i * (n-i+1);      // 或者提取公因子
}
```

好奇怪。。按理来说数学上都是一样的，但为啥codeblock_1和codeblock_2无法只能做对两个case？