// C++ program to find the
// length of longest alternate
// subsequence
#include <iostream>
using namespace std;
  
// LAS[i][pos] array to find
// the length of LAS till
// index i by including or
// excluding element arr[i]
// on the basis of value of pos
int LAS[1000][2] = { false };
  
int solve(int arr[], int n, int i, bool pos)
{
    // Base Case
    if (i == n)
        return 0;
  
    if (LAS[i][pos])
        return LAS[i][pos];
  
    int inc = 0, exc = 0;
  
    // If current element is
    // positive and pos is true
    // Include the current element
    // and change pos to false
    if (arr[i] > 0 && pos == true) {
        pos = false;
  
        // Recurr for the next
        // iteration
        inc = 1 + solve(arr, n, i + 1, pos);
    }
  
    // If current element is
    // negative and pos is false
    // Include the current element
    // and change pos to true
    else if (arr[i] < 0 && pos == false) {
        pos = true;
  
        // Recurr for the next
        // iteration
        inc = 1 + solve(arr, n, i + 1, pos);
    }
  
    // If current element is
    // excluded, reccur for
    // next iteration
    exc = solve(arr, n, i + 1, pos);
  
    LAS[i][pos] = max(inc, exc);
  
    return LAS[i][pos];
}
  
// Driver's Code
int main()
{
    int arr[] = { -1, 2, 3, 4, 5,
                  -6, 8, -99 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    // Print LAS
    cout << max(solve(arr, n, 0, 0),
                solve(arr, n, 0, 1));
}