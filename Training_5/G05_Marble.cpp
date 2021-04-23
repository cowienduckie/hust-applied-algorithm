#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct Plate{

    int w = 0;
    int h = 0;
    
}Plate;

//Global Variables
vector <Plate>  plate;

int mem[601][601];

//
int split(int W, int H){  //return max used area

    if (W == 0 || H == 0) return 0;

    if (mem[W][H] != -1)  return mem[W][H];

    int used = 0;

    for (int i = 0; i < plate.size(); ++i){

        int w = plate[i].w, h = plate[i].h;

        if (h <= H && w <= W){

            used = max(used, h * w + split(W, H - h) + split(W - w, h));
            used = max(used, h * w + split(w, H - h) + split(W - w, H)); 
        }   
    }

    mem[W][H] = used;

    return used;
}

//
int main(int argc, char **argv){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int W = 0, H = 0, size_num = 0;
    cin >> W >> H >> size_num;

    plate.resize(size_num);

    for (int i = 0; i < size_num; i++){

        cin >> plate[i].w >> plate[i].h;
    }

    //
    memset(mem, -1, sizeof(mem));


    //OUTPUT
    cout << W * H - split(W, H) << endl;

    return 0;
}