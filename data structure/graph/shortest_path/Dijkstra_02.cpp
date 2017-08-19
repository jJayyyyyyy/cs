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
		int minDist = INF, midID = -1;
		for( int i = 0; i < n; ++i ){
			if( vis[i] == false && dist[i] < minDist ){
				minDist = dist[i];
				midID = i;
			}
		}
		if( midID == -1 )	return;
		vis[midID] = true;

		for( int i = 0; i < n; ++i ){
			if( vis[i] == false && G[midID][i] != INF ){
				if( dist[midID] + G[midID][i] < dist[i] ){
					dist[i] = dist[midID] + G[midID][i];
					pre[i].clear();
					pre[i].push_back(midID);
				}else if( dist[midID] + G[midID][i] == dist[i] ){
					pre[i].push_back(midID);
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