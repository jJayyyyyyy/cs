#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int x, y;
	Node(int _x, int _y){
		x = _x;
		y = _y;
	}
};

int getD(int x1, int x2){
	if( x1 > x2 ){
		return x1 - x2;
	}else{
		return x2 - x1;
	}
}

bool isDiag(Node a, Node b){
	int X = getD(a.x, b.x);
	int Y = getD(a.y, b.y);
	return X == Y;
}

bool isLine(Node a, Node b){
	return a.y == b.y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, n, i, j, x, y, a, b;
	cin>>k;

	for( i = 0; i < k; ++i ){
		vector<Node> v;
		cin>>n;
		for( x = 1; x <= n; ++x ){
			cin>>y;
			Node node(x, y);
			v.push_back(node);
		}
		bool solution = true;
		for( a = 0; a < n; ++a ){
			for( b = a + 1; b < n; ++b ){
				if( isDiag(v[a], v[b]) ){
					solution = false;
					break;
				}
				if( isLine(v[a], v[b]) ){
					solution = false;
					break;
				}
			}
			if( solution == false ){
				break;
			}
		}
		if( solution == false ){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
	return 0;
}
