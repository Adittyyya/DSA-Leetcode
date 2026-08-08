class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        for(int i=0; i<chars.size(); i++){
            char ch = chars[i]; //storing  character one by one in ch
            int count = 0;
            while(i < chars.size() && chars[i] == ch){ //To count the frequency
                count++;
                i++;
            }

            if(count == 1){
                chars[idx] = ch;
                idx++;
            }else{
                chars[idx] = ch;
                idx++;

                string str = to_string(count); //converting int val into string using function
                for(char digit: str){//Counding each digit in a str
                    chars[idx] = digit; //String at index
                    idx++;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};