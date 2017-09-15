// PAT_B_1062, 1034
// PAT_A_1081

// 最大公因数, the Greatest Common Divisor
int get_gcd(int a, int b){
	if( b == 0 ){
		return a;
	}else{
		return get_gcd(b, a % b);
	}
}

// 最小公倍数, the Lowest Common Multiple
int get_lcm(int a, int b){
	int gcd = get_gcd(a, b);
	if( gcd != 0 ){
		return a * b / gcd;
	}else{
		return 0;
	}
}
