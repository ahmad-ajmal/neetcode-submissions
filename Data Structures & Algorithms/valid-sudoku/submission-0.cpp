class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check Rows
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<vector<unordered_set<char>>> grids(3, vector<unordered_set<char>>(3));

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(row[i].contains(board[i][j]))
                {
                    return false;
                }
                row[i].insert(board[i][j]);

                if(col[j].contains(board[i][j]))
                {
                    return false;
                }
                col[j].insert(board[i][j]);

                if(grids[i/3][j/3].contains(board[i][j]))
                {
                    return false;
                }
                grids[i/3][j/3].insert(board[i][j]);
            }
        }

        return true;
    }
};
