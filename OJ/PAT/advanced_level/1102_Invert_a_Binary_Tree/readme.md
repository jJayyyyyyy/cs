1.  构造二叉树，

    ```cpp
    struct Node{
		int lchild, rchild, parent;
		Node(){
			lchild = rchild = parent = NONE;
		}
	};
	Node node[MAX];
    // ...
    
    // 父子对应
    for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( isdigit(left) ){
			int lchild = left - '0';
			int parent = i;
			node[parent].lchild = lchild;
			node[lchild].parent = parent;
		}
		if( isdigit(right) ){
			int rchild = right - '0';
			int parent = i;
			node[parent].rchild = rchild;
			node[rchild].parent = parent;
		}
	}
    ```

2.  左右反转（后序LRN遍历，从叶节点开始反转）

    ```cpp
    void invertTree(int root){
		if( NONE != root ){
			invertTree(node[root].lchild);
			invertTree(node[root].rchild);
			int tmp = node[root].lchild;
			node[root].lchild = node[root].rchild;
			node[root].rchild = tmp;
		}
	}
    ```

3.  层序，中序输出

4.  同类题目(PAT_A)

1020 Tree Traversals
1086 Tree Traversals Again

1099. Build A Binary Search Tree
1064 Complete Binary Search Tree
1110. Complete Binary Tree

1123. Is It a Complete AVL Tree
1066 Root of AVL Tree


1102. Invert a Binary Tree 

1094. The Largest Generation

1004. Counting Leaves

