#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define N 16
#define INF 1e9

using namespace std;

struct edge{

    int u;
    int v;
    int w;
};

struct Union_Find {

    vector <int> parent;

    Union_Find(int n){

        parent.resize(n  + 1);

        for (int i = 1; i <= n; ++i){

            parent[i] = i;
        }
    }

    int Find(int x){

        return parent[x];
    }

    int Root(int x){

        while (Find(x) != x){

            x = Find(x);
        }

        return x;
    }

    void Unite(int x, int y){

        int r = Root(x);
        
        parent[r] = Root(y);
    }

    void Divide(int x, int y){

        while (parent[x] != Root(y)){

            x = parent[x];
        }

        parent[x] = x;
    }

    void Print(int len){

        for (int i = 1; i <= len ; ++i){

            cout << parent[i] << " ";
        }
        cout << endl;
    }
};

//Global Variables
int V = 0, E = 0, K = 0, W = 0, res = INF;

vector <edge> e;
vector <edge> mst[N];

Union_Find UF(N);

//
int dfs(int u, int p){

    int res = 0;

    for (auto e : mst[u]){

        int v = e.v;
        
        if (v == p)  continue;

        res = max(res, dfs(v, u) + 1);
    }

    return res;
}    

void checkMST(){

    int d = 0;

    for (int u = 1; u <= V; ++u){

        d = max(d, dfs(u, -1));

    }

    if (d <= K){

        res = min(res, W);
    }
}

void countST(int index, int count){
 
    if (count == (V - 1)){
 
        checkMST();

        return;
    }
 
    if (index == E){
 
        return;
    }
 
    int u = e[index].u, v = e[index].v, w = e[index].w;
 
    if (UF.Root(u) != UF.Root(v)){
 
        UF.Unite(u, v);

        mst[u].push_back({u, v, w});
        mst[v].push_back({v, u, w});

        W += w;
        
        countST(index + 1, count + 1);

        W -= w;

        mst[u].pop_back();
        mst[v].pop_back();
 
        UF.Divide(u, v);
    }

    countST(index + 1, count);
}
 

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> V >> E >> K;

    for (int i = 0; i < E; ++i){

        int u, v, w;  cin >> u >> v >> w;

        e.push_back({u, v, w});
    }

    //
    countST(0, 0); 

    //Output
    cout << res << endl;

    return 0;
}