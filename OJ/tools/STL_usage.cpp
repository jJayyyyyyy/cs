#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>		// substr
#include <algorithm>	// sort, upper_bound
#include <iostream>
using namespace std;

void usage_map(){
	map<string, int> m;
	m["hello"] = 1;
	cout<<m["hello"];
	if( m.find("hello") != m.end() ){
		cout<<m.find("hello")->second;
	}
}


void usage_set(){
	set<int> s;
	s.insert(123);
	if( s.find(234) != s.end() ){
		//
	}
}

/*
// 重载, PAT_A_1129
struct Item{
	int id, cnt;
	Item(int _id, int _cnt){
		id = _id;
		cnt = _cnt;
	}
	bool operator < (const Item & a) const {
		if( cnt != a.cnt ){
			return cnt > a.cnt;
		}else{
			return id < a.id;
		}
	}
};

set<Item> s;
s.insert(Item(id, cnt));
*/

void usage_queue(){
	queue<int> q;
	q.push(123);
	int a = q.front();
	q.pop();
}

void usage_stack(){
	stack<int> s;
	s.push(123);
	int a = s.top();
	s.pop();
}

void usage_string(){
	string s1 = "hello";
	string s2(5, '0');				// "00000"
	s1.find('l');					// 2
	s1.find_last_of('l');			// 3
	string s3 = s1.substr(3, 2);	// lo
}

int main(){
	return 0;
}