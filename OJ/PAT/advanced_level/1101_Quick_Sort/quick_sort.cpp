#include <iostream>
#include <algorithm>
#define MAX 100004
// #define MAX 104
using namespace std;
int input[MAX], ordered[MAX], ans[MAX];

int main(){
	int n, i, isFirst=1, cntAns=0;
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>input[i];
		ordered[i] = input[i];
	}

	sort( ordered, ordered + n );

	int maxOfLeft=0;
	for( i=0; i<n; i++ ){
		if( input[i]==ordered[i] && input[i]>maxOfLeft ){
			ans[cntAns++] = input[i];
		}
		maxOfLeft = max( input[i], maxOfLeft );
	}

	cout<<cntAns<<'\n';
	for( i=0; i<cntAns; i++ ){
		if(isFirst){
			cout<<ans[i];
			isFirst = 0;
		}else{
			cout<<' '<<ans[i];
		}
	}

	cout<<'\n';
	return 0;
}
