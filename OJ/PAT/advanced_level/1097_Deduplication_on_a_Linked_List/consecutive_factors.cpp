#include <iostream>
#include <cstdlib>
#include <iomanip>
#define MAX 100004
#define ADDR int
using namespace std;

struct Node{
	int val;
	ADDR next;
};

struct Output{
	int val;
	ADDR addr;
};

Node inputList[MAX];
Output uniqList[MAX];
Output dupList[MAX];
int uniqSet[MAX] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ADDR start, cur, next;
	int n, i, val;

	cin>>start>>n;

	for( i=0; i<n; i++ ){
		cin>>cur;
		cin>>inputList[cur].val>>inputList[cur].next;
	}
	
	int iUniq = 0, iDup = 0, absVal;

	for( cur=start; cur!=-1; ){
		val = inputList[cur].val;
		absVal = abs(val);
		next = inputList[cur].next;

		if( uniqSet[absVal] == 0 ){
			uniqSet[absVal] = 1;
			uniqList[iUniq].val = val;
			uniqList[iUniq].addr = cur;
			iUniq++;
		}else{
			dupList[iDup].val = val;
			dupList[iDup].addr = cur;
			iDup++;
		}		
		cur = next;
	}

	for( i=0; i<iUniq; i++ ){
		cout<<setfill('0')<<setw(5)<<uniqList[i].addr;
		cout<<' '<<uniqList[i].val<<' ';
		if( i < iUniq - 1 ){
			cout<<setfill('0')<<setw(5)<<uniqList[i+1].addr<<'\n';
		}else{
			cout<<"-1\n";
		}	
	}

	for( i=0; i<iDup; i++ ){
		cout<<setfill('0')<<setw(5)<<dupList[i].addr;
		cout<<' '<<dupList[i].val<<' ';
		if( i< iDup - 1 ){
			cout<<setfill('0')<<setw(5)<<dupList[i+1].addr<<'\n';
		}else{
			cout<<"-1\n";
		}
	}

	return 0;
}
