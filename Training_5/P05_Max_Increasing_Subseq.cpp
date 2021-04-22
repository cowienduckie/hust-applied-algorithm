#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0;  cin >> num;

    int LIS_from[num + 1], arr[num + 1];

    for (int i = 1; i <= num; ++i)  cin >> arr[i];  arr[0] = INT_MIN;

    //
    for(int i = num; i >= 0; --i){

        LIS_from[i] = 1;

        for (int j = i + 1; j <= num; ++j){

            if (arr[i] < arr[j] && 1 + LIS_from[j] > LIS_from[i]){

                LIS_from[i] = 1 + LIS_from[j];
            }
        }
    }


    //OUTPUT
    cout << LIS_from[0] - 1;

    return 0;
}