#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
	Node(int _val){
		val = _val;
		lchild = rchild = NULL;
	}
	void get(){
		cout<<val<<' ';
	}
};

bool isEmpty(Node * root){
	if( root == NULL)
		return true;
	else
		return false;
}

int getHeight(Node * root){
	if( root == NULL ){
		return 0;
	}
	int lHeight = getHeight(root->lchild);
	int rHeight = getHeight(root->rchild);
	return max(lHeight, rHeight) + 1;
}

void insert(Node * &root, int val){
	if( root == NULL ){
		root = new Node(val);
		return;
	}
	if( val < root->val ){
		insert(root->lchild, val);
	}else{
		insert(root->rchild, val);
	}
}

int inOrder(Node * root){
	if( root != NULL ){
		inOrder(root->lchild);
		root->get();
		inOrder(root->rchild);
	}
}

// LRD后序删除与释放
void delTree(Node * root){
	if( root != NULL ){
		delTree(root->lchild);
		delTree(root->rchild);
		delete root;
	}
}

int main(){
	Node * root = NULL;
	int n = 5;
	int a[5] = {3, 1, 2, 4, 5};
	for( int i = 0; i < n; ++i ){
		insert(root, a[i]);
	}

	if( isEmpty(root) == false ){
		cout<<getHeight(root)<<'\n';
		inOrder(root);
		cout<<'\n';
		delTree(root);
	}
	return 0;
}
