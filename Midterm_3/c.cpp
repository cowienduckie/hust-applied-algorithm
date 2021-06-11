#include <iostream>
#include <algorithm>
#include <vector>

#define N 1000010

using namespace std;

long long n, a[N], order[N], l[N], r[N];


int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> n;

    for (int i = 1; i <= n; ++i){

        cin >> a[i];

        order[i] = i;
        l[i] = i - 1;
        r[i] = i + 1;
    }

    auto compare = [](int i, int j){

        if (a[i] == a[j]) return i < j;

        return a[i] > a[j];
    };

    sort (order + 1, order + n + 1, compare);

    long long res = 0;

    for (int j = 1; j <= n; ++j){

        int i = order[j];

        res += a[i] + a[l[i]] + a[r[i]];

        l[r[i]] = l[i];
        r[l[i]] = r[i];
    }

    cout << res << endl;

    return 0;
}