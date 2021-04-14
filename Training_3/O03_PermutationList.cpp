#include <iostream>
#include <vector>

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0, k = 0;  cin >> n >> k;

    int per[n + 1];
    vector <int> unvisited;

    for (int i = 1; i <= n; ++i){

        per[i] = i;
    }

    //
    int pos = 0, check = 0;  vector <int> :: iterator it;

    while (--k){

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

        check = pos; 

        for (it = unvisited.begin(); it != unvisited.end(); ++it){

            ++pos;

            per[pos] = *it;
        }

        unvisited.clear();

        if(check == 0) break;

    }


    //OUTPUT
    if (k != 0){

        printf("-1");
    }
    else{

        for (int i = 1; i <= n; ++i){

           printf("%d ", per[i]);
        }
    }


    return 0;
}

//Functions