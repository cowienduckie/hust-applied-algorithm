#include <iostream>
#include <vector>
#include <algorithm>

#define N 22
#define INF 1e9

using namespace std;

//Global Variables
int V = 0, E = 0, result = INF;

bool adj[N][N];

bool mark[N];


//Function
bool update(){

    for (int v = 1; v <= V; ++v){

        if (mark[v] == false){

            bool flag = true;

            for (int u = 1; u <= V; ++u){

                if (mark[u] == true && adj[u][v] == true){

                    flag = false;
                    break;
                   }
            }

            if (flag == true){

                return false;
            }
        }
    }

   return true;
}

void brute(int u, int sz){

    if (u > V){

        if (update())  result = min(result, sz);

        return;
    }

    //Khong chon u
    mark[u] = false;
    brute(u + 1, sz);

    //Chon u
    bool flag = true;

    for (int v = 1; v < u; ++v){

        if (mark[v] == true && adj[u][v] == true){

            flag = false;
            break;
        }
    }

    if (flag){
        
        mark[u] = true;

        brute(u + 1, sz + 1);

        mark[u] = false;
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u = 0, v = 0;

        cin >> u >> v;

        adj[u][v] = true;
        adj[v][u] = true;
    }

    //
    brute(1, 0);

    //
    cout <<  result << endl;

    return 0;
}