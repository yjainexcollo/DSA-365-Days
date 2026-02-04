#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Step 1: Create the 'Inventory'
        vector<int> inventory(26, 0);
        for (char c : chars) {
            inventory[c - 'a']++;
        }

        int totalLength = 0;

        // Step 2: Check each word
        for (const string& word : words) {
            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }

            // Step 3: Comparison logic
            bool canForm = true;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] > inventory[i]) {
                    canForm = false;
                    break;
                }
            }

            // Step 4: Accumulate length
            if (canForm) {
                totalLength += word.length();
            }
        }

        return totalLength;
    }
};