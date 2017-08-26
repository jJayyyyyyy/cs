// Dijkstra + DFS 输出所有最短路径
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3fffffff
#define MAXSIZE 16
using namespace std;

int n=7, srcID, destID;
int dist[MAXSIZE];
int G[7][7] = {
	{INF, 4, 3, INF, 7, INF, INF},
	{4, INF, 6, 5, INF, INF, INF},
	{3, 6, INF, 11, 8, INF, INF},
	{INF, 5, 11, INF, 2, 2, 10},
	{7, INF, 8, 2, INF, INF, 5},
	{INF, INF, INF, 2, INF, INF, 3},
	{INF, INF, INF, 10, 5, 3, INF}
};
vector<int> pre[MAXSIZE], tmpPath, path;
bool vis[MAXSIZE] = {false};

void init(){
	fill(dist, dist + MAXSIZE, INF);
}

void Dijkstra(){
	dist[srcID] = 0;
	while( vis[destID] == false ){
		int minDist = INF, midV = -1;
		for( int i = 0; i < n; ++i ){
			if( vis[i] == false && dist[i] < minDist ){
				minDist = dist[i];
				midV = i;
			}
		}
		if( midV == -1 )	return;
		vis[midV] = true;

		for( int i = 0; i < n; ++i ){
			if( vis[i] == false && G[midV][i] != INF ){
				if( dist[midV] + G[midV][i] < dist[i] ){
					dist[i] = dist[midV] + G[midV][i];
					pre[i].clear();
					pre[i].push_back(midV);
				}else if( dist[midV] + G[midV][i] == dist[i] ){
					pre[i].push_back(midV);
				}
			}
		}
	}
}

void fkout(){
	for( int i = tmpPath.size() - 1; i >= 0; --i ){
		cout<<" -> "<<(char)(tmpPath[i]+'A');
	}
	cout<<"\nDistance: "<<dist[destID]<<'\n';
}

void DFS(int v){
	if( v == srcID ){
		tmpPath.push_back(v);
		fkout();
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for( int i = 0; i < pre[v].size(); ++i ){
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();
}

int main(){
	init();
	srcID = 0;
	destID = 5;
	Dijkstra();
	DFS(destID);
	return 0;
}