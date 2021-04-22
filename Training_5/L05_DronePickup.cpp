#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

//Global Variables
int num = 0, limit = 0;

vector <pair <int, int> > point;  //first --> amount of goods | second --> amount of energy

int mem[3001][101];

//Functions
int drone(int last, int stop){

    if (last == num)  return 0;

    if (stop == 1){

        if (last + point[last].second >= num)  return point[num].first;
        else 
            return INT_MIN;
    }

    if (mem[last][stop] != -1)  return mem[last][stop];

    int good = INT_MIN;

    for (int i = last + 1; i <= num && i <= last + point[last].second; ++i){

        good = max(good, point[i].first + drone(i, stop - 1));
    }

    mem[last][stop] = good;

    return good;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> num >> limit;  point.resize(num + 1);

    for (int i = 1; i <= num; ++i)  cin >> point[i].first;
    for (int i = 1; i <= num; ++i)  cin >> point[i].second;

    //
    memset(mem , -1, sizeof(mem));

    int result = point[1].first + drone(1, limit);

    //OUTPUT
    if (result > 0)  cout << result;
    else 
        cout << -1;

    return 0;
}