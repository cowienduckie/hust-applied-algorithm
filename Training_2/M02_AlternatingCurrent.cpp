#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string str; cin >> str;
    stringstream ss(str);

    char curr;

    stack <char> s;

    while(!ss.fail()){
        curr = ss.get();

        if (curr != '+' && curr != '-') continue;

        if (s.empty() || curr != s.top()){
            s.push(curr);
        }
        else s.pop();
    }

    if (s.empty())  cout << "Yes";
    else    cout << "No";

    return 0;
}