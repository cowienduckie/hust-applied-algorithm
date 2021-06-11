#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define N 10010

using namespace std;

vector <string> s(N, "");

string initString(int len, int z){

    string str;

    int counter = 1;

    for (int i = 1; i <= len; ++i){

        if (counter == z){

            str += "1";

            counter = 1;
        }
        else{

            str += "0";

            ++counter;
        }

        s[i] = str;
    }

    return str;
}

string genStringOfOnes(int len){

    string str = "";

    for (int i = 0; i < len; ++i){

        str += "1";
    }

    return str;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int n, k, z;  cin >> n >> k >> z;

    //
    if (n >= z){  //Using DP

        vector<long long> dp(n + 1, 0);

        int limit = min(z, 30);

        for (int i = 0; i <= limit; ++i){

            dp[i] = pow(2, i);
        }

        --dp[limit];

        int i = 1;  bool flag = true;

        for ( ; i <= n; ++i){

            if (i > limit){

                for (int j = 1; j <= limit; ++j){

                    dp[i] += dp[i - j];
                }
            }

            if (dp[i] > k){

                flag = false;

                break;
            }
        }

        if (flag){  //k > total of configs 

            cout << -1;

            exit(0);
        }

        //
        string str = initString(n, z);  --k;

        while (k > 0){

            int i = 1;

            for ( ; i <= n; ++i){

                if (str[n - i] == '0'){

                    if (dp[i - 1] <= k){

                        k -= dp[i - 1];
                    }
                    else{

                        break;
                    }
                }
            }

            if (k == 0){  //replace substring with all 1s length i

                str.replace(n - i + 1, i - 1, genStringOfOne(i - 1));
            }
            else{   //replace substring with standard rule

                str.replace(n - i + 1, i - 1, s[i - 1]);

                str[n - i] = '1';

                --k;
            }
        }

        //Output
        for (int i = 0; i < n; ++i){

            printf("%c ", str[i]);
        }   
    }
    else{  //If z > n --> normal binary list

        int i = 1;

        for ( ; i <= n; ++i){

            long long tmp = pow(2, i);

            if (tmp > k)  break;
        }

        n -= i;

        --i; 

        string str = "";  --k;

        while (i >= 0){

            long long tmp = pow(2, i);

            if (k >= tmp){

                k -= tmp;

                str += "1";
            }
            else{

                str += "0";
            }

            --i;
        }

        for (int i = 1; i <= n; ++i){

            str = "0" + str;
        }

        for (int i = 0; i < str.length(); ++i){

        printf("%c ", str[i]);
        }
    }

    return 0;
}