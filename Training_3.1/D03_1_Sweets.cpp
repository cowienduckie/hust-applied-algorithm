#include <iostream>
#include <cmath>

#define ull unsigned long long

#define m 1000000007

using namespace std;

ull modulo_inverse(ull x, int n){

    x = x % m;

    if (n == 1) return x;

    if (n % 2 == 0){

        return modulo_inverse((x * x) % m, n / 2) % m;
    }
    else{
        
        return modulo_inverse((x * x) % m, n / 2) * x % m;
    }
}

ull fact(int stop , int n){

    if (n == stop){

        return 1;
    }

    return n * fact(stop, n - 1) % m;
}

ull ifact(int n){

    if (n == 1){
        return 1;
    }

    return modulo_inverse(n, m - 2) * ifact(n - 1) % m;
}

ull  comb(ull k, ull n){

    if (k > n - k) k = n - k;

    return fact(n - k, n) * ifact(k) % m;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0, k = 0; cin >> n >> k;

    //OUTPUT
    cout << comb(k - 1, n + k - 1);

    return 0;
}