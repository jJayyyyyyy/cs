#include <iostream>
#include <algorithm>
#define MAX 1024
using namespace std;

int inputList[MAX] = {0};
int preList[MAX] = {0};
int mirrorPreList[MAX] = {0};
int iInput=0, iPre=0, iMirror=0;
int isFirst = 1;

struct Node{
	int val;
	Node *lchild, *rchild;
	Node(int _val){
		val = _val;
		lchild = rchild = NULL;
	}
};

int insertBST(Node * &parent, int val){
	if( NULL == parent ){
		parent = new Node(val);
		return 0;
	}

	if( val < parent->val ){
		insertBST(parent->lchild, val);
	}else{
		insertBST(parent->rchild, val);
	}
	return 0;
}

int preTraverse(Node * parent){
	if( NULL == parent ){
		return 0;
	}
	preList[iPre++] = parent->val;
	preTraverse(parent->lchild);
	preTraverse(parent->rchild);
	return 0;
}

int mirrorPreTraverse(Node * parent){
	if( NULL == parent ){
		return 0;
	}
	mirrorPreList[iMirror++] = parent->val;
	mirrorPreTraverse(parent->rchild);
	mirrorPreTraverse(parent->lchild);
	return 0;
}

int output(const int val){
	if( isFirst ){
		cout<<val;
		isFirst = 0;
	}else{
		cout<<' '<<val;
	}
	return 0;
}

int postTraverse(const Node * parent){
	if( NULL == parent ){
		return 0;
	}
	postTraverse(parent->lchild);
	postTraverse(parent->rchild);
	output(parent->val);
	return 0;
}

int mirrorPostTraverse(const Node * parent){
	if( NULL == parent ){
		return 0;
	}
	mirrorPostTraverse(parent->rchild);
	mirrorPostTraverse(parent->lchild);
	output(parent->val);
	return 0;
}

int cmp(const int a[], const int b[], const int len){
	for( int i=0; i<len; i++ ){
		if( a[i] != b[i] ){
			return 0;
		}
	}
	return 1;
}

int freeBST(Node * parent){
	if( NULL == parent ){
		return 0;
	}
	
	freeBST(parent->lchild);
	freeBST(parent->rchild);
	delete parent;
	return 0;
}

int main(){
	Node *root = NULL;
	int val, n, i;
	
	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>val;
		inputList[iInput++] = val;
		insertBST(root, val);
	}
	preTraverse(root);
	mirrorPreTraverse(root);
	if( 1 == cmp(inputList, preList, n) ){
		cout<<"YES\n";
		postTraverse(root);
	}else if( 1 == cmp(inputList, mirrorPreList, n) ){
		cout<<"YES\n";
		mirrorPostTraverse(root);
	}else{
		cout<<"NO\n";
	}
	
	freeBST(root);

	return 0;
}
