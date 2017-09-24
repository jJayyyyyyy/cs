#include <iostream>
#include <vector>
#include <iomanip>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int val, addr, next;
	void set(int _val, int _addr, int _next){
		val = _val;
		addr = _addr;
		next = _next;
	}
};

vector<Node> negative, mid, post, ans;
Node node[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, start, addr, val, next;
	cin>>start>>n>>k;
	for( int i = 0; i < n; ++i ){
		cin>>addr>>val>>next;
		node[addr].set(val, addr, next);
	}

	while( start != -1 ){
		Node tmp = node[start];
		start = tmp.next;
		if( tmp.val < 0 ){
			negative.push_back(tmp);
		}else if( tmp.val <= k ){
			mid.push_back(tmp);
		}else{
			post.push_back(tmp);
		}
	}

	for( const auto & item : negative ){
		ans.push_back(item);
	}
	for( const auto & item : mid ){
		ans.push_back(item);
	}
	for( const auto & item : post ){
		ans.push_back(item);
	}

	int i = 0;
	for( i = 0; i < ans.size() - 1; ++i ){
		cout<<setw(5)<<setfill('0')<<ans[i].addr;
		cout<<' '<<ans[i].val<<' ';
		cout<<setw(5)<<setfill('0')<<ans[i + 1].addr<<'\n';
	}
	cout<<setw(5)<<setfill('0')<<ans[i].addr;
	cout<<' '<<ans[i].val<<" -1\n";

	return 0;
}