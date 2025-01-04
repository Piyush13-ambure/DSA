//  swap min and max
//  Created by piyush ambure on 04/01/25.
#include <iostream>
using namespace  std;;
void swapMinMax(int arr[],int sz){
    int minindex=0;
    int maxindex=0;
    // Find the index of the minimum and maximum elements
    for (int i=0; i<sz; i++) {
        if (arr[i]<arr[minindex]) {
            minindex=i;
        }
        if (arr[i]>arr[maxindex]) {
            maxindex=i;
        }
    }
    // Swap the minimum and maximum elements
    if (minindex!=maxindex) {
        int temp = arr[minindex];
        arr[minindex]=arr[maxindex];
        arr[maxindex]=temp;
    
    }
}
int main(int argc, const char * argv[]) {
    int arr[]={4,2,7,8,1,2,5};
    int sz = sizeof(arr);
    
    
    cout << "Array before swap:" << endl;
    for (int i = 0; i < sz; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    swapMinMax(arr, sz);
    cout << "Array after swap:" << endl;
       for (int i = 0; i < sz; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
    return 0;
}
