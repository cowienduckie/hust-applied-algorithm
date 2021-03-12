#include <iostream>
#include <limits>

using namespace std;

int city = 0, num = 0;

int cost[22][22];
int min_cost = INT_MAX;
long long curr = 0, best = LLONG_MAX;
bool mark[22];
int route[22];

void tsp(int k){
    if (k > city){
        curr += cost[route[k-1]][1];

        best = min(best, curr);
        
        curr -= cost[route[k-1]][1];

        return;
    }

    for (int i = 2; i <= city; ++i){
        if (curr + min_cost * (city - k + 1) < best && mark[i] == false && cost[route[k-1]][i] > 0){
            route[k] = i; 
            mark[i] = true;
            curr += cost[route[k-1]][i];

            tsp(k+1);

            curr -= cost[route[k-1]][i];
            mark[i] = false;
            route[k] = 0;
        }
    }
    
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> city >> num;

    for (int k = 0; k < num; ++k){
        int i, j;
        cin >> i >> j;
        cin >> cost[i][j];

        min_cost = min(min_cost, cost[i][j]);
    }

    for (bool b : mark) b = false;

    route[1] = 1;
    tsp(2);

    cout << best;

    return 0;
}