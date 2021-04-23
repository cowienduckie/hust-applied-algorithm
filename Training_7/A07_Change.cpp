#include <iostream>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int N = 0, note = 0;  cin >> N;  N = 1000 - N;

    int vnd[] = {500, 100, 50, 10, 5, 1};

    //
    for (int i = 0; i < 6; ++i){

        int tmp = N / vnd[i];

        note += tmp;
        N -= tmp * vnd[i];
    }
    

    //OUTPUT
    cout << note;

    return 0;
}