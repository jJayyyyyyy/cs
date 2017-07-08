#include <iostream>
#include <algorithm>
#define INF 10000000
#define MAXV 504
using namespace std;

int cntCity, cntRoad, srcID, destID;
int G[MAXV][MAXV];
int VWeight[MAXV];
int cntVWeight[MAXV];
int ownTeam[MAXV];
int totalTeam[MAXV];
bool marked[MAXV];

int Dijkstra(){
	fill(marked, marked + MAXV, false);
	fill(VWeight, VWeight + MAXV, INF);
	fill(cntVWeight, cntVWeight + MAXV, 0);
	fill(totalTeam, totalTeam + MAXV, 0);

	VWeight[srcID] = 0;
	cntVWeight[srcID] = 1;
	totalTeam[srcID] = ownTeam[srcID];
	int midID = srcID;

	while( marked[destID] == false ){
		int minVWeight = INF;
		for( int i=0; i<cntCity; i++ ){
			if( marked[i] == false ){
				if( VWeight[i] < minVWeight ){
					minVWeight = VWeight[i];
					midID = i;
				}
			}
		}
		marked[midID] = true;

		for( int i=0; i<cntCity; i++ ){
			if( G[midID][i] != INF ){
				if( marked[i] == false ){
					if( VWeight[midID] + G[midID][i] < VWeight[i] ){
						VWeight[i] = VWeight[midID] + G[midID][i];
						totalTeam[i] = totalTeam[midID] + ownTeam[i];
						cntVWeight[i] = cntVWeight[midID];
					}else if( VWeight[midID] + G[midID][i] == VWeight[i] ){
						if( totalTeam[midID] + ownTeam[i] > totalTeam[i] ){
							totalTeam[i] = totalTeam[midID] + ownTeam[i];
						}
						cntVWeight[i] += cntVWeight[midID];
					}
				}
			}
		}
	}

	return 0;
}

int main(){
	cin>>cntCity>>cntRoad>>srcID>>destID;
	fill(G[0], G[0] + MAXV*MAXV, INF);

	for( int i=0; i<cntCity; i++ ){
		cin>>ownTeam[i];
	}

	int a, b;
	for( int i=0; i<cntRoad; i++ ){
		cin>>a>>b;
		cin>>G[a][b];
		G[b][a] = G[a][b];
	}
	
	Dijkstra();
	
	cout<<cntVWeight[destID]<<' '<<totalTeam[destID]<<'\n';
	
	return 0;
}