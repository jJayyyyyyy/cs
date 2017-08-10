// 判断是否为完全二叉树
// PAT相关例题：1110, 1123
// 注意1123要求输出层序序列，因此要把19行的return，换成isCBT=false，然后使用20行的break
int isCBTLevelTrav(Node * root){
	if( root != NULL ){
		queue<Node *> q;
		q.push(root);
		while( q.size() > 0 ){
			Node * node = q.front();
			// visit(node);
			q.pop();
			if( node != NULL ){
				q.push(node->lchild);
				q.push(node->rchild);
			}else{
				while( q.size() > 0){
					Node * p = q.front();
					if( p != NULL ){
						return 0;
						// break;
					}
					q.pop();
				}
			}
		}
	}
	return 1;
}