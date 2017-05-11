#include <iostream>
#include <algorithm>
#define MAX 1024
#define START 1
using namespace std;
typedef int Addr;

Addr n, ix=START;
int incNodeList[MAX] = {0};		// 1~n
int cbt[MAX] = {0};				// 1~n

int inOrderTraverse(Addr root){
	if( root > n ){
		return 0;
	}

	inOrderTraverse( root*2 );
	cbt[root] = incNodeList[ix++];
	inOrderTraverse( root*2 + 1 );
	return 0;
}

int main(){
	Addr i;
	cin>>n;

	for( i=1; i<=n; i++ ){
		cin>>incNodeList[i];
	}
	sort(incNodeList+1, incNodeList+1 + n );
	Addr root = 1;
	inOrderTraverse(root);

	cout<<cbt[1];
	for( i=2; i<=n; i++ ){
		cout<<' '<<cbt[i];
	}

	return 0;
}