/*Let's play a game!! Given a matrix mat[][] with n x m elements. Your task is to check that matrix is Super Similar or not. To perform this task you have to follow these Rules: Firstly all even index rows to be Rotated left and odd index rows to right, And Rotation is done X times(Index starting from zero). Secondly, After all the Rotations check if the initial and the final Matrix are same Return 1 else 0.

Your Task:
You do not need to read input or print anything. Your task is to complete the function isSuperSimilar() which takes n, m, x and the matrix as input parameter and returns 1 if the initial and the final Matrix are same else returns 0.
*/



class Solution {
  public:
    //Function to check if the given matrix is super similar for a given number x.
    int isSuperSimilar(int n, int m, vector<vector<int>>&mat, int x){
        //Checking if x is divisible by the number of columns, return 1.
        if(x%m==0)return 1;
        else{
        //If x is not divisible by the number of columns, perform the following checks.
        x%=m;
        //Iterating over each row.
        for(int j=0;j<n;j++){
            //Iterating over each column.
        for(int i=0;i<m;i++){
            //Checking if the current element is not equal to the element at position
            //(i-x+m)%m in the same row, return 0.
            if(mat[j][i]!=mat[j][(i-x+m)%m])
            {
                return 0;
            }
        }
        //If all elements in the row satisfy the above condition, return 1.
        return 1;
        }
    }
    }
};
