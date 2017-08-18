#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXSIZE 32
using namespace std;
/*
1---2---5	6---7
| \ |
|  \|
3	4

*/
vector<int> AG[MAXSIZE];
bool visited[MAXSIZE] = {false};

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
}

void BFS(int v){
	if( visited[v] == false ){
		queue<int> q;
		q.push(v);
		visited[v] = true;
		cout<<v<<' ';
		while( q.size() > 0 ){
			int u = q.front();
			q.pop();
			for( int i = 0; i < AG[u].size(); ++i ){
				int nextV = AG[u][i];
				if( visited[nextV] == false ){
					q.push(nextV);
					visited[nextV] = true;
					cout<<nextV<<' ';
				}
			}
		}
	}
}

void BFSTrav(int n){
	int cntBlock = 0;
	for( int v = 1; v <= n; ++v ){
		if( visited[v] == false ){
			BFS(v);
			++cntBlock;
		}
	}
	cout<<'\n'<<cntBlock<<'\n';
}

int main(){
	initAG();
	int n = 7;
	BFSTrav(7);
	return 0;
}