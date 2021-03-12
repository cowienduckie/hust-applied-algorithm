#include <iostream>

using namespace std;

int num = 0;

int arr[11];
bool mark[11];

void printPermutation(){
    for (int i = 1; i <= num; ++i){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void permutation(int curr){
    for (int i = 1; i <= num; ++i){
        if (mark[i] == false){
            arr[curr] = i;
            mark[i] = true;

            if (curr == num) printPermutation();
            else permutation(curr + 1);

            mark[i] = false;
        }
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> num;

    for (int i = 1; i <= num; ++i){
        arr[i] = i;
        mark[i] = false;
    }

    permutation(1);

    return 0;
}