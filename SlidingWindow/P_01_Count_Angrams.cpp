class Solution {
public:

    bool allZeros(vector<int> &cnt) {
        for (int x : cnt) {
            if (x != 0) return false;
        }
        return true;
    }

    int search(string &pat, string &txt) {
        int n = txt.size();
        int k = pat.size();
        if (k > n) return 0;

        vector<int> counter(26, 0);

        for (char ch : pat) {
            counter[ch - 'a']++;
        }

        int i = 0, j = 0;
        int result = 0;

        while (j < n) {
            counter[txt[j] - 'a']--;

            if (j - i + 1 == k) {
                if (allZeros(counter)) {
                    result++;
                }
                counter[txt[i] - 'a']++;
                i++;
            }

            j++;
        }

        return result;
    }
};
