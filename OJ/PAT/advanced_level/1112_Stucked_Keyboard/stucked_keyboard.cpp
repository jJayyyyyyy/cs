#include <iostream>
#include <string>
#include <set>
using namespace std;

bool sureNotBroken[160] = {false};
bool sureBroken[160] = {false};
set<char> printed;

int main() {
	int k, i, cnt = 1;
	string s, sEnd;
	cin>>k>>s;
	
	char pre='^', cursor;
	sEnd = s + '$';

	for( i=0; i<sEnd.length(); i++ ){
		cursor = sEnd[i];
		if( cursor == pre ){
			cnt++;
		}else{
			if( cnt % k != 0 ){
				sureNotBroken[pre] = true;
			}
			cnt = 1;
		}

		if( i != sEnd.length() - 1 ){
			if( cnt % k == 0 ){
				sureBroken[cursor] = true;
			}
		}
		pre = cursor;
	}

	for( i=0; i<s.length(); i++ ) {
		cursor = s[i];
		if( sureNotBroken[cursor] == true ){
			sureBroken[cursor] = false;
		}
	}

	for( i=0; i<s.length(); i++ ) {
		cursor = s[i];
		if( sureBroken[cursor] == true ){
			if( printed.find(cursor) == printed.end() ){
				cout<<cursor;
				printed.insert(cursor);
			}
		}
	}
	
	cout<<"\n";

	for( i=0; i<s.length(); ){
		cursor = s[i];
		cout<<cursor;
		if( sureBroken[cursor] == true ){
			i = i + k;
		}else{
			i = i + 1;
		}
	}

	return 0;
}
