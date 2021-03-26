#include <iostream>
#include <vector>
#include <algorithm>
#define BARNSIZE 1000000000

using namespace std;

vector <int> barn;   //Long barn, store location of stalls (0 -> 10^9)

int calc_cow(int dist){
    int curr = barn[0], count = 1;

    for (int i : barn){
        if ((i - curr) >= dist){
            ++count;

            curr = i;
        }
    }

    return count;
}


int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int test_case = 0;  cin >> test_case;

    while (test_case--){
        int stall = 0,  //Number of stalls (N), 2 <= N <= 10^5
            cow = 0;    //Number of cows (C), 2 <= C <= N

        cin >> stall >> cow;

        barn.clear();

        for (int i = 0; i < stall; ++i){
            int temp = 0;   cin >> temp;

            barn.push_back(temp);
        }

        sort(barn.begin(), barn.end());

        int left = 1, right = barn[barn.size() - 1];        

        while(right - left > 1){

            int mid = (left + right) / 2;

            if (calc_cow(mid) >= cow){
                left = mid;
            }
            else{
                right = mid;
            }
        }

        cout << left << endl;

    }

    
    return 0;
}
