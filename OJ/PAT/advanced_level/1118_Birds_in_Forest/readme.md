1.  同类题目

    1021, 1107, 1114, 1118

2.  使用并查集模板即可，这里数据估计比较简单，不使用路径压缩也能完成。

3.  路径压缩（以防万一）

    ```cpp
    int findFather(int x){
    	int a = x;
    	while( x != father[x] ){
    		x = father[x];
    	}
    
    	while( a != father[a]){
    		int z = a;
    		a = father[a];
    		father[z] = x;
    	}
    	return x;
    }
    ```
    