#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned long long a, b;
	
	cin >> a >> b;
	
	cout << (a% 1000000007 + b% 1000000007) % 1000000007;
	
	return 0;
}
