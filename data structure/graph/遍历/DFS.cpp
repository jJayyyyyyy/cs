#include <iostream>
#include <vector>
#include <algorithm>
#define MAXSIZE 32
using namespace std;
vector<int> AG[MAXSIZE];
int MG[MAXSIZE][MAXSIZE] = {0};
bool visited[MAXSIZE] = {false};

/*

1---2---5	6---7
| \ |
|  \|
3	4

*/

void initAG();
void initMG();

/* DFS Adj-List Graph */
void DFS(int v){
	visited[v] = true;
	cout<<v<<' ';
	// 每个节点的度相当于.size()
	for( int i = 0; i < AG[v].size(); ++i ){
		// 在AG[v] 里面的都是v的邻居
		int nextV = AG[v][i];
		if( visited[nextV] == false ){
			DFS(nextV);
		}
	}
}

/* DFS Matrix Graph */
void DFS(int v, int n){
	visited[v] = true;
	cout<<v<<' ';
	// 每次都需要遍历 [1, n]
	for( int nextV = 1; nextV <= n; ++nextV ){
		if( visited[nextV] == false){
			// MG[v][nextV] != 0表示nextV是v的邻居
			if( MG[v][nextV] != 0 ){
				DFS(nextV, n);
			}
		}
	}
}

void DFSTrav(int n, int type){
	int cntBlock = 0;
	// n个节点从1到n连续编号, [1, n]
	for(int v = 1; v <= n; ++v ){
		if( visited[v] == false ){		// 如果该节点未被访问过，那就开始一趟新的DFS，搜完后区块++
			if( type == 1 ){
				DFS(v);	// DFS推荐使用邻接表，简单一点
			}else{
				DFS(v, n);	// 邻接矩阵，需要知道总的节点数
			}
			++cntBlock;
		}
	}
	cout<<'\n'<<cntBlock<<'\n';
}

int main(){
	int n = 7;
	initAG();
	DFSTrav(n, 1);
	
	initMG();
	DFSTrav(n, 2);
	return 0;
}

// 邻接链表
void initAG(){
	AG[1].push_back(2);
	AG[2].push_back(1);
	AG[1].push_back(3);
	AG[3].push_back(1);
	AG[1].push_back(4);
	AG[4].push_back(1);
	AG[2].push_back(4);
	AG[4].push_back(2);
	AG[2].push_back(5);
	AG[5].push_back(2);

	AG[6].push_back(7);
	AG[7].push_back(6);
	fill(visited, visited + MAXSIZE, false);
}

void initMG(){
	MG[1][2] = MG[2][1] = 1;
	MG[1][3] = MG[3][1] = 1;
	MG[1][4] = MG[4][1] = 1;
	MG[2][4] = MG[4][2] = 1;
	MG[2][5] = MG[5][2] = 1;

	MG[6][7] = MG[7][6] = 1;
	fill(visited, visited + MAXSIZE, false);
}

