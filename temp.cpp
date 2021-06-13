#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int a , b , c;  cin >> a >> b >> c;

    string s; cin >> s;

    cout << (a + b + c) << " " << s << endl;

    return 0;
}