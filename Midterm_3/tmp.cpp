#include <iostream>
#include <algorithm>
#include <vector>

#define N 1000010

using namespace std;

//Global Variables
int n, a[N];

//Functions


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> n;

    for (int i = 1; i <= n; ++i){

        cin >> a[i];
    }

    a[n + 1] = 0; a[0] = 0;

    //
    unsigned long long res = 0;

    for (int shot = 1; shot <= n; ++shot){

        int i = (max_element(a + 1, a + n + 1) - a);

        int j = i - 1, k = i + 1; // ... j .. i .. k ...

        while (j > 0 && a[j] == 0){

            --j;
        }

        while (k <= n && a[k] == 0){

            ++k;
        }

        res += 1ull * ( a[i] + a[j] + a[k] );

        a[i] = 0;
    }
    
    cout << res << endl;

    return 0;
}