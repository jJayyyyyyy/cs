#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#define MAX 100004
using namespace std;

struct Node{
	int parent;
	int level;
	vector<int> children;
	Node(){
		parent = level = 0;
	}
};

Node node[MAX];
int maxLevel=0, maxCnt=1;

int updateLevel(int root){
	vector<int> children = node[root].children;
	for(int i=0; i<children.size(); i++){
		int iChild = children[i];
		int iParent = node[iChild].parent;
		node[iChild].level = node[iParent].level + 1;
	
		if( maxLevel < node[iChild].level ){
			maxLevel = node[iChild].level;
			maxCnt = 1;
		}else if( maxLevel == node[iChild].level ){
			maxCnt++;
		}

		updateLevel(iChild);
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, i, iParent, iChild, iRoot;
	double price, rate, hPrice, hRate;
	cin>>n>>price>>rate;

	for( i=0; i<n; i++ ){
		cin>>iParent;
		if( iParent == -1 ){
			iRoot = i;
		}else{
			iChild = i;
			node[iParent].children.push_back(iChild);
			node[iChild].parent = iParent;
		}
	}

	updateLevel(iRoot);
	hRate = pow(1.0+rate/100.00, maxLevel);
	hPrice = price * hRate;

	cout.setf(ios::fixed);
	cout<<setprecision(2)<<hPrice<<' '<<maxCnt<<'\n';
	return 0;
}
