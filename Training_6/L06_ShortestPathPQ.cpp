#include <iostream>
#include <vector>
#include <queue>

#define N 100010
#define INF 1e18 

using namespace std;

struct edge{

    int u;
    int v;
    int w;
};

//Global Variables
int V = 0, E = 0;

vector <edge> adj[N];
vector <unsigned long long> dist(N, INF);

//Functions
unsigned long long dijkstra(int s, int t){

    dist[s] = 0;

    priority_queue < pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>> > PQ;

    PQ.push({0, s});

    while (!PQ.empty()){

        int u = PQ.top().second;  PQ.pop();

        if (u == t){

            return dist[u];
        }

        for (edge e : adj[u]){

            int v = e.v;
            int w = e.w;

            if (w + dist[u] < dist[v]){

                dist[v] = w + dist[u];

                PQ.push({dist[v], v});
            }
        }
    }

    return -1;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v, w;  cin >> u >> v >> w;

        adj[u].push_back({u, v, w});
    }

    int s = 0, t = 0;  cin >> s >> t;

    cout << dijkstra(s, t) << endl;    

    return 0;
}