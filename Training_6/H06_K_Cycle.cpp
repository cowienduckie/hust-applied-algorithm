#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define N 31

using namespace std;

//Global Variables
int V = 0, E = 0, K = 0, result = 0;

vector <int> adj[N];
vector <bool> mark(N, false);

//Functions
void dfs(int s, int u, int p){

    if (p == K){

        if (u == s)  ++result;

        return;
    }

    for (int v : adj[u]){

        if (mark[v] == false){

            mark[v] = true;

            dfs(s, v, p + 1);

            mark[v] = false;
        }
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> V >> E >> K;

    for (int i = 0; i < E; ++i){

        int u = 0, v = 0;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Solution
    for (int s = 1; s <= V; ++s){

        dfs(s, s, 0);
    }

    //Output
    cout << result / (2 * K) << endl;

    return 0;
}