/*There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

*/
class Solution {
public:
    static int exchange(int n, int k){
        if (n<k) return 0;
        auto [n0, r]=div(n, k);
        return n0+exchange(n0+r, k);
    }
    static int numWaterBottles(int n, int k) {
        return n+exchange(n, k);
    }
};
