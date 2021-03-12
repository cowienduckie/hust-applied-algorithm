#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

/*TSP solution using backtracking
    Input included:
        cost[N][N] -> cost matrix from a city to another
        mark -> Check for if a city is visited or not
        pos -> current position of this step (before)
        city -> total number of cities
        count -> number of cities visited
        cmin -> minimum cost from a city to another
        curr -> current total cost of this route
        res -> lowest total cost of all routes
*/

void tsp(int cost[21][21], vector <bool>& mark, int pos, int city, int count, int cmin, long long curr, long long& res){
    if (curr + cmin * (city - count) >= res) return;    // Branch and Bound step

    if (count == city && cost[pos][1]){     //If this is last city, finish route and compare result
        
        res = min(res, curr + cost[pos][1]);
        return;
    }

    for (int i = 1; i <= city; ++i){    //browse all cities and find available cities to continue recursion
        if (mark[i] == false && cost[pos][i]){
            mark[i] = true; //update mark

            tsp(cost, mark, i, city, count + 1, cmin, curr + cost[pos][i], res);    //update pos, count, curr

            //backtracking step
            mark[i] = false;
        }
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    int city, num, cmin = INT_MAX;
    long long result = LLONG_MAX;

    cin >> city >> num;

    int cost[21][21];
    memset (cost, 0, sizeof(cost));

    for(int k = 0; k < num; ++k){
        int i, j;
        cin >> i >> j;
        cin >> cost[i][j];

        cmin = min(cmin, cost[i][j]);   //Take minimum cost from a city to another
    }

    vector <bool> mark(21);
    for (bool b : mark) b = false; //No city marked before tsp run

    mark[1] = true; //Mark first city

    tsp(cost, mark, 1, city, 1, cmin,  0, result);

    cout << result;

    return 0;
}