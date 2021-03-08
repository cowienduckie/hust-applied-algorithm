#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool br_check(char x, char y){  //Check current char and stack's top
    if ( (x == '(' && y == ')' ) || (x == '[' && y == ']') )
        return true;
    else return false;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string str, result; 
    cin >> str; str = "0" + str;//Initial bracket sequence

    int maxS = 0,  //Max square bracket
        square = 0, //Current square brackets
        last = 0,   //Index of last correct close bracket
        close = 0;  //Number of correct close bracket

    stack <char> s; //Check stack

    //A correct close bracket is the end of a correct substring
    //Put str into stack to check correctness normally
    //Stop to calculate square bracket that substring have
    //when meet a wrong close bracket
    for (int i = 1; i < str.length(); ++i){
        
        char chr = str[i];  //Store current bracket

        if (chr == '(' || chr == '['){  //Push all open brackets
            s.push(chr);
        }
        else {
            if (s.empty() || br_check(s.top(), chr) == false){   //Meet wrong close bracket
                int first = last + 1 - close * 2;   //First index of correct substring

                string sub = str.substr(first, last - first + 1);   //Correct substring

                //Compare result
                if (square >= maxS){
                    result = sub;
                    maxS = square;
                }

                //Reset counters and stack
                close = 0;
                square = 0;
                last = 0;
                while (s.empty() == false) s.pop();
            }
            else {  //Correct close bracket -> Update counters
                s.pop();

                last = i;
                ++close;
                if (chr == ']') ++square;
            }

        }
    }
    //If close != 0 --> Exist some wrong open brackets
    //Reverse above process with close bracket
    //If met wrong open bracket, break substring and calc result
    if (close != 0){
        while (s.empty() == false) s.pop(); //Reset stack

        square = 0; //Reset square counter
        string sub; //Store substring

        for (int i = last; close != -1; --i){  //Start from last and check backward
  
            char chr = str[i];  

            if ( chr == ']' || chr == ')' ){    //Push all close brackets
                s.push(chr);
                sub.push_back(chr);
                if (chr == ']') ++square;
            }
            else if (s.empty()){
                reverse(sub.begin(), sub.end());  //Correct substring

                if (square >= maxS){    //Compare result
                    result = sub;
                    maxS = square;
                }

                //Reset counters and stack;
                square = 0;
                sub = "";
                while (s.empty() == false) s.pop();

                if (close == 0) --close;    //End loop
            }
            else{   //Correct close bracket -> Update counters
                s.pop();
                sub.push_back(chr);

                --close;
            }
        }
    }
    
    //Output
    cout << maxS << endl << result << endl;

    return 0;
}