#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAXINFO 1004
#define MAXSIZE 10004
using namespace std;

struct Info{
	int id, fID, mID, k;
	int chID[8];
	double mset, area;
	void set(int _id, int _fID, int _mID, int _k){
		id = _id;
		fID = _fID;
		mID = _mID;
		k = _k;
	}
};

struct Family{
	int rootID = -1;	// 代表家族的成员的编号
	int people = 0;		// 家族人数
	double totalSet = 0.0, totalArea = 0.0;
	double avgSet = 0.0, avgArea = 0.0;
};

Info info[MAXINFO];
Family family[MAXSIZE];
int father[MAXSIZE];
// 在输入一条info时，对marked[] 进行更新
// marked[i]为true，说明 i 在info的ID中出现过，可能是id, faID, moID, chID
// 用于寻找每个家庭的 rootID，进一步统计人数及资产情况
bool marked[MAXSIZE] = {false};

// 初始化
void initFather(){
	for( int i = 0; i < MAXSIZE; ++i ){
		father[i] = i;
	}
}

int findFather(int x){
	while( x != father[x] ){
		x = father[x];
	}
	return x;
}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if( faA > faB ){
		// 确保根节点的编号是最小的
		father[faA] = faB;
	}else{
		// 确保根节点的编号是最小的
		father[faB] = faA;
	}
}

int cmp(Family a, Family b){
	if( a.avgArea != b.avgArea ){
		return a.avgArea > b.avgArea;
	}else{
		return a.rootID < b.rootID;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, id, fID, mID, k, cID, rootID;
	cin>>n;
	initFather();

	for( i = 0; i < n; ++i ){
		cin>>id>>fID>>mID>>k;
		info[i].set(id, fID, mID, k);
		
		marked[id] = true;
		if( fID != -1 ){
			marked[fID] = true;
			Union(fID, id);
		}
		if( mID != -1 ){
			marked[mID] = true;
			Union(mID, id);
		}

		for( j = 0; j < k; ++j ){
			cin>>cID;
			info[i].chID[j] = cID;
			marked[cID] = true;
			Union(cID, id);
		}
		cin>>info[i].mset>>info[i].area;
	}

	// 先统计每个家族有多少人
	for( i = 0; i < MAXSIZE; ++i ){
		// marked[i]为true，说明在输入的信息中出现过
		if( marked[i] == true ){
			// 查找i的根节点，记为rootID
			rootID = findFather(i);
			// 家族人数++
			family[rootID].rootID = rootID;
			family[rootID].people++;
		}
	}
	
	// 然后累计各个家族的资产
	for( i = 0; i < n; ++i ){
		id = info[i].id;
		rootID = findFather(id);
		
		// 每个家族，以 rootID 为基准，在 ans[rootID] 中累计资产情况
		family[rootID].totalSet += info[i].mset;	// 套数
		family[rootID].totalArea += info[i].area;	// 面积
	}

	int cntFamily = 0, maxID = 0;
	for( i = 0; i < MAXSIZE; ++i ){
		int people = family[i].people;
		if( people > 0 ){
			// 家族成员数肯定为正，否则家族为空
			// 这里的i可以理解为某个家族的rootID
			cntFamily++;
			family[i].avgSet = family[i].totalSet / people;
			family[i].avgArea = family[i].totalArea / people;
			maxID = i;
		}
	}

	sort( family, family + maxID + 1, cmp);
	cout<<cntFamily<<'\n';
	for( i = 0; i < cntFamily; ++i ){
		cout<<setfill('0')<<setw(4)<<family[i].rootID<<' '<<family[i].people<<' ';
		cout.setf(ios::fixed);
		cout<<setprecision(3)<<family[i].avgSet<<' ';
		cout<<setprecision(3)<<family[i].avgArea<<'\n';
	}
	return 0;
}