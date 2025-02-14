/*Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

*/


#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefixProduct; // Stores prefix products
    
public:
    ProductOfNumbers() {
        prefixProduct.push_back(1); // Initial dummy value to avoid division by zero
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();  // Reset if zero is encountered
            prefixProduct.push_back(1); // Add 1 to prevent division by zero issues
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefixProduct.size()) return 0; // If k exceeds valid range after reset, return 0
        return prefixProduct.back() / prefixProduct[prefixProduct.size() - 1 - k];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    
    cout << productOfNumbers.getProduct(2) << endl; // 20
    cout << productOfNumbers.getProduct(3) << endl; // 40
    cout << productOfNumbers.getProduct(4) << endl; // 0
    
    productOfNumbers.add(8);
    
    cout << productOfNumbers.getProduct(2) << endl; // 32
    
    return 0;
}
