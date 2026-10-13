class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen=0, maxf=0;
        int l=0, r=0;
        vector<int> hash(26, 0);
        while(r<n){
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            if((r-l+1)-maxf > k){
                hash[s[l] - 'A']--;
                l=l+1;
            }else{
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }
        return maxLen;
    }
};