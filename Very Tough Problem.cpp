/*You are given three numbers N, S and X. You have to tell whether it is possible to construct such sequence A of length N, where each Ai>=0 for 1<=i<=N and the sum of all numbers in a sequence is equal to S, and the XOR of sequence equals to X.


Your Task:  
You don't need to read input or print anything. Your task is to complete the function toughProblem() which takes the integer N, integer S, and integer X as input parameters and returns the “Yes” (without quotes) if it is possible to have such a sequence and “No” if it is not possible to have such a sequence
*/



class Solution{
public:    
  //Function to determine if the given problem is tough or not.
  string toughProblem(int n, int s, int x){
    //if there is only one variable, check if it is equal to x.
    if (n == 1) {
        return(s == x ? "Yes" : "No");
    }
    //if there are at least three variables, check if the difference
    //between s and x is even and greater than or equal to x.
    if (n >= 3) {
        return((s >= x && (s - x) % 2 == 0) ? "Yes" : "No");
    }
    //if there are two variables, check if the difference between s and x 
    //is even and can be evenly divided into x.
    if (s >= x && (s - x) % 2 == 0) {
        return((((s - x) / 2) & x) ? "No" : "Yes");
    } else {
        return("No");
    }
  }
    
};
