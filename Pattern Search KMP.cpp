/*Given a string S and a pattern P of all lowercase characters. The task is to check if the pattern exists in the string or not.
  Your Task:
The task is to complete the function KMPSearch() which returns true or false depending on whether pattern is present in the string or not, and computeLPSArray() which computes the longest prefix suffix for every index.*/



#include <iostream>
#include <string>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(string pat, int M, int* lps) {
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;      // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // try with shorter previous prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to check if the pattern exists in the string using KMP
bool KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    // Create lps[] that will hold the longest prefix suffix values for pattern
    int* lps = new int[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat

    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            delete[] lps;  // clean up memory
            return true;   // pattern found
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    delete[] lps;  // clean up memory
    return false;  // pattern not found
}

// Main function to test the KMPSearch
int main() {
    string S1 = "aabaacaadaabaaba", P1 = "aaaab";
    string S2 = "aabaacaadaabaaba", P2 = "caada";

    cout << "Example 1: ";
    cout << (KMPSearch(P1, S1) ? "Yes" : "No") << endl;

    cout << "Example 2: ";
    cout << (KMPSearch(P2, S2) ? "Yes" : "No") << endl;

    return 0;
}
