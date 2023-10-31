

import java.util.Arrays;

public class BestTeamWithNoConflicts {
//    // The goal
//     is to
//     select a
//     team of
//     players such
//     that the
//     sum of
//     the player
//     scores is
//     maximum and
//     the players
//     have the
//     same or
//     increasing ages.

public static int bestTeamScore(int[] scores, int[] ages) {
    // int m = ages.length;
   int n = scores.length;
   if(n==1){return scores[0];}
   int team[][]=new int [n][2];
   for (int i = 0; i < n; i++) {
    team[i][0] = ages[i];
    team[i][1] = scores[i];
}
 // sort on the basis of ages
 Arrays.sort(team, (a, b) -> (a[0] == b[0])? a[1] - b[1] : a[0] - b[0]  );
 //final array
 int[] dp = new int[n];
 int answer=0;
 for (int i = 0; i < n; i++) {
    dp[i] = team[i][1];
    answer = Math.max(answer, dp[i]);

 }

 for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) { // previous value
 if (team[i][1] >= team[j][1]){
    dp[i] = Math.max(dp[i],  team[i][1]+dp[j]);
}
 }

answer = Math.max(answer, dp[i]);
}
return answer;
}
}
