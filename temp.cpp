#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    vector <int> v = {1, 2, 3, 4, 5};

    cout << v.size() << endl << endl;

    v = vector <int> ({1, 2});

    cout << v.size() << endl;

    return 0;
}