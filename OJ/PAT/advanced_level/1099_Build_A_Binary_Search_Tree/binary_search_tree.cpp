#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 128
#define NONE -1
using namespace std;
typedef int Addr;

int isFirst=1, ix=0;
int incValueNodeList[MAX] = {0};

class NODE{
public:
	Addr left;
	Addr right;
	int value;
	NODE(){
		left = NONE;
		right = NONE;
		value = 0;
	}
};
NODE node[MAX];

int output(int value){
	if( isFirst ){
		cout<<value;
		isFirst = 0;
	}else{
		cout<<' '<<value;
	}
	return 0;
}

int levelTraverse(Addr root){
	queue<Addr> q;
	q.push(root);

	while( q.size() ){
		Addr parent = q.front();
		output(node[parent].value);
		q.pop();
		if( NONE != node[parent].left )
			q.push( node[parent].left );
		if( NONE != node[parent].right )
			q.push( node[parent].right );
	}

	return 0;
}

int inOrderSetTree(Addr root){
	if( root == NONE ){
		return 0;
	}

	inOrderSetTree( node[root].left );				//Addr
	node[root].value = incValueNodeList[ix++];			//setValue
	inOrderSetTree( node[root].right );				//Addr
	return 0;
}

int main(){
	int i, n;
	Addr root=0, left, right;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>left>>right;
		node[i].left = left;
		node[i].right = right;
	}

	for( i=0; i<n; i++ ){
		cin>>incValueNodeList[i];
	}

	// inOrder Traverse of a BST is an increasing order
	// so fill in the tree with an increasing array in inOrder
	// then a BST is formed
	sort(incValueNodeList, incValueNodeList + n);
	inOrderSetTree(root);
	levelTraverse(root);

	return 0;
}