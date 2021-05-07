#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define N 100010

using namespace std;

vector <int> adj[N];

stack <int> s;

int num[N], low[N], bConnect[N], curr = 0, res = 0;

void dfs(int u){

    bConnect[u] = 1;
    s.push(u);

    num[u] = low[u] = ++curr;

    for (int v : adj[u]){

        if (num[v] == 0){

            dfs(v);

            low[u] = min(low[u], low[v]);
        }
        else if (bConnect[v] == 1){

            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u] == low[u]){

        while(true){

            int tmp = s.top();  s.pop();

            bConnect[tmp] = 0;

            if (tmp == u)  break;
        }

        ++res;
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int V = 0, E = 0;  cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u = 0, v = 0;  cin >> u >> v;

        adj[u].push_back(v);
    }

    fill(num, num + N, 0);
    fill(bConnect, bConnect + N, 0);

    for (int u = 1; u <= V; ++u){

        if (num[u] == 0){

            dfs(u);
        }
    }

    cout << res;

    return 0;
}