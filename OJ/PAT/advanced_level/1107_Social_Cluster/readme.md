##   并查集

*   同类题目

    1114, 1107, 1013, 1021

##	逻辑

*	下面5行是本题关键代码，其他都是模板

	```cpp
	if( hobbyList[h] == EMPTY ){
		hobbyList[h] = id;
	}
	int hobbyOwnerID = findFather(hobbyList[h]);
	Union( id, hobbyOwnerID );
	```

##	更新模板

*	参考 PAT_A_1114

	```cpp
	// 对应本题，换成Cluster
	struct Family{
	    int rootID = 0;     // 根节点编号
	    int people = 0; 	// 每个区块/家族的成员数量
	}
	Family family[MAXSIZE];
	
	bool marked[MAXSIZE] = {false}; // 如果输入中包含了i, 那么对应的marked[i]就标为true
	int father[MAXSIZE];
	
	// 初始化
	void initFather(){
	    for( int i = 0; i < MAXSIZE; ++i ){
	        father[i] = i;
	    }
	}
	
	// 省略路径压缩，好记
	int findFather(int x){
	    while( x != father[x] ){
	        x = father[x];
	    }
	    return x;
	}
	
	// 归并为同一集合
	void Union(int a, int b){
	    int faA = findFather(a);
	    int faB = findFather(b);
	
	    // 本题要求以家族中最小编号为代表，即可以最小编号为根
	    if( faA < faB ){
	        // 确保根节点的编号是最小的
	        father[faB] = faA;
	    }else{
	        // 确保根节点的编号是最小的
	        father[faA] = faB;
	    }
	}
	
	// 统计区块component
	int cntFamily(){
	    for( int i = 0; i < MAXSIZE; ++i ){
	        if( marked[i] == true ){
	            int rootID = findFather(i);
	            family[rootID].people++;
	        }
	    }
	    int cnt = 0;
	    for( int i = 0; i < MAXSIZE; ++i ){
	        if( family[i].people > 0 ){
	            cnt++;
	        }
	    }
	    return cnt;
	}
	```