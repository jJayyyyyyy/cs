// 判断是否为完全二叉树
// PAT相关例题：1110, 1123, 1064(BST与CBT结合)
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

// PAT_1064
// BST中序遍历可以得到递增序列
// CBT用数组表示，进行中序遍历，同时依次填入递增节点，即可得到CBST
// CBT的层序遍历，即对数组进行 [1, n] 的遍历
void inOrderTraverse(int root){
	if( root <= n ){
		inOrderTraverse( root*2 );		// lchild
		CBT[root] = nodeList[ix++];
		inOrderTraverse( root*2 + 1 );	// rchild
	}
}
