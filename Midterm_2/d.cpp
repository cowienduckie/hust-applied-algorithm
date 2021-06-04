#include <iostream>
#include <vector>
#include <algorithm>

#define N 100010

using namespace std;

//Global variables
long long a[N], dp[N];

bool mark[N];
vector <int> imem;

//Functions
long long brute(int i, int n){

    if (i > n) return 0;

    if (mark[i] == true) return dp[i];

    mark[i] = true;

    dp[i] = max(brute(i + 1, n), a[i] + brute(i + 2, n));

    return dp[i];
}

void trace(int i, int n){

    if (i > n || dp[i] == 0) return;    //Dung lai khi dp[i] = 0
                                        //Boi vi khi nay cac so tiep theo <= 0

    if (dp[i] == a[i] + dp[i + 2]){

        trace(i + 2, n);

        imem.push_back(i);
    }
    else if(dp[i] == dp[i + 1]){

        trace(i + 1, n);
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0;  cin >> n;

    for (int i = 1; i <= n; ++i){
        
        cin >> a[i];
    }

    //
   

    //OUTPUT
    cout << brute(1, n) << endl;

    trace(1, n);

    reverse(imem.begin(), imem.end());

    cout << imem.size() << endl;

    for (auto i : imem){

        cout << i << " ";
    }
   
    return 0;
}