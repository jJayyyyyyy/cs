#include <stack>
struct Node{
	int val=0;
	Node *lchild=NULL, *rchild=NULL;
};

// 递归
void inOrder(Node * root){
	if( root != NULL ){
		// visit(root);
		inOrder(root->lchild);
		inOrder(root->rchild);
	}
}

// 非递归 LNR，与先序类似
void inOrder_nr(Node * root){
	stack<Node *> s;
	Node *p = root;
	while( p != NULL || s.size() > 0 ){
		// 一路往左
		if( p != NULL ){
			s.push(p->rchild);
			p = p->lchild;
		}else{
			p = s.top();
			s.pop();
			// visit(p);	// 先访问p, 也就是N
			p = p->rchild;	// 此时要么是叶节点，要么是没有左子树了，也就是完成了 L, 或LN
		}
	}
}