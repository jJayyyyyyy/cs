#include <iostream>
#define MAXSIZE 204
using namespace std;

int G[MAXSIZE][MAXSIZE] = {0};
int vList[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i, j, v1, v2, k, q;
	cin>>n>>m;
	for( i = 0; i < m; ++i ){
		cin>>v1>>v2;
		G[v1][v2] = G[v2][v1] = 1;
	}
	cin>>k;
	for( i = 0; i < k; ++i ){
		bool flag = true;
		cin>>q;
		for( j = 0; j < q; ++j ){
			cin>>vList[j];
			if( vList[j] == vList[0] && j > 0 && j < (q - 1) ){
				flag = false;
			}
		}
		if( j == (n + 1) && vList[0] == vList[q-1] && flag == true ){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}