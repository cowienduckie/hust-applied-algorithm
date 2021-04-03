#include <iostream>
#include <cmath>
#include <vector>
#include <cfloat>
#include <iomanip>

using namespace std;

double euclid(pair <int, int> a, pair <int, int> b){
    
    return sqrt( pow((double)(a.first - b.first), 2.0) + pow((double)(a.second - b.second), 2.0));
}

bool compareX(pair <int, int> a, pair <int, int> b){

    return a.first > b.first;
}

bool compareY(pair <int, int> a, pair <int, int> b){

    return a.second > b.second;
}

double cloPair(vector <int, int> point, int len){

    
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0, p1 = 0, p2 = 0;  cin >> num;
    double result = DBL_MAX;

    vector <pair <int, int> > point; point.resize(num);

    for (pair <int, int> &p : point){
        cin >> p.first >> p.second;
    }

    // 


    //OUTPUT
    cout << p1 << " " << p2 << " " << fixed << setprecision(6) << result << endl;

    return 0;
}