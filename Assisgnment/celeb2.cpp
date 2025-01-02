#include <iostream>
#include <vector>
using namespace std;

// Example adjacency matrix for demonstration
vector<vector<int>> acquaintanceMatrix = {
    {0, 1, 1, 1},  // Person 0 knows Person 1, 2, and 3
    {0, 0, 1, 1},  // Person 1 knows Person 2 and 3
    {0, 0, 0, 0},  // Person 2 knows no one (celebrity)
    {0, 0, 1, 0}   // Person 3 knows Person 2
};

// Hypothetical function to determine if A knows B
bool HaveAcquaintance(int A, int B) {
    return acquaintanceMatrix[A][B] == 1;
}

// Function to find the celebrity
int findCelebrity(int n) {
    int candidate = 0;

    // Step 1: Identify a potential candidate
    for (int i = 1; i < n; i++) {
        if (HaveAcquaintance(candidate, i)) {
            candidate = i;
        }
    }

    // Step 2: Verify the candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // Candidate must not know i, and everyone must know the candidate
            if (HaveAcquaintance(candidate, i) || !HaveAcquaintance(i, candidate)) {
                return -1; // No celebrity found
            }
        }
    }

    return candidate;
}

int main() {
    int n = 4; // Number of people at the party
    int celebrity = findCelebrity(n);

    if (celebrity == -1) {
        cout << "No celebrity found!" << endl;
    } else {
        cout << "The celebrity is person " << celebrity << endl;
    }

    return 0;
}
