#include <iostream>

#define ll long long

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0, min_dist = 0, max_dist = 0;
    cin >> num >> min_dist >> max_dist;  

    ll whouse[num], gold[num], result = 0;

    for(int i = 0; i < num; ++i){

        cin >> whouse[i];
        gold[i] = whouse[i];
    }
    //
    for (int i = 0; i < num; ++i){

        ll tmp = 0; 

        for (int d = min_dist; d <= max_dist; ++d){

            if (i - d >= 0){

                tmp = max(tmp, gold[i - d]);
            }
            else break;
        }

        gold[i] += tmp;

        result = max(result, gold[i]);
    }

    //OUTPUT
    cout << result;

    return 0;
}

//Functions