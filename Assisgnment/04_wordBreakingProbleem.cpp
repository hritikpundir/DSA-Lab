#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// Function to check if the string can be segmented into dictionary words
bool wordBreak(const string& s, const vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.length();

    // DP table where dp[i] is true if s[0..i-1] can be segmented
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Empty string is always valid

    // Build the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    cout << "Enter the string to check: ";
    string s;
    cin >> s;

    cout << "Enter the number of words in the dictionary: ";
    int dictSize;
    cin >> dictSize;

    vector<string> wordDict;
    cout << "Enter the words in the dictionary:" << endl;
    for (int i = 0; i < dictSize; ++i) {
        string word;
        cin >> word;
        wordDict.push_back(word);
    }

    if (wordBreak(s, wordDict)) {
        cout << "The string can be segmented into valid dictionary words." << endl;
    } else {
        cout << "The string cannot be segmented into valid dictionary words." << endl;
    }

    return 0;
}
