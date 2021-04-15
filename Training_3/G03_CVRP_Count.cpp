#include <iostream>
#include <vector>

#define mod 1000000007 

using namespace std;

//Global Variables
int truck_num = 0, cap_max = 0, client_num = 0, result = 0;

vector <vector <int> > route;
vector <bool> visited;
vector <int> client;

//
void brute(int truck, int cap){

    for (int i = 1; i <= client_num; ++i){

        if (visited[i] == false && cap >= client[i]){

            visited[i] = true;

            brute(truck, cap - client[i]);

            if (truck != truck_num - 1){

                brute(truck + 1, cap - client[i]);
            }

            visited[i] = false;
        }
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> client_num >> truck_num >> cap_max;

    route.resize(truck_num);
    client.resize(client_num + 1);
    visited.resize(client_num + 1);

    for (int i = 1; i <= client_num; ++i){

        cin >> client[i];
        visited[i] = false;
    }

    //
    


    //OUTPUT
    cout << result % mod;

    return 0;
}