class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(int i=0; i<str.size(); i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                st.push(str[i]);
            }else{
                if(st.size() == 0){//if closing come first(closing > opening)
                    return false;
                }

                if((st.top() == '(' && str[i] == ')') ||
                (st.top() == '[' && str[i] == ']') ||
                (st.top() == '{' && str[i] == '}')){//to check top in stack with left braces in string
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};