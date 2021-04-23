#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long
#define INF 1e9
#define N 10001
#define K 2001

using namespace std;

//Global Variables
int n = 0, k = 0, adj = 0, result = INF;

vector <pair <int, int> > network[N];

int dp[N][K];



//Functions
void dfs(int root, int parent){

    fill(dp[root], dp[root] + k + 1, INF);  dp[root][0] = 0;   //Zero cost to visit root itself

    for (pair <int, int> p : network[root]){

        int next = p.first;
        int cost = p.second;

        if (next == parent)  continue;  //Don't come back parent node

        dfs(next, root);

        for (int kk = 0; kk < k; ++kk){  //Update result that through root from next sub tree to previous sub tree

            result = min(result, dp[next][kk] + cost + dp[root][k - kk - 1]);
        }

        for (int i = 1; i < k; ++i){  //Update min cost of paths start form root and depth of i

            dp[root][i] = min(dp[root][i], cost + dp[next][i - 1]);
        }
        
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> n >> k >> adj;

    for (int i = 1; i <= adj; ++i){

        int src = 0, dst = 0, cost = 0;  cin >> src >> dst >> cost;  

        network[src].push_back({dst, cost});
        network[dst].push_back({src, cost});
    }

    //
    
    dfs(1, 0);

    //OUTPUT
    cout << result;

    return 0;
}