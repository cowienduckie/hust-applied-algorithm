#include <iostream>
#include <string>

using namespace std;

//Global Variables
int n = 0, k = 0, zero = 0;  

string str;
string brute[10000];

//Functions
void brutal_zero(){

    int zero_count = 1;  string tmp;

    for (int i = 0; i < n; ++i){

        if(zero_count < zero){

            tmp += "0";

            ++zero_count;
        }
        else{

            tmp += "1";

            zero_count = 1;
        }

        brute[n - i - 1] = tmp;
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> n >> k >> zero;

    //
    brutal_zero();

    str = brute[0]; 

    while(--k){

        int check = 0;

        for (int i = n - 1; i >= 0; --i){

            if (str[i] == '0'){

                string tmp;

                if (i == n - 1)  tmp = "1";
                else
                    tmp = "1" + brute[i + 1];
                
                str.replace(i, n - i, tmp);

                check = 1;  break;
            }
        }

        if (check == 0){

            cout << -1;

            return 0;
        }
    }
    
    //OUTPUT
    for (int i = 0; i < n; ++i)  printf("%c ", str[i]);

    return 0;
}