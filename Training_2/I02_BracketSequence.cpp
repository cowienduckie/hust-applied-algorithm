#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool bracket_check(char top, char chr){
    if (( top == '(' && chr == ')' ) || ( top == '[' && chr == ']' )){
        return true;
    }
    else return false;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string origin;    cin >> origin; //Take original string;

    int close = 0, closeS = 0, //close and square close brackets
        last = 0; //last position of a correct close bracket

    stack <char> check;
    vector <string> result_sub;
    vector <int> result_closeS;

    for (int i = 0; i < origin.length(); ++i){
        char chr = origin[i];

        if (chr == '(' || chr == '['){   //Push all opening brackets;
            check.push(chr);
        }
        else {
            if (check.empty() || bracket_check(check.top(), chr) == false){
                if (close == 0) continue;

                //Take correct substring
                int first = last - 2 * close + 1; //position of substring's first letter
                string sub;

                for( ; first <= last; ++first){ //Take substring from first -> last
                    sub.push_back(origin[first]);
                }
                result_sub.push_back(sub);
                result_closeS.push_back(closeS);

                //Reset close, last counter and check stack
                close = 0; last = 0; closeS = 0;

                while (check.empty() == false){
                    check.pop();
                }
            }
            else{
                ++close;
                last = i;
                check.pop();

                if (chr == ']') ++closeS;
            }
        }
    }

    if (close != 0){
        string sub = "";
        closeS = 0;

        stack <char> s;

        while (close != 0){
            char chr = origin[last];

            if (chr == ']' || chr == ')'){
                s.push(chr);
                sub.push_back(chr);

                if(chr == ']') closeS++;
            }
            else {
                if(s.empty()){
                    reverse(sub.begin(), sub.end());
                    result_sub.push_back(sub);
                    result_closeS.push_back(closeS);
                    closeS = 0;
                    sub = "";
                }
                else {
                    sub.push_back(chr);
                    s.pop();
                    --close;
                }
            }

            --last;
        }

        reverse(sub.begin(), sub.end());
        result_sub.push_back(sub);
        result_closeS.push_back(closeS);
    }

    if (result_sub.empty()) {
        result_sub.push_back("");
        result_closeS.push_back(0);
    }
    
    int max = -1, index = 0;

    for (int i = 0; i < result_sub.size(); ++i){  //Print optimal substrings
        if (result_closeS[i] >= max){
            max = result_closeS[i];
            index = i;
        }
    }

    //Output
    cout << max << endl << result_sub[index] << endl;

    return 0;
}