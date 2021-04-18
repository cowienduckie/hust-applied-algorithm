#include <iostream>
#include <vector>

using namespace std;

//Global Variables
int client_num = 0, truck_num = 0, max_cap = 0, route = 0;

vector <int> order;
vector <bool> visited;

void brute(int truck, int cap, int count){

    if (truck == truck_num && count == client_num){
        
        route = (route + 1) % 1000000007;

        return;
    }

    for (int i = 1; i <= client_num; ++i){

        if (visited[i] == false){

            visited[i] = true;

            if (truck == truck_num){

                if (cap < order[i]){

                    visited[i] = false;
                    return;
                }
                else{

                    brute(truck, cap - order[i], count + 1);
                }
            }
            else{

                if (cap != max_cap)  brute(truck + 1, max_cap - order[i], count + 1);

                if (cap >= order[i])  brute(truck, cap - order[i], count + 1);
            }

            visited[i] = false;
        }
    }
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> client_num >> truck_num >> max_cap;

    order.resize(client_num + 1);
    visited.resize(client_num + 1);

    for (int i = 1; i <= client_num; ++i){

        cin >> order[i];
        visited[i] = false;
    }
    visited[0] = true;

    //
    brute(1, max_cap, 0);

    //OUTPUT
    cout << route;

    return 0;
}