#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int V = 0, count = 0;  cin >> V;

    vector <int> adj[V + 1];

    for (int i = 0; i < V - 1; ++i){

        int u, v;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 2; i<= V; ++i){

        if (adj[i].size() == 1){

            ++count;
        }
    }

    cout << count << endl;

    return 0;
}