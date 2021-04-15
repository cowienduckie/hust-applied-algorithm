#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

//Global Variables
int teacher_num = 0, course_num = 0, conf_num = 0, result = INT_MAX;

vector <vector <int> > preList;
vector <vector <int> > assign;
vector <vector <int> > conflict;

//
bool check(int teacher, int course){
 
    if (find(preList[teacher].begin(), preList[teacher].end(), course) == preList[teacher].end()){
 
        return false;
    }
 
    for (int i : assign[teacher]){
 
        if (find(conflict[i].begin(), conflict[i].end(), course) != conflict[i].end()){
 
            return false;
        }
    }
 
    return true;
}

int max_load(){

    int maximal = 0;

    for (int i = 0; i < teacher_num; ++i){

        maximal = max(maximal, (int)assign[i].size());
    }

    return maximal;
}

void brute(int course){

    if (max_load() >= result) return;

    for (int i = 0; i < teacher_num; ++i){

        if (check(i, course)){

            assign[i].push_back(course);

            if (course == course_num){

                result = min(result, max_load());
            }
            else{

                brute(course + 1);
            }

            assign[i].pop_back();
        }
    }
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> teacher_num >> course_num;

    preList.resize(teacher_num);
    assign.resize(teacher_num);
    conflict.resize(course_num + 1);
    

    for (int i = 0; i < teacher_num; ++i){

        int tmp = 0;  cin >> tmp;  
        
        preList[i].resize(tmp);

        for(int &j : preList[i])  cin >> j;
    }

    cin >> conf_num;

    for (int i = 0; i < conf_num; ++i){

        int a = 0, b = 0;  cin >> a >> b;

        conflict[a].push_back(b);
        conflict[b].push_back(a);
    }

    //
    brute(1);

    //OUTPUT

    if (result == INT_MAX) cout << -1;
    else
        cout << result;

    return 0;
}