#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 100000000
#define MAXV 504
#define NOTFOUND -1
using namespace std;

int cntV, cntE, srcID, destID;
int G[MAXV][MAXV];	// G[i][j] is edgeWeight between i and j

int cntEWeight[MAXV];	// we want min/shortest of cntEWeight

int VWeight[MAXV];	// every city has its own rescue team
int cntVWeight[MAXV];	// total team gathered from the shortest path

int cntShortestPath[MAXV];
bool visitedV[MAXV] = {false};

int Dijkstra(){
	fill(cntEWeight, cntEWeight+MAXV, INF);
	fill(cntVWeight, cntVWeight+MAXV, 0);
	fill(cntShortestPath, cntShortestPath+MAXV, 0);
	fill(visitedV, visitedV+MAXV, false);

	cntEWeight[srcID] = 0;
	cntVWeight[srcID] = VWeight[srcID];

	cntShortestPath[srcID] = 1;

	for( int i=0; i<cntV; i++ ){
		int minWeight = INF;
		int minID = NOTFOUND;
		for( int j=0; j<cntV; j++ ){
			if( visitedV[j]==false && cntEWeight[j]<minWeight ){
				minWeight = cntEWeight[j];
				minID = j;
			}
		}

		if( minID == NOTFOUND ){
			return NOTFOUND;
		}else{
			visitedV[minID] = true;
			for( int j=0; j<cntV; j++ ){
				if( visitedV[j]==false && G[minID][j]!=INF ){
					if( cntEWeight[minID] + G[minID][j] < cntEWeight[j] ){
						cntEWeight[j] = cntEWeight[minID] + G[minID][j];
						cntVWeight[j] = cntVWeight[minID] + VWeight[j];
						cntShortestPath[j] = cntShortestPath[minID];
					}else if( cntEWeight[minID] + G[minID][j] == cntEWeight[j] ){
						if( cntVWeight[minID] + VWeight[j] > cntVWeight[j] ){
							cntVWeight[j] = cntVWeight[minID] + VWeight[j];
						}
						cntShortestPath[j] += cntShortestPath[minID];
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	cin>>cntV>>cntE>>srcID>>destID;
	fill(G[0], G[0] + MAXV*MAXV, INF);

	for(int i=0; i<cntV; i++){
		cin>>VWeight[i];
	}

	int a, b;
	for(int i=0; i<cntE; i++){
		cin>>a>>b;
		cin>>G[a][b];
		G[b][a] = G[a][b];
	}

	Dijkstra();

	cout<<cntShortestPath[destID]<<' '<<cntVWeight[destID]<<'\n';
	return 0;
}