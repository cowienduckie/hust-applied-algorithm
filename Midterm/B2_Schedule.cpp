#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Global Variables
int n = 0, res = 0;

vector <int> s;

//Functions
void solve(){

    int day = 6;

    vector <int> :: iterator it;

    while(!s.empty()){

        for (int i = day; i >= 1; --i){

            it = find(s.begin(), s.end(), i);

            if (it != s.end()){

                day -= *it;

                s.erase(it);

                break;
            }
        }
        
        if (!s.empty() && day < s[s.end() - s.begin() - 1]){

            day = 6;

            ++res;
        }
    }

    cout << res + 1;
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> n;

    for (int i = 0; i < n; ++i){

        int tmp;  cin >> tmp;

        s.push_back(tmp);
    }

    auto comp = [](int &a, int &b){

        return a > b;
    };

    sort(s.begin(), s.end(), comp);

    solve();   

    return 0;
}