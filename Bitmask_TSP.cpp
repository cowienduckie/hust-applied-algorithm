#include <iostream>
#include <limits>
#include <cstring>

#define MAX 21
#define ll long long

using namespace std;

//Global Variables
int city_num = 0, path = 0;
int **cost;
ll **store;

//Functions
ll tsp(int pos, int visited){

    if (visited == ((1 << (city_num + 1)) - 2))  return cost[pos][1];
    if (store[pos][visited] != 0)  return store[pos][visited];

    ll result = LLONG_MAX;

    for (int i = 1; i <= city_num; ++i){

        if (visited & (1 << i))  continue;

        result = min(result, cost[pos][i] + tsp(i, visited | (1 << i)));
    }

    store[pos][visited] = result;

    return result;
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> city_num >> path;

    cost = (int **)calloc(city_num + 1, sizeof(int *));
    store = (ll **)calloc(city_num + 1, sizeof(ll *));

    for (int i = 1; i <= city_num; ++i){
        
        cost[i] = (int *)calloc(city_num + 1, sizeof(int));
        store[i] = (ll *)calloc(1 << (city_num + 1), sizeof(ll));

        for (int j = 1; j <= city_num; ++j){

            cost[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < path; ++i){

        int a = 0, b = 0, c = 0;  cin >> a >> b >> c;

        cost[a][b] = c;
    }

    
    //


    //OUTPUT
    cout << tsp(1, 1 << 1) << endl;

    return 0;
}