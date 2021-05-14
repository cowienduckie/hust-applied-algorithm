#include <iostream>
#include <vector>
#include <queue>

#define N 100010

using namespace std;

//Global Variables
int V = 0;

vector <int> adj[N];
vector <int> parent(N);

//Functions
void bfs(int r){

    queue < pair<int, int> > Q;  //{node, parent}

    Q.push({r, -1});

    while(!Q.empty()){

        int u = Q.front().first;
        int p = Q.front().second;

        Q.pop();

        if (u != r)  parent[u] = p;

        for (int v : adj[u]){

            if (v == p)  continue;

            Q.push({v, u});
        }
    }
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V;

    for (int i = 0; i < V - 1; ++i){

        int u = 0, v = 0;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    for (int i = 2; i <= V; ++i)  cout << parent[i] << " ";

    return 0;
}