#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define N 1010
#define INF 1e9

using namespace std;

//global variables
string s;
int n;
vector <vector <int>> dp(N, vector <int> (N, -1));

//functions
int brCount(int i, int st) //i -> index | st -> remaining open brackets in stack
{   
    if (i == n)
    {
        if (st == 0) return 1;
        else
            return 0;
    }

    if (st < 0) return 0;

    if (dp[i][st] != -1)  return dp[i][st];

    int res = 0;

    if (s[i] == '(')
    {
        res = brCount(i + 1, st + 1) % mod;
    }
    else if (s[i] == ')')
    {
        res = brCount(i + 1, st - 1) % mod;
    }
    else
    {
        res += brCount(i + 1, st + 1) % mod;

        res += brCount(i + 1, st - 1) % mod;
    }

    dp[i][st] = res % mod;

    return res % mod;
}

void solve()
{
    getline(cin, s);
    n = s.length();

    cout << brCount(0, 0) << endl;
}

//
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    solve();

    return 0;
}