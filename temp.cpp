#include <iostream>
#include <bitset>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void max_1(int n){
    
    string binary = bitset<32>(n).to_string();
    
    int count = 0, res = 0;
    
    for (int i = 0; i < 32; ++i){
        
        if (binary[i] == '1'){
            
            ++count;
        }
        else{
            
            res = max(res, count);
            
            count = 0;
        }
    }
    
    cout << binary;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    max_1(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
