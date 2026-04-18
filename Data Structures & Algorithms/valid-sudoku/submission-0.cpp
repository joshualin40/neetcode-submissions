class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // first check all rows
        // there should be no dups, all chars should be 0-9
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> map;
            for (int j =0; j < 9; j++)
            {
                // first check if the char is between 0-9
                if (!isdigit(board[i][j]) && board[i][j] != '.') return false;
                if (board[i][j] != '.')
                    map[board[i][j]]++;
            }
            // now search through the map. if any key has value > 1 return false
            for (auto const& [key,value] : map)
            {
                if (value > 1) return false;
            }
        }
        // then check all columns
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> map;
            for (int j =0; j < 9; j++)
            {
                // first check if the char is between 0-9
                if (!isdigit(board[j][i]) && board[j][i] != '.') return false;
                if (board[j][i] != '.')
                    map[board[j][i]]++;
            }
            // now search through the map. if any key has value > 1 return false
            for (auto const& [key,value] : map)
            {
                if (value > 1) return false;
            }
        }

        for (int istart =0; istart<9; istart+=3)
        {
            for (int jstart = 0; jstart < 9; jstart += 3)
            {
                unordered_map<char, int> map;
                for (int i = 0; i < 3; i++)
                {
                    
                    for (int j =0; j < 3; j++)
                    {
                        // first check if the char is between 0-9
                        if (!isdigit(board[i + istart][j + jstart]) 
                        && board[i + istart][j + jstart] != '.') return false;
                        if (board[i + istart][j + jstart] != '.')
                            map[board[i + istart][j + jstart]]++;
                    }
                    // now search through the map. if any key has value > 1 return false
                }
                 for (auto const& [key,value] : map)
                    {
                        if (value > 1) return false;
                    }
            }
        }

        

        // then check the subboxes




        return true;
    }
};
