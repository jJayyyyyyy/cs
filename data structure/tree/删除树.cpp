#include <iostream>
#include <queue>
#define MAX 16
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
};

// LRN删除整棵树，并释放空间，先删子树再删根。若先删根，那么子树就找不到了。
void delTree(Node * root){
	if( root != NULL ){
		delTree(root->lchild);
		delTree(root->rchild);
		delete root;
	}
}

// 王道P133 App13，若某结点的val为x，则删除其左右子树
// 书上用的是层序，也可以用这里的先序NLR，相当于查到x后，就删掉其左右子树，再把x当成叶子
void preOrderDelX(Node * root, int x){
	if( root != NULL ){
		if( root->val == x ){
			delTree(root->lchild);
			delTree(root->rchild);
			root->lchild = NULL;    // 注意置空
			root->rchild = NULL;    // 注意置空
		}
		preOrderDelX(root->lchild, x);
		preOrderDelX(root->rchild, x);
	}
}