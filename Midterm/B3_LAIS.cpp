#include <iostream>
#include <vector>

using namespace std;

//Global Variables
int n = 0, res = 0;

vector <int> a;
vector <int> LAIS;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> n;  LAIS.resize(n + 1); a.resize(n + 1);

    for (int i = 1; i <= n; ++i){

        cin >> a[i];
    }

    for (int i = n; i >= 1; --i){

        LAIS[i] = 1;

        for (int j = i + 1; j <= n; ++j){

            if (a[j] * a[i] < 0 && abs(a[j]) > abs(a[i])){

                LAIS[i] = max(LAIS[i], LAIS[j] + 1);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i){

        res = max(res, LAIS[i]);
    }

    cout << res;

    return 0;
}