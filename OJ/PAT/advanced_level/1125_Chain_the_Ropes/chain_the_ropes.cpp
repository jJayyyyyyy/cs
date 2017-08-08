#include <iostream>
#include <algorithm>
#define MAXSIZE 10004
using namespace std;

int rope[MAXSIZE] = {0};

int main(){
	int n, i;
	cin>>n;
	for( i = 0; i < n; ++i ){
		cin>>rope[i];
	}
	sort( rope, rope + n);

	int len = rope[0];
	for( i = 1; i < n; ++i ){
		len = (len  + rope[i]) / 2;
	}

	cout<<len<<'\n';

	return 0;
}
