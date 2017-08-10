#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int isFirst=1, isPreEmpty=0, isCBT=1;

struct Node{
	Node *lchild, *rchild;
	int val, height;
	Node(int _val){
		val = _val;
		height = 1;
		lchild = rchild = NULL;
	}
};

int getHeight(Node *parent){
	if( NULL == parent ){
		return 0;
	}else{
		return parent->height;
	}
}

int updateHeight(Node *parent){
	int lH = getHeight(parent->lchild);
	int rH = getHeight(parent->rchild);
	parent->height = 1 + max(lH, rH);
	return 0;
}

int getBalanceFactor(Node *parent){
	int lH = getHeight(parent->lchild);
	int rH = getHeight(parent->rchild);
	return lH - rH;
}

int leftRotate(Node * &parent){
	Node *tmp = parent->rchild;
	parent->rchild = tmp->lchild;
	tmp->lchild = parent;
	updateHeight(parent);
	updateHeight(tmp);
	parent = tmp;
	return 0;
}

int rightRotate(Node * &parent){
	Node *tmp = parent->lchild;
	parent->lchild = tmp->rchild;
	tmp->rchild = parent;
	updateHeight(parent);
	updateHeight(tmp);
	parent = tmp;
	return 0;
}

int insertAVL(Node * &parent, int val){
	if( NULL == parent ){
		parent = new Node(val);
		return 0;
	}

	if(val < parent->val){
		insertAVL(parent->lchild, val);
		updateHeight(parent);
		if( 2 == getBalanceFactor(parent) ){
			if( 1 == getBalanceFactor(parent->lchild) ){
				rightRotate(parent);
			}else{
				leftRotate(parent->lchild);
				rightRotate(parent);
			}
		}
	}else{
		insertAVL(parent->rchild, val);
		updateHeight(parent);
		if( -2 == getBalanceFactor(parent) ){
			if( -1 == getBalanceFactor(parent->rchild) ){
				leftRotate(parent);
			}else{
				rightRotate(parent->rchild);
				leftRotate(parent);
			}
		}
	}
	return 0;
}

void output(Node *parent){
	if( parent != NULL ){
		if(isFirst){
			cout<<parent->val;
			isFirst = 0;
		}else{
			cout<<' '<<parent->val;
		}	
	}
}

void isCBTlevelTrav(Node *root){
	if( root != NULL ){
		queue<Node *> q;
		q.push(root);
		while( q.size() > 0 ){
			Node * node = q.front();
			output(node);
			q.pop();
			if( node != NULL ){
				q.push(node->lchild);
				q.push(node->rchild);
			}else{
				while( q.size() > 0 ){
					Node * p = q.front();
					if( p != NULL ){
						isCBT = 0;
						break;
					}
					q.pop();
				}
			}
		}
	}
}

int main(){
	Node *root = NULL;
	int val, n, i;
	cin>>n;

	for( i=0; i<n; i++ ){
		cin>>val;
		insertAVL(root, val);
	}

	isCBTlevelTrav(root);
	if( isCBT ){
		cout<<"\nYES\n";
	}else{
		cout<<"\nNO\n";
	}
	return 0;
}
