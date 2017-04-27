用

```cpp
int insertBST(Node * &parent, int val){
    if( NULL == parent){
        parent = new Node(val);
        return 0;
    }else{
        if( val < parent-val ){
            insertBST(parent->lchild);
        }else{
            insertBST(parent->rchild);
        }
    }
    return 0;
}
```

这种方法生成BST，给定一个输入序列，生成了BST，如果BST的preOrder

与输入序列相同，那么输入序列是先序preOrder
与输入序列不同，那么输入序列不是preOrder

（貌似是废话）

但是我们假定输入是preOrder序列，由于第一个节点是root

试错法，以根为基

对于BST，一个输入序列确定了一个BST