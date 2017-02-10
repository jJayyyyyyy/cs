#include <iostream>
#include <algorithm>
#define	MAXSIZE	100008
using namespace std;

int cmp(long long a, long long b){
	return a<b;
}

int main(){
	int i=0, j=0, ans;
	long long n=0, p=0, mp, num[MAXSIZE]={0};
	cin>>n>>p;

	for( i=0; i<n; i++ )
		cin>>num[i];
	sort(&num[0], &num[n], cmp);

	ans = 1;
	for( i=0; i<n; i++ ){
		mp = num[i]*p;
		j = upper_bound(&num[i+1], &num[n], mp) - &num[0];
		ans = max(ans, j-i);
	}
	cout<<ans<<'\n';

	return 0;
}
