#include <iostream>
#include <queue>
#define ZSIZE 64
#define XSIZE 1300
#define YSIZE 160
using namespace std;

struct Node{
	int z, x, y;
	Node(int _z, int _x , int _y){
		z = _z;
		x = _x;
		y = _y;
	}
};

int m, n, slice, th;
int pixel[ZSIZE][XSIZE][YSIZE];	// 内存够用，尽量选int，比bool要快一些
bool inq[ZSIZE][XSIZE][YSIZE] = {false};

int incZ[6] = {1, -1, 0, 0, 0, 0};
int incX[6] = {0, 0, 1, -1, 0, 0};
int incY[6] = {0, 0, 0, 0, 1, -1};

bool judge(int z, int x, int y){
	if( z >= slice || z < 0 || x >= m || x < 0 || y >= n || y < 0 ){
		return false;
	}
	if( pixel[z][x][y] == 0 || inq[z][x][y] == true ){
		return false;
	}
	return true;
}

int BFS(int z, int x, int y){
	int volume = 0;
	queue<Node> q;
	Node node(z, x, y);
	q.push(node);
	inq[z][x][y] = true;

	while( q.size() ){
		Node now = q.front();
		q.pop();
		++volume;
		for( int i=0; i<6; ++i ){
			int newZ = now.z + incZ[i];
			int newX = now.x + incX[i];
			int newY = now.y + incY[i];
			if( judge(newZ, newX, newY) ){
				Node n(newZ, newX, newY);
				q.push(n);
				inq[newZ][newX][newY] = true;
			}
		}
	}

	if( volume >= th ){
		return volume;
	}else{
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>m>>n>>slice>>th;
	
	for( int z=0; z < slice; ++z ){
		for( int x=0; x<m; ++x){
			for(int y=0; y<n; ++y){
				cin>>pixel[z][x][y];	// 坐标形式要注意，首先是第z层，然后是该层内的坐标[row][col]，即[x][y]
			}
		}
	}
	
	int totalVolume=0;

	for( int z=0; z < slice; ++z ){
		for( int x=0; x<m; ++x){
			for(int y=0; y<n; ++y){
				if( pixel[z][x][y] == 1 && inq[z][x][y] == false ){
					totalVolume += BFS(z, x, y);
				}
			}
		}
	}

	cout<<totalVolume<<'\n';

	return 0;
}