#include <iostream>

#define N 100010

using namespace std;

int a[N];

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int n = 0; cin >> n;

    for (int i = 1; i <= n; ++i){

        cin >> a[i];
    }

    //
    int result = 1;

    for (int i = 2; i <= n; ++i){

        if (a[i] < a[i - 1]){

            ++result;
        }
    }

    //
    cout << result << endl;

    return 0;
}