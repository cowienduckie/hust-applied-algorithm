#include <iostream>
#include <set>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    int num; cin >> num;

    set <int> set_1;    //Product < 0
    set <int> set_2;    //Product > 0
    set <int> set_3;    //Product = 0

    //
    int product = 1;

    for (int i = 0; i < num; ++i){
        int temp;

        cin >> temp;

        if (temp <= 0){
            if (set_3.insert(temp).second == false){

                set_1.insert(temp);

                product *= temp;
            }
        }
        else {
            if (set_2.insert(temp).second == false){

                set_1.insert(temp);
            }
        }
    }

    if (set_1.empty() || product > 0){
        int neg = *(--set_3.lower_bound(0));

        set_1.insert(neg);
        set_3.erase(neg);
    }
    else if (product == 0){
        int neg = *(--set_3.lower_bound(0));

        set_1.insert(neg);
        set_3.erase(neg);

        set_1.erase(0);
        set_3.insert(0);
    }

    if (set_2.empty()){
        int neg = *(--set_3.lower_bound(0));

        set_2.insert(neg);
        set_3.erase(neg);

        neg = *(--set_3.lower_bound(0));

        set_2.insert(neg);
        set_3.erase(neg);
    }
    

    //Output
    set <int> :: iterator it;

    cout << set_1.size();
    for (it = set_1.begin(); it != set_1.end(); ++it)
       cout << ' ' << *it;

    cout << endl << set_2.size();
    for (it = set_2.begin(); it != set_2.end(); ++it)
       cout << ' ' << *it;

    cout << endl << set_3.size();
    for (it = set_3.begin(); it != set_3.end(); ++it)
       cout << ' ' << *it;

    return 0;
}