#include <iostream>

using namespace std;

char str[20]; int num;

void biList(int pos){

    if (pos == num){

        printf("%s\n", str);
        return;
    }
        
    str[pos] = '0';
    biList(pos + 1);

    str[pos] = '1';
    biList(pos + 1);

}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> num;
    
    biList(0);

    return 0;
}