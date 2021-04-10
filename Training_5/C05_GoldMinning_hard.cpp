#include <iostream>

#define ll long long

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0, min_dist = 0, max_dist = 0, track = 0;
    cin >> num >> min_dist >> max_dist;  

    ll whouse[num], gold[num], result = 0, max_prev = 0;

    for(int i = 0; i < num; ++i){

        cin >> gold[i];
    }

    max_prev = gold[0];
    
    //
    for (int i = min_dist; i < num; ++i){

        if (track < i - max_dist){

            ll tmp = 0;

            for (int d = min_dist; d <= max_dist; ++d){

                if (tmp < gold[i - d]){

                    track = i - d;
                    max_prev = gold[track];
                }
            }            
        }

        if (max_prev < gold[i - min_dist]){

            track = i - min_dist;
            max_prev = gold[track];
        }
        
        gold[i] = max_prev + gold[i];

        result = max(result, gold[i]);
    }

    //OUTPUT
    cout << result;

    return 0;
}

//Functions