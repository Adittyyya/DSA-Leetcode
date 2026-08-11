class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();

        if (m == 0) {
            return {};
        }

        int n = mat[0].size();

        int stRow = 0, endRow = m - 1;
        int stCol = 0, endCol = n - 1;

        vector<int> ans;

        while (stRow <= endRow && stCol <= endCol) {

            // Top
            for (int j = stCol; j <= endCol; j++) {
                ans.push_back(mat[stRow][j]);
            }

            // Right
            for (int i = stRow + 1; i <= endRow; i++) {
                ans.push_back(mat[i][endCol]);
            }

            // Bottom
            for (int j = endCol - 1; j >= stCol; j--) {
                if (stRow == endRow) {
                    break;
                }
                ans.push_back(mat[endRow][j]);
            }

            // Left
            for (int i = endRow - 1; i >= stRow+1; i--) {
                if (stCol == endCol) {
                    break;
                }
                ans.push_back(mat[i][stCol]);
            }

            stRow++;
            endRow--;
            stCol++;
            endCol--;
        }

        return ans;
    }
};