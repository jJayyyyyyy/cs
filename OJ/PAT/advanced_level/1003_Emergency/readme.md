参考这里: [shortest_path](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/graph/shortest_path)

1.  emergency.cpp 是根据晴神宝典改写的
2.  emergency_02.cpp 是根据参考链接中给出的视频的方法写的Dijkstra()

    并不计算出起点到所有的点的最短路径，只要找到了终点就结束。
    
ps: 本题的第一个重点是Dijkstra，第二个重点是要计算出最短路径的个数(可能不止一条最短路径)，并且算出这些最短路径中，能召集到的最大数量的队伍

pps:    题目保证起点到终点之间有路可走。

ppps:   下午可能是高峰，用户多，因为方法2按理来说要比方法1少一些计算，但是最后的用时却比方法1大，重新用方法1的代码输入，结果相比上午，要多出13ms左右的时间