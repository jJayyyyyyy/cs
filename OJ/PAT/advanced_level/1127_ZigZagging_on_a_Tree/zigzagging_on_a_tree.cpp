#include <iostream>
#include <queue>
#include <string>
#include <stack>
#define MAX 32
using namespace std;

struct Node{
	Node *lchild, *rchild;
	int val, level;
	Node(int _val){
		val = _val;
		level = 1;
		lchild = rchild = NULL;
	}
};

int postList[MAX]={0}, inList[MAX]={0};
int n, ix=0;
Node * outList[MAX];
stack<int> st;

int r_output(){
	while( st.size() ){
		cout<<' '<<st.top();
		st.pop();
	}
	return 0;
}

int output(){
	cout<<outList[0]->val;

	for( int i=0; i<n; i++ ){
		if( outList[i]->level % 2 == 0 ){
			r_output();
			cout<<' '<<outList[i]->val;
		}else{
			st.push(outList[i]->val);
		}
	}
	r_output();
	return 0;
}

int levelTraverse(Node * root){
	queue<Node *> q;
	q.push(root);

	while( q.size() ){
		Node * parent = q.front();
		outList[ix++] = parent;
		q.pop();
		if( NULL != parent->lchild ){
			parent->lchild->level = parent->level + 1;
			q.push(parent->lchild);
		}
		if( NULL != parent->rchild ){
			parent->rchild->level = parent->level + 1;
			q.push(parent->rchild);
		}
	}
	output();
	return 0;
}

int insertTree(Node * &parent, int postLeft, int postRight, int inLeft, int inRight){
	if( postLeft > postRight ){
		return 0;
	}

	parent = new Node(postList[postRight]);
	int mid;
	for( mid=inLeft; mid<=inRight; mid++ ){
		if( inList[mid] == postList[postRight] ){
			break;
		}
	}
	int cntLeftTree = mid - inLeft;

	int postLeftTreeStart = postLeft;
	int postLeftTreeEnd = postLeft + cntLeftTree - 1;
	int postRightTreeStart = postLeft + cntLeftTree;
	int postRightTreeEnd = postRight - 1;

	int inLeftTreeStart = inLeft;
	int inLeftTreeEnd = mid - 1;
	int inRightTreeStart = mid + 1;
	int inRightTreeEnd = inRight;

	insertTree(parent->lchild, postLeftTreeStart, postLeftTreeEnd, inLeftTreeStart, inLeftTreeEnd);
	insertTree(parent->rchild, postRightTreeStart, postRightTreeEnd, inRightTreeStart, inRightTreeEnd);
	// updateHeight(parent);
	return 0;
}

int freeTree(Node * root){
	if( NULL == root ){
		return 0;
	}
	freeTree(root->lchild);
	freeTree(root->rchild);
	delete root;
	return 0;
}

int main(){
	int i;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>inList[i];
	}
	for( i=0; i<n; i++ ){
		cin>>postList[i];
	}
	Node * root = NULL;
	insertTree(root, 0, n-1, 0, n-1);
	levelTraverse(root);
	freeTree(root);
	return 0;
}