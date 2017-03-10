#include <iostream>
#include <queue>
#define MAX 32
using namespace std;

int postOrder[MAX], inOrder[MAX];
int n, isFirst=1;

struct Node{
	Node *lchild;
	Node *rchild;
	int value;
	Node(int v){
		lchild = NULL;
		rchild = NULL;
		value = v;
	}
};

Node *insert(int pLeft, int pRight, int inLeft, int inRight){
	if( pLeft>pRight )
		return NULL;

	int parentIndex = pRight;
	int parentValue = postOrder[parentIndex];
	Node *parent = new Node(parentValue);

	int mid;
	for( mid=inLeft; mid<inRight; mid++ ){
		if( parentValue==inOrder[mid] ){
			break;
		}
	}

	int cntLeft = mid - inLeft;
	int pSubRight = pLeft + cntLeft - 1;
	int pSubLeft = pLeft + cntLeft;
	int inSubRight = mid - 1;
	int inSubLeft = mid + 1;

	parent->lchild = insert( pLeft, pSubRight, inLeft, inSubRight );
	parent->rchild = insert( pSubLeft, pRight-1, inSubLeft, inRight );
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
	q.push(root);

	while( q.size() ){
		Node *parent = q.front();
		output(parent->value);
		q.pop();
		if( NULL!=parent->lchild )
			q.push(parent->lchild);
		if( NULL!=parent->rchild )
			q.push(parent->rchild);
	}
	return 0;
}

int freeTree(Node *root){
	if(root==NULL)
		return 0;
	freeTree(root->lchild);
	freeTree(root->rchild);
	delete root;
	return 0;
}

int main(){
	cin>>n;
	int i;
	for( i=0; i<n; i++ ){
		cin>>postOrder[i];
	}
	for( i=0; i<n; i++ ){
		cin>>inOrder[i];
	}

	Node *root = insert(0, n-1, 0, n-1);
	levelTraverse(root);
	freeTree(root);
	return 0;
}
