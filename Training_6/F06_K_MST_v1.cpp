//Kruskal Algorithm (|E|log|V|) -> 80pts
//Luckily got 80pts because this is a wrong answer
//Kruskal considers edge by edge so it cannot choose starting points
//If the smallest edge is not included in answer so algorithm go wrong
//Try Prim algorithm instead?
#include <iostream>
#include <vector>
#include <algorithm>

#define N 21

using namespace std;

struct edge{

    int u;
    int v;
    int w;

    edge(int u, int v, int w){

        this->u = u;
        this->v = v;
        this->w = w;
    }
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

        if (parent[x] == x){

            return x;
        }
        else{

            parent[x] = Find(parent[x]);

            return parent[x];
        }
    }

    void Unite(int x, int y){

        parent[Find(x)] = Find(y);
    }
};

//Global Variables
int V = 0, E = 0, K = 0;

vector <edge> e;

//

int K_MST(){
    
    int res = 0;  Union_Find UF(V);

    auto compare = [](edge &a, edge &b){

        return a.w < b.w;
    };

    sort(e.begin(), e.end(), compare);

    for (int i = 0; i < E; ++i){

        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;

        if (UF.Find(u) != UF.Find(v)){

            UF.Unite(u, v);

            res += w;  --K;

            if (K == 0){

                return res;
            }
        }
    }

    return -1;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E >> K;

    for (int i = 0; i < E; ++i){

        int u, v, w;  cin >> u >> v >> w;

        e.push_back({u, v, w});
    }

    cout << K_MST() << endl;

    return 0;
}