#include <iostream>
#include <vector>

using namespace std;

int num = 0, cond_num = 0, counter = 0;

vector <pair <int, int>> cond;

int arr[7];  bool mark[7];

void printPermutation(){
    for (int i = 1; i <= num; ++i){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

bool checkPermutation(){
    
    for(pair <int, int> c : cond){        
        bool check = false;

        for (int i = 1; i <= num; ++i){

            if (arr[i] == c.first){

                for (int j = i + 1; j <= num; ++j){

                    if (arr[j] == c.second){
                        check = true; 
                        break;
                    }
                }

                break;
            }
        }

        if (check == false) return false;
    }

    return true;
}

void permutation(int curr){
    for (int i = 1; i <= num; ++i){

        if (mark[i] == false){
            arr[curr] = i;
            mark[i] = true;

            if (curr == num && checkPermutation()){
                printPermutation();
                ++counter;
            }    
            else permutation(curr + 1);

            mark[i] = false;
        }
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> num >> cond_num;

    for (int i = 1; i <= num; ++i){
        arr[i] = i;
        mark[i] = false;
    }

    for (int i = 0; i < cond_num; ++i){
        int a, b; cin >> a >> b;

        cond.push_back(make_pair(a, b));
    }

    //
    permutation(1);

    //OUTPUT
    cout << counter;
    
    return 0;
}