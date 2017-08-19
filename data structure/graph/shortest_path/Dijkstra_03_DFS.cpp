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
    	int minDist=INF, midID = -1;
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