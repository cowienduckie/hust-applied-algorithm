#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ull unsigned long long
#define INF 1e9

using namespace std;

//Global Variables
int city_num = 0, path_len = 0, cable_num = 0, result = INF;

vector <vector <pair <int, int> > > network;

vector <int> path;

//Functions
void link(int last_sv, int pos, int cost){

    if (cost >= result) return;

    for (pair <int, int> sv : network[last_sv]){

        vector <int> :: iterator tmp = find(path.begin(), path.end(), sv.first);

        if (tmp == path.end()){

            if (pos == path_len){

                result = min(result, cost + sv.second);

            }
            else{

                path.push_back(sv.first);

                link(sv.first, pos + 1, cost + sv.second);

                path.pop_back();
            }
        }
    }
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> city_num >> path_len >> cable_num;
 
    network.resize(city_num + 1);

    for (int i = 1; i <= cable_num; ++i){

        int src = 0, dst = 0, cost = 0;  cin >> src >> dst >> cost;  

        network[src].push_back({dst, cost});
        network[dst].push_back({src, cost});
    }

    //
    for (int i = 1; i <= city_num; ++i){

        network[0].push_back({i, 0});
    }

    link(0, 0, 0);

    //OUTPUT
    cout << result;

    return 0;
}