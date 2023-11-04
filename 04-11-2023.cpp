class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_time = 0;

    for (int position : left) {
        max_time = max(max_time, position);
    }

    for (int position : right) {
        max_time = max(max_time, n - position);
    }

    return max_time;
        
    }
};
