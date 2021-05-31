#include <iostream>
#include <vector>
#include <cmath>

#define ull unsigned long long

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int tc = 0;  cin >> tc;

    vector <ull> p(16, 1);

    for (int i = 1; i <= 15; ++i){

        p[i] = 10 * p[i - 1];
    }

    while(tc--){

        ull w = 0, c = 0;  cin >> w >> c;

        if (w % 1000){

            cout << 0 << endl;

            continue;
        }

        w /=  1000;

        ull note = 0, cases = 1;

        for (int i = c; i >= 0; --i){

            vector <int> used(10, 0);

            for (auto j : {5 , 3 , 2, 1}){
            
                ull t = 1ull * j * p[i];
                ull n = w / t;  
                
                w %= t;
                note += n;

                if (n > 0) used[j] = 1;
            }

            ull tmp = 1;
            if (used[1] && used[5]) ++tmp;
            if (used[1] && used[3]) ++tmp;

            cases *= tmp;
        }

        cout << note << " " << cases << endl;
    }
    
    return 0;
}