//Prim Algorithm O( (|V| + |E|)log|E| ) ->100pts
#include <iostream>
#include <vector>
#include <queue>

#define N 100010
#define INF 1e9

using namespace std;

//Structure
struct edge{

    int u;
    int v;
    int w;
};

//Global variables
int V = 0, E = 0;

vector <edge> adj[N];
vector <bool> mark(N, false);
vector <int> best_w(N, INF);

//Functions
long long MST (){

    long long res = 0, count = 0;

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;  //{best_w, vertex}

    best_w[1] = 0;   PQ.push({0, 1});

    while (count < V){

        while(!PQ.empty() && PQ.top().first != best_w[PQ.top().second]){

            PQ.pop();
        }

        if (PQ.empty()) return -1;

        int v = PQ.top().second, w = PQ.top().first;  PQ.pop();

        for (edge e : adj[v]){

            if (best_w[e.v] > e.w && mark[e.v] == false){

                best_w[e.v] = e.w;

                PQ.push({e.w, e.v});
            }
        }

        ++count;   res += w;  mark[v] = true;
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