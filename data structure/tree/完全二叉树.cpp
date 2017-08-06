// 判断是否为完全二叉树
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