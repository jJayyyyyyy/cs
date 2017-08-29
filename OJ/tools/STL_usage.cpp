#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>		// substr
#include <algorithm>		// sort, upper_bound
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
	string s2(5, '0');
	cout<<s1.find('l');
	cout<<s1.find_last_of('l');
	string s3 = s1.substr(3, 2);
}

// PAT_A_1085
void usage_upper_bound(){
	int myints[] = {10,20,30,30,20,10,10,20};
	vector<int> v(myints,myints+8);							// 10 20 30 30 20 10 10 20

	sort( v.begin(), v.end() );							// 10 10 10 20 20 20 30 30

	vector<int>::iterator low, up;
	low = lower_bound( v.begin(), v.end(), 20 );					//	    ^
	up = upper_bound( v.begin(), v.end(), 20 );					//		     ^

	cout<<"lower_bound at position "<<( low- v.begin() )<<'\n';
	cout<<"upper_bound at position "<<( up - v.begin() )<<'\n';
}

int main(){
	return 0;
}
