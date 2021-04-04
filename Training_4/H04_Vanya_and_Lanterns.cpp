#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
 
using namespace std;
 
int str_len = 0, num = 0;
 
vector <int> lantern;
 
bool lantern_corp(double rad){
 
    if( (double)lantern[0] - rad > 0|| lantern[num - 1] + rad < str_len){
        
        return false;
    }
 
    for (int i = 0; i < num - 1; ++i){
 
        if (lantern[i + 1] - lantern[i] > rad * 2){
 
            return false;
        }
    }
    
    return true;
}
 
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> num >> str_len;
 
    for (int i = 0; i < num; ++i){
        int tmp = 0; cin >> tmp;
 
        lantern.push_back(tmp);
    }
 
    sort(lantern.begin(), lantern.end());
 
    //
    double low = 0, high = 1e9;
 
    for (int i = 0; i < 63; ++i){
 
        double mid = (low + high) / 2;
 
        if(lantern_corp(mid) == true){
            high = mid;
        }
        else {
            low = mid;
        }
    }    
 
    //OUTPUT
    cout << setprecision(10) << fixed << high;
 
    return 0;
}