#include <iostream>

using namespace std;

//Global Variables


//List of functions


//Main
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0, m = 0, k = 0;  cin >> n >> m >> k;

    int comb[m + 1];

    //
    for (int i = 1; i <= m; ++i){  //Initiate first configuration

        comb[i] = i;
    }

    /*
        Denote m-subset of n is m boxes conataining numbers
        The first subset is [1][2][3]...[m-1][m] also the minimum number in each box
        Maximum number in each box is the nCm th subset [n-m+1][n-m+2]...[n-m+1][n]

        Rule:
            When a box exceed max value, prev box increasing by 1.
            When a box increases by 1, all next boxes decrease to their new minimums.
                Example: [a][b][c]...[x][y][z] and x increase by 1. Then [a][b][c]...[x + 1][x + 2][x + 3].
            Consider from the back, last box is always first box exceed maximum. Then it make its previous and so forth.
            That domino effect until when a box increase by 1 but not exceed max or every boxes exceeded max.

        Loop end when we found kth combination or k is greater than nCm 
    */
    int pos = 0, max = 0;  //Current position and maximum number of each box

    while (--k){  //Because 1st combination is calculated so k must decrease before loop.

        pos = m, max = n;  //Consider from the last box

        ++comb[pos];  //Update next combination

        while (comb[pos] > max && pos > 0){ //Domino effect

            ++comb[pos - 1];

            --pos;  --max;
        }

        for (int i = pos + 1; i <= m; ++i){  //A box increases and all next boxes decreases

            comb[i] = comb[i - 1] + 1;
        }

        if (pos == 0) break;  //Last combination mean first box reach its maximum and position point to zero
    }

    //OUTPUT
    if (k != 0){  //k greater than nCm

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