class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n3 != n1 + n2)
            return false;

        int i = 0, j = 0, k = 0;

        while (k < n3) {
            if (j < n2 && s2[j] == s3[k]) {
                j++, k++;
            }
            else if (i < n1 && s1[i] == s3[k]) {
                i++, k++;
            }
            else {
                while (k >= 0 && s3[k] != s1[i]) {
                    k--, j--;
                }
                if (k < 0)
                    return false;
                k++, i++;
                j = max(j, 0);
            }
        }
        return true;
    }
};