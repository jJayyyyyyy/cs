// PAT层序(BFS)相关题目
// 1102, 

#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
};

// 层序遍历
void levelTraverse(Node * root){
	if( root != NULL ){
		queue<Node *> q;
		q.push(root);
		while( q. size() ){
			Node * node = q.front();
			q.pop();
			//visit(node);
	
			if( node->lchild != NULL ){
				q.push(node->lchild);
			}
			if( node->rchild != NULL ){
				q.push(node->rchild);
			}
		}
	}
}

// 非递归求高度可用层序法
int getHeight(Node * root){
	int height = 0;
	if( root != NULL ){
		queue<Node *> q;
		q.push(root);
		int front = 0, rear = 1;
		int lastNode = rear;

		while( q. size() ){
			Node * node = q.front();
			q.pop();
			front++;
			if( node->lchild != NULL ){
				q.push(node->lchild);
				rear++;
			}
			if( node->rchild != NULL ){
				q.push(node->rchild);
				rear++;
			}
			if( front == lastNode ){
				height++;
				lastNode = rear;
			}
		}
	}
	return height;
}

// 判断是否为完全二叉树 CBT
int isCBTLevelTrav(Node * root){
	if( root != NULL ){
		queue<Node *> q;
		q.push(root);
		while( q. size() ){
			Node * node = q.front();
			q.pop();
			if( node != NULL ){
				q.push(node->lchild);
				q.push(node->rchild);
			}else{
				while( q.size() ){
					Node * p = q.front();
					q.pop();
					if( p != NULL ){
						return 0;
					}
				}
			}
		}
	}
	return 1;
}