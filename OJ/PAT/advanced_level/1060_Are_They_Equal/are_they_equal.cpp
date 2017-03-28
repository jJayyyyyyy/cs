#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Numb{
public:
	string sigDigits;
	int posDecimal;
	int digitLen;
	int expo;
	Numb(string strNum, int n){
		if( strNum=="0"){
			// num == 0
			string zero(n, '0');
			sigDigits = zero;
			expo = 0;
			posDecimal = 0;
		}else if( strNum[0]=='0' && strNum[1]=='.' ){
			// 0<num<1
			strNum = strNum.substr(2);
			int firstIdx = strNum.find_first_not_of('0');
			sigDigits = strNum.substr(firstIdx);
			expo = -firstIdx;
			int digitLen = sigDigits.size();
			if( digitLen<n ){
				sigDigits.insert( digitLen, n - digitLen, '0' );
			}else{
				sigDigits.erase( n, digitLen - n );
			}
		}else{
			// num >= 1
			posDecimal = strNum.find('.');
			digitLen = strNum.size();
			if( posDecimal!=string::npos ){
				// has decimal
				expo = posDecimal;
				sigDigits = strNum.erase( posDecimal, 1 );
			}else{
				// no decimal
				expo = digitLen;
				sigDigits = strNum;
			}

			if( digitLen<n ){
				sigDigits.insert( digitLen, n - digitLen, '0' );
			}else{
				sigDigits.erase( n, digitLen - n );
			}
		}
		// cout<<oriStrNum<<' '<<strNum<<' '<<sigDigits<<' '<<posDecimal<<' '<<digitLen<<' '<<expo<<'\n';
	}

	string getSigDigit(){
		return sigDigits;
	}

	int getExpo(){
		return expo;
	}
};

string double2str(double num){
	stringstream ss;
	string s;

	ss.setf(ios::fixed);
	ss<<num;
	ss>>s;
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	double n1, n2;
	cin>>n>>n1>>n2;
	string s1, s2;
	s1 = double2str(n1);
	s2 = double2str(n2);
	// cout<<s1<<'\t'<<s2<<'\n';
	Numb num1( s1, n ), num2( s2, n );

	string sigDigit1 = num1.getSigDigit();
	int expo1 = num1.getExpo();


	string sigDigit2 = num2.getSigDigit();
	int expo2 = num2.getExpo();


	if( expo1==expo2 && sigDigit1==sigDigit2 ){
		cout<<"YES";
		cout<<" 0."<<sigDigit1<<"*10^"<<expo1;
	}else{
		cout<<"NO";
		cout<<" 0."<<sigDigit1<<"*10^"<<expo1;
		cout<<" 0."<<sigDigit2<<"*10^"<<expo2;
	}

	// 3 12345 12344.5
	// 5 123.4 123456.7
	// 4 123.4 123456.7
	// 5 123.4 123456.7
	
	// 3 12345.6 12345.6
	// 3 0 0
	// 3 0.1 0.12

	// 4 0000 0000.00
	// 4 00123.5678 0001235
	// 3 0.0520 0.0521
	// 4 00000.000000123 0.0000001230
	return 0;
}