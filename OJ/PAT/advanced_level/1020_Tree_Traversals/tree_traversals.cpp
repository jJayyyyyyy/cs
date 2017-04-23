#include <iostream>
#include <queue>
#define MAX 32
using namespace std;

int postList[MAX]={0};
int inList[MAX]={0};
int isFirst = 1;

struct Node{
	Node *lchild, *rchild;
	int val, height;
	Node(int _val){
		val = _val;
		height = 1;
		lchild = rchild = NULL;
	}
};

int insertTree(Node * &parent, int postLeft, int postRight, int inLeft, int inRight){
	if( postLeft > postRight ){
		return 0;
	}

	int parentIndex = postRight;
	int parentValue = postList[parentIndex];
	parent = new Node(parentValue);

	int mid;
	for( mid=inLeft; mid<=inRight; mid++ ){
		if( inList[mid] == parentValue ){
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
	return 0;
}

int output(int val){
	if( isFirst ){
		isFirst = 0;
		cout<<val;
	}else{
		cout<<' '<<val;
	}
	return 0;
}

int levelTraverse(Node * root){
	queue<Node *> q;
	q.push(root);

	while( q.size() ){
		Node * parent = q.front();
		output(parent->val);
		q.pop();
		if( NULL != parent->lchild ){
			q.push(parent->lchild);
		}
		if( NULL != parent->rchild ){
			q.push(parent->rchild);
		}
	}
	return 0;
}

int freeTree(Node *parent){
	if( NULL == parent ){
		return 0;
	}
	freeTree(parent->lchild);
	freeTree(parent->rchild);
	delete parent;
	return 0;
}

int main(){
	int n, i;
	cin>>n;

	for( i=0; i<n; i++ ){
		cin>>postList[i];
	}
	for( i=0; i<n; i++ ){
		cin>>inList[i];
	}
	Node *root = NULL;
	insertTree(root, 0, n-1, 0, n-1);
	levelTraverse(root);
	freeTree(root);

	return 0;
}