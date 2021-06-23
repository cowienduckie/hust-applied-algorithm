#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define N 100010
#define INF 1e9

using namespace std;

//global variables
int a[N], LIS[N];

//functions
void solve()
{
    //input
    int n, res = 0;  cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    //solution
    for (int i = n; i >= 1; --i)
    {
        LIS[i] = 1;

        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] + 1 == a[j] && LIS[i] < 1 + LIS[j])
            {
                LIS[i] = 1 + LIS[j];
            }
        }

        res = max(res, LIS[i]);
    }

    //output
    cout << res << endl;
}

//
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    int tc = 0;  cin >> tc;

    while(tc--)
    {
        solve();
    }

    return 0;
}