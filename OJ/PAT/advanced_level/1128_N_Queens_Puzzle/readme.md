*   原来棋盘是从左下角开始编号的，就和xOy坐标系一样，最左下角是原点

*   暴力解法。。

    1.   先保存每个点的坐标
    
    ```cpp
    struct Node{
    	int x, y;
    };
    ```
    
    2.  输入一组数据后，双层循环，逐个比较
    
        *   是否在同一对角线（X Y 间距相同）
        *   是否在同一行（）
        
        ```cpp
        bool solution = true;
		for( a = 0; a < n; ++a ){
			for( b = a + 1; b < n; ++b ){
				if( isDiag(v[a], v[b]) ){
					solution = false;
					break;
				}
				if( isLine(v[a], v[b]) ){
					solution = false;
					break;
				}
			}
			if( solution == false ){
				break;
			}
		}
        ````