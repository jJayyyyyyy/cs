#include <iostream>
#include <vector>
#include <queue>
#define MAXV 1004
using namespace std;

vector<int> G[MAXV];
bool visited[MAXV];
int lostCity;

void DFS(int city){
	if( city != lostCity ){
		visited[city] = true;
		for( int i=0; i<G[city].size(); i++ ){
			int nextCity = G[city][i];
			if( visited[nextCity] == false ){
				DFS(nextCity);
			}
		}
	}
}

void BFS(int city){
	if( city != lostCity ){
		queue<int> q;
		q.push(city);
		visited[city] = true;
		while( q.size() > 0 ){
			int next = q.front();
			q.pop();
			for( int i = 0; i < G[next].size(); ++i ){
				int id = G[next][i];
				if( visited[id] == false && id != lostCity ){
					q.push(id);
					visited[id] = true;
				}
			}
		}
	}
}

int main(){
	int cntCity, cntEdge, cntQuery, i, cityA, cityB, query;
	cin>>cntCity>>cntEdge>>cntQuery;
	for( i=0; i<cntEdge; i++ ){
		cin>>cityA>>cityB;
		G[cityA].push_back(cityB);
		G[cityB].push_back(cityA);
	}

	for( query = 0; query < cntQuery; ++query ){
		cin>>lostCity;
		fill( visited, visited+MAXV, false );
		int cntBlock = 0;
		for( int city = 1; city <= cntCity; ++city ){
			if( city != lostCity && visited[city] == false ){
				DFS(city);
				cntBlock++;
			}
		}
		cout<<cntBlock-1<<'\n';
	}
	return 0;
}