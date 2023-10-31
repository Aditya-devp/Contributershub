public class RegularExpressionMatching {
    // using Recursion
    public boolean isMatch(String s, String p) {
        return isMatchRec(s, p, s.length() - 1, p.length() - 1);
    }

    public static boolean isMatchRec(String s1, String s2, int i, int j) {
        if (i == -1 && j == -1) {
            return true;
        }
        // without else if condition we get string out of bound Exception
        else if (j == -1) {
            return false;
        }
        if (i >= 0 && (s1.charAt(i) == s2.charAt(j) || s2.charAt(j) == '.')) {
            return isMatchRec(s1, s2, i - 1, j - 1);
        } else if (s2.charAt(j) == '*') {
            boolean ans = isMatchRec(s1, s2, i, j - 2);
            boolean ans1 = false;
            if (s2.charAt(j - 1) == '.') {
                for (int a = i; a >= 0; a--) {
                    boolean temp = isMatchRec(s1, s2, a - 1, j - 2);
                    ans1 = (temp) ? temp : ans;
                }
            } else {
                char c = s2.charAt(j - 1);
                for (int a = i; a >= 0 && s1.charAt(a) == c; a--) {
                    boolean temp = isMatchRec(s1, s2, a - 1, j - 2);
                    ans1 = (temp) ? temp : ans1;
                }
            }
            return (ans1 == true) ? ans1 : ans;
        } else {
            return false;
        }
    }
}
