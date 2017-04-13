#include <iostream>
#include <queue>
#define MAX 32
using namespace std;

int postOrder[MAX], inOrder[MAX];
int isFirst = 1;

class Node{
public:
	Node *lchild;
	Node *rchild;
	int value;
	Node(int _value){
		value = _value;
		lchild = NULL;
		rchild = NULL;
	}
};

Node *insert(int postLeft, int postRight, int inLeft, int inRight){
	if( postLeft > postRight ){
		return NULL;
	}
	int parentIndex = postRight;
	int parentValue = postOrder[parentIndex];
	Node *parent = new Node(parentValue);

	int mid;
	for( mid=inLeft; mid<=inRight; mid++ ){
		if( inOrder[mid]==parentValue ){
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

	parent->lchild = insert(postLeftTreeStart, postLeftTreeEnd, inLeftTreeStart, inLeftTreeEnd);
	parent->rchild = insert(postRightTreeStart, postRightTreeEnd, inRightTreeStart, inRightTreeEnd);
	return parent;
}

int output(int value){
	if(isFirst){
		cout<<value;
		isFirst = 0;
	}else{
		cout<<' '<<value;
	}

	return 0;
}

int levelTraverse(Node *root){
	queue<Node*> q;
	q.push( root );
	while( q.size() ){
		Node *parent = q.front();
		q.pop();
		output(parent->value);
		if( NULL != parent->lchild ){
			q.push( parent->lchild );
		}
		if( NULL != parent->rchild ){
			q.push( parent->rchild );
		}
	}
	return 0;
}

int freeTree(Node *root){
	if( NULL == root ){
		return 0;
	}
	freeTree(root->lchild);
	freeTree(root->rchild);
	delete root;
	return 0;
}

int main(){
	int n, i;
	cin>>n;

	for( i=0; i<n; i++ ){
		cin>>postOrder[i];
	}
	for( i=0; i<n; i++ ){
		cin>>inOrder[i];
	}
	Node *root = insert( 0, n-1, 0, n-1 );
	levelTraverse(root);
	freeTree(root);

	return 0;
}
