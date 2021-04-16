#include <iostream>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int ins_num;  cin >> ins_num;

    //
    int x = 0;

    for (int i = 0; i < ins_num; ++i){

        string tmp;  cin >>tmp;

        if (tmp[0] == 'X'){

            if (tmp[1] == '+') ++x;
            else
                --x;
        }
        else if (tmp[0] == '+') ++x;

        else
            --x;
        
    }

    //OUTPUT
    cout << x;


    return 0;
}