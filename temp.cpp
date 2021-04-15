#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Global Variables
int n = 0, k = 0;  

int per[10001];

vector <int> unvisited;

//List of functions


//Main
int main(int argc, char **argv){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    scanf("%d %d", &n, &k);


    //
    int x = 1; unsigned long long fact = 1; 

    for (int i = 1; i <= n; ++i){

        per[i] = i;

        if (fact <= k){

            x = i;

            fact = fact * x;
        }
    }  

    if (k > fact){

        printf("-1");

        exit(0);
    }

    fact = fact / x; 

    int y = k / fact, pos = n - x + 2;

    per[n - x + 1] = n - x + y;
    per[n - x + y] = n - x + 1;

    for (int i = n; i>= n - x + 1; --i){

        if (i != per[n - x + 1]){

            per[pos] = i;

            ++pos;
        }
    }

    k = k % fact;

    int check = 0;  vector <int> :: iterator it;  
 
    while (k--){

        pos = n + 1;  check = 0;

        while (check == 0 && pos >= 1){

            --pos; unvisited.push_back(per[pos]);

            for (it = unvisited.begin(); it != unvisited.end(); ++it){

                if (per[pos] < *it){

                    int tmp = *it;

                    *it = per[pos];

                    per[pos] = tmp;

                    check = 1;

                    break;
                }
            }
        }

        for (it = unvisited.begin(); it != unvisited.end(); ++it){

            ++pos;

            per[pos] = *it;
        }

        unvisited.clear();
    }
 

    //OUTPUT

   for (int i = 1; i <= n; ++i){

       printf("%d ", per[i]);
    }

    return 0;
}

//Functions