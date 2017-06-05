1.  构造二叉树，

    ```cpp
    class Node{
    public:
    	Addr lchild, rchild, parent;
    	Node(){
    		lchild = NONE;
    		rchild = NONE;
    		parent = NONE;
    	}
    };
    
    // ...
    
    // 父子对应
    for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( isdigit(left) ){
			Addr lchild = left - '0';
			Addr parent = i;
			nodeList[parent].lchild = lchild;
			nodeList[lchild].parent = parent;
		}
		if( isdigit(right) ){
			Addr rchild = right - '0';
			Addr parent = i;
			nodeList[parent].rchild = rchild;
			nodeList[rchild].parent = parent;
		}
	}
    ```

2.  左右反转（后序LRN遍历，从叶节点开始反转）

    ```cpp
    int invertTree(Addr root){
    	if( NONE == root ){
    		return 0;
    	}
    
    	invertTree(nodeList[root].lchild);
    	invertTree(nodeList[root].rchild);
    	Addr tmpLeft = nodeList[root].lchild;
    	nodeList[root].lchild = nodeList[root].rchild;
    	nodeList[root].rchild = tmpLeft;
    	return 0;
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

