#include <iostream>
#include <queue>
#include <vector>
#define MAXSIZE 504
using namespace std;

vector<int> G[MAXSIZE];
bool visited[MAXSIZE] = {false};

void BFS(int v){
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while( q.size() > 0 ){
		int now = q.front();
		q.pop();
		for( int i = 0; i < G[now].size(); ++i ){
			int nextV = G[now][i];
			if( visited[nextV] == false ){
				q.push(nextV);
				visited[nextV] = true;
			}
		}
	}
}

void DFS(int v){
	visited[v] = true;
	for( int i = 0; i < G[v].size(); ++i ){
		int nextV = G[v][i];
		if( visited[nextV] == false ){
			DFS(nextV);
		}
	}
}

bool checkConn(int n){
	// BFS(1);
	DFS(1);
	for( int i = 1; i <= n; ++i ){
		if( visited[i] == false ){
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i, j, v1, v2;
	cin>>n>>m;
	for( i = 0; i < m; ++i ){
		cin>>v1>>v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}

	bool isConn = checkConn(n);	// 判断是否为连通图
	int cntOdd = 0, isFirst = 1;
	for( i = 1; i <= n; ++i ){
		int cnt = G[i].size();
		if( isFirst ){
			cout<<cnt;
			isFirst = 0;
		}else{
			cout<<' '<<cnt;
		}
		if( cnt % 2 == 1 ){
			cntOdd++;
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