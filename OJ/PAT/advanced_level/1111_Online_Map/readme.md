*   Dijkstra一定记得`初始化`！！！（就因为这个浪费了一小时。。

*   函数中，多维数组，作为引用参数

    ```cpp
    // int a[MAXSIZE][MAXSIZE];
    
    void foo(int (& a)[MAXSIZE][MAXSIZE]){
        
    }
    ```

    引用多维vector也类似
    
    ```cpp
    // vector<int> v[MAXSIZE];
    
    void foo(vector<int> (& v)[MAXSIZE]){
        
    }
    ```
