class Solution {
public:
    int square_Sum(int n) {
        int ans = 0;
        while(n>0) {
            ans = ans + pow((n%10),2);
            n=n/10;
        }
        return ans;
    }
    
    
    bool isHappy(int n) {
        while(n>4) {
            n = square_Sum(n);
        }
        return (n==1);
    }
};