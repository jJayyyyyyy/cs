#include <stdio.h>
#include <stdlib.h>

int list[100]={0};
int i=0;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
} Node;

int IsEmpty(Node *root){
	if(root!=NULL)
		return 1;
	else
		return 0;
}

int GetDepth(Node *root){
	int l_dep, r_dep;
	if(root==NULL)
		return 0;
	else{
		l_dep = GetDepth(root->left);
		r_dep = GetDepth(root->right);
		if(l_dep>r_dep)
			return l_dep+1;
		else
			return r_dep+1;
	}
}

Node *Find(Node *root, int data){
	Node *p;
	if(root==NULL)
		return NULL;
	else{
		if(root->data==data)
			return root;
		else{
			if( (p=Find(root->left, data))!=NULL )
				return p;
			else if( (p=Find(root->right, data))!=NULL )
				return p;
			else
				return NULL;
		}
	}
}

int FreeTree(Node *root){
	if(root!=NULL){
		FreeTree(root->left);
		FreeTree(root->right);
		free(root);
	}
	return 1;
}

int LDR(Node *root){
	if(root!=NULL){
		LDR(root->left);
		list[i++] = root->data;
		LDR(root->right);
	}
	return 1;
}

Node *NewNode(int data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node *InsertLeft(Node *parent, int data){
	Node *node = NewNode(data);
	parent->left = node;
	return node;
}

Node *InsertRight(Node *parent, int data){
	Node *node = NewNode(data);
	parent->right = node;
	return node;
}

int main(){
	int j=0;
	Node *root, *p_parent, *p_left, *p_right;

	root = NewNode(190);
	p_left = InsertLeft(root, 188);
	p_right = InsertRight(root, 186);
	p_left = InsertLeft(p_left, 175);
	LDR(root);
	printf("%d ", list[j++]);
	printf("%d ", list[j++]);
	printf("%d ", list[j++]);
	printf("%d\n", list[j++]);

	p_right = InsertRight(p_right, 170);
	p_parent = p_right;
	p_left = InsertLeft(p_parent, 168);
	p_right = InsertRight(p_parent, 168);
	LDR(p_parent);
	printf("%d ", list[j++]);
	printf("%d ", list[j++]);
	printf("%d\n", list[j++]);

	p_right = InsertRight(p_right, 160);
	p_parent = p_right;
	p_left = InsertLeft(p_parent, 160);
	p_right = InsertRight(p_parent, 158);
	LDR(p_parent);
	printf("%d ", list[j++]);
	printf("%d ", list[j++]);
	printf("%d\n", list[j++]);


	FreeTree(root);
	return 0;
}
