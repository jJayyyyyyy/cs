#include <stack>
struct Node{
	int val=0;
	Node *lchild=NULL, *rchild=NULL;
};

// 递归
void preOrder(Node * root){
	if( root != NULL ){
		// visit(root);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

// 非递归 NLR，与中序类似
void preOrder_nr(Node * root){
	stack<Node *> s;
	Node *p = root;
	while( p != NULL || s.size() > 0 ){
		// 一路往左
		if( p != NULL ){
			// visit(p);
			s.push(p->rchild);
			p = p->lchild;
		}
		// 到左端尽头了，也就是把NL结束了，下面进行R，R在栈里
		else{
			p = s.top();
			s.pop();
		}
	}
}