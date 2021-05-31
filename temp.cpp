#include <iostream>
#include <cmath>
#include <string>

#define ull unsigned long long

using namespace std;

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int test = 0; cin >> test;

    ull val[16];

    for (int i = 0; i <= 15; ++i){

        val[i] = 5000 * pow(10, i);
    }

    //4 = 3 + 1 = 2 + 2
    //6 = 5 + 1 = 3 + 3
    //9 = 5 + 3 + 1 = 5 + 2 + 2 = 3 + 3 + 3;
    while (test--){
        
		string W;  int c;  cin >> W >> c;

		ull note = 0, cases = 1;

		int len = W.length();

		for (int i = len - 1; i >= 3; --i){

			int d =  atoi(W[i]);
		}

        for (int i = c; i >= 0; --i){

            ull t = W / pow(10, i + 3);  W -= t * pow(10, i + 3);

            if(t == 0){

                continue;
            }
            else if (t == 9){

                note += 3;

                cases *= 3;
            }
            else if (t == 4 || t == 6){

                note += 2;

                cases *= 2;
            }
            else if (t == 1 || t == 2 || t == 3 || t == 5){
                note += 1;
            }
            else{

                note += 2;
            }
        }

        if (W == 0)  cout << note << " " << cases << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}