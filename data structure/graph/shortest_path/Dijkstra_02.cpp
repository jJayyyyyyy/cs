#include <iostream>
#include <algorithm>
#define INF 1000000
#define MAXV 10
using namespace std;

int cntV=7, srcID, destID;
int G[7][7] = {
	{INF, 4, 3, INF, 7, INF, INF},
	{4, INF, 6, 5, INF, INF, INF},
	{3, 6, INF, 11, 8, INF, INF},
	{INF, 5, 11, INF, 2, 2, 10},
	{7, INF, 8, 2, INF, INF, 5},
	{INF, INF, INF, 2, INF, INF, 3},
	{INF, INF, INF, 10, 5, 3, INF}
};
int pre[MAXV];
int dist[MAXV];
bool marked[MAXV];

int init(){
	fill(marked, marked + MAXV, false);
	fill(dist, dist + MAXV, INF);
	return 0;
}

int Dijkstra(){
	dist[srcID] = 0;
	int midID = srcID;

	while( marked[destID] == false ){
		int minWeight = INF;
		for( int i=0; i<cntV; i++ ){
			if( marked[i] == false ){
				if( dist[i] < minWeight ){
					minWeight = dist[i];
					midID = i;
				}
			}
		}
		marked[midID] = true;

		for( int i=0; i<cntV; i++ ){
			if( G[midID][i] != INF ){
				if( marked[i] == false ){
					if( dist[midID] + G[midID][i] < dist[i] ){
						dist[i] = dist[midID] + G[midID][i];
						pre[i] = midID;
					}
				}
			}
		}
	}
	return 0;
}

int output(){
	// des < mid < mid < src
	int id = destID;
	while( id != srcID ){
		cout<<id<<" <-- ";
		id = pre[id];
	}
	cout<<srcID<<'\n';
	cout<<dist[destID]<<'\n';
	// cout<<dist[5]<<'\n';
}

int main(){
	init();

	srcID = 0;		// 0 is vertex-A
	destID = 5;     // 5 is vertex-F
	// destID = 2;

	Dijkstra();
	output();
	
	return 0;
}