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
    ll *sum_even = (ll *)calloc(num, sizeof(ll));   //Max even subseq sum end with ith element
    ll *sum_odd = (ll *)calloc(num, sizeof(ll));    //Max odd subseq sum end with ith element

    for (int i = 0; i < num; ++i){

        cin >> arr[i];
    }    

    //There are 2 cases that no solution
    //n = 1 and that is odd,    n = 2 and these are 1 odd and 1 even

    if ((num == 1 && arr[0] % 2 == 1) || (num == 2 && (arr[0] + arr[1]) % 2 == 1)){

        cout << "NOT_FOUND";
        exit(0);
    }

    //Consider ith number a[i]:
    //If a[i] is odd -->    sum_even[i] = sum_odd[i-1] + a[i]
    //                      sum_odd[i] = max of a[i] and a[i] + sum_even[i-1]
    //
    //If a[i] is even -->   sum_odd[i] = sum_odd[i-1] + a[i]
    //                      sum_even[i] = max of a[i] and a[i] + sum_even[i-1]
    // 
    //Above algorithm is easy to understand if initial value of 2 sum arrays are right
    //What if first element is even, how first sum_odd initiated???
    //Always start above algorithm after first odd element in sequence
    //Calculate all previous sum_even of previous even elements
    int i = 1;

    //Init values for first element
    if (arr[0] % 2 == 0){   //If first element is even, find first odd element

        sum_even[i] = arr[0];
        
        result = arr[0];

        for (; i < num; ++i){  //All element before the first odd element are even, so calculate sum_even and update result normally

            if (arr[i] % 2 == 0){
                    
                sum_even[i] = max(sum_even[i - 1] + arr[i], arr[i]);            
            }
            else{  //First odd element is found, init values for algorithm

                sum_even[i] = 0;
                sum_odd[i] = arr[i] + sum_even[i - 1];

                break;
            }

            result = max(sum_even[i], result);
        }
    }
    else{  //If first element is odd, start algorithm normally

        sum_even[0] = 0;
        sum_odd[0] = arr[0];

        i = 0;
    }

    
    //Main algorithm
    for ( i = i + 1; i < num; ++i){

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
    cout << result;
    
    return 0;
}

//Functions
