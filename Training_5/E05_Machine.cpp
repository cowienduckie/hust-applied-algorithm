#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0, result = INT_MIN, max_end = INT_MIN;  cin >> num;

    vector <pair <int, int>> period;  //first --> start time | second --> end time

    for (int i = 0; i < num; ++i){

        int start = 0, end = 0;  cin >> start >> end;

        period.push_back({start, end});

        max_end = max(max_end, end);
    }

    //
    auto compare = [](pair<int, int> &a, pair<int, int> &b){

        return a.first < b.first;
    };

    sort(period.begin(), period.end(), compare);  

    int max_from[max_end + 2], it = num - 1; max_from[max_end + 1] = -1;

    for (int i = max_end + 1; i >= 1;){

        if (it >= 0 && i == period[it].first){

            max_from[i] = max(max_from[i], period[it].second - period[it].first);

            --it;
        }
        else{

            max_from[i - 1] = max_from[i];

            --i;
        }
    }  

    for (int i = 0; i < num; ++i){

        int tmp = INT_MIN;

        if (max_from[period[i].second + 1] != -1){

            tmp = max_from[period[i].second + 1] + period[i].second - period[i].first;
        }

        result = max(tmp, result);
    }

    //OUTPUT
    if (result != INT_MIN)  cout << result << endl;
    else 
        cout << -1 << endl;

    return 0;
}