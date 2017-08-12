// BST的建立
// 一个输入序列唯一确定一棵BST
#include <iostream>
using namespace std;

struct Node{
	int val;
	Node *lchild=NULL, *rchild=NULL;
	Node(int _val){
		val = _val;
	}
};

void insertBST(Node * & root, int val){
	if( NULL == root ){
		root = new Node(val);
		return;
	}
	if( val < root->val ){
		insertBST(root->lchild, val);
	}else{
		insertBST(root->rchild, val);
	}
}

int main(){
    Node * root = NULL;
    int a[5] = {3, 2, 1, 4, 5};
    for( int i = 0; i < 5; ++i ){
        insertBST(root, a[i]);
    }
    return 0;
}


// PS: PAT_1064
// BST中序遍历可以得到递增序列
// CBT用数组表示，进行中序遍历，同时依次填入递增节点，即可得到CBST
// CBT的层序遍历，即对数组进行 [1, n] 的遍历
void inOrder(int root){
	if( root <= n ){
		inOrder( root*2 );		// lchild
		CBT[root] = nodeList[ix++];
		inOrder( root*2 + 1 );	// rchild
	}
}


// PS: PAT_1099
// 对于一棵结构固定的树，对其进行中序遍历，同时填充递增序列，就可以得到相应的BST
void inOrder(int root){
	if( root != -1 ){
		inOrder( nodeList[root].lchild );
		nodeList[root].val = incList[ix++];
		inOrder( nodeList[root].rchild );
	}
}
