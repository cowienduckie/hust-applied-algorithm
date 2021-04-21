#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Global Variables
int node_num = 0, edge_num = 0, path_len = 0, result = 0;

vector <vector <int>> graph;
vector <int> path;

//Functions
void find_path(int last, int pos){

    for (vector <int>::iterator it = graph[last].begin(); it != graph[last].end(); ++it){

        vector<int>::iterator tmp = find(path.begin(), path.end(), *it);

        if (tmp == path.end()){

            if(pos == path_len + 1){

                ++result;
            }
            else{

                int next = *it;

                path.push_back(next);

                find_path(next, pos + 1);

                path.pop_back();
            }
        }
    }
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //INPUT
    cin >> node_num >> path_len >> edge_num;  graph.resize(node_num + 1);

    for (int i = 0; i < edge_num; ++i){

        int a = 0, b = 0;  cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= node_num; ++i){

        graph[0].push_back(i);
    }

    //
    find_path(0, 1);


    //OUTPUT
    cout << result / 2 << endl;

    return 0;
}