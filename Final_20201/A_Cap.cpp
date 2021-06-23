#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define N 101
#define INF 1e9

using namespace std;

//global variables

//functions
void solve(){
    
    //input
    int n, m, a[N], res = 0;

    cin >> n;
    for (int i = 0; i < n; i++){

        cin >> a[i];
    }

    //solution
    sort (a, a + n);

    cin >>m;
    for (int i = 0; i < m; i++){

        int b; cin >> b;

        if (binary_search(a, a + n, b)){

            ++res;
        }
    }

    //output
    cout << res << endl;    
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    int tc = 0;  cin >> tc;

    while(tc--){

        solve();
    }

    return 0;
}