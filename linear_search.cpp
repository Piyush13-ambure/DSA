// linear search
//  main.cpp
//  Practice
//
//  Created by piyush ambure on 03/01/25.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
using namespace std;
int  leniar_search(int arr[], int SIZE ,int targate ){
    for (int i=0;i<SIZE;i++){
        if (arr[i] ==targate){
            return i;
        }
            }
    return  -1;
}
int main() {
    // Array size
    const int SIZE = 1000;
    int arr[SIZE];
    
    // Seed for random number generation
    srand(static_cast<unsigned>(time(0)));
    
    // Set to keep track of used numbers
    unordered_set<int> usedNumbers;

    for (int i = 0; i < SIZE; ++i) {
        int num;
        do {
            num = rand() % 10000; // Random number between 0 and 9999
        } while (usedNumbers.find(num) != usedNumbers.end()); // Ensure uniqueness

        arr[i] = num;               // Add to array
        usedNumbers.insert(num);    // Add to set
    }
    for (int i = 0; i < 1000; ++i) {
           cout << "arr[" << i << "] = " << arr[i] << endl;
       }
    int targate;
    cout<<"enter targate::"<<endl;
    cin>>targate;
    int index = leniar_search( arr, SIZE , targate );
    cout << index;
    return 0;
}
