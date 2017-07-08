#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 100000000
#define MAXCITY 504
#define NOTFOUND -1
using namespace std;

int cntCity, cntRoad, srcID, destID;
int G[MAXCITY][MAXCITY];		// G[i][j] is edgeWeight between i and j
int shortestPath[MAXCITY];		// we want min/shortest of shortestPath
int ownTeam[MAXCITY];			// every city has its own rescue team
int totalTeam[MAXCITY];			// total team gathered from the shortest path
int cntShortestPath[MAXCITY];	// there could be several paths that have the shortest distance from src to dest
bool marked[MAXCITY];

int Dijkstra(){
	fill(shortestPath, shortestPath+MAXCITY, INF);
	fill(totalTeam, totalTeam+MAXCITY, 0);
	fill(cntShortestPath, cntShortestPath+MAXCITY, 0);
	fill(marked, marked+MAXCITY, false);

	
	shortestPath[srcID] = 0;
	cntShortestPath[srcID] = 1;
	totalTeam[srcID] = ownTeam[srcID];

	for( int i=0; i<cntCity; i++ ){
		int dist = INF;
		int midCity = NOTFOUND;
		// find the closest unmarked city, then its ID is midCity
		for( int j=0; j<cntCity; j++ ){
			if( marked[j]==false && shortestPath[j]<dist ){
				dist = shortestPath[j];
				midCity = j;
			}
		}

		if( midCity == NOTFOUND ){
			return NOTFOUND;
		}else{
			marked[midCity] = true;
			for( int j=0; j<cntCity; j++ ){
				if( marked[j]==false && G[midCity][j]!=INF ){
					// we find a shorter path 
					if( shortestPath[midCity] + G[midCity][j] < shortestPath[j] ){
						shortestPath[j] = shortestPath[midCity] + G[midCity][j];
						totalTeam[j] = totalTeam[midCity] + ownTeam[j];
						cntShortestPath[j] = cntShortestPath[midCity];
					}
					// this path is equally short
					else if( shortestPath[midCity] + G[midCity][j] == shortestPath[j] ){
						// we need the largest num of teams
						if( totalTeam[midCity] + ownTeam[j] > totalTeam[j] ){
							totalTeam[j] = totalTeam[midCity] + ownTeam[j];
						}
						cntShortestPath[j] += cntShortestPath[midCity];
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	cin>>cntCity>>cntRoad>>srcID>>destID;
	fill(G[0], G[0] + MAXCITY*MAXCITY, INF);	// G is a 2-D array. so fill() should be used in this form

	for(int i=0; i<cntCity; i++){
		cin>>ownTeam[i];
	}

	int a, b;
	for(int i=0; i<cntRoad; i++){
		cin>>a>>b;
		cin>>G[a][b];
		G[b][a] = G[a][b];
	}

	Dijkstra();

	cout<<cntShortestPath[destID]<<' '<<totalTeam[destID]<<'\n';
	return 0;
}