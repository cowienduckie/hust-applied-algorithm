#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_SIZE 1000

//Global Variables
int store[MAX_SIZE + 1][MAX_SIZE + 1];
int mem[MAX_SIZE + 1][MAX_SIZE + 1];

//Functions
void order(int &a, int &b, int &c){

    int arr[3] = {a,b,c};

    sort(arr, arr + 3);

    a = arr[0];  b = arr[1]; c = arr[2];
}

int babylon(int length, int width){

    if (mem[length][width] != -1)  return mem[length][width];

    int height = 0;

    for (int l = length; l >= 1; --l){

        for (int w = width; w >= 1; --w){

            if(store[w][l] != -1){

                height = max(height, store[w][l] + babylon(l - 1, w - 1));
            }
        }
    }

    mem[length][width] = height;

    return height;
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case = 0;

    while (true){

        //INPUT
        int num = 0;  cin >> num;  if (num == 0) break;

        memset(mem, -1, sizeof(mem));
        memset(store, -1, sizeof(store));  int size = 0;

        for (int i = 1; i<= num; ++i){

            int x = 0, y = 0, z = 0;  cin >> x >> y >> z;

            order(x, y, z);

            store[y][x] = store[x][y] = max(store[x][y], z);
            store[z][x] = store[x][z] = max(store[x][z], y);
            store[z][y] = store[y][z] = max(store[y][z], x);

            size = max(size, z);
        }

        //      

        //OUTPUT
        cout << "Case " << ++test_case << ": maximum height = " << babylon(size, size) << endl;
    }

    return 0;
}