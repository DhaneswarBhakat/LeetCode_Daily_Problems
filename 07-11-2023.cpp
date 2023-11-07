class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
    vector<pair<double, int>> monsters;

    for (int i = 0; i < n; i++) {
        double time = static_cast<double>(dist[i]) / speed[i];
        monsters.push_back({time, i});
    }

    sort(monsters.begin(), monsters.end());

    double current_time = 0.0;
    int monsters_eliminated = 0;

    for (const auto& monster : monsters) {
        double time = monster.first;
        int index = monster.second;

        if (current_time + 1.0 >= time) {
            monsters_eliminated++;
            current_time = time;
        }
    }

    return monsters_eliminated;
        
    }
};
