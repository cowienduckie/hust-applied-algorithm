#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int n = 0;  cin >> n;

    int *tree = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)  cin >> tree[i];

    //
    sort(tree, tree + n);

    int timer = 0;

    for (int i = n - 1; i >= 0; --i){

        --timer;

        timer = max(timer, tree[i]);
    }

    //OUTPUT
    cout << timer + n + 1<< endl;


    return 0;
}