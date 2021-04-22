#include <iostream>
#include <limits>

#define ull unsigned long long 

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0;  cin >> num;

    int arr[num], min_until[num], minimum = INT_MAX;

    for (int i = 0; i < num; ++i){  

        cin >> arr[i];

        minimum = min(arr[i], minimum);

        min_until[i] = minimum;
    }

    int pair = 0;  cin >> pair;

    //
    ull result = 0;

    for (int i = 1; i <= pair; ++i){

        int src = 0, dst = 0;  cin >> src >> dst;

        if (min_until[src] != min_until[dst]){

            result += min_until[dst];
        }
        else{

            int tmp = INT_MAX;
            for (int i = src; i <= dst; ++i){

                tmp = min(tmp, arr[i]);
            }

            result += tmp;
        }
    }

    //OUTPUT
    cout << result;                                         


    return 0;
}