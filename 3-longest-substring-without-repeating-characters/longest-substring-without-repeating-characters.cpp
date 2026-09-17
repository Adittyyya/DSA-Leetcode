class Solution {
public:
//TC: O(n) - r is running till n
//SC: O(256) - hash is using 256
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256, -1);

        int l=0, r=0;
        int maxLength = 0;

        while(r<n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }
            int length = r-l+1;
            maxLength = max(maxLength, length);
            hash[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};