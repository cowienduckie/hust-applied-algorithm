//Classification Vehicle Routing Problem
#include <iostream>
#include <vector>

using namespace std;

//Global variables
int cus = 0, truck_num = 0, max_cap = 0, route = 0, total = 0;

vector <int> order = {0};
vector <bool> visited = {true};

//Functions
void vrp(int truck, int cap, int count){

    if (max_cap * (truck_num - truck) + cap < total){

        return;
    }

    if (truck == truck_num && count == cus){
        
        route = (route + 1) % 1000000007;

        return;
    }

    for (int i = 1; i <= cus; ++i){

        if (visited[i] == false){

            visited[i] = true;  total -= order[i];

            if (truck == truck_num){

                vrp(truck, cap - order[i], count + 1);
            }
            else{

                if (cap != max_cap)  vrp(truck + 1, max_cap - order[i], count + 1);

                if (cap >= order[i])  vrp(truck, cap - order[i], count + 1);
            }

            visited[i] = false;  total += order[i];
        }
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int fact[6] = {1, 1, 2, 6, 24, 120};

    cin >> cus >> truck_num >> max_cap;

    for (int i = 1; i <= cus; ++i){

        int tmp = 0;  cin >> tmp;  total += tmp;

        order.push_back(tmp);
        visited.push_back(false);
    }

    //
    vrp(1, max_cap, 0);

    //OUTPUT
    cout << route / fact[truck_num];

    return 0;
}