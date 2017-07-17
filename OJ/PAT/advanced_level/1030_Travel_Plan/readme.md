*   Dijkstra + DFS, 背模板, 会应用

*	初始化全部放在init()

*	Dijkstra模板 ---> 算出并保存所有最短路径

	```cpp
	int Dijkstra(){
		dist[srcID] = 0;
		while( marked[destID] == false ){
			int minDist = INF, midID = -1;
			//注意, 本题的顶点区间是[0, cntV], 其他题目也可能是[0, n), 或(1, n]
			for( int i=0; i<=cntV; ++i ){
				if( marked[i] == false && dist[i] < minDist ){
					minDist = dist[i];
					midID = i;
				}
			}
			if( midID == -1 ){
				return -1;
			}
			marked[midID] = true;
			
			for( int i=0; i<=cntV; ++i ){
				if( marked[i] == false && G[midID][i] != INF ){
					if(  dist[midID] + G[midID][i] < dist[i] ){
						dist[i] = dist[midID] + G[midID][i];
						pre[i].clear();
						pre[i].push_back(midID);
					}else if( dist[midID] + G[midID][i] == dist[i] ){
						pre[i].push_back(midID);
					}
					// 注意, 最短路径的条数就是 pre[destID].size(), DFS中会用到
				}
			}
		}
		
		return 0;
	}
	```

*	DFS模板 ---> 遍历这些最短路径，得到满足第二、三、四标准的最优解

	```cpp
	int DFS(int v){
		// 从终点到起点
		if( v == srcID ){
			tmpPath.push_back(v);
			// some var def
			
			for( int i = tmpPath.size() - 1; i >= 0; --i ){
				int id = tmpPath[i];
				// do sth
				// blablabla
			}
			
			tmpPath.pop_back();
			return 0;
		}
		
		tmpPath.push_back(v);
		for( int i=0; i<pre[i].size(); ++i ){
			DFS(pre[v][i]);
		}
		tmpPath.pop_back();	//试探结束, 换一条路
		return 0;
	}
	
	int main(){
		// ...
		// 从终点开始, 倒着进行深搜
		DFS(destID);	
		// ...
		return 0;
	}
	```

*   同类题目
    
    *   [1003]
    *   [1018]
    *   [1030]    
    *   [1072]
    *   [1087]

