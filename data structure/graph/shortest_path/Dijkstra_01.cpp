#include <iostream>
#define INF 1000000
#define MAXVERTEX 10
using namespace std;

struct MatrixGraph{
	int cntVertex = 7;
	int edgeWeight[7][7] = {
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

int Dijkstra(MatrixGraph G){
	int weight[MAXVERTEX];
	int preVertex[MAXVERTEX];
	bool visitedVertex[MAXVERTEX];
	int i, j, k, srcID, destID, minWeight;
	int minID;
	
	// cin>>srcID;	// from 0 to MAXVERTEX-1
	srcID = 0;

	for( i=0; i<G.cntVertex; i++ ){
		weight[i] = G.edgeWeight[srcID][i];
		if( weight[i]<INF && weight[i]>0 ){
			preVertex[i] = srcID;
		}
		visitedVertex[i] = false;
	}
	
	visitedVertex[srcID] = true;
	weight[srcID] = 0;
	for( i=0; i<G.cntVertex; i++ ){
		minWeight = INF;
		minID = srcID;
		for( j=0; j<G.cntVertex; j++ ){
			if( visitedVertex[j]==false && weight[j]<minWeight ){
				minWeight = weight[j];
				minID = j;
			}
		}

		visitedVertex[minID] = true;

		for( j=0; j<G.cntVertex; j++ ){
			if( visitedVertex[j]==false ){
				int preVertexWeight = weight[minID];
				int pathWeight = G.edgeWeight[minID][j];
				int newWeight = preVertexWeight + pathWeight;
				int curVertexWeight = weight[j];

				if( newWeight < curVertexWeight ){
					weight[j] = newWeight;
					preVertex[j] = minID;	// minID is preVertex of j
				}
			}
		}
	}	
	cout<<"destID < srcID \n";
	// cin>>destID;
	destID = 5;     // 5 means F in that video
	cout<<srcID<<' '<<destID<<'\n';

	for( i=0; i<G.cntVertex; i++ ){
		int id = destID;
		while( id != srcID ){
			cout<<id<<" < ";
			id = preVertex[id];
		}
		cout<<srcID<<'\n';
	}
}

int main(){
	Dijkstra(G);
	return 0;
}