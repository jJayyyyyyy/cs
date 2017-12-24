#include <iostream>
#include <stack>
#define MAXSIZE 50001
using namespace std;

struct Node{
	int val=0;
	Node *lchild=NULL, *rchild=NULL;
	Node(int _val){
		val = _val;
	}
};

int pre[MAXSIZE], in[MAXSIZE], isFirst=1;

// 1086, 先序+中序，造树
Node * preInCreate(int preL, int preR, int inL, int inR){
	if( preL > preR ){
		return NULL;
	}
	int val = pre[preL];
	Node * root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; ++mid ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	root->lchild = preInCreate(preL+1, preL+numLeft, inL, mid-1);
	root->rchild = preInCreate(preL+numLeft+1, preR, mid+1, inR);
	return root;
}

void disp(Node * p){
	if( isFirst ){
		isFirst = 0;
		cout<<p->val<<'\n';
	}
}

void postTraverse(Node * root){
	if( root != NULL && isFirst == 1 ){
		postTraverse(root->lchild);
		postTraverse(root->rchild);
		disp(root);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	
	cin>>n;
	for( i = 0; i < n; i++ ){
		cin>>pre[i];
	}
	for( i = 0; i < n; i++ ){
		cin>>in[i];
	}
	
	Node * root = NULL;
	root = preInCreate(0, n-1, 0, n-1);
	postTraverse(root);
	return 0;
}