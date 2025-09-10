/*Given the co-effecients of X,Y and Z in a system of simultaneous equations. Find the values of X,Y and Z.

 a1X + b1Y + c1Z = d1
 a2X + b2Y + c2Z = d2
 a3X + b3Y + c3Z = d3

 Your Task:  
You dont need to read input or print anything. Complete the function myCalculator() which takes Arr as input parameter and returns 0 in case the system is inconsistent and 1 in case the system is consistent and has infinitely many solutions. In case the system is consistent and has a unique solution, return 3 space separated integers denoting the floor values of X, Y and Z respectively.

 */

class Solution {
  public:
    int echelonize(double array[3][4], int row, int col)
{
    int pivot_index=0;  //leading coefficient
    /*
    for every row, do popluate to the rows under it to make 
    the ith coefficient to be 0
    */
    int all_zero=true;
    for(int i=0; i<row; i++){
        /*here need to make sure the leading pivot is not for the row i, so
        we need to swap if it's 0*/
        double maxabs=abs(array[i][i]);
        int maxabs_row=i; //find which row has the max abs value of it's col ith(pivot) 
        for(int l=i; l<row; l++){
            if(abs(array[l][i])>maxabs){
                maxabs_row=l;
                maxabs=abs(array[l][i]);
            }
        }
        if(maxabs==0)
            return -1;  //means not consistant
        else            //swap row maxabs_row with i
            for(int l=0; l<col; l++)
                swap(array[i][l], array[maxabs_row][l]);
            
        /*to populate the row i*/
        for(int j=i+1; j<row; j++){
            //add every col to jth row
            all_zero=true;
            //cout<<endl<< "row "<<j<<endl;
            double t_factor=array[j][i];
            double d_factor=array[i][i];
            for(int k=0; k<col; k++)
            {
                array[j][k]+=array[i][k]*-1*t_factor/d_factor;
                //cout<<array[j][k]<<" ";
                if(array[j][k]!=0&&k!=col-1)
                    all_zero=false;
            }
            if(all_zero) return -1;     //means not consistant, multiple solution
        }
    }

    /*for now, the matrix is echelon already, do fruther to be redueced
    do a reverse one*/
    for(int i=row-1; i>=0; i--){
        /*to populate the row i*/
        for(int j=i-1; j>=0; j--){
            //cout<<endl<< "row "<<j<<endl;
            double t_factor=array[j][i];
            double d_factor=array[i][i];
            //add every col to jth row
            for(int k=0; k<col; k++)
            {
                array[j][k]+=array[i][k]*-1*t_factor/d_factor;
                //cout<<array[j][k]<<" ";
            }
        }
    }

    for(int i=0; i<row; i++){
        double d_factor=array[i][i];
        for(int j=0; j<col; j++){
            array[i][j]/=d_factor;
        }
    }

    return 0;
    
}
vector<double> myCalculator(double Arr[3][4]){
    vector<double>ans;
    if(echelonize(Arr, 3, 4)!=-1){
        ans.push_back(floor(Arr[0][3]));
        ans.push_back(floor(Arr[1][3]));
        ans.push_back(floor(Arr[2][3]));
    }
    else{
        ans.push_back(0);
    }
    return ans;
}
};
