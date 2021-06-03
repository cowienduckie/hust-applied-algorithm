#include <iostream>
#include <string>
#include <stack>

#define M 1000000007

using namespace std;

//Global Variables
string s; 
int len = 0, result;
stack <char> st;

//Functions
void brute(int i){

    if (i == len){

        if (st.empty())  result = (result + 1) % M;
    }

    if (s[i] == '?'){

        st.push('(');  


        brute(i + 1);

        st.pop();
        

        if (!st.empty()){

            st.pop();

            brute(i + 1);

            st.push(')');
        }     
    }
    else if (s[i] == '('){

            st.push('(');

            brute(i + 1);

            st.pop();
    }
    else{

        if (st.empty()){

            return;
        }
        else{

            st.pop();

            brute(i + 1);

            st.push(')');
        }
    }      
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    getline(cin, s);  len = s.length();

    brute(0);

    cout << result;

    return 0;
}