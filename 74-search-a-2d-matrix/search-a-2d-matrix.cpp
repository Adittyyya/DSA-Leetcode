class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size();
        int n = mat[0].size();

        int stR = 0;
        int endR = m - 1;

        while(stR <= endR) {

            int midR = stR + (endR - stR) / 2;

            if(mat[midR][0] <= tar && tar <= mat[midR][n-1]) {

                int stC = 0;
                int endC = n - 1;

                while(stC <= endC) {

                    int midC = stC + (endC - stC) / 2;

                    if(mat[midR][midC] == tar) {
                        return true;
                    }
                    else if(mat[midR][midC] < tar) {
                        stC = midC + 1;
                    }
                    else {
                        endC = midC - 1;
                    }
                }

                return false;
            }
            else if(mat[midR][n-1] < tar) {
                stR = midR + 1;
            }
            else {
                endR = midR - 1;
            }
        }

        return false;
    }
};