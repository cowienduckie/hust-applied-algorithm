//Note: I think this is greedy algorithm but not exhaustive search algorithm
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

//Global Variables
int n = 0, k = 0;  

int per[10001];

int unused[14];

//List of functions


//Main
int main(int argc, char **argv){ 
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    scanf("%d %d", &n, &k);


    //
    int x = 1;  unsigned long long fact = 1; 

    for (int i = 1; i <= n; ++i){

        per[i] = i;

        if (fact <= k){

            x = i;  fact = fact * x;
        }
    }  

    if (k > fact){

        printf("-1");
        exit(0);
    }

    for (int i = 1; i <= 13; ++i){

        if (i <= x)  unused[i] = n - x + i;
        else
            unused[i] = INT_MAX;
    }

    //
    int index = INT_MAX - 1;

    while(k > 0) { 

        fact = 1;        
        for (x = 1; x <= 13; ++x){

            fact = fact * x;
            
            if (k < fact) break;
        }

        for (int i = index + 1; i <= n - x; ++i){

            per[i] = unused[1];
            unused[1] = INT_MAX;

            sort(unused + 1, unused + 14); 
        }

        fact = fact / x; 

        int y = k / fact;  k = k % fact; index = n - x + 1;  

        if (k != 0) ++y;

        per[index] = unused[y];
        unused[y] = INT_MAX;

        sort(unused + 1, unused + 14);
        
        if ( k == 0){

            int pos = 1;
            for (int i = n; i >= n - x + 2; --i){

                per[i] = unused[pos];

                ++pos;
            }
        }
    }


    //OUTPUT

    for (int i = 1; i <= n; ++i){

       printf("%d ", per[i]);
    }

    return 0;
}

//Functions