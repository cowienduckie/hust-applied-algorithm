#include <iostream>

using namespace std;

int main()
{
    int num; cin >> num;
    string str;

    while (num--){
        cin >> str;
        if (str.length() > 10){
            cout << str[0] << str.length() - 2 << str[str.length()-1] << endl;
        } else {
            cout << str << endl;
        }
    }

    return 0;
}