//Dijkstra algorithm 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define N 100010
#define INF 1e9

using namespace std;

struct edge{

    int v;
    int w;
};

//Global Variables
int V = 0, E = 0;

vector <edge> adj[N];
vector <long long> dp(N, INF);

//Functions
void dijkstra(int s, int t){

    dp[s] = 0;

    priority_queue <pair<long long, int >, 
                    vector<pair <long long, int>>, 
                    greater <pair<long long, int>>> PQ;

    PQ.push({dp[s], s});

    while (!PQ.empty()){

        int u = PQ.top().second;

        PQ.pop();

        if (u == t){
            
            cout << dp[t] << endl;
            return;
        }

        for (edge &e : adj[u]){

            int v = e.v;
            int w = e.w;

            if (dp[v] > dp[u] + w){

                dp[v] = dp[u] + w;

                PQ.push({dp[v], v});
            }
        }
    }
}


void trace(int u, int s){

    if (u == s){

        cout << u << " ";

        return;
    }

    for (edge &e : adj[u]){

        int v = e.v;
        int w = e.w;

        if (dp[u] == dp[v] + w){

            trace(v, s);

            break;
        }        
    }

    cout << u << " ";
}


void solve(){

    auto compare = [](edge &a, edge &b){

        return a.v > b.v;
    };

    for (int u = 1; u <= V; ++u){

        sort(adj[u].begin(), adj[u].end(), compare);
    }

    int s, t;  cin >> s >> t;

    dijkstra(s, t);

    trace(t, s);
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v, w;  cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    solve();    

    return 0;
}