#include <iostream>
using namespace std;

int dataList[3] = {1, 2, 3};

class Node{
public:
	int data;
	Node *next;
	Node(int _data){
		data = _data;
		next = NULL;
	}
};

int pushBack(Node *&head, int data){
	if( NULL == head){
		head = new Node(data);
		return 0;
	}

	Node *p = head;
	while(NULL != p->next){
		p = p->next;
	}
	p->next = new Node(data);

	return 0;
}

int init(Node *&head, const int len){
	for(int i=0; i<len; i++){
		pushBack( head, dataList[i] );
	}
	return 0;
}

int insPreHead(Node *&head, const int data){
	Node *node = new Node(data);
	node->next = head;
	head = node;
	return 0;
}

int insPostHead(Node *head, const int data){
	Node *node = new Node(data);
	node->next = head->next;
	head->next = node;
	return 0;
}

Node *findNode(Node *head, const int nodeData){
	Node *node = head;

	while(NULL != node){
		if(nodeData == node->data){
			return node;
		}
		node = node->next;
	}
	return 0;
}

int insPostNode(Node *head, int nodeData, const int data){
	if(NULL == head){
		return 0;
	}
	Node *pre = findNode(head, nodeData);
	Node *node = new Node(data);
	node->next = pre->next;
	pre->next = node;
	return 0;
}

int freeList(Node *head){
	Node *p, *q;
	p = head;
	while(NULL != p){
		q = p->next;
		delete p;
		p = q;
	}
	return 0;
}

int traverse(Node *head){
	int size = 0;
	Node *p = head;
	while( NULL != p){
		cout<<p->data<<' ';
		p = p->next;
		size++;
	}

	return size;
}

int main(){
	Node *head = NULL;
	init(head, 3);
	// insPreHead(head, 4);
	// insPostHead(head, 5);
	// insPostNode(head, 1, 6);
	
	int size = traverse(head);
	freeList(head);

	return 0;
}

