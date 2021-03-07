#include <iostream>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int num_test = 0, row = 0, col = 0;

    cin >> num_test;

    while (num_test--){
        //Preparation
        int largest = 0;
        cin >> row >> col;

        int **radar_1 = new int*[row];
        int **radar_2 = new int*[row];

        for (int i = 0; i < row; ++i){
            radar_1[i] = new int[col];

            for (int j = 0; j < col; ++j){
                cin >> radar_1[i][j];
            }
        }

        for (int i = 0; i < row; ++i){
            radar_2[i] = new int[col];

            for (int j = 0; j < col; ++j){
                cin >> radar_2[i][j];
            }
        }

        //
        

        //Output
        cout << largest << endl;

        //Free memory
        for (int i = 0; i < row; ++i){
            delete [] radar_1[i];
            delete [] radar_2[i];
        }
        delete [] radar_1;
        delete [] radar_2;
    }

    return 0;
}
