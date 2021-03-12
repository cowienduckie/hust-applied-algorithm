#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;
/*Cbus solution using backtracking
    Input included:
        cost[N][N] -> cost matrix from a city to another
        mark -> check for if a city is visited or not
        pos -> current position of this step (before)
        pass -> total number of passengers
        place -> number of places available on bus
        count -> number of passengers transported
        cmin -> minimum cost from a city to another
        curr -> current total cost of this route
        result -> lowest total cost of all routes
*/
//Supposing, the map is divided as 2 parts:  passenger's home and destination
//A recursive step in this solution 2 constraints beside normal ones: 
//      home A -> bus must have empty place (place != 0)
//      destination A -> A must be on bus already (mark[A's home] = true)
//City 0 is treated as the last home, driver's home
void bus(int cost[23][23], vector<bool>& mark, int pos, int pass, int place, int count, int cmin, long long curr, long long& result){
    if (curr + cmin  * (pass * 2  + 1 - count) >= result) return; //Branch and bound step

    if (count == pass * 2 + 1 && cost[pos][0]){  //If this is last city, finish route and compare result

        result = min(curr + cost[pos][0], result);
        return;
    }

    for (int i = 1; i <= pass * 2; ++i){  //browse all cities and find available cities to continue recursion

        if (mark[i] == false && cost[pos][i]){

            if (i > pass){  //Destination -> place increase
                if (mark[i-pass] == false) continue;
                else{
                    mark[i] = true;  //update mark

                    bus(cost, mark, i, pass, place + 1, count + 1, cmin, curr + cost[pos][i], result); //update pos, count, curr, place
                    //backtracking step
                    mark[i] = false;
                }
            }
            else{   //Home -> place decrease
                if (!place)  continue;
                else{
                    mark[i] = true;//update mark

                    bus(cost, mark, i, pass, place - 1, count + 1, cmin, curr + cost[pos][i], result);//update pos, count, curr, place
                    //backtracking step
                    mark[i] = false;
                }
            }         
        }
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    int pass = 0, place = 0, cmin = INT_MAX; cin >> pass >> place;
    long long result = LLONG_MAX;

    int cost[23][23];

    for (int i = 0; i <= 2 * pass; ++i){
        for (int j = 0; j <= 2 * pass; ++j){
            cin >> cost[i][j];

            if (cost[i][j] > 0) cmin = min(cmin, cost[i][j]);//Minimum cost from a city to another, ignoring 0 value
        }
    }

    vector <bool> mark(23);
    for (bool b : mark)  b = false;//No city marked before tsp run
    
    mark[0] = true;//Mark first city
    bus(cost, mark, 0, pass, place, 1, cmin, 0, result);

    cout << result;

    return 0;
}