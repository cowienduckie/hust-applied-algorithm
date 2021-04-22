#include <iostream>

using namespace std;

//Global Variables
int n = 0, k = 0, limit = 0;

char *bit_str;

//Functions
void brutal_zero(int pos, int zero){

    if (pos == n){

        --k;

        if (k == 0){

            for (int i = 0; i < n; ++i){

                printf("%c ", *(bit_str + i));
            }

            exit(0);
        }

        return;
    }

    if (zero + 1 < limit){

        bit_str[pos] = '0';

        brutal_zero(pos + 1, zero + 1);
    }

    bit_str[pos] = '1';

    brutal_zero(pos + 1, 0);
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> n >> k >> limit;

    bit_str = (char *)calloc(n, sizeof(char));

    //
    brutal_zero(0, 0);

    //OUTPUT
    cout << -1;

    return 0;
}