#include <iostream>
using namespace std;

// Hypothetical function to determine if A knows B
bool HaveAcquaintance(int A, int B) {
    // Replace this with the actual implementation
    return true; // Example placeholder
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
