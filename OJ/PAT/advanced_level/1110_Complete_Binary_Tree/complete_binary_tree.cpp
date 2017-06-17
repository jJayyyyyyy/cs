#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#define MAX 32
#define NONE -1
#define EMPTY 0
#define FULL 1
using namespace std;
typedef int Addr;

class Node{
public:
	Addr lchild, rchild, parent;
	Node(){
		lchild = NONE;
		rchild = NONE;
		parent = NONE;
	}
};

Node nodeList[MAX];
vector<Addr> levelOrderList;
int isCBT=true, preLeaf=FULL;

int levelTraverse(Addr root){
	queue<Addr> q;
	q.push(root);

	while( q.size() ){
		Addr parent = q.front();
		levelOrderList.push_back(parent);
		q.pop();

		Addr lchild = nodeList[parent].lchild;
		Addr rchild = nodeList[parent].rchild;
		if( NONE != lchild ){
			q.push(lchild);
			if( EMPTY == preLeaf ){
				isCBT = false;
			}
		}else{
			preLeaf = EMPTY;
		}

		if( NONE != rchild ){
			q.push(rchild);
			if( EMPTY == preLeaf ){
				isCBT = false;
			}
		}else{
			preLeaf = EMPTY;
		}
	}
	return 0;
}

int str2num(string s){
	stringstream ss(s);
	int num;
	ss>>num;
	return num;
}

int main(){
	int n, i;
	string left, right;
	Addr lchild, rchild, parent;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( "-" != left ){
			lchild = str2num(left);
			parent = i;
			nodeList[parent].lchild = lchild;
			nodeList[lchild].parent = parent;
		}
		if( "-" != right ){
			rchild = str2num(right);
			parent = i;
			nodeList[parent].rchild = rchild;
			nodeList[rchild].parent = parent;
		}
	}

	Addr root;
	for( i=0; i<n; i++ ){
		if( NONE == nodeList[i].parent ){
			root = i;
			break;
		}
	}

	levelTraverse(root);
	if( isCBT ){
		cout<<"YES "<<levelOrderList[n - 1];
	}else{
		cout<<"NO "<<root;
	}
	
	return 0;
}

