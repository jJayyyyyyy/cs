#include <iostream>
#define MAXSIZE 16
using namespace std;

// 每棵子树从上往下调整，使CBT成为最大堆
void adjustHeap(int hp[], int parent, int len){
	// 数组范围是 [1, n]
	int child = parent * 2;
	while( child <= len ){
		int left = child, right = child + 1;
		if( right <= len ){
			// 改变这里和下面的[<], 换成[>], 就构成了最小堆
			if( hp[left] < hp[right] ){
				child = right;
			}
		}
		// 改变这里和上面的[<], 换成[>], 就构成了最小堆
		if( hp[parent] < hp[child] ){
			swap( hp[parent], hp[child] );
			parent = child;
			child = parent * 2;
		}else{
			break;
		}
	}
}

// 这是最大堆，树根元素hp[1]最大
// 不断把树根放到数组最后，然后对[1, i-1]进行堆化adjustHeap
// 也就是大的放到后面，这样，最后就能得到一个递增序列
void heapSort(int hp[], int len){
	for( int i = len / 2; i >= 1; --i ){
		// 从最后一个结点开始, 向上找parent
		// 以parent为根，向下进行堆化
		adjustHeap(hp, i, len);
	}
	for( int i = len; i > 1; --i ){
		// 把大的放到后面
		swap( hp[1], hp[i] );
		// 重新堆化 [1, i-1] 
		adjustHeap(hp, 1, i - 1);
	}
}

void getHeap(int hp[], int len){
	for( int i = 1; i <= len; ++i ){
		cout<<hp[i]<<' ';
	}
	cout<<'\n';
}

int main(){
	// 用数组表示CBT，然后映射成为最大堆
	int hp[MAXSIZE] = { -1, 5, 4, 1, 2, 3, 6, 9, 10, 8, 7 };
	int len = 10;
	// 数组范围是 [1, n], 不从0开始
	getHeap(hp, len);
	heapSort(hp, len);
	getHeap(hp, len);
	return 0;
}