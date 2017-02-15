#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;
int num[MAXSIZE]={0};

int cmp(int a, int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin>>n;

	for( i=1; i<=n; i++ ){
		cin>>num[i];
	}
	sort(&num[1], &num[n+1], cmp);

	int e=1;
	while(1){
		if( e<100000 && num[e]>e ){
			e *= 2;
		}else{
			e = e/2; 
			break;
		}
	}

	while(e<=100000){
		if( num[e]<=e ){
			break;
		}
		e++;
	}

	if(e==0)
		cout<<0;
	else
		cout<<e-1;

	return 0;
}