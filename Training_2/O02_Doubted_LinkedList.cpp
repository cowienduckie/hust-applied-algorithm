#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <pair<int, int>> cell;   //cell = pair of left and right

int find_rear(int head){    //head -> rear

    while(cell[head].second != 0){
        head =  cell[head].second;
    }

    return head;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num;    cin >> num; //Number of cells
    cell.resize(num + 1); 

    //Solution:   Devise head and rears and lonely cells in 2 stack (0, x), (0,0)
    //            Join all (0, 0) -> 1 lonely linked list
    //            Put lonlely list's head into stack 1
    //            Join heads with rears with find_rear function

    stack <int> head;   //(0, x) head stack
    stack <int> alone;  //(0, 0) lonely stack

    //Input data
    for (int i = 1; i <= num; ++i){
        cin >> cell[i].first >> cell[i].second;

        if (cell[i].first == 0 && cell[i].second == 0)  alone.push(i);
        else if (cell[i].first == 0)    head.push(i);
    }

    //Join lonely stack
    while (alone.empty() == false){ 
        int top = alone.top();

        if (cell[top].first == 0)   head.push(top);

        alone.pop();

        if (alone.empty() == false){
            cell[top].second = alone.top();
            cell[alone.top()].first = top;
        }
    }

    //Join heads with rears
    while (head.empty() == false){
        int top = head.top();

        head.pop();

        if (head.empty() == false){
            int rear = find_rear(top);

            cell[rear].second = head.top();
            cell[head.top()].first = rear;
        }

    }

    //Output
    for (int i = 1; i <= num; ++i){
        cout << cell[i].first << " " << cell[i].second << endl;
    }

    return 0;
}