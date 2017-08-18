*   若使用邻接矩阵，顶点i的度，可以通过遍历G[i][j]得到，j 范围是[1, n]

	三种情况
	
	*   所有顶点的度都是偶数    ——  Eulerian
	*   只有2个顶点的度是奇数   ——  Semi-Eulerian
	*   其他                    ——  Non-Eulerian
	
*   以上方法，仍有一个case无法通过，猜测是给定的所有顶点形成了多个（互不连通的）图，所以需要先检查图的连通性。

	```cpp
	bool visit[MAXSIZE] = {false};
	
	bool checkConn(int v, int n){
		queue<int> q;
		q.push(v);
		visit[v] = true;
		while( q.size() > 0 ){
			int u = q.front();
			q.pop();
			for( int i = 1; i <= n; ++i ){
				if( visit[i] == false && G[u][i] != 0 ){
					q.push(i);
					visit[i] = true;
				}
			}
		}
		for( int i = 1; i <= n; ++i ){
			if( visit[i] == false ){
				return false;
			}
		}
		return true;
	}
	```
	
*	原解法基于BFS，本题与1013 Battle Over Cities类似

*	20170818增加DFS解法。

	推荐使用 `邻接链表` + `DFS` 的形式，代码简洁好记。
