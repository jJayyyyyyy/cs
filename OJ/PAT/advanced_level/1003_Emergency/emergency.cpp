#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3fffff00
#define MAXSIZE 504
using namespace std;

int n, srcID, destID, maxTeam = 0, cntRoad = 0;
int G[MAXSIZE][MAXSIZE], Team[MAXSIZE], dist[MAXSIZE];
bool vis[MAXSIZE];
vector<int> pre[MAXSIZE], tmpPath, path;

void init(){
	fill(G[0], G[0] + MAXSIZE * MAXSIZE, INF);
	fill(dist, dist + MAXSIZE, INF);
	fill(Team, Team + MAXSIZE, 0);
	fill(vis, vis + MAXSIZE, false);
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

void cntTeam(){
	int tmpTeam = 0;
	for( int i = tmpPath.size() - 1; i >= 0; --i ){
		int v = tmpPath[i];
		tmpTeam += Team[v];
	}
	if( tmpTeam > maxTeam ){
		maxTeam = tmpTeam;
		path = tmpPath;
	}
}

void DFS(int v){
	if( v == srcID ){
		tmpPath.push_back(v);
		++cntRoad;
		cntTeam();
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int m, v1, v2, i, len;
	cin>>n>>m>>srcID>>destID;
	for( i = 0; i < n; ++i){
		cin>>Team[i];
	}

	for( i = 0; i < m; ++i ){
		cin>>v1>>v2>>len;
		G[v1][v2] = G[v2][v1] = len;
	}
	Dijkstra();
	DFS(destID);
	cout<<cntRoad<<' '<<maxTeam<<'\n';
	return 0;
}
