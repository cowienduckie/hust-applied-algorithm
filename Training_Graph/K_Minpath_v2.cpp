//Bellman Ford algorithm
//Space problem is solved but algorithm is too slow for tests
//
//Dijkstra algorithm -> Time complexity: O (|V| * log(|E|))
#include <iostream>
#include <algorithm>
#include <vector>

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
vector <int> order;
vector <bool> mark(N, false);

//Functions
void bellmanFord(int s){

    dp[s] = 0;

    for (int i = 1; i < V - 1; ++i){

        for (int u = 1; u <= V; ++u){

            for (edge &e : adj[u]){

                int v = e.v;
                int w = e.w;

                dp[v] = min(dp[v], 1ll * (w + dp[u]));
            }
        }
    }
}


void trace(int u, int s){

    order.push_back(u);

    if (u == s) return;

    for (edge &e : adj[u]){

        int v = e.v;
        int w = e.w;

        if (dp[u] == dp[v] + w){

            trace(v, s);

            break;
        }        
    }
}

void printAnswer(int t){

    cout << dp[t] << endl;

    reverse(order.begin(), order.end());

    for (int &u : order){

        cout << u << " ";
    }
}

void solve(){

    int s, t;  cin >> s >> t;

    bellmanFord(s);

    trace(t, s);

    printAnswer(t);
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