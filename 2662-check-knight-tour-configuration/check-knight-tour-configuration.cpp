class Solution {
public:

//Time Complexity: O( (8)^(n*n) )
    bool isValid(vector<vector<int>> &arr, int r, int c, int n, int expVal){

        //base case for false or in validity
        if(r < 0 || c < 0 || r >= n || c >= n || arr[r][c] != expVal){
            return false;
        }

        //base case for true or validity
        if(expVal == n*n - 1){
            return true;
        }

        //8 possible moves
        int ans1 = isValid(arr, r-2, c+1, n, expVal+1);
        int ans2 = isValid(arr, r-1, c+2, n, expVal+1);
        int ans3 = isValid(arr, r+1, c+2, n, expVal+1);
        int ans4 = isValid(arr, r+2, c+1, n, expVal+1);
        int ans5 = isValid(arr, r+2, c-1, n, expVal+1);
        int ans6 = isValid(arr, r+1, c-2, n, expVal+1);
        int ans7 = isValid(arr, r-1, c-2, n, expVal+1);
        int ans8 = isValid(arr, r-2, c-1, n, expVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& arr) {
        return isValid(arr, 0, 0, arr.size(), 0);
    }
};