//  sum and product
//  Created by piyush ambure on 04/01/25.
#include <iostream>
using namespace std;
// function perfrom an addition in an array elements
int sum(int arr [] ,int sz){
    int sum = 0;
    for (int i =0; i<sz; i++) {
        sum += arr[i];
    }
    return sum;
}
int product(int arr[],int sz){
    
   int product =1;
    for (int i =0; i<sz; i++) {
        product*=arr[i];
    }
    return product;
}
int main(int argc, const char * argv[]) {
    int arr[]={4,2,7,8,1,2,5};
    int sz = 7;
    cout<<"Addtion::"<<sum(arr, sz)<<endl;
    cout<<"Product ::"<<product(arr,sz)<<endl;
    return 0;
}
