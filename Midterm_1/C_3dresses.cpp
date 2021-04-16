#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int dress_num = 0, pair_num = 0, result = INT_MAX;  cin >> dress_num >> pair_num;

    int cost[dress_num + 1];

    vector <vector <int>> relate(dress_num + 1);

    for (int i = 1; i <= dress_num; ++i){

        cin >> cost[i];
    }

    for (int i = 1; i <= pair_num; ++i){

        int a = 0, b = 0;  cin >> a >> b;

        relate[a].push_back(b);
        relate[b].push_back(a);
    }

    //
    for (int dr1 = 1; dr1 <= dress_num; ++dr1){

        for (int dr2 : relate[dr1]){

            if (dr2  <= dr1) continue;

            for (int dr3 : relate[dr2]){

                if (dr3 <= dr2) continue;

                vector <int> :: iterator tmp = find(relate[dr3].begin(), relate[dr3].end(), dr1);

                if ( tmp != relate[dr3].end() ){

                    result = min(result, cost[dr1] + cost[dr2] + cost[dr3]);
                }
            }
        }
    }

    //OUTPUT
    if (result != INT_MAX)  cout << result;
    else
        cout << -1;

    return 0;
}