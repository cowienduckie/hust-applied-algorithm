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

vector <int> adj[N];        //list of tasks may start after completetion of i-th
vector <int> d(N, 0);       //duration of tasks
vector <int> mark(N, 0);    //number of tasks must be completed before i-th

//Functions
void best_topo(){

    int result = 0;

    priority_queue <pair<int , int>, 
                    vector <pair<int, int>>, 
                    greater <pair<int, int>>> PQ;
    //first -> complete time   second -> task

    for (int u = 1; u <= V; ++u){ //push all tasks having mark = 0

        if(mark[u] == 0){

            PQ.push({d[u], u});
        }
    }

    while (!PQ.empty()){

        int complete = PQ.top().first; int u = PQ.top().second; 
        PQ.pop();

        for (int v : adj[u]){

            --mark[v];

            if (mark[v] == 0)  PQ.push({complete + d[v], v});
        }

        result = max(result, complete);
    }

    cout << result << endl;
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