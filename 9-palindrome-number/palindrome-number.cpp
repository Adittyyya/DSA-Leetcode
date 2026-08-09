class Solution {
public:
    bool isPalindrome(int n) {

        if (n < 0) {
            return false;
        }

        int copyN = n;
        int revNum = 0;
        while(n > 0){
            int digit = n%10;
            if(revNum > INT_MAX/10){
                return false;
            }
            revNum = (revNum*10) + digit;
            n = n/10;
        }
        return revNum == copyN;
    }
};