#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct state{
    int a;
    int b;
    int step;

    state(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->step = c;
    }
};


int main(int argc, char **argv){
    //Input
    int jug_a, jug_b, target, result = -1;
    cin >> jug_a >> jug_b >> target;

    //Setup
    map <pair<int, int>, int> visited;
    queue <state> bfs;
    bfs.push({0, 0, 0});

    //Solve
    while(!bfs.empty()){
        int a = bfs.front().a;//Current water in jug a
        int b = bfs.front().b;//Current water in jug b
        int step = bfs.front().step;//Current step

        bfs.pop();//Pop current state

        if (visited[{a, b}] == 1) //Skip visited state
            continue;
        
        visited[{a, b}] = 1; //Mark current state
        

        //If current water in jug a or b, problem is solved
        if(a == target || b == target){
            result = step;
            break;
        } else {
            //Case 1. Fill Jug a if jug a empty
            if(a == 0){
                bfs.push({jug_a, b, step + 1});
            }
            //Case 2. Fill Jug b if jug b empty
            if(b == 0){
                bfs.push({a, jug_b, step + 1});
            }
            //Case 3. Empty jug a if jug a full
            if (a != 0){
                bfs.push({0, b, step + 1});
            }
            //Case 4. Empty jug b if jug b full
            if (b != 0){
                bfs.push({a, 0, step + 1});
            }
            //Case 5. Jug a -> Jug b if jug b isn't full
            if (b != jug_b){
                int temp = jug_b - b;
                temp = min(temp, a);
                bfs.push({a - temp, b + temp, step + 1});
            }
            //Case 6. Jug a -> Jug b if jug b isn't full
            if (a != jug_a){
                int temp = jug_a - a;
                temp = min(temp, b);
                bfs.push({a + temp, b - temp, step + 1});
            }
        }
    }

    //Output
    cout << result;

    return 0;
}