#include <iostream>
#include <cctype>
#include <queue>
#define MAX 16
#define NONE -1
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
int isFirst = 1;

int invertTree(Addr root){
	if( NONE == root ){
		return 0;
	}

	invertTree(nodeList[root].lchild);
	invertTree(nodeList[root].rchild);
	Addr tmpLeft = nodeList[root].lchild;
	nodeList[root].lchild = nodeList[root].rchild;
	nodeList[root].rchild = tmpLeft;
	return 0;
}

int output(Addr parent){
	if( isFirst ){
		cout<<parent;
		isFirst = 0;
	}else{
		cout<<' '<<parent;
	}
	return 0;
}

int levelTraverse(Addr root){
	queue<Addr> q;
	q.push(root);

	while( q.size() ){
		Addr parent = q.front();
		output(parent);
		q.pop();
		if( NONE != nodeList[parent].lchild ){
			q.push(nodeList[parent].lchild);
		}
		if( NONE != nodeList[parent].rchild ){
			q.push(nodeList[parent].rchild);
		}
	}

	return 0;
}

int inOrderTraverse(Addr root){
	if( NONE == root ){
		return 0;
	}
	
	inOrderTraverse(nodeList[root].lchild);
	output(root);
	inOrderTraverse(nodeList[root].rchild);
	return 0;
}

int main(){
	int n, i;
	char left, right;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( isdigit(left) ){
			Addr lchild = left - '0';
			Addr parent = i;
			nodeList[parent].lchild = lchild;
			nodeList[lchild].parent = parent;
		}
		if( isdigit(right) ){
			Addr rchild = right - '0';
			Addr parent = i;
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

	invertTree(root);
	isFirst = 1;
	levelTraverse(root);
	cout<<'\n';
	isFirst = 1;
	inOrderTraverse(root);

	return 0;
}

