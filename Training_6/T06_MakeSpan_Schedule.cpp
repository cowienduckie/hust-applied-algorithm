#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define N 10010
#define INF 1e9

using namespace std;

//Global Variables
int V = 0, E = 0;

vector <int> adj[N];        //list of tasks can start after completetion of i-th
vector <ll> d(N, 0);       //duration of tasks
vector <int> mark(N, 0);    //number of tasks must be completed before i-th
vector <bool> visited(N, false);

//Functions
void best_topo(){

    ll result = 0;

    priority_queue <pair<ll , int>, 
                    vector <pair<ll, int>>, 
                    greater <pair<ll, int>>> PQ;
    //first -> start time   second -> task

    for (int u = 1; u <= V; ++u){ //push all tasks has mark = 0

        if(mark[u] == 0){

            PQ.push({0, u});
        }
    }

    while (!PQ.empty()){

        if (visited[PQ.top().second]){

            PQ.pop();
            continue;
        }

        ll start = PQ.top().first; int u = PQ.top().second; 
        PQ.pop();

        for (int v : adj[u]){

            --mark[v];

            if (mark[v] == 0)  PQ.push({start + d[u], v});
        }

        result = max(result, start + d[u]);
        visited[u] = true;
    }

    cout << result;
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //
    cin >> V >> E;

    for (int u = 1; u <= V; ++u){

        cin >> d[u];
    }

    for (int i = 1; i <= E; ++i){

        int u = 0, v = 0;  cin >> u >> v;

        adj[u].push_back(v);

        ++mark[v];
    }
    
    //
    best_topo();

    return 0;
}