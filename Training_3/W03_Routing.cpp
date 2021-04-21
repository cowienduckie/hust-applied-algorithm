#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <sstream>

#define INF 1e9

using namespace std;

//Global Variables
int spot_num = 0, route_num = 0, first = 0, last = 0, len = 0;

vector <vector <int>> map;
vector <int> route;

int **mem;

//Functions
int tsp(int pos, int visited){

    if (mem[pos][visited] != 0) return mem[pos][visited];

    if (visited == (1 << (len - 1)) - 1){

        if (map[route[pos]][last] != 0)  return map[route[pos]][last];
        else
            return INF;
    }

    int result = INF;

    for (int i = 1; i < len - 1; ++i){

        if (visited & (1 << i) || map[route[pos]][route[i]] == 0)  continue;

        result = min(result, map[route[pos]][route[i]] + tsp(i, visited | (1 << i)));
    }

    mem[pos][visited] = result;

    return result;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> spot_num >> route_num;

    map.resize(spot_num + 1);

    for (int i = 1; i <= spot_num; ++i){

        map[i].resize(spot_num + 1);

        for (int j = 1; j <= spot_num; ++j){

            cin >> map[i][j];
        }
    }

    //
    string str;  getline(cin, str);

    while(route_num--){

        //INPUT
        int res = INF;  route.clear();
        
        int tmp = 0;  getline(cin, str);  stringstream ss(str);

        while(ss >> tmp){

            route.push_back(tmp);
        }
        
        len = route.size();  first = route[0];  last = route[len - 1];

        mem = (int **)calloc(len - 1, sizeof(int*));

        for (int i = 0; i < len - 1; ++i){

            mem[i] = (int *)calloc((1 << (len - 1)), sizeof(int));
        }

        //
        
        res = min(res, tsp(0, 1 << 0));

        //OUTPUT
        if (res < INF)  cout << res << endl;
        else 
            cout << 0 << endl;

        for (int i = 0; i < len - 1; ++i){

            free(mem[i]);
        }
        free(mem);
    }

    return 0;
}