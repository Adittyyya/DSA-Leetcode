class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
         string ans = "";
        int minLen = INT_MAX;

        for(int st = 0; st < s.length(); st++){
            int count = 0;
            for(int end = st; end < s.length(); end++){

                if(s[end] == '1'){
                    count++;
                }

                if(count > k){
                    break;
                }

                if(count == k){
                    string sub = s.substr(st, end - st + 1);

                    if(sub.length() < minLen) {
                        minLen = sub.length();
                        ans = sub;
                    }
                    else if(sub.length() == minLen && sub < ans) {
                        ans = sub;
                    }
                }
            }
        }
        return ans;
    }
};