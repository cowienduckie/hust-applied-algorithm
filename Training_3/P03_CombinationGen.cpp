#include <iostream>

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0, m = 0;  cin >> n >> m;

    int comb[m + 1];

    for (int i = 1; i <= m; ++i){  //Take input combination

        scanf("%d", comb + i);
    }

    //
    int pos = m, max = n;  //Consider from the last box

    ++comb[pos];  //Update next combination

    while (comb[pos] > max && pos > 0){ //Domino effect

        ++comb[pos - 1];

        --pos;  --max;
    }

    for (int i = pos + 1; i <= m; ++i){  //A box increases and all next boxes decreases

        comb[i] = comb[i - 1] + 1;
    } 
   
    //OUTPUT
    if (pos == 0){

        printf("-1");
    }
    else{

        for (int i = 1; i <= m; ++i){

            printf("%d ", comb[i]);
        }
    }
    

    return 0;
}

//Functions