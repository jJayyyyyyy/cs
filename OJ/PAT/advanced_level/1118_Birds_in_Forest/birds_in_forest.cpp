#include <iostream>
#define MAXSIZE 10004
using namespace std;

bool marked[MAXSIZE] = {false};
int father[MAXSIZE];
int treeList[MAXSIZE] = {0};

void init(){
	for( int i = 0; i < MAXSIZE; ++i ){
		father[i] = i;
	}
}

int findFather(int x){
	while( x != father[x] ){
		x = father[x];
	}
	return x;
}

void Union(int a, int b){
	int fa1 = father[a];
	int fa2 = father[b];
	if( fa1 < fa2 ){
		father[fa2] = fa1;
	}else{
		father[fa1] = fa2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, k, rootID, id, cntTree=0, maxID=0, q, id1, id2;
	init();
	cin>>n;
	for( i = 0; i < n; ++i ){
		cin>>k;
		cin>>rootID;
		marked[rootID] = true;
		if( rootID > maxID ){
			maxID = rootID;
		}
		for( j = 1; j < k; ++j ){
			cin>>id;
			marked[id] = true;
			if( id > maxID ){
				maxID = id;
			}
			Union(rootID, id);
		}
	}	

	for( i = 0; i < MAXSIZE; ++i ){
		if( marked[i] == true ){
			rootID = findFather(i);
			treeList[rootID]++;
		}
	}

	for( i = 0; i < MAXSIZE; ++i ){
		if( treeList[i] > 0 ){
			++cntTree;
		}
	}

	cout<<cntTree<<' '<<maxID<<'\n';
	cin>>q;
	for( i = 0; i < q; ++i ){
		cin>>id1>>id2;
		if( findFather(id1) == findFather(id2) ){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}

	return 0;
}