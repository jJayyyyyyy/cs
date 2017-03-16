#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 128
using namespace std;

int isFirst=1, ix=0;
int num_list[MAX];

class Node{
public:
	int left;
	int right;
	int parent;
	int value;
	int reset(){
		left = -1;
		right = -1;
		parent = -1;
		value = 0;
		return 0;
	}
} node[MAX];

int output(int id){
	if(isFirst){
		cout<<id;
		isFirst = 0;
	}else{
		cout<<' '<<id;
	}
	return 0;
}

int levelTraverse(int root){
	queue<int> q;
	q.push(root);

	while( q.size() ){
		int parent = q.front();
		output(node[parent].value);
		q.pop();
		if( -1!=node[parent].left )
			q.push( node[parent].left );
		if( -1!=node[parent].right )
			q.push( node[parent].right );
	}

	return 0;
}

int inorderSetValue(int root){
	if(root==-1)
		return 0;
	inorderSetValue(node[root].left);
	node[root].value = num_list[ix++];
	inorderSetValue(node[root].right);

	return 0;
}

int main(){
	int i=0, n, root;

	cin>>n;
	for( i=0; i<n; i++ ){
		node[i].reset();
	}

	int left, right;
	for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( -1!=left ){
			node[i].left = left;
			node[left].parent = i;
		}
		if( -1!=right ){
			node[i].right = right;
			node[right].parent = i;
		}
	}

	for( i=0; i<n; i++ ){
		cin>>num_list[i];
		if( node[i].parent==-1 ){
			root = i;
		}
	}

	sort(num_list, num_list+n);

	inorderSetValue(root);
	isFirst = 1;
	levelTraverse(root);

	return 0;
}