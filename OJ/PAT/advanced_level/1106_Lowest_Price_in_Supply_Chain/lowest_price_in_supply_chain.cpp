#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define uint unsigned int
#define MAXSIZE 100004
using namespace std;

struct Node
{
	int level;
	vector<int> children;
	Node()
	{
		level = 0;
	}
};

Node nodeList[MAXSIZE];
int minLevel = MAXSIZE;
int minCnt = 1;

int updateLevel(int iParent){
	vector<int> children = nodeList[iParent].children;
	for( uint i=0; i<children.size(); i++ ){
		int iChild = children[i];
		nodeList[iChild].level = nodeList[iParent].level + 1;
		updateLevel(iChild);
	}
	return 0;
}

int updateMinLevel(int iParent){
	vector<int> children = nodeList[iParent].children;

	if( 0 == children.size() ){
		int level = nodeList[iParent].level;
		if( level < minLevel ){
			minLevel = level;
			minCnt = 1;
		}
		else if( level == minLevel ){
			minCnt++;
		}
	}else{
		for( uint i=0; i<children.size(); i++ ){
			int iChild = children[i];
			updateMinLevel(iChild);
		}
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, k, child;
	double price, lowPrice, rate, lowRate;

	cin>>n>>price>>rate;
	for( i=0; i<n; i++ ){
		cin>>k;
		for( j=0; j<k; j++ ){
			cin>>child;
			if( 0 != child ){
				nodeList[i].children.push_back(child);
			}
		}
	}
	updateLevel(0);
	updateMinLevel(0);

	lowRate = pow(1.0+rate/100.0, minLevel);
	lowPrice = price * lowRate;

	cout.setf(ios::fixed);
	cout<<setprecision(4)<<lowPrice<<' '<<minCnt<<'\n';

	return 0;
}
