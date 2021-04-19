#include <iostream>
#include <vector>
#include <limits>

#define ull unsigned long long

using namespace std;

//Global Variables
int cus_num = 0, truck_num = 0, max_cap = 0, result = INT_MAX;

vector <vector <int>> cost;
vector <int> order;
vector <int> truck;
vector <int> store;

//Functions
int cap(int cus){

    int tmp = 0;

    for (int i = 1; i <= cus_num; ++i){

        if (cus & (1 << i)){

            tmp += order[i];
        }
    }

    return tmp;
}

bool isInclude(int i, int cus){

    for (int j = 1; j <= cus_num; ++j){

        if (i & (1 << j)){

            if ( !(cus & (1 << j)) ){

                return false;
            }
        }
    }

    return true; 
}

int tsp(int pos, int route){ 

    if (route == (1 << (cus_num + 1)) - 1) return cost[pos][0];

    int result = INT_MAX;

    for (int i = 1; i <= cus_num; ++i){

        if (route & (1 << i))  continue;

        result = min(result, cost[pos][i] + tsp(i, route | (1 << i)));
    }

    return result;
}

void checkRoute(){

    int tmp_cost = 0;

    for (int i = 1; i <= truck_num; ++i){

        tmp_cost += tsp(0, (1 << (cus_num + 1)) - truck[i] - 1);
    }

    result = min(tmp_cost, result);
}

void vrp(int ind, int cus, int pos){

    for (int i = pos; i < store.size(); ++i){

        if (ind == truck_num){

            if (cus == store[i]){

                truck[ind] = cus;

                return checkRoute();
            }
        }
        else if (isInclude(store[i], cus)){
            
            truck[ind] = store[i];

            vrp(ind + 1, cus - store[i], i + 1);
        }
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> cus_num >> truck_num >> max_cap;

    cost.resize(cus_num + 1);
    order.resize(cus_num + 1);
    truck.resize(truck_num + 1);

    for (int i = 1; i <= cus_num; ++i){

        cin >> order[i];
    }

    for (int i = 0; i <= cus_num; ++i){

        cost[i].resize(cus_num + 1);

        for (int j = 0; j <= cus_num; ++j){

            cin >> cost[i][j];
        }
    }

    //
    for (int i = 2; i <= (1 << (cus_num + 1)) - 2; i += 2){

        if (cap(i) <= max_cap){

            store.push_back(i);
        }
    }
    
    vrp(1, (1 << (cus_num + 1)) - 2, 0);

    //OUTPUT
    cout << result;

    return 0;
}