// 具体题目可参考 PAT1102, https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1102_Invert_a_Binary_Tree

struct Node{
	int val;
	Node * lchild, * rchild;
};

// 先反转根的左子树，再反转根的右子树
// 然后调换根的左右孩子
void invertBTree(Node * root){
	if( root != NULL ){
		invertBTree(root->lchild);
		invertBTree(root->rchild);
		Node * tmp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = tmp;
	}
}
