#include <iostream>
#include <iomanip>
#define MAX 100004
using namespace std;

struct Member{
	int atParty;
	int cpAtParty;
	int cpID;
	Member(){
		atParty = cpAtParty = cpID = -1;
	}
};

Member member[MAX];
int singleList[MAX] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n1, n2, i, id1, id2, cpID, cnt=0, isFirst=1;
	
	cin>>n1;
	for( i=0; i<n1; i++ ){
		cin>>id1>>id2;
		member[id1].cpID = id2;
		member[id2].cpID = id1;
	}

	cin>>n2;
	for( i=0; i<n2; i++ ){
		cin>>id1;
		member[id1].atParty = 1;
		cpID = member[id1].cpID;
		if( -1 != cpID ){
			member[cpID].cpAtParty = 1;
		}
	}

	for( i=0; i<MAX; i++ ){
		if( 1 == member[i].atParty ){
			if( -1 == member[i].cpID ){
				// cout<<"member "<<i<<" has no cp\n";
				singleList[cnt++] = i;
			}else if( -1 == member[i].cpAtParty ){
				// cout<<"member "<<i<<"'s cp is not here\n";
				singleList[cnt++] = i;
			}
		}
	}

	cout<<cnt<<'\n';
	for( i=0; i<cnt; i++ ){
		if( isFirst ){
			cout<<setfill('0')<<setw(5)<<singleList[i];
			isFirst = 0;
		}else{
			cout<<' '<<setfill('0')<<setw(5)<<singleList[i];
		}
	}

	return 0;
}
