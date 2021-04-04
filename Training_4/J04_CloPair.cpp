#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cfloat>

using namespace std;

typedef struct point{
    int x;
    int y;

    point(int x, int y){
        this->x = x;
        this->y = y;
    }

}point;

vector <point> points;

bool compareX (point p1, point p2){
    return p1.x < p2.x;

}

bool compareY (point p1, point p2){

    return p1.y < p2.y;
}

bool operator == (point a, point b){

    return a.x == b.x && a.y == b.y;
}

double euclid(pair <point, point> p){

    return sqrt(pow((double)(p.first.x - p.second.x), 2) + pow((double)(p.first.y - p.second.y), 2));
}

pair <point, point> brute_force(int left, int right){

    double min = DBL_MAX; 
    pair <point, point> p = make_pair(point(0, 0), point(0, 0));

    for (int i = left; i < right; ++i){

        for (int j = i + 1; j <= right; ++j){

            double dist = euclid(make_pair(points[i], points[j]));

            if(dist < min){
                min = dist;
                p = make_pair(points[i], points[j]);
            }
        }
    }
    

    return p;
}

pair <point, point> clopair(int left, int right){

    if (right - left + 1 <= 3){
        return brute_force(left, right);
    }

    int mid = (left + right) / 2; double dist = 0;

    pair <point, point> min_left = clopair(left, mid);
    pair <point, point> min_right = clopair(mid + 1, right);
    pair <point, point> pair_part = make_pair(point(0, 0), point(0, 0));


    if (euclid(min_left) < euclid(min_right)){
        
        pair_part = min_left;
        dist = euclid(min_left);
    }  else  {

        pair_part = min_right;
        dist = euclid(min_right);
    }

    //Initiate strip store points whose distance is mid < dist
    vector <point> strip;

    for (int i = left; i <= right; ++i){

        if (abs(points[i].x - points[mid].x) < dist){

            strip.push_back(points[i]);
        }
    }

    //Find minimum distance in strip
    double min_strip = DBL_MAX; 

    pair <point, point> pair_strip = make_pair(point(0, 0), point(0, 0));

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i){

        for (int j = i + 1; j < strip.size() && abs(strip[i].y - strip[j].y) < dist; ++j){

            double temp = euclid(make_pair(strip[i], strip[j]));

            if(temp < min_strip){
                min_strip = temp;
                pair_strip = make_pair(strip[i], strip[j]);
            }
        }
    }

    return min_strip < dist ? pair_strip : pair_part;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0;  cin >> num;

    vector <point>  original;

    for (int i = 0; i < num; ++i){
        int x = 0, y = 0;
        cin >> x >> y;

        point temp = point(x,y);

        points.push_back(temp);
        original.push_back(temp);
    }

    sort(points.begin(), points.end(), compareX);

    //
    pair <point, point> result = clopair(0, num - 1);

    double min_dist = euclid(result);  int ind1 = 0, ind2 = 0, check = 0;

    for (int i = 0; i < num; ++i){
        if (original[i] == result.first || original[i] == result.second){

            if (check == 0){

                ind1 = i;
                ++check;
            }  else  {

                ind2 = i;
                ++check;
            }
        }
        else if (check == 2) break;
    }

    //OUTPUT
    cout << ind1 << " " << ind2 << " " << setprecision(6) << fixed << min_dist << endl;

    return 0;
}