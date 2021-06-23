//Greedy strategy
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define N 52
#define INF 1e9

using namespace std;

//global variables
int n, Q, d[N][N], a[N];

int value_order[N];
bool visited[N];

vector <int> result;
int len = INF;

//functions
void greedy1()  //nearest first
{
    fill(visited, visited + n + 1, false);

    vector <int> res;
    int target = Q, u = 0, tmp_len = 0;

    while (target > 0)
    {
        int v = 0, minim = INF;

        for (int i = 1; i <= n; ++i){

            if (visited[i])  continue;

            if (minim > d[u][i])
            {
                v = i;
                minim = d[u][i];
            }
        }

        tmp_len += d[u][v];
        target -= a[v];
        visited[v] = true;
        res.push_back(v);  
        u = v;          
    }

    tmp_len += d[u][0];

    if (tmp_len < len)
    {
        len = tmp_len;
        result = res;
    }
}

void greedy2()  //value first
{
    vector <int> res;
    int target = Q;
    int tmp_len = 0;

    auto comp = [](int &i, int &j){

        return a[i] > a[j];
    };

    sort (value_order + 1, value_order + n + 1, comp);

    for (int i = 1; i <= n; ++i)
    {
        target -= a[value_order[i]];

        res.push_back(value_order[i]);

        tmp_len += d[value_order[i - 1]][value_order[i]];

        if (target <= 0){

            tmp_len += d[value_order[i]][0];

            if (tmp_len < len){

                len = tmp_len;
                result = res;
            }

            break;
        }
    }
}

void greedy3()  //value on distance first (then value)
{
    fill(visited, visited + n + 1, false);

    vector <int> res;
    int target = Q, u = 0, tmp_len = 0;

    while (target > 0)
    {
        int v = 0;
        double maxim = 0;

        for (int i = 1; i <= n; ++i){

            if (visited[i])  continue;

            double val_on_dist = (double)min(a[i], target) / d[u][i];

            if (maxim < val_on_dist)
            {
                v = i;
                maxim = val_on_dist;
            }
            else if(maxim == val_on_dist && a[i] > a[v])
            {
                v = i;
                maxim = val_on_dist;
            }
        }

        tmp_len += d[u][v];
        target -= a[v];
        visited[v] = true;
        res.push_back(v);  
        u = v;          
    }

    tmp_len += d[u][0];

    if (tmp_len < len)
    {
        len = tmp_len;
        result = res;
    }
}

void greedy4()  //value on distance first (then distance)
{
    fill(visited, visited + n + 1, false);

    vector <int> res;
    int target = Q, u = 0, tmp_len = 0;

    while (target > 0)
    {
        int v = 0;
        double maxim = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (visited[i])  continue;

            double val_on_dist = (double)min(a[i], target) / d[u][i];

            if (maxim < val_on_dist)
            {
                v = i;
                maxim = val_on_dist;
            }
            else if(maxim == val_on_dist && d[u][i] < d[u][v])
            {
                v = i;
                maxim = val_on_dist;
            }
        }

        //update
        tmp_len += d[u][v];
        target -= a[v];
        visited[v] = true;
        res.push_back(v);  
        u = v;          
    }

    tmp_len += d[u][0];

    if (tmp_len < len)
    {
        len = tmp_len;
        result = res;
    }
}

void solve()
{   
    //input
    cin >> n >> Q;

    a[0] = 0;
    value_order[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        value_order[i] = i;
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cin >> d[i][j];
        }
    }

    //solution
    greedy1();
    greedy2();
    greedy3();
    greedy4();

    //output
    if (len == INF)
    {
        cout << -1 << endl;
        return;
    }

    cout << len << endl;
    cout << result.size() << endl;

    for (int i : result){

        cout << i << " ";
    }
}

//
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    int tc = 1;  //cin >> tc;

    while(tc--)
    {
        solve();
    }

    return 0;
}