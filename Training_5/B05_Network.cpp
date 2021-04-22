#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long
#define INF 1e9

using namespace std;

//Global Variables
int city_num = 0, path_len = 0, cable_num = 0;

vector <vector <pair <int, int> > > network;

vector <vector <ull> > mem;

vector <int> path;

//Functions
ull link(int last_sv, int pos){

    if (mem[last_sv][pos] != 0) return mem[last_sv][pos];

    ull result = INF;

    for (pair <int, int> sv : network[last_sv]){

        vector <int> :: iterator tmp = find(path.begin(), path.end(), sv.first);

        if (tmp == path.end()){

            if (pos == path_len){

                if (result > sv.second)  result = sv.second;

            }
            else{

                path.push_back(sv.first);

                result = min(result, sv.second + link(sv.first, pos + 1));

                path.pop_back();
            }
        }
    }

    mem[last_sv][pos] = result;

    return result;
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

    mem.resize(city_num + 1);

    for (int i = 0; i <= city_num; ++i){

        mem[i].resize(path_len + 1);

        for (int j = 0; j <= path_len; ++j){

            mem[i][j] = 0;
        }
    }

    //OUTPUT
    cout << link(0,0);

    return 0;
}