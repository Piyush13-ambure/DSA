/*You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, return -1.

*/

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num2==0) return popcount(unsigned(num1));
        long long x=num1;
        for(int k=1; k<36; k++){
            x-=num2;
            if (x<k) return -1;
            if (x>=0 && k>=popcount((unsigned long long)(x))) return k;
        }
        return -1;
    }
};
