#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//Global Variables
int station_num = 0, max_time = 0, max_dist = 0;  

vector < pair <int, int> > station;  //first --> amount of goods | second --> pickup time

int mem[1001][101];

//Functions
int travel(int last, int time){

    if (mem[last][time] != -1)  return mem[last][time];

    int good = 0;

    for (int i = last + 1; i <= station_num && i <= last + max_dist; ++i){

        if (time >= station[i].second)
            good = max(good, station[i].first + travel(i, time - station[i].second));
    }

    mem[last][time] = good;

    return good;
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> station_num >> max_time >> max_dist;

    
    station.resize(station_num + 1);  memset(mem, -1, sizeof(mem));

    for (int i = 1; i <= station_num; ++i) cin >> station[i].first;
    for (int i = 1; i <= station_num; ++i) cin >> station[i].second;

    //
    int result = 0;

    for (int i = 1; i <= station_num; ++i){

        result = max(result, station[i].first +  travel(i, max_time - station[i].second));
    }


    //OUTPUT
    cout << result << endl;


    return 0;
}