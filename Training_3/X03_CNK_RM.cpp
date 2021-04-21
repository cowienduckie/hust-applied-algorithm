#include <iostream>

#define ull unsigned long long
#define m 1000000007

using namespace std;

//Functions
ull pow(ull x, ull n){

    x = x % m;

    if (n == 1) return x;

    if (n & 1)  return ((pow((x * x) % m, n / 2) % m) * x) % m;
    else 
        return pow((x * x) % m, n / 2) % m;
}

ull n_choose_k(ull n, ull k){

    if (k > n - k)  k = n - k;

    ull result = 1;

    for (ull i = k; i >= 1; --i){

        result = ((result % m) * (i % m)) % m;
    }

    result = pow(result, m - 2) % m;

    for (ull i = n - k + 1; i <= n; ++i){

        result = ((result % m) * (i % m)) % m;
    }
    

    return result % m;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ull n = 0, k = 0;  cin >> k >> n;

    cout << n_choose_k(n, k) << endl;

    return 0;
}