#include <iostream>
#include <algorithm>
#define INF 1000000
#define MAXV 10
using namespace std;

struct MatrixGraph{
	int cntV = 7;
	int edge[7][7] = {
		{INF, 4, 3, INF, 7, INF, INF},
		{4, INF, 6, 5, INF, INF, INF},
		{3, 6, INF, 11, 8, INF, INF},
		{INF, 5, 11, INF, 2, 2, 10},
		{7, INF, 8, 2, INF, INF, 5},
		{INF, INF, INF, 2, INF, INF, 3},
		{INF, INF, INF, 10, 5, 3, INF}
	};
};

MatrixGraph G;

int pathFromSrc[MAXV];
int preV[MAXV];
bool marked[MAXV];
int i, j, k, srcID, destID, minDist;

int Dijkstra(MatrixGraph G){
	fill(marked, marked + MAXV, false);
	for( i=0; i<G.cntV; i++ ){
		pathFromSrc[i] = G.edge[srcID][i];
		if( pathFromSrc[i] < INF ){
			if( pathFromSrc[i]>0 ){
				// 距离在0~INF之间，说明i与起点src直接相连
				preV[i] = srcID;
			}
		}
	}
	marked[srcID] = true;
	pathFromSrc[srcID] = 0;

	for( i=0; i<G.cntV; i++ ){
		minDist = INF;
		int midV = srcID;
		// find the midVertex
		for( j=0; j<G.cntV; j++ ){
			if( marked[j] == false ){
				if( pathFromSrc[j] < minDist ){
					minDist = pathFromSrc[j];
					midV = j;
				}
			}
		}
		marked[midV] = true;

		for( j=0; j<G.cntV; j++ ){
			if( marked[j] == false ){
				// pathFromSrc[midV] 是起点src到中介点midV的最短距离
				// G.edge[midV][j] 是中介点midV与点j之间的距离，若为INF则表示不相连
				// pathFromSrc[j] 是起点到点j的最短距离
				if( pathFromSrc[midV] + G.edge[midV][j] < pathFromSrc[j] ){
					// 更新起点到j 的最短距离
					pathFromSrc[j] = pathFromSrc[midV] + G.edge[midV][j];
					// 更新j的前置节点，即中介点，经过中介点到i的距离比原来更短
					preV[j] = midV;
				}
			}
		}
	}	
	return 0;
}

int main(){
	srcID = 0;		// 0 is vertex-A
	destID = 5;     // 5 is vertex-F
	Dijkstra(G);

	// des < mid < mid < src
	int id = destID;
	while( id != srcID ){
		cout<<id<<" <-- ";
		id = preV[id];
	}
	cout<<srcID<<'\n';
	return 0;
}