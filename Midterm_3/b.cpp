#include <iostream>
#include <algorithm>
#include <vector>

#define N 100010

using namespace std;

struct edge{

    int u;
    int v;
};

//Global Variables
int V = 0;

int dp[N], par[N];

vector <int> adj[N];
vector <edge> e(N);

//Functions
int count_child(int u, int p){

    int child = 0;

    for (int v: adj[u]){

        if (v == p) continue;

        child += count_child(v, u) + 1;

        par[v] = u;
    }

    dp[u] = child + 1;

    return child;
}

void update(int u, int v){

    if (v == 0) return;

    dp[v] -= dp[u];

    update(u, par[v]);
}

int root(int u){

    if (par[u] == 0) return u;

    return root(par[u]);
}

void solve(int c){

    int u = e[c].u, v = e[c].v;

    if (u == par[v]) swap(u, v);

    update(u, v);

    par[u] = 0;

    int r = root(v);

    cout << dp[r] * dp[u] << endl;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> V;

    for (int i = 1; i <= V - 1; ++i){

        int u, v;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        e[i] =  {u, v};
    }

    //
    count_child(1, 0);

    par[1] = 0;

    //
    int Q = 0;  cin >>  Q;

    for (int i = 1; i <= Q; ++i){

        int c = 0;  cin >> c;

        solve(c);
    }

    return 0;
}