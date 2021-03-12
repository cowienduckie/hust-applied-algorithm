#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long num_obj = 0, max_w = 0, result = 0;

void knapsac(vector<pair<int, int>> object,int last, long long value, long long weight){ 

    if (last == (num_obj - 1)){
        result = max(value, result);
        return;
    }
    
    for (int i = last + 1; i < num_obj; ++i){
        if (weight + object[i].first <= max_w){
            knapsac(object, i,value + object[i].second, weight + object[i].first);
        }
        else{
            result = max(value, result);
            break;
        }
        
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //Input
    cin >> num_obj >> max_w;

    vector < pair <int, int> > object(num_obj); 

    for (int i = 0; i < num_obj; ++i ){
        cin >> object[i].first >> object[i].second;
    }
    
    auto compare = [](pair <int, int> a, pair <int, int> b){
        return a.first < b.first;
    };

    sort(object.begin(), object.end(), compare);

    knapsac(object, -1, 0, 0);

    //Output
    cout << result;

    return 0;
}