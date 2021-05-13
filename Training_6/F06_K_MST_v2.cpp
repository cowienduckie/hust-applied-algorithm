//Prim Algorithm (K * |V|^2) -> 100pts
//Graph can be unconnected but still has K-MST if it has K-connected component
//Start from each vertex can lead to a new  K-MST (or duplicated)
//Use DP to optimize if |V| is small enough
#include <iostream>
#include <vector>
#include <algorithm>

#define N 21
#define INF 1e9

using namespace std;

struct edge{

    int u;
    int v;
    int w;

    edge(int u, int v, int w){

        this->u = u;
        this->v = v;
        this->w = w;
    }
};

//Global variables
int V = 0, E = 0, K = 0, res = INT_MAX;

vector <bool> mark(N, false);
vector <edge> adj[N];
vector <int> best_w(N, INF);


//Function
void K_MST(int u){

    fill(best_w.begin(), best_w.end(), INF);

    fill(mark.begin(), mark.end(), false);

    best_w[u] = 0;

    int count = 0, weight = 0;

    while (count < K + 1){

        int v = -1, w = INF;

        for (int x = 1; x <= V; ++x){

            if (mark[x] == false && best_w[x] < w){

                v = x;

                w = best_w[x];
            }
        }

        if (v == -1)  return;

        mark[v] = true;

        ++count;

        weight += w;

        for (auto e :adj[v]){

            if(best_w[e.v] > e.w){

                best_w[e.v] = e.w;
            }
        }
    }

    res = min(res, weight);
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E >> K;

    for (int i = 0; i < E; ++i){

        int u, v, w;  cin >> u >> v >> w;

        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, w});
    }

    for (int u = 1; u <= V; ++u){

        K_MST(u);
    }

    if (res != INT_MAX) cout << res << endl;
    else 
        cout << -1 << endl;
    

    return 0;
}