#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	long long max;
	cin >> n;
	int arr[n];
	int s[n];
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	s[0] = arr[0];
	max = s[0];

	for (int i = 1; i < n; ++i){
		if (s[i-1] > 0) s[i] = s[i-1] + arr[i];
		else s[i] = arr[i];
		max = max > s[i] ? max : s[i];
	}
	
	cout << max;
	
	return 0;
}
