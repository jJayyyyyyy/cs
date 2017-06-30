#include <iostream>
#include <queue>
#define MAXVERTEX 32
#define UNDIGRAPH 0
#define DIGRAPH 1
#define EMPTY 1000000
using namespace std;

struct matrixGraph{
	char vertexList[MAXVERTEX];
	int edgeWeight[MAXVERTEX][MAXVERTEX];
	int isTraved[MAXVERTEX];
	int numVertex;
	int numEdge;
	int type;
};

int setMatrixGraph(matrixGraph & graph);
int resetMatrixGraph(matrixGraph & graph);
int putMatrixGraph(matrixGraph & graph);
int BFSTraverse(matrixGraph & graph);

int main(){
	matrixGraph graph;
	int i, j;
	cin>>graph.type;
	cin>>graph.numVertex>>graph.numEdge;
	resetMatrixGraph(graph);
	setMatrixGraph(graph);
	putMatrixGraph(graph);
	BFSTraverse(graph);

	return 0;
}

int setMatrixGraph(matrixGraph & graph){
	int i, j, k, weight;
	char node1, node2;
	// get vertexList
	for(i=0; i<graph.numVertex; i++ ){
		cin>>graph.vertexList[i];
	}

	// get edgeWeight between vertex1 and vertex2
	for(k=0; k<graph.numEdge; k++){
		cin>>node1>>node2>>weight;
		for(i=0; node1!=graph.vertexList[i]; i++);
		for(j=0; node2!=graph.vertexList[j]; j++);
		graph.edgeWeight[i][j] = weight;
		if( graph.type == UNDIGRAPH ){
			graph.edgeWeight[j][i] = weight;
		}
	}
	return 0;
}

int resetMatrixGraph(matrixGraph & graph){
	int i, j;
	for(i=0; i<graph.numVertex; i++){
		graph.isTraved[i] = 0;
		for(j=0; j<graph.numVertex; j++){
			graph.edgeWeight[i][j] = EMPTY;
		}
	}
	return 0;
}

int putMatrixGraph(matrixGraph & graph){
	int i, j;
	cout<<"The graph will be printed below:\n";
	// cout<<"All vertexes:\n";
	for(i=0; i<graph.numVertex; i++){
		cout<<'\t'<<graph.vertexList[i];
	}
	cout<<'\n';

	for(i=0; i<graph.numVertex; i++){
		cout<<graph.vertexList[i];
		for(j=0; j<graph.numVertex; j++){
			if( graph.edgeWeight[i][j] == EMPTY ){
				cout<<"\tInf";
			}else{
				cout<<'\t'<<graph.edgeWeight[i][j];
			}
		}
		cout<<'\n';
	}
	return 0;
}

int BFSTraverse(matrixGraph & graph){
	queue<int> q;
	int i=0, j=0;
	q.push(0);
	graph.isTraved[0] = 1;

	while( q.size() ){
		i = q.front();
		cout<<graph.vertexList[i]<<"->";
		q.pop();

		for(j=0; j<graph.numVertex; j++){
			if( graph.isTraved[j] == 0 ){
				if( graph.edgeWeight[i][j] != EMPTY ){
					q.push(j);
					graph.isTraved[j] = 1;
				}
			}
		}
	}
	cout<<"\ndone!\n";

	return 0;
}

/*
0
5 6
1
2
3
4
5
1 2 2
1 3 5
1 5 3
2 4 4
3 5 5
3 5 2


*/