#include <iostream>


using namespace std;

//Global Variables
int X[10001], Y[10001], LCS[10001][10001];

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0, m = 0;  cin >> n >> m;

    for (int i = 1; i <= n; ++i)  cin >> X[i];
    for (int i = 1; i <= m; ++i)  cin >> Y[i];

    //
    for (int i = 0; i <= n; ++i){

        for (int j = 0; j <= m; ++j){

            if (i == 0 || j == 0)  

                LCS[i][j] = 0;

            else if (X[i] == Y[j])

                LCS[i][j] = 1 + LCS[i - 1][j -1];

            else
                LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
        }
    }
    

    //OUTPUT
    cout << LCS[n][m];


    return 0;
}