//Prim Algorithm O( (|V| + |E|)log|E| ) ->100pts
#include <iostream>
#include <vector>
#include <queue>

#define N 21
#define INF 1e9

using namespace std;

//Structure
struct edge{

    int u;
    int v;
    int w;
};

//Global variables
int V = 0, E = 0, K = 0;

vector <edge> adj[N];

//Functions


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> V >> E >> K;

    for (int i = 0; i < E; ++i){

        int u, v, w;  cin >> u >> v >> w;

        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, w});
    }

    //

    //Output
    cout <<  endl;

    return 0;
}