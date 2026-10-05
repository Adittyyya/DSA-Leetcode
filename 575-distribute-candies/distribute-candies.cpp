class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();//always even-given
        unordered_set<int> set1(candyType.begin(), candyType.end());

        int type = set1.size();

        if(n/2 <= type){
            return n/2;
        }
        return type;
    }
};