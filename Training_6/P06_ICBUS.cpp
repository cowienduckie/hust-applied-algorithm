#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define N 5010
#define INF 1e9

using namespace std;

//Struct 
struct Bus{

    int cap;
    int cost;
};

struct edge{

    int v;
    int w;
};

//Global Variables
int V = 0, E = 0;

vector <Bus> bus(N);
vector <int> adj[N];
vector <edge> edges[N];
vector <bool> mark(N);
vector <int> dist(N, INF);


//Functions
void bfs(){

    for (int i = 1; i <= V; ++i){

        fill(mark.begin(), mark.end(), false);

        int cap = bus[i].cap;
        int cost = bus[i].cost;

        queue <pair <int, int>> Q;   Q.push({i, 0}); //{v, distance from u}

        while(!Q.empty()){

            int u = Q.front().first;
            int d = Q.front().second;

            Q.pop();

            if (d == cap) continue;

            for (int v : adj[u]){

                if (mark[v] == true) continue;

                mark[v] = true;

                edges[i].push_back({v, cost});

                Q.push({v, d + 1});
            }
        }
    }
}

int dijkstra(int s, int t){

    priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> PQ;

    dist[s] = 0;   PQ.push({0, s});

    fill(mark.begin(), mark.end(), false);

    while (!PQ.empty()){

        int u = PQ.top().second;   PQ.pop();

        if (u == t){

            return dist[u];
        }

        if (mark[u] == true)  continue;

        mark[u] = true;

        for (edge e : edges[u]){

            int v = e.v;
            int w = e.w;

            if (mark[v] == true) continue;

            if (dist[u] + w < dist[v]){

                dist[v] = dist[u] + w;

                PQ.push({dist[v], v});
            }
        }
    }

    return -1;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> V >> E;

    for (int i = 1; i <= V; ++i){

        cin >> bus[i].cost >> bus[i].cap;
    }

    for (int i = 1; i <= E; ++i){

        int u, v;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Solution
    bfs();

    //Output
    cout << dijkstra(1, V) << endl;    

    return 0;
}