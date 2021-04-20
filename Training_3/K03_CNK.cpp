#include <iostream>

#define ull unsigned long long

using namespace std;

//Global Variables
ull m = 0;

//Functions
ull pow(ull x, ull n){

    x = x % m;

    if (n == 1) return x;

    if (n & 1)  return ((pow((x * x) % m, n / 2) % m) * x) % m;
    else 
        return pow((x * x) % m, n / 2) % m;
}

ull bignumMultiply(ull a, ull b){

    ull res = 0;

    a = a % m;

    while(b){

        if (b & 1)  res = (res + a) % m;

        a = (a * 2) % m;

        b = b >> 1;
    }

    return res;
}

ull bignumPow(ull x, ull n){

    x = x % m;

    if (n == 1) return x;

    if (n & 1)  return bignumMultiply(bignumPow(bignumMultiply(x, x), n / 2), x);
    else 
        return bignumPow(bignumMultiply(x, x), n / 2) % m; 
}

ull n_choose_k(ull n, ull k){

    if (k > n - k)  k = n - k;

    ull result = 1;

    if (m <= 1e9 + 7){

        for (ull i = k; i >= 1; --i){

            result = ((result % m) * (i % m)) % m;
        }

        result = pow(result, m - 2) % m;

        for (ull i = n - k + 1; i <= n; ++i){

            result = ((result % m) * (i % m)) % m;
        }
    }
    else{

        for (ull i = k; i >= 1; --i){

            result = bignumMultiply(result, i);
        }

        result = bignumPow(result, m - 2);

        for (ull i = n - k + 1; i <= n; ++i){

            result = bignumMultiply(result, i);
        }
    }

    return result % m;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int test_case = 0;  cin >> test_case;

    //n choose k mod m
    while(test_case--){  

        ull n = 0, k = 0;

        cin >> n >> k >> m;

        cout << n_choose_k(n, k) << endl;
    }


    return 0;
}