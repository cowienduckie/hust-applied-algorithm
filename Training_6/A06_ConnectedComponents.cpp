#include <iostream>
#include <vector>
#include <algorithm>

#define N 100010

using namespace std;

vector <int> adj[N];
vector <int> mark(N);

int V = 0, E = 0;

void dfs(int u){

    mark[u] = 1;

    for (int v : adj[u]){

        if (mark[v] == -1){

            dfs(v);
        }
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    fill(mark.begin(), mark.end(), -1);

    for (int i = 0; i < E; ++i){

        int u, v;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = 0;

    for (int u = 1; u <= V; ++u){

        if (mark[u] == -1){

            dfs(u);
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}