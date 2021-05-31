#include <iostream>
#include <vector>

#define N 10010
#define INF 1e9

using namespace std;

//Global Variables
int V = 0, E = 0;

vector <int> adj[N];
vector <int> d(N, 0);
vector <bool> mark(N, false);

//Functions
long long dfs(int u){

    if (mark[u] == true) return 0;

    mark[u] = true;

    long long res = INF;

    for (int v : adj[u]){

        res = min(dfs(v), res);
    }

    return res + d[u];
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    for (int u = 1; u <= V; ++u){

        cin >> d[u];
    }

    for (int i = 0; i < E; ++i){

        int u = 0, v = 0;  cin >> v >> u;

        adj[u].push_back(v);
    }
    
    //
    long long result = 0;

    for (int u = 1; u <= V; ++u){

        if (mark[u] == false){

            result = max(result,dfs(u));
        }
    }

    //OUTPUT
    cout << result << endl;

    return 0;
}