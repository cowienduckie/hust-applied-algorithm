#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int digit = 0, check = 0;  cin >> digit;
    string str;
    getline(cin, str);  getline(cin, str);

    //
    for (int i = digit - 1; i >= 0; --i){

        if (str[i] == '0'){

            str.replace(i, 1, "1");

            for (int j = i + 1; j < digit; ++j){

                str.replace(j, 1, "0");
            }

            check = 1;  break;
        }
    }


    //OUTPUT
    if (check == 1)  cout << str;
    else 
        cout << -1;

    return 0;
}