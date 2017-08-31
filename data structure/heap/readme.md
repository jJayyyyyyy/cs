1.	堆可以用完全二叉树CBT来实现。

2.	大顶堆/最大堆：根节点元素是所有节点中最大的，递归定义。小顶堆/最小堆则相反。

3.	给定一棵CBT，如何堆化？

	*	首先定义`adjustHeap()`，给定节点编号，对以它为根的子树进行堆化。

		*	在两个叶节点中选出大的，假设是左孩子`iLeft`

		*	左孩子`iLeft`与父节点`iParent`比较

		*	若`vParent < vLeft`，那么左孩子变成父节点，父节点变成左孩子

			*	`iParent = iLeft`，对左子树做相同处理

		*	否则退出循环

	*	从最末节点的父节点开始，倒着对树进行堆化。由于是倒着进行堆化的，每一次都会把底层更大的值往上提。

	```cpp
	for( int i=len/2 - 1; i>=0; i-- ){
		adjustHeap(hp, i, len);
	}
	```
	
*	PAT对应题目[PAT_A_1098](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1098_Insertion_or_Heap_Sort)