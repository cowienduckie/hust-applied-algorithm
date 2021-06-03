#include <iostream>

#define N 20010

using namespace std;

long long a[N];
long long result = 0;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int n = 0, m = 0, M = 0;  cin >> n >> m >> M;

    for (int i = 0; i < n; ++i){

        cin >> a[i];
    }

    for (int i = 0; i < n; ++i){

        long long sum =  0;

        for (int j = i; j < n; ++j){

            sum += a[j];

            if (sum >= m && sum <=M){

                ++result;
            }
        }
    }

    cout << result << endl;

    return 0;
}