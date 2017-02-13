#include <iostream>
#include <algorithm>
#define MAX 100004
using namespace std;

int num[MAX]={0}, ans[MAX]={0}, sorted[MAX]={0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, cnt=0, isFirst=1, leftMax=0;
	cin>>n;

	for(i=0; i<n; i++){
		cin>>num[i];
		sorted[i] = num[i];
	}

	sort(sorted, sorted+n);
	leftMax = 0;
	for( i=0; i<n; i++ ){
		if( num[i]==sorted[i] && num[i]>leftMax ){
			ans[cnt++] = num[i];
		}
		leftMax = max(leftMax, num[i]);
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
