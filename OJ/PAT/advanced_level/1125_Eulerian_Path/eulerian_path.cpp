#include <iostream>
#include <queue>
#define MAXSIZE 504
using namespace std;

bool G[MAXSIZE][MAXSIZE] = {false};
bool visit[MAXSIZE] = {false};

bool checkConn(int v, int n){
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while( q.size() > 0 ){
		int u = q.front();
		q.pop();
		for( int i = 1; i <= n; ++i ){
			if( visit[i] == false && G[u][i] != 0 ){
				q.push(i);
				visit[i] = true;
			}
		}
	}
	for( int i = 1; i <= n; ++i ){
		if( visit[i] == false ){
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
		G[v1][v2] = G[v2][v1] = true;
	}

	bool isConn = checkConn(1, n);	// 判断是否为连通图
	int cntOdd = 0, isFirst = 1;
	for( i = 1; i <= n; ++i ){
		int cnt = 0;
		for( j = 1; j <= n; ++j ){
			if( G[i][j] == true ){
				cnt++;
			}
		}
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