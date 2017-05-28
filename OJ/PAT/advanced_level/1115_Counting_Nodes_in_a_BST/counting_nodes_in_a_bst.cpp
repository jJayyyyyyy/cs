#include <iostream>
#include <queue>
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

int maxLevel1=1, maxLevel2=0;
int maxCnt1=0, maxCnt2=0;

int insertBST(Node * &parent, int val){
	if( NULL == parent ){
		parent = new Node(val);
		return 0;
	}

	if( val <= parent->val ){
		insertBST( parent->lchild, val );
	}else{
		insertBST( parent->rchild, val );
	}
	return 0;
}

int levelTraverse(Node * &root){
	int level=1;
	queue<Node *> q;
	q.push(root);

	while( q.size() ){
		Node * parent = q.front();
		q.pop();
		level = parent->level;
		if( level > maxLevel1 ){
			maxLevel1 = level;
		}

		if( NULL != parent->lchild ){			
			parent->lchild->level = level + 1;
			q.push( parent->lchild );
		}
		if( NULL != parent->rchild ){
			parent->rchild->level = level + 1;
			q.push( parent->rchild );
		}
	}
	maxLevel2 = maxLevel1 - 1;

	return 0;
}

int preTraverse(Node * &root){
	if( NULL == root ){
		return 0;
	}

	if( root->level == maxLevel1 ){
		maxCnt1++;
	}else if( root->level == maxLevel2 ){
		maxCnt2++;
	}
	// cout<<root->val<<": "<<root->level<<'\t';
	preTraverse(root->lchild);
	preTraverse(root->rchild);
	return 0;
}

int freeBST(Node * &parent){
	if( NULL == parent ){
		return 0;
	}

	freeBST(parent->lchild);
	freeBST(parent->rchild);
	delete parent;
}

int main(){
	Node *root=NULL;
	int n, i, val;
	cin>>n;

	if( 1 == n ){
		cout<<"1 + 0 = 1\n";
		return 0;
	}

	for( i=0; i<n; i++ ){
		cin>>val;
		insertBST(root, val);
	}

	levelTraverse(root);
	preTraverse(root);
	// cout<<'\n';
	// cout<<maxLevel1<<'\n'<<maxCnt1<<' '<<maxCnt2<<'\n';
	cout<<maxCnt1<<" + "<<maxCnt2<<" = "<<maxCnt1+maxCnt2<<'\n';

	freeBST(root);

	return 0;
}