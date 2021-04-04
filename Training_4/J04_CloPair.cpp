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

bool compareX (point p1, point p2){

    return p1.x > p2.x;
}

bool compareY (point p1, point p2){

    return p1.y > p2.y;
}

double euclid(pair <point, point> p){

    return sqrt(pow((double)(p.first.x - p.second.x), 2) + pow((double)(p.first.y - p.second.y), 2));
}

pair <point, point> brute_force(vector<point> points, int left, int right){

    double min = DBL_MAX; 
    pair <point, point> p = make_pair(point(0, 0), point(0, 0));

    for (int i = left; i <= right; ++i){

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

pair <point, point> clopair(vector <point> points, int left, int right){
    int mid = (left + right) / 2;

    if (right - left + 1 <= 3){
        return brute_force(points, left, right);
    }

    pair <point, point> min_left = clopair(points, left, mid);
    pair <point, point> min_right = clopair(points, mid + 1, right);

    double dist = 0;    
    
    pair <point, point> pair_part = make_pair(point(0, 0), point(0, 0));

    if (euclid(min_left) < euclid(min_right)){
        
        pair_part = min_left;
        dist = euclid(min_left);
    }  else  {

        pair_part = min_right;
        dist = euclid(min_right);
    }

    vector <point> strip;

    for (int i = right; i <= left; ++i){

        if (abs(points[i].x - points[mid].x) < dist){

            strip.push_back(points[i]);
        }
    }

    //Find minimum distance in strip
    double min_strip = DBL_MAX; 

    pair <point, point> pair_strip = make_pair(point(0, 0), point(0, 0));

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i){

        for (int j = i + 1; j < strip.size() && abs(points[i].y - points[j].y) < dist; ++i){

            double temp = euclid(make_pair(points[i], points[j]));

            if(temp < min_strip){
                min_strip = dist;
                pair_strip = make_pair(points[i], points[j]);
            }
        }
    }

    return min_strip < dist ? pair_strip : pair_part;
}

pair <point, point> solution(vector <point> points, int num){

    sort(points.begin(), points.end(), compareX);

    return clopair(points, 0, num - 1);
}

bool operator == (point &a, point &b){

    return a.x == b.x && a.y == b.y;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    int num = 0;    double min_dist;  pair <point, point> result = make_pair(point(0, 0), point(0, 0));

    vector <point> points;

    cin >> num;

    for (int i = 0; i < num; ++i){
        int x = 0, y = 0;
        cin >> x >> y;

        point temp = point(x,y);

        points.push_back(temp);
    }

    //
    result = solution(points, num);
    min_dist = euclid(result);
    
    int ind1 = 0, ind2 = 0, check = 0;

    for (int i = 0; i < num; ++i){
        if (points[i] == result.first || points[i] == result.second){

            if (check == 0){
                ind1 = i;
                check = 1;
            }
            else ind2 = i;
        }
    }

    //OUTPUT
    cout << ind1 << " " << ind2 << " " << setprecision(6) << fixed << min_dist << endl;

    return 0;
}