#include <iostream>
#include <set>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    int n = 0, m = 0, res = 1;
    cin >> n;
    int arr_n[n]; set <int> store;
    for (int &i : arr_n){
        cin >> i;
        store.insert(i);
    }
    cin >> m;
    int arr_m[m];
    for (int &i : arr_m){
        cin >> i;
    }
    
    //Solution of
    for (int &i : arr_m){
        if (store.insert(i).second == true){
            res = 0;
            break;
        }
    }

    cout << res;

    return 0;
}