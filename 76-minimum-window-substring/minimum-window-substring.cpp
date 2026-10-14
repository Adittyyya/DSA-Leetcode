class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size();
        int n = s.size();
        int l=0, r=0, minlen=INT_MAX;
        int count=0;
        int stIdx=-1;
        vector<int>hash(256, 0);

        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }
        while(r < n){

            if(hash[s[r]] > 0){
                count = count + 1;
            }
            hash[s[r]]--;

            while(count == m){
                if((r-l+1) < minlen){
                    minlen = r-l+1;
                    stIdx = l;
                }
                hash[s[l]]++;

                if(hash[s[l]] > 0){
                    count = count-1;
                }
                l++;
            }
            r= r+1;
        }
       return stIdx == -1 ? "" : s.substr(stIdx, minlen);
    }
};