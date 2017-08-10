// 相关题目: PAT_1020, PAT_1086
#define MAXSIZE 32
struct Node{
	int val=0;
	Node *lchild=NULL, *rchild=NULL;
	Node(int _val){
		val = _val;
	}
};

int preList[MAXSIZE], inList[MAXSIZE], postList[MAXSIZE];

// 1086, 先序+中序，造树
Node * preInCreate(int preL, int preR, int inL, int inR){
	if( preL > preR ){
		return NULL;
	}
	int val = pre[preL];
	Node * root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; ++mid ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	root->lchild = preInCreate(preL+1, preL+numLeft, inL, mid-1);
	root->rchild = preInCreate(preL+numLeft+1, preR, mid+1, inR);
	return root;
}

// 1020, 后序+中序，造树
Node * postInCreate(int postL, int postR, int inL, int inR){
	if( postL > postR ){
		return NULL;
	}
	int val = post[postR];
	Node * root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; ++mid ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	root->lchild = postInCreate(postL, postL+numLeft-1, inL, mid-1);
	root->rchild = postInCreate(postL+numLeft, postR-1, mid+1, inR);
	return root;
}
