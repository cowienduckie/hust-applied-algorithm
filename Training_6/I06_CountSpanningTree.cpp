#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define N 20

using namespace std;

struct edge{

    int u;
    int v;

    edge(int u, int v){

        this->u = u;
        this->v = v;
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
int V = 0, E = 0, res = 0;

vector <edge> e;

Union_Find UF(N);

//

void countST(int index, int count){
 
    if (count == (V - 1)){
 
        ++res;

        return;
    }
 
    if (index == E){
 
        return;
    }
 
    int u = e[index].u, v = e[index].v;
 
    if (UF.Root(u) != UF.Root(v)){
 
        UF.Unite(u, v);
        
        countST(index + 1, count + 1);
 
        UF.Divide(u, v);
    }

    countST(index + 1, count);
}
 

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v;  cin >> u >> v;

        e.push_back({u, v});
    }

    //
    countST(0, 0); 

    //Output
    cout << res << endl;

    return 0;
}