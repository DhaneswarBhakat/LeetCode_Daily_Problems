class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_count; // Map to store character counts

    // Count the occurrences of each character in the string
    for (char ch : s) {
        char_count[ch]++;
    }

    // Find the first unique character and return its index
    for (int i = 0; i < s.length(); ++i) {
        if (char_count[s[i]] == 1) {
            return i;
        }
    }

    // If no unique character is found, return -1
    return -1;

    }
};
