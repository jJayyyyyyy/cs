#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define MAXRECORDS 10004
#define MAXQUERIES 80004
using namespace std;

struct Record{
	string id, time; 
	int onCampus;
	Record(){
		id = time = "";
		onCampus = 0;
	}
	int set(string &_id, string &_time, string &_onCampus){
		id = _id;
		time = _time;
		if( _onCampus == "in" ){
			onCampus = 1;
		}else{
			onCampus = -1;
		}
		return 0;
	}
	int getTime(){
		int h = stoi(time.substr(0, 2));
		int m = stoi(time.substr(3, 2));
		int s = stoi(time.substr(6, 2));
		return 3600*h + 60*m + s;
	}
};

vector<Record> records(MAXRECORDS);
vector<Record> validRecords;
map<string, int> cntTime;
map<string, int>::iterator it;
int currentCars[MAXRECORDS] = {0};

int cmp1(const Record &r1, const Record &r2){
	if( r1.id != r2.id ){
		return r1.id < r2.id;
	}else{
		return r1.time < r2.time;
	}
}

int cmp2(const Record &r1, const Record &r2){
	return r1.time < r2.time;
}

int getStandardTime(int second){
	int h = second/3600;
	second %= 3600;
	int m = second/60;
	int s = second % 60;

	cout<<setfill('0')<<setw(2)<<h<<':';
	cout<<setfill('0')<<setw(2)<<m<<':';
	cout<<setfill('0')<<setw(2)<<s;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k, i;
	int maxTime = 0;
	string id, time, onCampus;

	cin>>n>>k;

	for( i=0; i<n; i++ ){
		cin>>id>>time>>onCampus;
		records[i].set(id, time, onCampus);
	}

	// cout<<'\n';
	// for( i=0; i<n; i++ ){
	// 	cout<<records[i].id<<' '<<records[i].time<<' '<<records[i].onCampus<<'\n';
	// }
	// cout<<'\n';

	sort(records.begin(), records.begin()+n, cmp1);

	for( i=0; i<n-1; ){
		if( records[i].id == records[i+1].id && records[i].onCampus == 1 && records[i+1].onCampus == -1 ){
			// is valid record
			validRecords.push_back(records[i]);
			validRecords.push_back(records[i+1]);

			// update cntTime
			if( cntTime.find(records[i].id) != cntTime.end() ){
				cntTime[ records[i].id ] += records[i+1].getTime() - records[i].getTime();
			}else{
				cntTime[ records[i].id ] = records[i+1].getTime() - records[i].getTime();
			}

			// update maxTime
			if( maxTime < cntTime[ records[i].id ] ){
				maxTime = cntTime[ records[i].id ];
			}

			i+=2;
		}else{
			// is invalid record
			++i;
		}
	}

	sort(validRecords.begin(), validRecords.end(), cmp2);

	currentCars[0] = 1;
	for( i=1; i<validRecords.size(); i++ ){
		// in means +1, out means -1
		currentCars[i] = currentCars[i-1] + validRecords[i].onCampus;
	}

	// for( i=0; i<validRecords.size(); i++ ){
	// 	cout<<validRecords[i].id<<' '<<validRecords[i].time<<' '<<validRecords[i].onCampus<<'\n';
	// }

	// cout<<maxTime<<'\n';
	string query;
	for( i=0; i<k; i++ ){
		cin>>query;
		int j, prev;
		for( j=prev; j<validRecords.size(); j++ ){
			if( query < validRecords[j].time ){
				cout<<currentCars[j-1]<<'\n';
				break;
			}else if( j == validRecords.size()-1 ){
				cout<<currentCars[j]<<'\n';
			}
		}
		prev = j;
	}

	for( it=cntTime.begin(); it!=cntTime.end(); it++ ){
		if( it->second == maxTime ){
			cout<<it->first<<' ';
		}
	}
	getStandardTime(maxTime);
	
	return 0;
}
