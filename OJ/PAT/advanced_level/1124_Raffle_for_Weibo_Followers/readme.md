*	结合STL的set，就很简单了。

	```cpp
	s.insert(var);			// 插入元素
	s.find(var) != s.end()	// 判断元素是否存在于set
	```

```cpp
for( i = 1; i <= m; ++i ){
	cin>>nickname;
	if( i == st ){
		if( win.find(nickname) == win.end() ){	// 如果没有中过奖
			cout<<nickname<<'\n';
			win.insert(nickname);
			st += step;
		}else{		// 该用户已经中过奖了，那么就判断下一位
			st++;
		}
	}
}
```