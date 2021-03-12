#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
     
using namespace std;
/*Taxi solution using backtracking
    Input included:
        cost[N][N] -> cost matrix from a city to another
        mark -> Check for if a city is visited or not
        pos -> current position of this step (before)
        pass -> total number of passengers
        count -> number of passengers transported
        cmin -> minimum cost from a city to another
        curr -> current total cost of this route
        result -> lowest total cost of all routes
*/

//Supposing, the map is divided as 2 parts:  passenger's home and destination
//A recursive step in this solution include 2 parts: 
//      home A -> destination A
//      destination A -> home B
//City 0 is treated as the last home, driver's home

void taxi(int cost[23][23], vector<bool>& mark, int pos, int pass, int count, int cmin, long long curr, long long& result){
    if (curr + cmin * 2 * (pass - count) >= result) return; //Branch and bound step
     
    if (count == pass && cost[pos][pos + pass] && cost[pos + pass][0]){     //If pos is the last passenger's home, next home is driver's

        result = min(curr + cost[pos][pos + pass] + cost[pos + pass][0], result); //Finish route and compare result
        return;
    }
     
    for (int i = 1; i <= pass; ++i){    //browse all cities and find available cities to continue recursion

        if (mark[i] == false && cost[pos][i]){
            mark[i] = true; //update mark
     
            if (pos != 0)   //While choosing first passenger, just go from driver's home to first passenger's
                taxi(cost, mark, i, pass, count + 1, cmin, curr + cost[pos][pos + pass] + cost[pos + pass][i], result);
            else
                taxi(cost, mark, i, pass, count + 1, cmin, curr + cost[pos][i], result);    //Update pos, count, curr
            //backtracking step
            mark[i] = false;
        }
    }
}
     
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    int pass = 0, cmin = INT_MAX; cin >> pass;
    long long result = LLONG_MAX;
     
    int cost[23][23];
     
    for (int i = 0; i <= 2 * pass; ++i){
        for (int j = 0; j <= 2 * pass; ++j){
            cin >> cost[i][j];
     
            if (cost[i][j] > 0) cmin = min(cmin, cost[i][j]); //Minimum cost from a city to another, ignoring 0 value
        }
    }
     
    vector <bool> mark(23);
    for (bool b : mark)  b = false;  //No city marked before tsp run
     
    mark[0] = true;//Mark first city
    taxi(cost, mark, 0, pass, 0, cmin, 0, result);
 
    cout << result;

    return 0;
}