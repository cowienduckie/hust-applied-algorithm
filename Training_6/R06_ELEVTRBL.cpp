#include <iostream>
#include <queue>
#include <algorithm>

#define N 1000010

using namespace std;

int mark[N];

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int floors, start, finish, up, down;

    cin >> floors >> start >> finish >> up >> down;
   
    fill(mark, mark + N, 0);

    queue <pair <int, int>> bfs;

    bfs.push({start, 0});  mark[start] = 1;

    while (!bfs.empty()){

        int pos = bfs.front().first;
        int step = bfs.front().second;

        bfs.pop();

        if (pos == finish){

            cout << step << endl;

            exit(0);
        }        

        if (pos + up <= floors && mark[pos + up] == 0){  
            
            bfs.push({pos + up, step + 1});

            mark[pos + up] = 1;
        }
        if (pos - down >= 1 && mark[pos - down] == 0){   
            
            bfs.push({pos - down, step + 1});

            mark[pos - down] = 1;
        }
    }

    cout << "use the stairs" << endl;

    return 0;
}