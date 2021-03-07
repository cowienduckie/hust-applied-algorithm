#include <iostream>
#include <vector>
#include <stack>

#define asphalt_constrant 1000000000

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int  road_len = 0, noti_num = 0, curr = asphalt_constrant + 24, roughness = 0;

    vector <int> road = {asphalt_constrant + 24};   //Road detail with asphalt no. and begining of road
    vector <int> result;    //Store roughness changes

    cin >> road_len; //Take road inputs
    for (int i = 1; i <= road_len; ++i){
        int temp;
        cin >> temp;
        road.push_back(temp);

        if (curr != temp){
            ++roughness; //Calc roughness at first
            curr = temp;
        }
    }
    road.push_back(asphalt_constrant + 24);//End of road

    cin >> noti_num; //Take noti input and calc roughness changes
    for (int i = 0; i < noti_num; ++i){
        int part = 0, asphalt = 0; //Road part no. and asphalt no.
        cin >> part >> asphalt;

        //The change in roughness equal change in roughness of 3 part in a row
        //[1]  [2]  [3] <- [2] is changed
        int p1 = road[part - 1], p2 = road[part], p3 = road[part + 1];

        //Store old roughness
        int old_rough = 0;
        if (p1 == p2 && p3 == p2) old_rough = 1;
        else if (p1 == p2 || p3 == p2) old_rough = 2;
        else old_rough = 3;

        //Update road change
        road[part] = asphalt;
        p2 = road[part];

        //Calc new roughness
        int new_rough = 0;
        if (p1 == p2 && p3 == p2) new_rough = 1;
        else if (p1 == p2 || p3 == p2) new_rough = 2;
        else new_rough = 3;
        
        roughness += new_rough - old_rough;

        result.push_back(roughness);
    }

    for (int i : result){   //Print output
        cout << i << endl;
    }

    return 0;
}