#include <iostream>

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0; long long result = 0;  cin >> num;

    long long arr[num], sum[num];

    for (long long &i :arr){

        cin >> i;
    }    

    //
    sum[0] = arr[0];
    result = sum[0];

    for (int i = 1; i < num; ++i){

        sum[i] = max (arr[i], sum[i - 1] + arr[i]);

        result = max(result, sum[i]);
    }


    //OUTPUT
    cout << result;

    return 0;
}

//Functions
