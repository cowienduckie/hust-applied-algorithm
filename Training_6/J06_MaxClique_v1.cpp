//v1_Greedy Algorithm
//100pts but go wrong if nodes with high degree are not existing in Max Clique
//Try Brute Force instead?
#include <iostream>
#include <vector>
#include <algorithm>

#define N 20

using namespace std;

//Global Variables
int V = 0, E = 0;

int adj[N][N], node[N], deg[N];

vector <int> clique;

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v;  cin >> u >> v;

        adj[u][v] = adj[v][u] = 1;

        ++deg[u];
        ++deg[v];
    }

    //Greedy Algorithm
    for (int i = 1; i <= V; ++i) node[i] = i;

    auto comp = [&](int u, int v){

        return deg[u] > deg[v];
    };

    sort(node + 1, node + 1 + V, comp);

    for (int i = 1; i <= V; ++i){

        int u = node[i];

        bool flag = true;

        for (int v : clique){

            if (!adj[u][v]){

                flag = false;
                break;
            }
        }

        if (flag) clique.push_back(u);
    }


    //Ouput
    cout << clique.size() << endl;

    return 0;
}