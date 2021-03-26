#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int num, cond;  cin >> num >> cond;

    vector <pair <int, int>> precedence;

    while(cond--){
        int a, b; cin >> a >> b;

        precedence.push_back(make_pair(a, b));
    }
    
    return 0;
}