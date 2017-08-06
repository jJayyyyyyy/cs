*   注意，在在输入数量上，本题和同类题目略有区别。

*   20170806更新，判断是否为完全二叉树，更直观好记的写法，参考王道P131, App7 + [data structure](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/tree)

    ```cpp
    // 静态数组
    int isCBTLevelTrav(int root){
    	if( root != NONE ){
    		queue<int> q;
    		q.push(root);
    		while( q.size() ){
    			int parent = q.front();
    			levelOrderList.push_back(parent);
    			q.pop();
    			if( parent != NONE ){
    				q.push(node[parent].lchild);
    				q.push(node[parent].rchild);
    			}else{
    				while( q.size() ){
    					int p = q.front();
    					q.pop();
    					if( p != NONE ){
    						return 0;
    					}
    				}
    			}
    		}
    	}
    	return 1;
    }
    
    // 二叉链表
    int isCBTLevelTrav(Node * root){
    	if( root != NULL ){
    		queue<Node *> q;
    		q.push(root);
    		while( q. size() ){
    			Node * node = q.front();
    			q.pop();
    			if( node != NULL ){
    				q.push(node->lchild);
    				q.push(node->rchild);
    			}else{
    				while( q.size() ){
    					Node * p = q.front();
    					q.pop();
    					if( p != NULL ){
    						return 0;
    					}
    				}
    			}
    		}
    	}
    	return 1;
    }
    ```
