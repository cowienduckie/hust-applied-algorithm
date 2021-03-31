#include <iostream>
#include <vector>

#define MAX_HEIGHT 1e9

using namespace std;

vector <int> tree;

long long saw(int height){
    long long part = 0;

    for (int i = 0; i < tree.size(); ++i){
        if (tree[i] > height){
            part += tree[i] - height;
        }
    }

    return part;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long tree_num = 0, wood_target = 0;  cin >> tree_num >> wood_target;

    for (int i = 0; i < tree_num; ++i){
        int temp = 0; cin >> temp;

        tree.push_back(temp);
    }

    int left = 1, right = MAX_HEIGHT;

    while (right - left > 1){
        int mid = (left + right) / 2;

        if (saw(mid) >= wood_target){
            left = mid;
        }
        else{
            right = mid;
        }
    }

    cout << left;

    return 0;
}
