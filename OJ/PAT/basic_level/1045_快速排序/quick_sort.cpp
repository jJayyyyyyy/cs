#include <iostream>
#include <algorithm>
#define MAX 100004
using namespace std;

int originList[MAX]={0}, ans[MAX]={0}, sorted[MAX]={0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, cnt=0, isFirst=1, maxOfLeft=0;
	cin>>n;

	for(i=0; i<n; i++){
		cin>>originList[i];
		sorted[i] = originList[i];
	}

	sort(sorted, sorted+n);
	maxOfLeft = 0;
	for( i=0; i<n; i++ ){
		if( originList[i]==sorted[i] && originList[i]>maxOfLeft ){
			ans[cnt++] = originList[i];
		}
		maxOfLeft = max(maxOfLeft, originList[i]);
	}

	cout<<cnt<<'\n';
	for( i=0; i<cnt; i++ ){
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
