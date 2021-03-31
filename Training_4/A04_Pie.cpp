#include <iostream>
#include <iomanip>
#include <cmath>

#define pi acos(-1)

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int test_case = 0; cin >> test_case;

    while (test_case--){
        int N = 0, F = 0;   //N = number of pies, F = number of friends
        cin >> N >> F;  ++F;    //I want a piece too!

        double V[N]; 

        for (int i = 0; i < N; ++i){
            int r =0 ;    cin >> r;

            V[i] = pi * r * r;
        }

        double left = 0.0, right = pi * 10000 * 10000;

        for (int it = 0; it < 54; ++it){

            int num = 0;

            double mid = (left + right) / 2;

            for (int i = 0; i < N; ++i){
                num += floor(V[i] / mid);
            }

            if (num >= F){
                left = mid;
            }
            else{
                right = mid;
            }
        }
    

        cout << fixed << setprecision(6) << left << endl;
    }

    return 0;
}