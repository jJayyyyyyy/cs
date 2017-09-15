#include <iostream>
#define MAXSIZE 1004
using namespace std;

bool vis[MAXSIZE] = {false}; // 输入时，将对应的 vis[i] 标为 true
int father[MAXSIZE];
int blockList[MAXSIZE] = {0};

// 初始化
void initFather(){
	for( int i = 0; i < MAXSIZE; ++i ){
		father[i] = i;
	}
}

// 此处省略了路径压缩，好记
int findFather(int x){
	while( x != father[x] ){
		x = father[x];
	}
	return x;
}

// 归并为同一集合
void Union(int a, int b){
	int fa1 = findFather(a);
	int fa2 = findFather(b);
	// 以最小编号为根
	if( fa1 < fa2 ){
		father[fa2] = fa1;
	}else{
		father[fa1] = fa2;
	}
}

// PAT_1118 统计区块数量，以及maxID
void cntBlockAndMaxID(){
	int maxID = 0;
	for( int i = 0; i < MAXSIZE; ++i ){
		if( vis[i] == true ){
			maxID = i;			// 最大结点编号
			int rootID = findFather(i);
			blockList[rootID]++;
		}
	}
	int block = 0, maxBlock = -1;
	for( int i = 0; i < MAXSIZE; ++i ){
		if( blockList[i] > 0 ){
			maxBlock = i;		// 最大区块编号，可用于对区块进行排序
			block++;			// 最大区块数量
		}
	}
	cout<<block<<' '<<maxID<<'\n';
}