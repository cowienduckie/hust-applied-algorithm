//LIS time complexity O(NlogN)
#include <iostream>
#include <vector>

#define N 100001

using namespace std;

//Global Variables
int n = 0;  

vector <int> arr(N + 1);
vector <int> tail(N + 1, 0);


//Functions
int ceilIndex(int l, int r, int key){

    while (r - l > 1){

        int m = l + (r - l) / 2;

        if (tail[m] >= key){

            r = m;
        }
        else{

            l = m;
        }
    }

    return r;
}

int LIS(){

    int len = 1;  tail[0] = arr[0];

    for (int i = 1; i < n; ++i){

        if (arr[i] < tail[0]){  //Smaller than first element -> It might start for a longer IS

            tail[0] = arr[i];
        }
        else if (arr[i] > tail[len - 1]){   //Bigger than last element -> Lengthen all IS before

            tail[len++] = arr[i];
        }
        else{   //Some where in middle -> find its place in tail

            tail[ceilIndex(-1, len - 1, arr[i])] = arr[i];
        }
    }

    return len;
}


//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> n;

    for (int i = 0; i < n; ++i)  cin >> arr[i];
    
    //OUTPUT
    cout << LIS();

    return 0;
}