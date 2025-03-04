//Given a string str consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> lower, upper;

        // Separate lowercase and uppercase characters
        for (char ch : str)
        {
            if (islower(ch))
                lower.push_back(ch);
            else
                upper.push_back(ch);
        }

        // Sort both lists
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // Reconstruct the sorted string while maintaining original case positions
        int l_idx = 0, u_idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (islower(str[i]))
                str[i] = lower[l_idx++];
            else
                str[i] = upper[u_idx++];
        }

        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        Solution obj;
        cout << obj.caseSort(str, n) << endl;
    }
  return 0;
}
// } Driver Code Ends
