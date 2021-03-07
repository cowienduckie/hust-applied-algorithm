#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char **argv){
    int num = 0; cin >> num;
    int res[num];
    string str;


    for (int i = 0; i < num; ++i){
        cin >> str;

        stack <char> stk;
        int result = 1;

        for (auto &chr : str){
            if (chr == ')' || chr == ']' || chr == '}'){
                if (stk.empty()){
                    result = 0;
                    break;
                }
                else if (stk.top() == '(' && chr == ')'){
                    stk.pop();
                }
                else if (stk.top() == '[' && chr == ']'){
                    stk.pop();
                }
                else if (stk.top() == '{' && chr == '}'){
                    stk.pop();
                }
                else {
                    break;
                }
            } else {
                stk.push(chr);
            }
        }

        if (!stk.empty())    result = 0;

        cout << result << endl;
    }

    return 0;
}