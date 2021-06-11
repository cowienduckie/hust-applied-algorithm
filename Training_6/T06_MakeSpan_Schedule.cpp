#include <iostream>
#include <vector>

#define N 10010
#define INF 1e9

using namespace std;

struct edge{

    int v;
    int w;
}

//Global Variables
int V = 0, E = 0;

vector <int> adj[N];
vector <int> d(N, 0);


//Functions
void span


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    for (int u = 1; u <= V; ++u){

        cin >> d[u];

        adj[u].push_back(0);
    }

    for (int i = 0; i < E; ++i){

        int u = 0, v = 0;  cin >> v >> u;

        adj[u].push_back({v, d[u]});
    }
    
    //
    int result = 0;

    

    //OUTPUT
    cout << result << endl;

    return 0;
}