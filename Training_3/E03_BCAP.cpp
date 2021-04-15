#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

//Global Variables
int course_num = 0, period_num = 0, result = INT_MAX;

vector <vector <int> > assign;
vector <vector <int> > req;
vector <int> credit;

//Functions
int check_cre(){

    int max_cre = INT_MIN;

    for (int i = 0; i < period_num; ++i){

        int cre = 0;

        for (int j : assign[i]){

            cre += credit[j];
        }

        max_cre = max(max_cre, cre);
    }

    return max_cre;
}

bool check_req(int period, int course){

    for (int pre : req[course]){

        bool flag = false;

        for (int i = 0; i <= period - 1; ++i){

            vector <int> :: iterator it = find(assign[i].begin(), assign[i].end(), pre);

            if (it != assign[i].end()){

                flag = true;
                break;
            }
        }

        if (flag == false)  return false;
    }

    return true;
}

void brute(int course){

    //cout << course << endl;

    if (check_cre() >= result) return;

    for (int i = 0; i < period_num; ++i){

        if (check_req(i, course)){

            assign[i].push_back(course);

            if (course == course_num - 1){

                result = min(result, check_cre());
            }
            else{

                brute(course + 1);
            }

            assign[i].pop_back();
        }
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> course_num >> period_num;

    assign.resize(period_num);
    req.resize(course_num);
    credit.resize(course_num);

    for (int &c : credit)  cin >> c;

    for (int i = 0; i < course_num; ++i){

        for (int j = 0; j < course_num; ++j){

            int tmp = 0;  cin >> tmp;

            if (tmp == 1) req[i].push_back(j);
        }
    }

    //
    brute(0);


    //OUTPUT
    if (result != INT_MAX)  cout << result;
    else
        cout << -1;

    return 0;
}