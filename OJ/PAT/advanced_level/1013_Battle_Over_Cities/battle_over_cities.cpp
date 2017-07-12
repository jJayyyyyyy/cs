#include <iostream>
#include <vector>
#include <algorithm>
#define MAXV 1004
using namespace std;

vector<int> G[MAXV];
bool marked[MAXV];
int lostCity;

int DFS(int city){
	if( city == lostCity ){
		return 0;
	}

	marked[city] = true;
	for( int i=0; i<G[city].size(); i++ ){
		int nextCity = G[city][i];
		if( marked[nextCity] == false ){
			DFS(nextCity);
		}
	}
	return 0;
}

int main(){
	int cntCity, cntEdge, cntQuery, i, cityA, cityB, query;

	cin>>cntCity>>cntEdge>>cntQuery;

	for( i=0; i<cntEdge; i++ ){
		cin>>cityA>>cityB;
		G[cityA].push_back(cityB);
		G[cityB].push_back(cityA);
	}

	for( query=0; query<cntQuery; query++ ){
		cin>>lostCity;
		fill( marked, marked+MAXV, false );
		int cntBlock = 0;
		for( int city=1; city<=cntCity; city++ ){
			if( city != lostCity && marked[city] == false ){
				DFS(city);
				cntBlock++;
			}
		}
		cout<<cntBlock-1<<'\n';
	}
	

	return 0;
}