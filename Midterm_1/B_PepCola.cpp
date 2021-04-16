#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int store_num = 0;  cin >> store_num;
    int store[store_num];

    for (int i = 0; i < store_num; ++i){

        cin >> store[i];
    }
    sort(store, store + store_num);


    int day_num = 0;  cin >> day_num;

    //
    for (int i = 0; i < day_num; ++i){

        int money = 0;  cin >> money;

        if (store[0] > money){

            cout << 0 << endl;
            continue;
        }
        else if (store[store_num - 1] <= money){

            cout << store_num << endl;
            continue;
        }

        int left = 0, right = store_num - 1;

        while (left < right - 1){

            int mid = (left + right) / 2;

            if (store[mid] > money)  right = mid;
            else
                left = mid;
        }

        cout << right << endl;
    }


    //OUTPUT


    return 0;
}