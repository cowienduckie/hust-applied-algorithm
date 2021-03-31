#include <iostream>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case = 0;  cin >> test_case;

    while (test_case--){
        //INPUT
        int scribe_num = 0, book_num = 0;   cin >> book_num >> scribe_num;

        int book[book_num + 1], scribe[scribe_num + 1]; scribe[scribe_num] = book_num;

        for (int i = 1; i <= book_num; ++i){
            cin >> book[i];
        }
        
        //Find Root by Bisection
        long long low = 1, high = 5e9, curr = 0;

        while (high - low > 1){
            long long mid = (low + high) / 2; scribe[0] = 0;

            for (int i = scribe_num; i >= 1; --i){
                curr = 0;

                for (int j = scribe[i]; j >= i; --j){
                    if (curr + book[j] > mid){
                        curr = 0;
                        scribe[i - 1] = j;
                        break;
                    }

                    scribe[i-1] = j - 1;
                    curr += book[j];
                }
            }

            if (scribe[0] != 0){
                low = mid;  //Store wrong configurations
            }
            else{
                high = mid; //Store possible configurations
            }
        }

        //Calc result sequence with root stored in high
        scribe[0] = 0;
        for (int i = scribe_num; i >= 1; --i){
            curr = 0;

            for (int j = scribe[i]; j >= i; --j){
                if (curr + book[j] > high){
                    scribe[i - 1] = j;
                    break;
                }

                scribe[i-1] = j - 1;
                curr += book[j];
            }
        }

        //OUTPUT
        for (int i = 1; i <= scribe_num; ++i){
            for (int j = scribe[i - 1] + 1; j <= scribe[i]; ++j){
                cout << book[j] << " ";
            }

            if (i == scribe_num)    cout << endl;
            else
                cout << " / ";
        }
    }    

    return 0;
}

