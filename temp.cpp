#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define N 1000
#define INF 1e9

using namespace std;

//global variables
string s;
int n = 0, res = 0;

//functions
bool check()
{
    stack <char> st;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if (st.empty())  return false;
            else
                st.pop();   
        }
    }

    if (!st.empty()) return false;
    else
        return true;
}

void brCount(int i)
{
    if (i == n)
    {
        if (check())  ++res;
        return;
    }

    s[i] = ')';
    brCount(i + 1);

    s[i] = '(';
    brCount(i + 1);
}

void solve()
{
    brCount(0);

    cout << res << endl;
}

//
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        s += "?";
    }

    solve();

    return 0;
}