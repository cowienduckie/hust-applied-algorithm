#include <iostream>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int target = 0, num = 0, trip = 0;  cin >> num >> target;

    int arr[num + 1];

    for (int i = 1; i <= num; ++i){
        cin >> arr[i];
    }

    //Denote duplets[max_index][sum of 2 backward numbers] 
    //Store all sum of 2 backward numbers = [j] + a[k] < target -> There is possible a[i]
    int **duplets = (int**)calloc(num + 1, sizeof(int*));

    for (int i = 2; i <= num - 1; ++i){

        duplets[i] = (int*)calloc(target + 1, sizeof(int));

        for (int j = i + 1; j <= num; ++j){

            int temp = arr[j] + arr[i];

            if (temp < target)  ++duplets[i][temp];
        }
    }

    for (int i = 1; i <= num - 2; ++i){

        for (int j = i + 1; j <= num - 1; ++j){

            int temp = target - arr[i];

            if (temp > 0)   trip += duplets[j][temp];
        }
    }    

    //OUTPUT
    cout << trip;

    return 0;
}