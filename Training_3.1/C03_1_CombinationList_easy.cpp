#include <iostream>

using namespace std;

void printRes(int comb[], int m){
    for (int i = 1; i <= m; ++i){
        cout << comb[i] << ' ';
    }
    cout << endl;
}

void combinationList(int n, int m, int last, int count, int comb[]){

    for (int i = last + 1; i <= n; ++i){
        
        comb[count + 1] = i;

        if ((count + 1) == m){
            printRes(comb, m);
        } 
        else
            combinationList(n, m, i, count + 1, comb);
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;  cin >> n >> m;

    int comb[m + 1];

    combinationList(n, m, 0, 0, comb);

    return 0;
}