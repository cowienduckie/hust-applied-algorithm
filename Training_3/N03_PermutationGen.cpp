#include <iostream>

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0;  cin >> n;

    int perm[n + 1];  bool check[n + 1];  perm[0] = 0;

    for (int i = 1; i <= n; ++i){

        scanf("%d", perm + i);
        check[i] = true;
    }

    //
    int pos = n + 1;  int tmp = 0;

    do{ 
        --pos;  check[ perm[pos] ] = false;  ++perm[pos];

        while(perm[pos] <= n){

            if (check[ perm[pos] ] == false){

                check[ perm[pos] ] = true;
                tmp = 1;
                break;
            }
                
            ++perm[pos];
        }
            
    } while(tmp == 0);

    tmp = pos;

    for (int i = 1; i<= n; ++i){

        if (check[i] == false){

            ++tmp;
            perm[tmp] = i;
            check[i] = true;
        }
    }

    //OUTPUT
    if (pos == 0){

        printf("-1");
    }
    else{

        for (int i = 1; i <= n; ++i){

            printf("%d ", perm[i]);
        }
    }

    return 0;
}

//Functions