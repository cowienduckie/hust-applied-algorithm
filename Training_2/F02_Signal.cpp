#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    int num = 0, b =0, result = -1;
    cin >> num >> b;
    int a[num];
    for (int i = 0; i < num; ++i){
        cin >> a[i];
    }

    if (num < 3){
        cout << -1;
        return 0;
    }

    //Calc max left array of every element
    int max_left[num]; max_left[0] = INT_MIN;
    for (int i = 1; i <= num - 2; ++i){
        max_left[i] = max(max_left[i-1], a[i-1]);
    }

    //Calc max right array of every element
    int max_right[num]; max_right[num-1] = INT_MIN;
    for (int i = num - 2; i >= 1; --i){
        max_right[i] = max(max_right[i+1], a[i+1]);
    }

    //Calc result
    for (int i = 1; i <= num - 2; ++i){
        if (max_left[i] - a[i] >= b && max_right[i] - a[i] >= b){
            int temp = max_left[i] + max_right[i] - 2 * a[i];
            if (temp > result) result = temp;
        }
    }

    cout << result;

    return 0;
}