//Prim Algorithm O(|V| ^ 2) -> 60 pts
//1 <= |V|, |E| <= 10^5 -> Use O( (|V| + |E|)log|E| ) implimentation

#include <iostream>
#include <vector>

#define N 100010
#define INF 1e9

using namespace std;

//Structure
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
int V = 0, E = 0;

vector <edge> adj[N];
vector <bool> mark(N, false);
vector <int> best_w(N, INF);

//Functions
long long MST (){

    long long res = 0, count = 0;

    best_w[1] = 0;

    while (count < V){

        int v = 0, w = INF;

        for (int u = 1; u <= V; ++u){

            if (mark[u] == false && best_w[u] < w){

                v = u;  w = best_w[u];
            }
        }

        if (v == 0)  return -1;   //This is not a continued graph

        for (edge e : adj[v]){

            if (best_w[e.v] > e.w){

                best_w[e.v] = e.w;
            }
        }

        mark[v] = true;   ++count;   res += w;
    }

    return res;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v, w;  cin >> u >> v >> w;

        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, w});
    }

    //
    long long res = MST();

    //Output
    cout << res << endl;

    return 0;
}