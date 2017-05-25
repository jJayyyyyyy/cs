#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int string2double2string(const string &str1, double &num, string &str2){
	stringstream ss1, ss2;
	ss1<<str1;
	ss1>>num;
	ss2<<fixed<<setprecision(2)<<num;
	ss2>>str2;
	return 0;
}

int main(){
	int n, i=0, j=0, cnt=0;
	double sigma=0.0;

	cin>>n;
	for( i=0; i<n; i++ ){
		string numOut, numIn;
		double num=0.0;
		int isEqual = 1;

		cin>>numIn;

		string2double2string(numIn, num, numOut);
		for( j=0; j<numIn.size(); j++ ){
			if( numIn[j] != numOut[j] ){
				isEqual = 0;
			}
		}
		
		if( isEqual==0 || num<-1000 || num>1000 ){
			cout<<"ERROR: "<<numIn<<" is not a legal number\n";
		}else{
			sigma += num;
			cnt++;
		}
	}

	if( cnt > 1 ){
		cout<<"The average of "<<cnt<<" numbers is "<<fixed<<setprecision(2)<<sigma/cnt<<'\n';
	}else if( cnt == 1 ){
		cout<<"The average of 1 number is "<<fixed<<setprecision(2)<<sigma<<'\n';
	}else{
		cout<<"The average of 0 numbers is Undefined\n";
	}

	return 0;
}
