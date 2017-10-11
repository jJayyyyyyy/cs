#include <iostream>
#include <set>
#define MAXSIZE 50004
using namespace std;

struct Item{
	int id, cnt;
	Item(int _id, int _cnt){
		id = _id;
		cnt = _cnt;
	}
	// 第一个const，表示函数不可修改成员变量。
	// 第二个const，我们在给sort写cmp的时候，如果用了引用&参数，那么cmp的形参表也是要加const的。或者形参表的 const 和 & 同时去掉，也可以编译。
	bool operator < (const Item & a) const {
		if( cnt != a.cnt ){
			return cnt > a.cnt;
		}else{
			return id < a.id;
		}
	}
};

set<Item> s;
// cntList[i] 表示id为i的商品，被用户点过的次数
int cntList[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, id;
	cin>>n>>k;
	for( int i = 0; i < n; ++i ){
		cin>>id;
		if( i != 0 ){
			cout<<id<<":";
			int j = 0;
			for( auto it = s.begin(); it != s.end() && j < k; ++it, ++j ){
				cout<<' '<<it->id;
			}
			cout<<'\n';
		}
		auto it = s.find(Item( id, cntList[id] ) );		// 使用auto类型代替 set<Item>::iterator，更加简洁
		if( it != s.end() ){
			s.erase(it);
		}
		cntList[id]++;
		s.insert(Item( id, cntList[id] ) );
	}
	return 0;
}