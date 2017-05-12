#include <iostream>
#include <string>
#include <stack>
#define MAX 32
using namespace std;

// pre NLR
// in LNR
// post LRN

struct Node{
	Node *lchild, *rchild;
	int val;
	Node(int _val){
		val = _val;
		lchild = rchild = NULL;
	}
};

int preList[MAX]={0}, inList[MAX]={0};
int isFirst = 1;

int insertTree(Node * &parent, int preLeft, int preRight, int inLeft, int inRight){
	if(preLeft > preRight){
		return 0;
	}

	parent = new Node(preList[preLeft]);

	int mid;
	for( mid=inLeft; mid<=inRight; mid++ ){
		if( inList[mid] == preList[preLeft] ){
			break;
		}
	}
	int cntLeftTree = mid - inLeft;

	int preLeftTreeStart = preLeft + 1;
	int preLeftTreeEnd = preLeft + cntLeftTree;
	int preRightTreeStart = preLeft + cntLeftTree + 1;
	int preRightTreeEnd = preRight;

	int inLeftTreeStart = inLeft;
	int inLeftTreeEnd = mid - 1;
	int inRightTreeStart = mid + 1;
	int inRightTreeEnd = inRight;

	insertTree(parent->lchild, preLeftTreeStart, preLeftTreeEnd, inLeftTreeStart, inLeftTreeEnd);
	insertTree(parent->rchild, preRightTreeStart, preRightTreeEnd, inRightTreeStart, inRightTreeEnd);
	return 0;
}

int output(int val){
	if( isFirst ){
		cout<<val;
		isFirst = 0;
	}else{
		cout<<' '<<val;
	}
	return 0;
}

int postTraverse(Node * root){
	if( NULL == root ){
		return 0;
	}
	postTraverse(root->lchild);
	postTraverse(root->rchild);
	output(root->val);
	return 0;
}

int freeTree(Node * root){
	if( NULL == root ){
		return 0;
	}

	freeTree(root->lchild);
	freeTree(root->rchild);
	delete root;
	return 0;
}

int main(){
	stack<int> st;
	string usInput;
	int n, i, j=0, k=0, len, val;
	cin>>n;

	len = n * 2;
	for( i=0; i<len; i++ ){
		cin>>usInput;
		if( "Push" == usInput ){
			cin>>val;
			preList[j++] = val;
			st.push(val);
		}else{
			inList[k++] = st.top();
			st.pop();
		}
	}

	Node * root = NULL;
	insertTree(root, 0, n-1, 0, n-1);
	postTraverse(root);
	freeTree(root);
	return 0;
}