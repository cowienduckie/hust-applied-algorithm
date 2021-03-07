#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int num; cin >> num;
    int age[num], sorted[num], displease[num];

    for (int i = 0; i < num; ++i){
        cin >> age[i];
        sorted[i] = i;
    }

    auto compare = [&](int &x, int &y){
        if (age[x] != age[y]) return age[x] < age[y];
        else return x < y;
    };

    sort(sorted, sorted + num, compare);

    int current_min = sorted[0];
    for (int i = 0; i < num; ++i){
        int temp = sorted[i];
        current_min = max(current_min, temp);
        temp = current_min - temp -1;

        displease[sorted[i]] =  temp;
    }

    for (int i = 0; i < num; ++i){
        cout << displease[i] << ' ';
    }

    return 0;
}