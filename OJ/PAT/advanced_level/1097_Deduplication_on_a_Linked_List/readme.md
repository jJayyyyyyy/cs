1.  首先建立链表

2.  然后顺序遍历链表，对于每一个元素，首先判断之前是否出现过

    ```cpp
    if( uniqSet[absVal] == 0 ){
        // 没有出现
        uniqSet[absVal] = 1;
    	
    }else{
        // 出现过了
    }
    ```

    然后，元素的值和地址归入`uniqList[]`或`dupList[]`
    
3.  最后，分别遍历`uniqList[]`和`dupList[]`

4.  不知道为什么，无法通过PAT的case1，思路和[这里](http://blog.csdn.net/xyzchenzd/article/details/44828933)是一样的。

晕