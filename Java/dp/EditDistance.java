public class EditDistance {
    public int minDisRec(String word1, String word2, int i, int j) {
        if (i == word1.length()) {
            return word2.length() - j;
        } else if (j == word2.length()) {
            return word1.length() - i;
        } else if (word1.equals(word2)) {
            return 0;
        }
        int ans;
        if (word1.charAt(i) == word2.charAt(j)) {
            ans = minDisRec(word1, word2, i + 1, j + 1);
        } else {
            int ans1 = minDisRec(word1, word2, i + 1, j + 1) + 1;
            int ans2 = minDisRec(word1, word2, i, j + 1) + 1;
            int ans3 = minDisRec(word1, word2, i + 1, j) + 1;
            ans = Math.min(ans2, Math.min(ans1, ans3));
        }
        return ans;
    }

    public int minDistanceTab(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int dp[][] = new int[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++)
            dp[i][0] = i;
        for (int j = 0; j < n + 1; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int a = dp[i - 1][j] + 1;
                    int b = dp[i - 1][j - 1] + 1;
                    int c = dp[i][j - 1] + 1;
                    dp[i][j] = Math.min(b, Math.min(a, c));
                }
            }
        }
        return dp[m][n];
    }
}
