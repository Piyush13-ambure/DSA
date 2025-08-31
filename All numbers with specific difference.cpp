/*Given a positive number n and a number d.  Find the count of positive numbers smaller or equal to  n such that the difference between the number and sum of its digits is greater than or equal to given specific value d.


Your Task:
You don't need to read input or print anything. Your task is to complete the function getCount() which takes 2 integers n and d as input and returns the answer.

*/

class Solution {
  public:

    // Function to get Sum of Digits of a Number.
    long long sumOfDigit(long long K) {

        long long sod = 0;
        while (K) {
            sod += K % 10;
            K /= 10;
        }
        return sod;
    }

  public:
    long long getCount(long long N, long long D) {

        // Binary Search to get the least number satisfying the Conditions

        long long low = 1, high = N;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (mid - sumOfDigit(mid) < D)
                low = mid + 1;

            else
                high = mid - 1;
        }

        // The least satisfying number must be subtracted from N to get the answer.

        return (N - high);
    }
};
