#include <iostream>
#include <string>       

using namespace std;

int main(){
    int num; cin >> num;
    int result[num];
    string str; //current string
    char value[26] =    {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
                       //a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
    char temp = getchar();
    for (int i = 0; i < num; ++i){
        getline(cin, str);
        
        int count = 0;
        for (auto &chr : str){
            if (chr == ' '){
                ++count;
            } else {
                count += value[chr - 'a'];
            }
        }
        
        result[i] = count;
    }

    for (int i = 0; i < num; ++i){
        cout << "Case #" << i+1 << ": " << result[i] << endl;
       
    }

    return 0;
}