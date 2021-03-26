#include <iostream>
     
using namespace std;
         
int num = 0;

void printRes(int binary){
    for (int i = num - 1; i >= 0; --i){
        
        cout << (int) (binary >> i & 1);
    }
    cout << endl;
}

void binaryList(int pos, int binary){
    if (pos == num){
        printRes(binary);

        return;
    }

    binary = binary << 1;   binaryList(pos + 1, binary);

    binary = binary + 1;  binaryList(pos + 1, binary);
}

     
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> num;
     
    binaryList(0, 1);

    return 0;
}