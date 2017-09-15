union find set, 并查集, disjoint set

*	关键0，初始化！

*	关键1，在每次输入时进行 Union()，合并区块。并标记 vis[i] 为 true

*	关键2，计算区块数量，以及各种maxID

*	剩下的就是记模板

	一般模板请看本目录下的cpp，含结构体的较为复杂的目标，请参考 PAT_1114

*	PAT_A参考题目
	
	1.	输入完成后，结构不变：1021, 1107, 1114, 1118

	2.	结构会变：1013
	
		关于1013，由于每次查询都要去掉一个顶点，也就是结构会变，并且重新findFather()和Union()
		
		无法在输入时完成就确定区块结构，无法重用
		
		这样的题目，不要用并查集（较复杂，还要写路径压缩，否则会超时），直接用图的DFS, BFS模板就好了
		
*	路径压缩（以防万一）

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