#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define N 10010

using namespace std;

vector <string> s(N, "");

string genZeros(int len, int z){

    string str;

    int counter = 1;

    for (int i = 1; i <= len; ++i){

        if (counter == z){

            str += "1";

            counter = 1;
        }
        else{

            str += "0";

            ++counter;
        }

        s[i] = str;
    }

    return str;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int n, k, z;  cin >> n >> k >> z;

    string str = genZeros(n, z);

    while (--k){

        bool skip = true;

        for (int i = n - 1; i >= 0; --i){

            if (str[i] == '0'){

                int len = n - i;

                skip = false;

                str[i] = '1';

                if (len == 0)  break;

                str.replace(i + 1, len, s[len]);

                break;
            }
        }

        if (skip) break;
    }

    if (k != 0)  cout << -1;
    else{

        for (int i = 0; i < n; ++i){

            printf("%c ", str[i]);
        }
    }
        

    return 0;
}