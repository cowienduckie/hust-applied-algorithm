#include <iostream>
#include <vector>
#include <algorithm>

#define N 1010

using namespace std;

//Global Variables
long long x[N], y[N];

//Functions
long long product(int n){
    
    long long result = 0;

    for (int i = 0; i < n; ++i){

        result += x[i] * y[i];
    }

    return result;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int tc = 0, cn = 1;  cin >> tc;

    while (tc--){

        int n = 0; cin >> n;  long long result = 0;

        for (int i = 0; i < n; ++i){

            cin >> x[i];
        }
        for (int i = 0; i < n; ++i){

            cin >> y[i];
        }

        //
        sort(x, x + n);
        sort(y, y + n, greater<long long>());

        result = product(n);

        cout << "Case #" << cn++ << ": " << result << endl;          
    }    

    return 0;
}