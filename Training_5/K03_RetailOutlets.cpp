#include <iostream>
#include <vector>
#include <cstring>

#define m 1000000007

using namespace std;

//Global Variables
int branch_num = 0, outlet_num = 0;

vector <int> branch;

int mem[101][501];

//Functions
int dist(int br, int outlet){

    if (mem[br][outlet] != -1)  return mem[br][outlet];

    if (br == branch_num){

        if(outlet % branch[br] == 0)  return 1;
        else 
            return 0;
    }

    if (outlet == 0)  return 1;

    int times = outlet / branch[br], counter = 0;

    for (int i = 1; i <= times; ++i){

        counter += dist(br + 1, outlet - branch[br] * i);

        counter %= m;
    }

    counter += dist(br + 1, outlet);

    mem[br][outlet] = counter % m;

    return counter % m;
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> branch_num >> outlet_num;  branch.resize(branch_num + 1);

    for (int i = 1; i <= branch_num; ++i){

        cin >> branch[i];

        outlet_num -= branch[i];
    }

    //
    memset(mem, -1, sizeof(mem));

    //OUTPUT
    cout << dist(1, outlet_num);

    return 0;
}