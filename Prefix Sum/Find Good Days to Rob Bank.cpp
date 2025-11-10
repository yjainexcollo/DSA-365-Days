class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        vector<int> pre(n, 0), suf(n, 0);
        // 0, 1, 2, 3, 3, 4, 0
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                pre[i] = 1 + pre[i - 1];
            }
        }

        // 0, 4, 3, 2, 1, 0, 0
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                suf[i] = 1 + suf[i + 1];
            }
        }

        vector<int> ans;

        for (int i = time; i < n - time; i++) {
            cout << pre[i] << endl;
            cout << suf[i] << endl;
            if (pre[i] >= time && suf[i] >= time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};