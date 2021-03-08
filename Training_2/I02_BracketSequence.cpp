#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool br_check(char x, char y) { //Check correct bracket pair
    if (( x == '(' && y == ')' )  ||  ( x == '[' && y == ']' )) return true;
    else return false;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    string str; cin >> str; //Bracket Sequence
    
    vector <int> index; //Mark correctness of brackets in str -> 1 = correct  0 = incorrect
    index.resize(str.length(), 0); index.push_back(24); //Initiate value 0

    stack <int> s;  //Check stack

    //
    for (int i = 0; i < str.length(); ++i){
        
        char chr = str[i];  //Current bracket

        //Normal brackets check
        if (chr == '('|| chr == '['){
            s.push(i);
        }
        else if (s.empty() || br_check( str[s.top()], chr ) == false){
            //When meet wrong closing, empty stack and continue
            while(s.empty() == false)   s.pop();

            continue;
        }
        else {  //When meet correct closing, mark both correct closing and opening
            index[s.top()] = 1;
            index[i] = 1;

            s.pop();    
        }
    }

    string sub, result; //temp substring and final result
    int square = 0, max_square = -1;    //square bracket counter and max square bracket

    for (int i = 0; i <= index.size(); ++i){

        if (index[i] == 1){ //Store correct ones until meet the incorrect
            if (str[i] == '[')  ++square;   //Count square bracket
            
            sub.push_back(str[i]);
        }
        else {
            if (square > max_square){   //Compare with present result
                max_square = square;
                result = sub;
            }

            sub = "";   //Reset temp values
            square = 0;
        }
    }

    //Output
    cout << max(max_square, 0) << endl << result << endl;   

    return 0;
}