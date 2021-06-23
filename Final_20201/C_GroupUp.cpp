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
int a[N];

//functions
void solve()
{   
    //input
    int n;  cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    //solution
    int step = 1, res = 0;

    while (step + 1 <= n)
    {   
        int time = 0;
        for (int i = 1; i <= n; i += 2 * step)
        {
            if (i + step <= n)
            {
                a[i] += a[i + step];
                time = max(time, a[i]);
            }
        }

        //update
        res += time;
        step *= 2;
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