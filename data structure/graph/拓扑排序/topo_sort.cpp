#include <iostream>
#include <vector>
#include <queue>
#define MAXSIZE 40
using namespace std;

vector<int> G[MAXSIZE];		// 邻接链表
int n, inDegree[MAXSIZE];	// 顶点数，每个顶点的入度

bool topoSort(){
	int cnt = 0;			// 记录加入拓扑序列的顶点数量
	queue<int> q;
	for( int i = 0; i < n; ++i ){
		if( inDegree[i] == 0 ){
			q.push(i);		// 将所有入度为0的顶点入队
		}
	}

	while( q.size() ){
		int v = q.front();
		// cout<<v<<' ';	// visit v
		q.pop();
		for( const auto & node : G[v] ){
			int nextV = node;
			inDegree[nextV]--;
			if( inDegree[nextV] == 0 ){
				q.push(nextV);
			}
		}
		G[v].clear();
		cnt++;
	}
	if( cnt == n ){
		return true;		// 拓扑序列大小等于所有顶点数，说明拓扑排序成功
	}else{
		return false;		// 否则失败，要么有环，要么不连同
	}
}

int main(){

	return 0;
}