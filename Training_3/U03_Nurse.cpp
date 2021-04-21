#include <iostream>

#define m 1000000007

using namespace std;

//Global Variables
int day_num = 0, min_work = 0, max_work = 0, result = 0;

//Functions
void nurse(int today, int on, int off){ //on -> number of work days until yesterday | off -> is yesterday a dayoff?
    if (today > day_num){

        if (off == 1 || on >= min_work){

            ++result;

            result %= m;
        }
        return;
    }

    if (on >= min_work && on <=max_work)  nurse(today + 1, 0, 1);
    
    if (on < max_work)  nurse(today + 1, on + 1, 0);
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> day_num >> min_work >> max_work;

    //
    nurse(2, 1, 0);
    nurse(2, 0, 1);

    //OUTPUT
    cout << result;

    return 0;
}