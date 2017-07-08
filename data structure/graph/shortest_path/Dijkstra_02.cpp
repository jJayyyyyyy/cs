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
int preV[MAXV];
int VWeight[MAXV];
bool marked[MAXV];

int Dijkstra(){
	fill(marked, marked + MAXV, false);
	fill(VWeight, VWeight + MAXV, INF);
	VWeight[srcID] = 0;
	int midID = srcID;

	while( marked[destID] == false ){
		int minVWeight = INF;
		for( int i=0; i<cntV; i++ ){
			if( marked[i] == false ){
				if( VWeight[i] < minVWeight ){
					minVWeight = VWeight[i];
					midID = i;
				}
			}
		}
		marked[midID] = true;

		for( int i=0; i<cntV; i++ ){
			if( G[midID][i] != INF ){
				if( marked[i] == false ){
					if( VWeight[midID] + G[midID][i] < VWeight[i] ){
						VWeight[i] = VWeight[midID] + G[midID][i];
						preV[i] = midID;
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
		id = preV[id];
	}
	cout<<srcID<<'\n';
	cout<<VWeight[destID]<<'\n';
	// cout<<VWeight[5]<<'\n';
}

int main(){
	srcID = 0;		// 0 is vertex-A
	destID = 5;     // 5 is vertex-F
	// destID = 2;
	
	Dijkstra();
	output();
	
	return 0;
}