#include <iostream>
#include <vector>
#include <set>
#include <utility> 

using namespace std;

int num_test = 0, row = 0, col = 0;

int max_obj(pair <int, int> m){
    return col * row - (abs(m.second) * col + abs(m.first) * row - abs(m.first * m.second));
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> num_test;

    auto comp = [](pair <int, int> p1, pair <int, int> p2){
        if (p1 != p2)
            return max_obj(p1) >= max_obj(p2);
        else return false;
    };

    while (num_test--){
        //Preparation
        int largest = 0;
        cin >> row >> col;

        vector < vector <int> > radar;    radar.resize(row, vector<int>(col));

        vector < pair <int, int>> arrive;

        set < pair <int, int>, decltype(comp)>  move(comp);

        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                cin >> radar[i][j];
            }
        }

        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                int temp;
                cin >> temp;

                if (temp == 1) arrive.push_back(make_pair(i, j));

                radar[i][j] = temp - 2 * radar[i][j];

                move.insert(make_pair(i , j));
                move.insert(make_pair(i , j * (-1)));
                move.insert(make_pair(i * (-1), j));
                move.insert(make_pair(i * (-1), j * (-1)));
            }
        }
        move.erase(make_pair(0, 0));
        //
       for (pair <int, int> m: move){
           cout << m.first << " " << m.second << " : " << max_obj(m) <<endl;

           if (largest == arrive.size() || largest >= max_obj(m)){
               break;
           }

           int temp = 0;

           for (pair <int, int> a : arrive){
               
               int oldX = a.first + m.first;
               int oldY = a.second + m.second;

               if ( 0 <= oldX && oldX < row && 0 <= oldY && oldY < col && 
                    (radar[oldX][oldY] == -1 || radar[oldX][oldY] == -2) )
               ++temp;
           }

           largest = max(largest, temp);
       }
    
        //Output
        cout << largest << endl;
    }

    return 0;
}