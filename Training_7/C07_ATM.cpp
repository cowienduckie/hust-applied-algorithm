#include <iostream>
#include <cmath>

#define ull unsigned long long

using namespace std;

//Global Variables
ull val[64];


//Functions


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int test = 0, exp = 0;  cin >> test;

    for (int i = 0; i <= 60; i += 4){

        val[i] = 1000 * pow(10, exp);
        val[i + 1] = 2000 * pow(10, exp);
        val[i + 2] = 3000 * pow(10, exp);
        val[i + 3] = 5000 * pow(10, exp);

        ++exp;
    }

    //
    while (test--){
        
        ull W = 0, c = 0;  cin >> W >> c;


    }

    for (int i = 0; i < 64; ++i){

        cout << val[i] << endl;
    }

    return 0;
}