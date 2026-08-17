class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        //Horizontally
        for(int j=0; j<9; j++){
            if(board[row][j] == dig){
                return false;
            }
        }

        //vertically
        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        //Grid --> It may seem like nested loop but it is of O(9)TC which is constant
        int stR = (row/3)*3;
        int stC = (col/3)*3;
        for(int i=stR; i<=stR+2; i++){
            for(int j=stC; j<=stC+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col){

        //base case
        if(row == 9){
            return true;
        }

        int nextRow = row, nextCol = col+1;
        if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
        }
        if(board[row][col] != '.'){
            return helper(board, nextRow, nextCol);
        }

        //Place the digits
        for(char dig='1'; dig<='9'; dig++){
            if(isSafe(board, row, col, dig)){
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.'; //Backtracking - if dig from 1 to 9 is not existing
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};