//Floyd Warshall algorithm using DP
//Space complexity O(|V|^2) -> too large for N = 10^5 
//
//Bellman Ford algorithm -> Nice to try, space complexity O(2|V| + |E|)
#include <iostream>
#include <algorithm>
#include <vector>

#define N 10010
#define INF 1e9

using namespace std;

//Global Variables
int V = 0, E = 0;

int dp[N][N];
int nextNode[N];

//Functions
void floydWarshall(){

    for (int u = 1; u <= V; ++u){   //Initiate base cases

        for (int v = u + 1; v <= V; ++v){

            if (u == v){

                dp[u][v] = dp[v][u] = 0;
            }
            else if (dp[u][v] == 0){

                dp[u][v] = dp[v][u] = INF;
            }
        }
    }

    for (int k = 1; k <= V; ++k){

        for (int u = 1; u <= V; ++u){

            for (int v = 1; v <= V; ++v){

                dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
            }
        }
    }
}

void trace(int u, int v){

    for (int k = 1; k <= V; ++k){

        if (u == k || k == v)  continue;

        if (dp[u][v] == dp[u][k] + dp[k][v]){

            nextNode[u] = k;
            nextNode[k] = v;

            trace(u, k);

            trace(k, v);
        }
    }
}

void printAnswer(int s, int t){

    cout << dp[s][t] << endl;

    int u = s;

    while (u != -1){

        cout << u << " ";

        u = nextNode[u];
    }
}

void solve(){

    int s, t; cin >> s >> t;

    nextNode[s] = t; 
    nextNode[t] = -1;

    floydWarshall();

    trace(s , t);

    printAnswer(s, t);
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v, weight;  cin >> u >> v >> weight;

        dp[u][v] = dp[v][u] = weight;
    }

    solve();    

    return 0;
}