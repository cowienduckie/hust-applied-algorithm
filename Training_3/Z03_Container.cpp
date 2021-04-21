#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct Item{

    int h = 0;
    int w = 0;
    int area = 0;

}item;

//Global Variables
int item_num = 0, width = 0, height = 0, result = -1, area = 0, counter = 0;

int container[31][31];

vector <item> store;  

//Functions
bool isEmpty(int x, int y, int W, int H){

    for (int i = 0; i < W; ++i){

        for (int j = 0; j < H; ++j){

            if (container[x + i][y + j] == 1)  return false;
        }
    }

    return true;
}

void put(int x, int y, int W, int H){

    for (int i = 0; i < W; ++i){

        for (int j = 0; j < H; ++j){

            container[x + i][y + j] = 1;
        }
    }
}

void pop(int x, int y, int W, int H){

    for (int i = 0; i < W; ++i){

        for (int j = 0; j < H; ++j){

            container[x + i][y + j] = 0;
        }
    }
}


void place(int count){

    for (int i = 1; i <= width - store[count].w + 1; ++i){

        for (int j = 1; j <= height - store[count].h + 1; ++j){

            if (container[i][j] != 1 && isEmpty(i, j, store[count].w, store[count].h)){

                if (count == item_num){

                    cout << 1;

                    exit(0);
                }
                else{

                    put(i, j, store[count].w, store[count].h);

                    place(count + 1);

                    pop(i, j, store[count].w, store[count].h);
                }
            }

        }
    }
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT    
    cin >> height >> width >> item_num;  store.resize(item_num + 1);

    for (int i = 1; i <= item_num; ++i){

        cin >> store[i].h >> store[i].w; store[i].area = store[i].w * store[i].h;

        //Precheck 
        area += store[i].area;
        if (store[i].h > height || store[i].w > width || area > width * height)  result = 0;
    }

    //
    if (result == 0){

        cout << 0; 

        return 0;
    }

    auto compare = [](item &a, item &b){

        if (a.area != b.area)  return (a.area > b.area);
        else 
            return  (max(a.h, a.w) > max(b.h, b.w));
    };

    sort(store.begin(), store.end(), compare);

    memset(container, 0, sizeof(container));

    place(1);

    //OUTPUT
    cout << 0;

    return 0;
}