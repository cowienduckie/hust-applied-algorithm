#include <iostream>
#include <vector>
#include <limits>

#define ull unsigned long long

using namespace std;

//Global Variables

vector <int> v;

//List of functions
void combination(int L, int n, int r);
int n_choose_m(int max, int n, int m);

//Main
int main(int argc, char **argv){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0, m = 0, k = 0;  cin >> n >> m >> k;  v.resize(n + 1);


    //
    combination(k, n, m);
    
    //OUTPUT

    if (k <= n_choose_m(k, n, m)){

        for (int i = 1; i <= n; ++i){

            if (v[i] == 1){

                printf("%d ", i);
            }
        }

    }
    else  cout << -1;

    //cout << endl << n_choose_m(25, 15, 100000000);

    return 0;
}

//Functions
void combination(int k, int n, int m){

    int comb = 0, tmp = n;

    while (tmp > 0){

        if (tmp > m && m >= 0){

            comb = n_choose_m(k, tmp - 1, m);

            //cout << comb << endl;
        }
        else comb = 0;

        if (k < comb){ 

            v[n - tmp + 1] = 1;

            --m;
            k -= comb;
        }
        else v[n - tmp + 1] = 0;

        --tmp;
    }
}

int n_choose_m(int max, int n, int k){
    ull res = 1;

    for (ull d = 1; d <= k; ++d, --n){

        res = res * n / d;

        if (res > max){
            
            return INT_MAX;
        }
    }

    return res;
}
