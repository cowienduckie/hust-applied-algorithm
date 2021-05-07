#include <iostream>
#include <vector>
#include <algorithm>

#define N 100010

using namespace std;

vector <int> adj[N];

int num[N], low[N], curr = 0;

int bridge = 0, ap[N], root = 0,  children = 0;

void dfs(int u, int p){

    num[u] = low[u] = ++curr;

    for (int v : adj[u]){

        if (v == p)  continue;

        if (num[v] == 0){

            dfs(v, u);

            low[u] = min(low[u], low[v]);

            //Check whether (u, v) is a bridge or not 
            if (low[v] > num[u]){

                ++bridge;
            }

            //Check whether u is an articulation point or not
            if (u != root && low[v] >= num[u]){

                ap[u] = 1;
            }

            //Update root's children on DFS tree
            if (u == root)  ++children;
            
        }
        else{

            low[u] = min(low[u], num[v]);
        }
    }

    
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int V = 0, E = 0; cin >> V >> E;

    fill(ap, ap + N, 0);

    for (int i = 0; i < E; ++i){

        int u, v;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= V; ++u){

        if (num[u] == 0){

            root = u;
            children = 0;

            dfs(u, -1);

            if (children > 1){

                ap[root] = 1;
            }
        }
    }

    int articulation = 0;

    for (int a : ap)  articulation += a;

    cout << articulation << " " << bridge << endl;

    return 0;
}