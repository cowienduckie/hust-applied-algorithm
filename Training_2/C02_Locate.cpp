#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstring>

#define N 1001

using namespace std;

int check[N * 2][N * 2];    //Check matrix
                            //NOTE: Large size array HAVE TO declare outside main
                            //      because of stack overflow!!!

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int test = 0, row = 0, col = 0, result = 0;  cin >> test;   //Number of test cases

    vector < pair<int, int> > before;   //Store objects before
    vector < pair<int, int> > after;    //Store objects after

    while (test--){
        //Set up for new test case
        memset(check, 0, sizeof(check));
        before.clear();
        after.clear();
        result = 0;

        //Radar size
        cin >> row >> col;  

        //Store all objects before and after into prepared vectors
            //Input before radar
        for (int i = 0; i < row; ++i){  
            for (int j = 0; j < col; ++j){
                int temp;  cin >> temp;

                if (temp == 1) before.push_back(make_pair(i, j));
            }
        }

            //Input after radar
        for (int i = 0; i < row; ++i){  
            for (int j = 0; j < col; ++j){
                int temp;  cin >> temp;

                if (temp == 1) after.push_back(make_pair(i, j));
            }
        }
        
        //Take direction of all elements in 2 vectors and store in check matrix
        //(new_x - old_x) + N = delta_x
        //(new_y - old_y) + N = delta_y
        //Check matrix have 2*N size for negative delta (delta increased by N)
        //check [delta_x + N] [delta_y + N] increase for each pair
        for (auto bf : before){
            for (auto at : after){
                int delta_x = bf.first - at.first + N;
                int delta_y = bf.second - at.second + N;

                ++check[delta_x][delta_y];
            }
        }

        //After all, find max element in check matrix -> result
        for (int i = 0; i < N * 2; ++i){
            result = max(result, *max_element(check[i], check[i] + N * 2));
        }
        
        cout << result << endl;
    }

    return 0;
 }
