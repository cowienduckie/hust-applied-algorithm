#include <iostream>
#include <vector>
#include <algorithm>

#define N 100010

using namespace std;

vector <vector <int>> adj(N);

vector <int> side[2];

int mark[N];

void dfs(int u, int s){

    mark[u] = 1;  side[s].push_back(u);

    for (int v : adj[u]){

        if (mark[v] == 0){

            if (s == 0){

                dfs(v, 1);
            }
            else{

                dfs(v, 0);
            }
        }
        else{

            vector <int> :: iterator it = find(side[s].begin(), side[s].end(), v);

            if (it != side[s].end()){

                cout << 0 << endl;

                exit(0);
            }
        }
    }


}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int V = 0, E = 0;  cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v;  cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(mark, mark + N, 0);
    
    for (int u = 1; u <= V; ++u){

        if (mark[u] == 0){

            dfs(u, 0);
        }
    }

    cout << 1 << endl;

    return 0;
}