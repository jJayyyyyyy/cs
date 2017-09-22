#include <iostream>
#include <vector>
#include <queue>
#define MAXSIZE 504
using namespace std;

bool vis[MAXSIZE] = {false};
vector<int> G[MAXSIZE];

void BFS(int v){
	queue<int> q;
	q.push(v);
	vis[v] = true;
	while( q.size() ){
		int nowV = q.front();
		q.pop();
		for( int i = 0; i < G[nowV].size(); ++i ){
			int nextV = G[nowV][i];
			if( vis[i] == false ){
				q.push(nextV);
				vis[nextV] = true;
			}
		}
	}
}

void DFS(int v){
	vis[v] = true;
	for(int i = 0; i < G[v].size(); ++i ){
		int nextV = G[v][i];
		if( vis[nextV] == false ){
			DFS(nextV);
		}
	}
}

bool checkConn(int n){
	int block = 0;
	for( int i = 1; i <= n; ++i ){
		if( vis[i] == false ){
			DFS(1);
			++block;
		}
	}
	return (1 == block);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, v1, v2;
	cin>>n>>m;
	for( int i = 0; i < m; ++i ){
		cin>>v1>>v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}

	bool isConn = checkConn(n);
	int cntOdd = 0, isFirst = 1;
	for( int i = 1; i <= n; ++i ){
		int degree = G[i].size();
		if( degree % 2 == 1 ){
			++cntOdd;
		}

		if( isFirst ){
			cout<<degree;
			isFirst = 0;
		}else{
			cout<<' '<<degree;
		}
	}
	if( cntOdd == 0 && isConn == true ){
		cout<<"\nEulerian\n";
	}else if( cntOdd == 2 && isConn == true ){
		cout<<"\nSemi-Eulerian\n";
	}else{
		cout<<"\nNon-Eulerian\n";
	}
	return 0;
}