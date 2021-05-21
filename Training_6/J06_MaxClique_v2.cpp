//v2_Brute and bitmask --> 100pts
#include <iostream>

#define N 13

using namespace std;

//Global Variables
int V = 0, E = 0, result = 0;

int adj[N][N], dp[N][1<<N];


//Functions
void update(int c){

    int tmp = 0;

    for (int i = 1; i <= V; ++i){

        if (c & (1 << i)){

            ++tmp;
        }
    }

    result = max(result, tmp);
}

void brute(int u, int c){

    if (u == V + 1){

        return update(c);
    }

    if (dp[u][c] != 0) return;

    bool flag = true;

    for (int v = 1; v <= V; ++v){

        if (c & (1 << v)){ //If node v is marked

            if (adj[u][v] != 1){

                flag = false;
                break;
            }
        }
    }

    if (flag)  brute(u + 1, c | (1 << u));

    brute(u + 1, c);
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> V >> E;

    for (int i = 0; i < E; ++i){

        int u, v;   cin >> u >> v;

        adj[u][v] = adj[v][u] = 1;
    }

    brute(1, 1);

    cout << result << endl;   

    return 0;
}