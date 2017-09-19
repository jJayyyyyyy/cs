#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int level;
	vector<int> children;
	Node(){
		level = 0;
	}
};

Node node[MAXSIZE];
int minLevel=MAXSIZE, minCnt=1;

void updateLevel(int root){
	for( auto childID : node[root].children  ){
		node[childID].level = node[root].level + 1;
		updateLevel(childID);
	}
}

void getMinLevel(int root){
	if( 0 == node[root].children.size() ){
		int level = node[root].level;
		if( level < minLevel ){
			minLevel = level;
			minCnt = 1;
		}else if( level == minLevel ){
			++minCnt;
		}
	}else{
		for( auto childID : node[root].children ){
			getMinLevel(childID);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, id;
	double price, rate;
	cin>>n>>price>>rate;
	for( int i = 0; i < n; ++i ){
		cin>>k;
		for( int j = 0; j < k; ++j ){
			cin>>id;
			node[i].children.push_back(id);
		}
	}
	
	updateLevel(0);
	getMinLevel(0);
	double lowRate = pow(1.0 + rate/100.0, minLevel);
	double lowPrice = price * lowRate;
	cout.setf(ios::fixed);
	cout<<setprecision(4)<<lowPrice<<' '<<minCnt<<'\n';
	return 0;
}