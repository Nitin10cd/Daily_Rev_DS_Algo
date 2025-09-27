#include <bits/stdc++.h>
using namespace std;

/*
📌 QUESTION:
You are given:
1. A list of `s` sample values (integers).
2. `r` ranges, each defined by two integers: `left` and `right`.

For each range, you need to count how many sample values fall **within that range (inclusive)**.

---

📊 EXAMPLE:

Input:
Enter the number of samples and the number of ranges: 5 2
Enter 5 samples:
1 5 8 10 12
Enter range 1 (left and right): 0 6
Enter range 2 (left and right): 8 12

Step-by-step:
Samples: [1, 5, 8, 10, 12]

Range 1 → [0, 6]:
- 1 ✅
- 5 ✅
- 8 ❌
- 10 ❌
- 12 ❌
✅ Count = 2

Range 2 → [8, 12]:
- 1 ❌
- 5 ❌
- 8 ✅
- 10 ✅
- 12 ✅
✅ Count = 3

Output:
The count of samples in range [0, 6] is: 2
The count of samples in range [8, 12] is: 3

---

🧠 What the program does:
- Reads `s` (number of samples) and `r` (number of ranges).
- Reads `s` sample values into an array.
- For each of the `r` ranges, reads `left` and `right` and counts how many samples lie between them (inclusive).
- Prints the count for each range.
*/

int main() {
    int s, r;
    cout << "Enter the number of samples and the number of ranges: ";
    if (!(cin >> s >> r)) {
        cerr << "Invalid input! Exiting.\n";
        return 1;
    }
    
    vector<int> arr(s);
    cout << "\nEnter " << s << " samples:\n";
    for (int i = 0; i < s; i++) {
        if (!(cin >> arr[i])) {
            cerr << "Invalid sample input!\n";
            return 1;
        }
    }

    for (int i = 0; i < r; i++) {
        cout << "Enter range " << i + 1 << " (left and right): ";
        int left, right;
        if (!(cin >> left >> right)) {
            cerr << "Invalid range input!\n";
            return 1;
        }

        int count = 0;
        for (int j = 0; j < s; j++) {
            if (arr[j] >= left && arr[j] <= right) {
                count++;
            }
        }

        cout << "The count of samples in range ["
             << left << ", " << right << "] is: "
             << count << "\n";
    }

    return 0;
}
