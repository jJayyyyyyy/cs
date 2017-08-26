*	Dijkstra_01.cpp是对<零基础学算法>第3版的p134~p135所给程序的改编，参照的例子是YouTube上的视频[Dijkstra's Algorithm](https://www.youtube.com/watch?v=gdmfOwyQlcI)。

	以后再做改进，先学习过程。

*	Dijkstra_02.cpp是按照视频所述的算法，得到的代码。思路如下：

	```
	1.  一开始，将所有的dist[i]都初始化为INF=0x3fffffff，再将起点A的dist[srcID]初始化为0
	2.  在未标记的点中，选取dist最小的点，记为中介点midV
	3.  标记midV
	4.  找到与midV相邻的，且未被标记的点 G[mid][i]
	5.  对于 G[mid][i] 中的点i，若通过中介点midV到i的路径比原来的路径更短，即 (dist[midV] + G[midV][i] < dist[i] )，则更新dist[i]
	6.  重复2~6，直到终点被标记，则任务完成
	```

	该算法，在找到从终点的最短路径后就会停止，而不是算出从起点到所有点的最短路径。
	
	比如说，我们把destID换成2（对应点C），那么可以得出最短路径 A->C。
	
	这时如果我们输出一下A到F长度，会发现它的值仍然是INF，因为最短路径肯定不会经过那里，也就没必要去算了。

	vis[i] 存储的就是，已经确定了最短路径的点i，因为这些点都是步骤2中的midV已经是从起点出发的路上最小的了，比其他已知的点都要小。而未知的点都要通过这些已知点才能到达，比大更大，当然不是最短路径了。注意，这里的路径权值不能有非正数，否则会出现比大更小的情况，这也是Dijkstra算法的约束条件。

*	实例参考：[PAT_A_1003_Emergency](https://github.com/jJayyyyyyy/cs/blob/master/OJ/PAT/advanced_level/1003_Emergency/emergency.cpp)

*	Dijkstra + DFS, 参考示例

	1003, 1018, 1030, 1072, 1087, 1111
