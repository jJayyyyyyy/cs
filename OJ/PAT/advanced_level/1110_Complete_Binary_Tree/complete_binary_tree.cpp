#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#define MAX 32
#define NONE -1
using namespace std;

struct Node{
	int lchild, rchild, parent;
	Node(){
		lchild = rchild = parent = NONE;
	}
};

Node node[MAX];
vector<int> levelOrderList;

int isCBTLevelTrav(int root){
	if( root != NONE ){
		queue<int> q;
		q.push(root);
		while( q.size() ){
			int parent = q.front();
			levelOrderList.push_back(parent);
			q.pop();
			if( parent != NONE ){
				q.push(node[parent].lchild);
				q.push(node[parent].rchild);
			}else{
				while( q.size() ){
					int p = q.front();
					q.pop();
					if( p != NONE ){
						return 0;
					}
				}
			}
		}
	}
	return 1;
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
	int lchild, rchild, parent, root;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( "-" != left ){
			lchild = str2num(left);
			parent = i;
			node[parent].lchild = lchild;
			node[lchild].parent = parent;
		}
		if( "-" != right ){
			rchild = str2num(right);
			parent = i;
			node[parent].rchild = rchild;
			node[rchild].parent = parent;
		}
	}

	for( i=0; i<n; i++ ){
		if( NONE == node[i].parent ){
			root = i;
			break;
		}
	}

	int isCBT = isCBTLevelTrav(root);
	if( isCBT ){
		cout<<"YES "<<levelOrderList[n - 1];
	}else{
		cout<<"NO "<<root;
	}
	return 0;
}
