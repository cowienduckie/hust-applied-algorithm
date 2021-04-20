#include <iostream>
#include <algorithm>

using namespace std;

//Global Variables
int num = 0, result = 0;
int c[7];   //0  1  2  3  4  5  6
            //I  C  T  H  U  S  K

//
void calculator(){

    do{
        int tmp = (100*c[0] + 10*c[1] + c[2]) - (100*c[6] + 62) + (1000*c[3] + 100*c[4] + 10*c[5] + c[2]);

        if (tmp == num){  
        
            ++result;
        }
    }while(next_permutation(c, c + 7));
}

void n_choose_k(int n, int k, int last, int count){

    for (int i = last + 1; i <= n; ++i){

        c[count] = i;

        if (count == k - 1){

            calculator();
        }
        else 
            n_choose_k(n, k, i,count + 1);
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> num;

    //
    
    n_choose_k(9, 7, 0, 0);

    //OUTPUT
    cout << result;


    return 0;
}