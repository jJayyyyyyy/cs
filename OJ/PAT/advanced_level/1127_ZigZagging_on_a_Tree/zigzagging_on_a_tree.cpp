#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#define MAXSIZE 32
using namespace std;

struct Node{
	int val, level;
	Node *lchild, *rchild;
	Node(int _val){
		val = _val;
		level = 1;
		lchild = rchild = NULL;
	}
};

int post[MAXSIZE]={0}, in[MAXSIZE]={0};
int n;
vector<Node *> ans;
stack<int> st;

void r_output(){
	while( st.size() ){
		cout<<' '<<st.top();
		st.pop();
	}
}

void output(){
	cout<<ans[0]->val;
	for( int i = 1; i < n; ++i ){
		if( ans[i]->level % 2 == 0 ){
			r_output();
			cout<<' '<<ans[i]->val;
		}else{
			st.push(ans[i]->val);
		}
	}
	r_output();
	cout<<'\n';
}

void levelTraverse(Node * root){
	queue<Node *> q;
	q.push(root);
	while( q.size() ){
		Node * node = q.front();
		ans.push_back(node);
		q.pop();
		if( NULL != node->lchild ){
			node->lchild->level = node->level + 1;
			q.push(node->lchild);
		}
		if( NULL != node->rchild ){
			node->rchild->level = node->level + 1;
			q.push(node->rchild);
		}
	}
	output();
}

void insert(Node * & root, int postL, int postR, int inL, int inR){
	if( postL > postR ){
		return;
	}
	int val = post[postR];
	root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; ++mid ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	insert(root->lchild, postL, postL+numLeft-1, inL, mid-1);
	insert(root->rchild, postL+numLeft, postR-1, mid+1, inR);
}

int main(){
	cin>>n;
	for( int i = 0; i < n; ++i ){
		cin>>in[i];
	}
	for( int i = 0; i < n; ++i ){
		cin>>post[i];
	}
	Node * root = NULL;
	insert(root, 0, n-1, 0, n-1);
	levelTraverse(root);
	return 0;
}