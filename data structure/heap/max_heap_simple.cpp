#include <iostream>
#include <algorithm>
#define MAXSIZE 16
using namespace std;

// 注意，CBT数组范围是 [1, n]

// 调整子树，使其成为大根堆
void DownAdjust(int hp[], int parent, int len){
	// 子树，从根到叶进行调整
	for(int child = parent*2; child <=len; parent = child, child = parent*2 ){
		int lchild = child, rchild = child + 1;
		if( rchild <= len ){
			if( hp[lchild] < hp[rchild] ){
				// 选出左右孩子中，更大的那个
				child = rchild;
			}
		}
		
		if( hp[parent] < hp[child] ){
			// 小元素下沉，大元素上调
			// 如果孩子比父亲大，就交换元素	
			swap( hp[parent], hp[child] );
		}else{
			// 否则，子树已经成为最大堆，退出
			break;
		}
	}
}

void SortHeap(int hp[], int len){
	/*
	 * 按照 [len/2, 1] 的逆序，以每个节点为根
	 * 对子树进行从根到叶的调整，使每个子树都成为最大堆
	 * 先完成一轮堆化，使整棵树为最大堆
	*/
	for( int root = len / 2; root >= 1; root-- ){
		DownAdjust(hp, root, len);
	}
	
	/*
	 * 大根堆的hp[1]是整棵树最大的元素，把它与数组最后的元素交换，
	 * 然后对[1, len-1] 重新进行堆化，构造大根堆
	 * 重复上述过程，最后就能得到一个递增数组
	*/
	for( int end = len; end > 1; end-- ){
		// 把大的放到后面
		int root = 1;
		swap( hp[root], hp[end] );
		// 重新堆化 [1, i-1]
		DownAdjust(hp, root, end - 1);
	}
}

void PrintHeap(int hp[], int len){
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
	PrintHeap(hp, len);
	SortHeap(hp, len);
	PrintHeap(hp, len);
	return 0;
}