#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned long long a, b, c;
    cin >> a >> b;
    
    unsigned long long a1 = a % 10;
    unsigned long long a0 = (a - a1) / 10;
    unsigned long long b1 = b % 10;
    unsigned long long b0 = (b - b1) / 10;
    unsigned long long c0 = (a1 + b1) / 10;
    unsigned long long c1 = a1 + b1 - c0 * 10;
    
    c = a0 + b0 + c0;
    
    if (c > 0) cout << c;
    
    cout << c1;
    
    
    return 0;
}
