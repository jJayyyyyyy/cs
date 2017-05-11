1.  BST中序遍历是递增的
2.  CBT用数组表示，进行中序遍历，同时依次填入递增节点
3.  得到CBST

```cpp
// CBT inOrderTraverse
int inOrderTraverse(Addr root){
	if( root > n ){
		return 0;
	}
                                        // Addr [1, n] 
	inOrderTraverse( root*2 );          // lchild = root * 2
	cbt[root] = incNodeList[ix++];      // root
	inOrderTraverse( root*2 + 1 );      // rchild = root * 2
	return 0;
}
```

