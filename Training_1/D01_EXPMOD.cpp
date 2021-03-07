#include <bits/stdc++.h>

using namespace std;

int pow (unsigned long long &a, unsigned long long &b, int p){ //(a ^ b) mod p
	int res = 1;
	
	a = a % p;
	
	while (b > 0){
		if (b & 1){ //if b is odd, multiply a with res -> b = b-1 is even
			res = (res * a) % p;
		}
		
		b = b >> 1; //b = b/2
		a = (a * a) % p;
	}
	
	return res;
}

int main() {
	unsigned long long a, b;
	
	cin >> a >> b;
	
	cout << pow(a, b, 1000000007);
	
	return 0;
}
