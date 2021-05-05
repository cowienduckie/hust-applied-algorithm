#include <iostream>
#include <algorithm>

using namespace std;

int res = 0, c[6];  //C T D L G U

int calc(){

    return (c[0] * 10e4 + c[1] * 10e3 + (c[2] + c[1]) * 10e2 + (c[3] + c[1]) * 10e1 + (c[4] + c[5]) * 10 + c[1] + c[2]); 
}

void perm(int n){

    do{

        if (c[0] * c[1] == 0)  continue;

        if (calc() == n) ++res;

    }
    while (next_permutation(c, c + 6));
}

void n_choose_k(int i, int last, int n){

    for (int j = last + 1; j <= 9; ++j){

        c[i] = j;

        if (i == 5){

            perm(n);
        }
        else n_choose_k(i + 1, j, n);
    }
}

void solve(int n){

    n_choose_k(0, -1, n);

    cout << res;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int n = 0;  cin >> n;

    solve(n);

    return 0;
}