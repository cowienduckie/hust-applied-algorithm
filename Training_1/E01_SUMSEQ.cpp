#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 0, sum = 0, p = 1000000007;	cin >> n;
	int arr[n];
	
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
		sum = (sum + arr[i] % p) %p;
	}	
	
	cout << sum;
	
	return 0;
}
