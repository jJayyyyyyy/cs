// 高度从叶到根，叶节点高度为1
// 深度从根到叶，根节点深度为1，层数同深度

#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
};

// 递归法求高度
int getHeight(Node * root){
	if( root == NULL ){
		return 0;
	}
	int lHeight = getHeight(root->lchild);
	int rHeight = getHeight(root->rchild);
	return max(lHeight, rHeight) + 1;
}

// 非递归求深度/层数可用层序法
int getLevel(Node * root){
	int level = 0;
	if( root != NULL ){
		queue<Node *> q;
		q.push(root);
		int front = 0, rear = 1;
		int lastNode = rear;

		while( q. size() ){
			Node * node = q.front();
			q.pop();
			front++;	// 队首出队
			if( node->lchild != NULL ){
				q.push(node->lchild);
				rear++;	// 队尾入队
			}
			if( node->rchild != NULL ){
				q.push(node->rchild);
				rear++;	// 队尾入队
			}
			if( front == lastNode ){
				level++;
				lastNode = rear;
			}
		}
	}
	return level;
}