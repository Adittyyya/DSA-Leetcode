class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < s[0].length(); i++) {
            char ch = s[0][i];
            bool match = true;

            // Comparing matches
            for (int j = 1; j < n; j++) {
                if (i >= s[j].size() || ch != s[j][i]) {
                    match = false;
                    break;
                }
            }

            if (match == false) {
                break;
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};