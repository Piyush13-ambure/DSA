//You are given a string s in the form of an IPv4 Address. Your task is to validate an IPv4 Address, if it is valid return true otherwise return false.

//IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., "172.16.254.1"

//A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255. Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255)
//Note: Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.


      #include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
  public:
    // Function to check if a string is a valid IPv4 address
    int isValid(string& s) {
        vector<string> segments;
        stringstream ss(s);
        string segment;

        // Split the input string by '.' into segments
        while (getline(ss, segment, '.')) {
            segments.push_back(segment);
        }

        // An IPv4 address must have exactly 4 segments
        if (segments.size() != 4) {
            return false;
        }

        // Validate each segment
        for (const string& seg : segments) {
            // Segment must not be empty
            if (seg.empty()) {
                return false;
            }

            // Segment must not have leading zeros unless it is "0"
            if (seg.size() > 1 && seg[0] == '0') {
                return false;
            }

            // Segment must be numeric
            for (char ch : seg) {
                if (!isdigit(ch)) {
                    return false;
                }
            }

            // Convert the segment to an integer
            int num = stoi(seg);

            // Segment must be within the range [0, 255]
            if (num < 0 || num > 255) {
                return false;
            }
        }

        return true; // If all checks pass, it is a valid IPv4 address
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    string ip1 = "172.16.254.1";
    cout << "Is valid IPv4: " << solution.isValid(ip1) << endl; // Output: 1 (true)

    string ip2 = "256.256.256.256";
    cout << "Is valid IPv4: " << solution.isValid(ip2) << endl; // Output: 0 (false)

    string ip3 = "192.168.01.1";
    cout << "Is valid IPv4: " << solution.isValid(ip3) << endl; // Output: 0 (false)

    string ip4 = "192.168.1";
    cout << "Is valid IPv4: " << solution.isValid(ip4) << endl; // Output: 0 (false)

    string ip5 = "0.0.0.0";
    cout << "Is valid IPv4: " << solution.isValid(ip5) << endl; // Output: 1 (true)

    return 0;
}
