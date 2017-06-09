#include <iostream>
#define MAXSIZE 16
using namespace std;

struct Heap{
	int len;
	int data[MAXSIZE];
	Heap(){
		len = MAXSIZE;
		for( int i=0; i<=len/2; i++ ){
			data[i] = len/2 - i;
		}
		for( int i=len/2; i<len; i++ ){
			data[i] = i + 1;
		}
	}
};

// reorder the array to make a max heap
int adjustHeap(Heap &hp, int iParent, int len){
	int iChild = iParent*2 + 1;
	while( iChild < len ){
		int iLeft = iChild;
		int iRight = iLeft + 1;
		if( iRight < len ){
			// change both [<] to [>], then it is a min heap
			if( hp.data[iLeft] < hp.data[iRight] ){
				iChild = iRight;
			}
		}

		// change both [<] to [>], then it is a min heap
		if( hp.data[iParent] < hp.data[iChild] ){
			int tmp = hp.data[iParent];
			hp.data[iParent] = hp.data[iChild];
			hp.data[iChild] = tmp;
			iParent = iChild;
			iChild = iParent*2 + 1;
		}else{
			break;
		}
	}

	return 0;
}

// it's a max heap
// put the biggest one to the end
// then you get an ascending array
int heapSort(Heap &hp, int len){	
	for( int i=len/2 - 1; i>=0; i-- ){
		// heap-ize the array to make a max heap
		adjustHeap(hp, i, len);
	}

	for( int i=len-1; i>0; i-- ){
		// put the biggest to the end
		int tmp = hp.data[0];
		hp.data[0] = hp.data[i];
		hp.data[i] = tmp;
		// re-order the array from 0 to i, to get an ascending array
		adjustHeap(hp, 0, i);
	}
	return 0;
}

int getHeap(Heap &hp, int len){
	for( int i=0; i<len; i++ ){
		cout<<hp.data[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

int main(){
	Heap hp;
	getHeap(hp, hp.len);
	heapSort(hp, hp.len);
	getHeap(hp, hp.len);

	return 0;
}
