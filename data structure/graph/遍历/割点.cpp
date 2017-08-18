/* 2018王道，P229思维拓展，割点
 * （假设原图是连通图）
 * 思路1即按定义，去掉假定割点keyV及其边，若图不连通，则keyV就是割点
 * 思路2与PAT_A_1013类似，去掉假定割点后，统计连通分量，cntBlock>1 说明keyV就是割点
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXSIZE 32
using namespace std;
vector<int> AG[MAXSIZE];
bool visited[MAXSIZE] = {false};

/*
1---2---4---5---6
  \ |
   \|
	3

该图中，2, 4, 5 是割点（去掉该节点及其相连的边后，无向图不再连通
*/

void initAG();

/* DFS Adj-List Graph */
void DFS(int v, int keyV){
	visited[v] = true;
	for( int i = 0; i < AG[v].size(); ++i ){
		int nextV = AG[v][i];
		if( nextV != keyV && visited[nextV] == false ){
			DFS(nextV, keyV);
		}
	}
}

// 从1或2开始遍历全图(不包括假定割点)，若存在未标记节点，则输出假定割点
void DFSTrav1(int n){
	for( int keyV = 1; keyV <= n; ++keyV ){
		fill(visited, visited + MAXSIZE, false);
		if( keyV == 1 ){
			DFS(2, keyV);
		}else{
			DFS(1, keyV);
		}

		for( int v = 1; v <= n; ++v ){
			if( v!=keyV && visited[v] == false ){
				cout<<keyV<<'\n';
				break;
			}
		}
	}
}

// 统计连通分量
void DFSTrav2(int n){
	for( int keyV = 1; keyV <= n; ++keyV ){
		fill(visited, visited + MAXSIZE, false);
		int cntBlock = 0;
		for( int v = 1; v <= n; ++v ){
			if( v != keyV && visited[v] == false ){
				DFS(v, keyV);
				++cntBlock;
			}
		}
		if( cntBlock > 1 ){
			cout<<keyV<<'\n';
		}
	}
}

int main(){
	int n = 6;
	initAG();
	DFSTrav2(n);
	return 0;
}

// 邻接链表
void initAG(){
	AG[1].push_back(2);
	AG[1].push_back(3);

	AG[2].push_back(1);
	AG[2].push_back(3);
	AG[2].push_back(4);

	AG[3].push_back(1);
	AG[3].push_back(2);
	
	AG[4].push_back(2);
	AG[4].push_back(5);
	
	AG[5].push_back(4);
	AG[5].push_back(6);
	
	AG[6].push_back(5);
	fill(visited, visited + MAXSIZE, false);
}
