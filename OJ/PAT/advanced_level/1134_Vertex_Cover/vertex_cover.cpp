#include <iostream>
#include <algorithm>
#include <vector>
#define MAXSIZE 10004
using namespace std;

vector<int> edgeOfV[MAXSIZE];
bool visEdge[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, v1, v2;
	cin>>n>>m;
	for( int i = 0; i < m; ++i ){
		cin>>v1>>v2;
		edgeOfV[v1].push_back(i);	// 保存与节点v1相连的边
		edgeOfV[v2].push_back(i);
	}
	
	cin>>k;
	for( int query = 0; query < k; ++query ){
		// 初始化，使每条边的状态为未访问
		fill(visEdge, visEdge + m, false);
		bool isCover = true;
		int nv, vid, eid;

		cin>>nv;
		for( int i = 0; i < nv; ++i ){
			cin>>vid;
			for( auto eid : edgeOfV[vid] ){
				visEdge[eid] = true;
			}
		}

		for( int i = 0; i < m; ++i ){
			// 如果还存在没有没有被访问过的边，说明不能cover
			if( visEdge[i] == false ){
				isCover = false;
				break;
			}
		}

		if( isCover == true ){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}