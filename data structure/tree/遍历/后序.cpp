// 后序遍历，可用于删除树，查找某个节点的祖先，查找某两个节点的公共祖先

struct Node{
	int val=0;
	Node *lchild=NULL, *rchild=NULL;
}

// 递归
void postOrder(Node * root){
	if( root != NULL ){
		postOrder(root->lchild);
		postOrder(root->rchild);
		// visit(root);
	}
}

// 非递归, 模板
void postOrder_nr(Node * root, int x){
	stack<Node *> s, s1, s2;
	Node * p = root;
	Node * marked = NULL;
	while( p != NULL || s.size() > 0 ){
		if( p != NULL ){
			s.push(p);
			p = p->lchild;
		}else{
			p = s.top();		// 此时p==NULL, 到底了，所以从栈顶开始再试探
			if( p->rchild != NULL && p->rchild != marked ){		// 若右子树存在，且未被访问过，则探索右子树
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}else{				// 否则开始访问
				p = s.top();
				s.pop();
				
				/*	若要求打印值为x的节点，它的所有祖先，或者它到根的路径
					若要找公共祖先，就在这里先保存一个s的副本，找齐2个副本s1, s2以后，从栈顶开始找最长公共子序列
				*/
				// visit(p);
				// if( p->val == x ){
				// 	while( s.size() > 0 ){		// 栈内元素构成了叶到根的路径, p==s.top()
				// 		s.top()->disp();
				// 		s.pop();
				// 	}
				// 	return;
				// }
				
				marked = p;
				p = NULL;
			}
		}
	}
}