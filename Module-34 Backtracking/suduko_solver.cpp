/* 
LeetCode 37 - Sudoku Solver
 */

#include<bits/stdc++.h>
using namespace std;

// const int N = 9;
// vector<vector<char>>solution_board;

class Solution{
public:
    vector<vector<char>> solution_board;
    //  returns true if the sudoku board doesnt have any empty cell;
    bool solution_found(vector<vector<char>>sudoku_board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(sudoku_board[i][j] == '.') return false;
            }
        }
        return true;
    }
    // return the position of the first encountered '.' character in the sudoku board as pair 
    pair<int, int> get_first_free_cell(vector<vector<char>>sudoku_board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(sudoku_board[i][j] == '.') return {i, j};
            }
        }  
        return {-1, -1};
    }

    vector<char> get_candidates(vector<vector<char>>sudoku_board, pair<int, int> free_cell){
        int row = free_cell.first;
        int col = free_cell.second;
        vector<char> ans;
        
        for(char digit = '1'; digit <= '9'; digit++){
            bool is_candidate = true;

            // 1. check the row
            for(int j = 0; j < 9; j++){
                if(sudoku_board[row][j] == digit){
                    is_candidate = false;
                    break;
                }
            }

            // 2. check the column
            for(int i = 0; i < 9; i++){
                if(sudoku_board[i][col] == digit){
                    is_candidate = false;
                    break;
                }
            }

            // 3. check the submatrix
            int a = row / 3, b = col / 3;
            a *= 3, b *= 3;
            for(int i = a; i < a+3; i++){
                for(int j = b; j < b+3; j++){
                    if(sudoku_board[i][j] == digit){
                        is_candidate = false;
                        break;
                    }
                }
            }

            if(is_candidate) ans.push_back(digit);
        }

        return ans;
    }

    bool backtrack(vector<vector<char>>sudoku_board){
        if(solution_found(sudoku_board) ){
            solution_board = sudoku_board;
            return true;
        }
        pair<int, int> free_cell = get_first_free_cell(sudoku_board);
        vector<char>candidates = get_candidates(sudoku_board, free_cell);

        for(char candidate : candidates){
            int row = free_cell.first;
            int column = free_cell.second;

            //add candidate to state
            sudoku_board[row][column] = candidate;

            // backtrack state
            bool solution_found = backtrack(sudoku_board);
            if(solution_found) return true;

            // remove candidate from state
            sudoku_board[row][column] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> board){
        backtrack(board);
        // for(int i = 0; i < 9; i++){
        //     for(int j = 0; j < 9; j++){
        //         cout << solution_board[i][j] << " ";
        //     } cout << '\n';
        // }
    }
};

int main(){
    vector<vector<char>>sudoku_board(9, vector<char>(9));

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku_board[i][j];
        }
    }
    Solution solution;
    solution.solveSudoku(sudoku_board);

}