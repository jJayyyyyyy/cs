#include <iostream>
#include <cctype>
#include <queue>
#define MAX 16
#define NONE -1
using namespace std;

struct Node{
	int lchild, rchild, parent;
	Node(){
		lchild = rchild = parent = NONE;
	}
};

Node node[MAX];
int isFirst = 1;

void invertTree(int root){
	if( NONE != root ){
		invertTree(node[root].lchild);
		invertTree(node[root].rchild);
		int tmp = node[root].lchild;
		node[root].lchild = node[root].rchild;
		node[root].rchild = tmp;
	}
}

void output(int parent){
	if( isFirst ){
		cout<<parent;
		isFirst = 0;
	}else{
		cout<<' '<<parent;
	}
}

void levelTraverse(int root){
	queue<int> q;
	q.push(root);

	while( q.size() ){
		int parent = q.front();
		output(parent);
		q.pop();
		if( NONE != node[parent].lchild ){
			q.push(node[parent].lchild);
		}
		if( NONE != node[parent].rchild ){
			q.push(node[parent].rchild);
		}
	}
}

void inOrderTraverse(int root){
	if( NONE != root ){
		inOrderTraverse(node[root].lchild);
		output(root);
		inOrderTraverse(node[root].rchild);
	}
}

int main(){
	int n, i;
	char left, right;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( isdigit(left) ){
			int lchild = left - '0';
			int parent = i;
			node[parent].lchild = lchild;
			node[lchild].parent = parent;
		}
		if( isdigit(right) ){
			int rchild = right - '0';
			int parent = i;
			node[parent].rchild = rchild;
			node[rchild].parent = parent;
		}
	}

	int root;
	for( i=0; i<n; i++ ){
		if( NONE == node[i].parent ){
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
