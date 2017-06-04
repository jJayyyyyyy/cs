#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	double sigma=0.0, num=0.0;
	int n, i, t;
	cin>>n;

	for( i=1; i<=n; i++ ){
		cin>>num;
		sigma += num * ( i + (n-i)*i );
		// sigma += num * i * (n-i+1);
	}

	cout.setf(ios::fixed);
	cout<<setprecision(2)<<sigma<<'\n';
	return 0;
}
