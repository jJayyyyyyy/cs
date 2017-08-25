*   Dijkstra一定记得`初始化`！！！（就因为这个浪费了一小时。。

*   没有vs的情况下，充分利用`dist[v]`进行调试

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

*   TODO

    更新所有最短路径的题目，使用统一模板
    
    1003, 1018, 1030, 1072, 1087, 1111
