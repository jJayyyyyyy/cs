// 参考PAT_1111
#include <algorithm>
#include <vector>
#define MAXSIZE 504
#define INF 0x3fffffff
using namespace std;

int n, srcID, destID, minCost=INF;
int G[MAXSIZE][MAXSIZE], cost[MAXSIZE][MAXSIZE];
int dist[MAXSIZE];
bool vis[MAXSIZE] = {false};
vector<int> pre[MAXSIZE], tmpPath, path;

void init(){
	fill(G[0], G[0] + MAXSIZE * MAXSIZE, INF);
	fill(dist, dist + MAXSIZE, INF);
}

void Dijkstra(){
	dist[srcID] = 0;
	while( vis[destID] == false ){
		int minDist=INF, midV = -1;
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

void calCost(){
	int tmpCost = 0;
	for( int i = tmpPath.size() - 1; i > 0; --i ){
		int id = tmpPath[i];
		int nextID = tmpPath[i - 1];
		tmpCost += cost[id][nextID];
	}
	if( tmpCost < minCost ){
		minCost = tmpCost;
		path = tmpPath;
	}
}

void DFS(int v){
	if( v == srcID ){
		tmpPath.push_back(v);
		calCost();
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for(int i = 0; i < pre[v].size(); ++i ){
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();
}

int main(){
	return 0;
}


/*
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXSIZE 504
#define INF 0x3fffffff
using namespace std;

int n, m, src, dest;
bool vis[MAXSIZE] = {false};
int G[MAXSIZE][MAXSIZE];
int dist[MAXSIZE];
int team[MAXSIZE];
int maxCost=0, cntPath=0;
vector<int> pre[MAXSIZE], tmpPath, ansPath;

void init(){
	fill(G[0], G[0] + MAXSIZE*MAXSIZE, INF);
	fill(dist, dist + MAXSIZE, INF);
}

void Dijkstra(){
	dist[src] = 0;
	while( vis[dest] == false ){
		int mid = -1;
		int minDist = INF;
		for( int i = 0 ; i < n; i++ ){
			if( vis[i] == false && dist[i] < minDist ){
				mid = i;
				minDist = dist[i];
			}
		}
		if( mid == -1 ){
			return;
		}

		vis[mid] = true;
		for( int i = 0; i < n; i++ ){
			if( vis[i] == false && G[mid][i] != INF ){
				if( dist[mid] + G[mid][i] < dist[i] ){
					dist[i] = dist[mid] + G[mid][i];
					pre[i].clear();
					pre[i].push_back(mid);
				}else if( dist[mid] + G[mid][i] == dist[i] ){
					pre[i].push_back(mid);
				}
			}
		}
	}
}

void calCost(){
	int tmpCost = 0;
	for( int i = tmpPath.size()-1; i>=0; i-- ){
		int now = tmpPath[i];
		// int next = tmpPath[i-1];
		tmpCost += team[now];
	}
	if( tmpCost > maxCost ){
		maxCost = tmpCost;
		ansPath = tmpPath;
	}
}

void DFS(int v){
	if( v == src ){
		tmpPath.push_back(v);
		calCost();
		cntPath++;
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for( int i = 0; i < pre[v].size(); i++ ){
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	int v1, v2, len;
	cin>>n>>m>>src>>dest;
	for( int i = 0; i < n; i++ ){
		cin>>team[i];
	}
	for( int i = 0; i < m; i++ ){
		cin>>v1>>v2>>len;
		G[v1][v2] = G[v2][v1] = len;
	}

	Dijkstra();
	DFS(dest);

	cout<<cntPath<<' '<<maxCost<<'\n';
	return 0;
}



*/