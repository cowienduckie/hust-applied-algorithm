#include <iostream>

using namespace std;

//Global Variables
int N = 0, M = 0, result = 0;

int board[13][13];

//
void newBoard(){

    for (int i = 1; i <= N; ++i){  //clean board

        for (int j = 1; j <= N; ++j){

            board[i][j] = 0;
        }
    }

    for (int i = 1; i <= M; ++i){  //update holes

        int x = 0, y = 0;  cin >> x >> y;

        board[x][y] = 24;
    }

    result = 0;
}

void spreadThreat(int col, int row){ //increase by 1 for all squares on the right col that queen(col, row) threats

    for (int i = 1;  i <= N - col; ++i){

        ++board[col + i][row];

        if (col + i <= N && row + i <= N) ++board[col + i][row + i];
        if (col + i <= N && row - i >= 1) ++board[col + i][row - i];
    }
}

void withdrawThreat(int col, int row){ //decrease by 1 for all squares on the right col that queen(col, row) threats

    for (int i = 1;  i <= N - col; ++i){

        --board[col + i][row];

        if (col + i <= N && row + i <= N) --board[col + i][row + i];
        if (col + i <= N && row - i >= 1) --board[col + i][row - i];
    }
}


//Algorithm
//On the chess board. value of each square means how many queens threat it
//When a queen threat a square, its value increase by 1
//The hole is a super threat, so that square have infinity value
//A queen can only be placed in a safe square
//Using backtracking to place N queens column by column and count number of complete board
//The threat is only spread to the right side of a queen because we consider from left to right
//Don't forget withdraw threat right the way it spread when a queen moved out from a square 
//
void placeQueen(int col){ //Place queen column by column 

    if (col > N){

        ++result;
        
        return;
    }

    for (int row = 1; row <= N; ++row){

        if (board[col][row] == 0){

            spreadThreat(col, row);

            placeQueen(col + 1);

            withdrawThreat(col, row);
        }
    }    
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while(true){
        //INPUT
        cin >> N >> M;  if (N == 0 && M == 0)  break;

        newBoard();

        //
        
        placeQueen(1);//Place queen from the first left column

        //OUTPUT
        cout << result << endl;
    }

    return 0;
}