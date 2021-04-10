#include <iostream>
#include <limits>

#define ll long long

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0; ll result = LLONG_MIN;  cin >> num;

    ll *arr = (ll *)calloc(num, sizeof(ll));
    ll *sum_even = (ll *)calloc(num, sizeof(ll));
    ll *sum_odd = (ll *)calloc(num, sizeof(ll));

    for (int i = 0; i < num; ++i){

        cin >> arr[i];
    }    

    //
    if (arr[0] % 2 == 0){

        sum_even[0] = arr[0];

        result = arr[0];
    }
    else {

        sum_odd[0] = arr[0];
    }


    for (int i = 1; i < num; ++i){

        if (arr[i] % 2 == 0){

            sum_even[i] = max(sum_even[i - 1] + arr[i], arr[i]);

            sum_odd[i] = sum_odd[i - 1] + arr[i];
        }
        else{

            sum_odd[i] = max(sum_even[i - 1] + arr[i], arr[i]);

            sum_even[i] = sum_odd[i - 1] + arr[i];
        }

        result = max(result, sum_even[i]);
    }

    //OUTPUT
    if (result != LLONG_MIN)  cout << result;
    else
        cout << "NOT_FOUND";
    
    return 0;
}

//Functions
