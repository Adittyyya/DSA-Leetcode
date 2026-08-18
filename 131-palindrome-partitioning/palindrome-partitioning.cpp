class Solution {
public:

    bool isPalindrome(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }
    void getAllParts(string s, vector<string> &partition, vector<vector<string>> &ans){
        //base case
        if(s.size() == 0){
            ans.push_back(partition);
            return;
        }

        //main logic
        for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);
            if(isPalindrome(part)){// if palindrome then only recursion will be performed
                partition.push_back(part);
                getAllParts(s.substr(i+1), partition, ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        getAllParts(s, partition, ans);
        return ans;
    }
};