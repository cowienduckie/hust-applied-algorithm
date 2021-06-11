#include <iostream>
#include <algorithm>
#include <vector>

#define N 1010

using namespace std;

int n, adj[N][N];


int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> n;

    int res = 1;

    for (int i = 1; i <= n; ++i){

        bool flag = false;

        for (int j =  1; j <= n; ++j){

            cin >> adj[i][j];

            if (adj[i][j] == 0 && i != j){

                res = 0;

                flag = true;

                break;
            }
        }

        if (flag)  break;
    }

    //
    cout << res << endl;

    //

    return 0;
}