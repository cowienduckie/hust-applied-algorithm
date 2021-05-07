#include <iostream>
#include <vector>
#include <algorithm>

#define N 1000010

using namespace std;

vector <vector <int>> adj(N);

vector <vector <int>> gender(2);

int mark[N], res = 1;

void dfs(int u, int s){

    mark[u] = 1;  gender[s].push_back(u);

    for (int v : adj[u]){

        if (res == 0)  break;

        if (mark[v] == 0){

            if (s == 0){

                dfs(v, 1);
            }
            else{

                dfs(v, 0);
            }
        }
        else{

            vector <int> :: iterator it = find(gender[s].begin(), gender[s].end(), v);

            if (it != gender[s].end()){

                res = 0;
            }
        }
    }


}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int test = 0, index = 0;  cin >> test;

    while (test--){

        //Clear memory
        gender[0].clear();
        gender[1].clear();

        for (auto &v : adj){

            v.clear();
        }   

        res = 1;

        fill(mark, mark + N, 0);

        //Input
        int V = 0, E = 0;  cin >> V >> E;

        for (int i = 0; i < E; ++i){

            int u, v;  cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //dfs
        for (int u = 1; u <= V; ++u){

            if (mark[u] == 0){

                dfs(u, 0);
            }
        }

        //Output
        cout << "Scenario #" << ++index << ":" << endl;

        if (res == 0){

            cout << "Suspicious bugs found!" << endl;
        }
        else{

            cout << "No suspicious bugs found!" << endl;
        }
    }

    return 0;
}