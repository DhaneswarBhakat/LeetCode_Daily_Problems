class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
         vector<string> result;
    stack<int> st;

    int currentIndex = 0;

    for (int i = 1; i <= n; i++) {
        if (currentIndex == target.size()) {
            break;
        }

        if (target[currentIndex] == i) {
            result.push_back("Push");
            currentIndex++;
        } else {
            result.push_back("Push");
            result.push_back("Pop");
        }
    }

    return result;
        
    }
};
