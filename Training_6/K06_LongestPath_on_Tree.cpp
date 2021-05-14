#include <iostream>
#include <vector>

#define N 100010
#define INF 1e9

using namespace std;

struct edge{

    int u;
    int v;
    int w;

};

//Global Variables
int V = 0, result = -INF;

vector <edge> adj[N];
vector <int> dp(N, -INF);

//Functions
void dfs(int u, int p){

    dp[u] = 0;

    for (auto e : adj[u]){

        int v = e.v;
        int w = e.w;

        if (v == p) continue;

        dfs(v, u);

        result = max(result, dp[u] + w + dp[v]);

        dp[u] = max(dp[u], w + dp[v]);
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V;

    for (int i = 0; i < V - 1; ++i){

        int u, v, w;   cin >> u >> v >> w;

        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, w});
    }

    dfs(1, -1);

    cout << result << endl;    

    return 0;
}