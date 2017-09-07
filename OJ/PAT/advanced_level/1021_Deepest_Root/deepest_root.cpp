#include <iostream>
#include <vector>
#include <set>
#define MAXSIZE 10004
using namespace std;

vector<int> G[MAXSIZE];
int father[MAXSIZE] = {0};
bool rootList[MAXSIZE] = {0};
int maxHeight = 0;
set<int> tmpSet, ansSet;
set<int>::iterator it;

int initFather(int n){
	for(int i=1; i<=n; i++){
		father[i] = i;
	}
	return 0;
}

int findFather(int node){
	int node1 = node;
	int node2 = node1;

	while( node != father[node] ){
		node = father[node];
	}

	int root = node;

	while( node1 != father[node1] ){
		node2 = node1;
		node1 = father[node1];
		father[node2] = root;
	}

	return root;
}

int Union(int node1, int node2){
	int fa1 = findFather(node1);
	int fa2 = findFather(node2);
	if( fa1 != fa2 ){
		father[fa1] = fa2;
	}
	return 0;
}

int getComponent(int n){
	int component = 0;
	for( int i=1; i<=n; i++ ){
		rootList[ findFather(i) ] = true;
	}

	for( int i=1; i<=n; i++ ){
		if( rootList[i] == true ){
			component += 1;
		}
	}
	return component;
}

int DFS(int node, int height, int preNode){
	if( height > maxHeight ){
		tmpSet.clear();
		tmpSet.insert(node);
		maxHeight = height;
	}else if(height == maxHeight){
		tmpSet.insert(node);
	}

	for( int i=0; i<G[node].size(); i++ ){
		if( G[node][i] == preNode ){
			continue;
		}else{
			DFS(G[node][i], height+1, node);
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, node1, node2;
	cin>>n;
	
	if( n == 1 ){
		cout<<"1\n";
	}else{
		initFather(n);

		for(i=1; i<n; i++){
			cin>>node1>>node2;
			G[node1].push_back(node2);
			G[node2].push_back(node1);
			Union(node1, node2);
		}

		int component = getComponent(n);
		if( component > 1 ){
			cout<<"Error: "<<component<<" components\n";
		}else{
			DFS(1, 1, -1);
			ansSet = tmpSet;
			it = ansSet.begin();
			DFS(*it, 1, -1);

			ansSet.insert( tmpSet.begin(), tmpSet.end() );
			
			for( it=ansSet.begin(); it!=ansSet.end(); it++ ){
				cout<<*it<<'\n';
			}
		}
	}
	
	return 0;
}
