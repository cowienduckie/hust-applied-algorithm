#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Object{

    int m;  //weight
    int v;  //value
    
}object;

//Global Variables
vector <object> obj;   //first = weight, second = values 

int num = 0, M = 0, max_val = 0;  

//List of functions
void pyb(int pos,int value, int weight);  //Pack your bag


//Main
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> num >> M;  //M = max weight

    for (int i = 0; i < num; ++i){

        object tmp;
        cin >> tmp.m >> tmp.v;  obj.push_back(tmp);
    }

    //
    auto compare = [](object &a, object &b){
        return a.m < b.m;
    };
 
    sort(obj.begin(), obj.end(), compare);

    pyb(0, 0, 0);

    //OUTPUT
    cout << max_val;

    return 0;
}

//Functions
void pyb(int pos, int value, int weight){

    for (int i = pos; i < num; ++i){

        if (weight + obj[i].m <= M){

            pyb(i + 1,value + obj[i].v, weight + obj[i].m);
        }
        else  break;        
    }
    
    max_val = max(value, max_val);
}