#include <iostream>
#include <vector>
#include <algorithm>

#define N 100010

using namespace std;

//Global Variables
int V = 0, E = 0; 
int num[N], low[N], curr = 0;

vector <int> adj[N];
vector <int> forest[N];


//Functions
void dfs(int u, int p){

    num[u] = low[u] = ++curr;

    for (int v : adj[u]){

        if (v == p)  continue;

        if (num[v] == 0){

            dfs(v, u);

            low[u] = min(low[u], low[v]);

            //Check whether (u, v) is a bridge or not 
            if (low[v] > num[u]){

                forest[u].push_back(v);
                forest[v].push_back(u);
            }            
        }
        else{

            low[u] = min(low[u], num[v]);
        }
    }
}

int calc_nodes(int u){

    num[u] = 1;

    int node = 1;

    for (auto v : forest[u]){

        if (num[v] == 1) continue;

        node += calc_nodes(v);
    }

    return node;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Complete forest with bridges
    for (int u = 1; u <= V; ++u){

        if (num[u] == 0){

            dfs(u, -1);
        }
    }

    //Find all tree and its amount of nodes
    fill(num, num + N, 0);   //Recycle num array for marking nodes

    long long result = 0;

    for (int u = 1; u <= V; ++u){

        if (num[u] == 0){

            int node = calc_nodes(u);

            result += 1ll * (node - 1) * (node - 2) / 2;
        }
    }

    cout << result << endl;

    return 0;
}