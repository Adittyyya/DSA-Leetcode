class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> ans;

        for(int i= 0; i<n; i++){
            int freq = 0;
            for(int j=i; j<n; j++){
                if(arr[j] == arr[i]){
                    freq++;//1
                }
            }
            if(freq > n/3){//check if already presentt
                bool alreadyPres = false;
                for(int x: ans){
                    if(x == arr[i]){
                        alreadyPres = true;
                    }
                }
                if(!alreadyPres){
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};