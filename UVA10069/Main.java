import java.math.BigInteger;
import java.util.Scanner;
 
 /*
  Accepted: 0.162s
  Algorithm: dynamic programming
  Tips: I was confused by the directions. I thought that the answer
  could not go above 10,100 but I misread the directions. You cannot
  use primitive types for this as the answers can go well above 10,100.
  Description: Let a[i,j] represent the number of times the sequence of
  letters X1, ..., Xi is a subsequence of Y1, ..., Yj. Then, we can define
  a recurrence as follows:
  a[i,0] = 0 for all i > 0 since the letters of X cannot be a subsequence of
  the empty string.
  a[0,j] = 1 for all j >= 0 since the empty string of X is a subsequence of
  any substring of Y.
  a[i,j] = a[i,j-1] + a[i-1,j-1] if Xi == Yj
  
  Example: (The dp table created)
  	0	b	a	b	g	b	a	g
  0	1	1	1	1	1	1	1	1
  
  b 0	1	1	2	2	3	3	3
  
  a 0	0	1	1	1	1	4	4
  
  g 0	0	0	0	1	1	1	5
  */
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String a, b;
    BigInteger dp[][];
    int lenA, lenB, ncases = sc.nextInt(); sc.nextLine();
    while (ncases > 0) {
    	ncases--;
    	a = sc.nextLine(); b = sc.nextLine();
    	lenA = a.length(); lenB = b.length();
    	dp = new BigInteger[lenB + 1][lenA + 1];
    	for (int i = 0; i < dp.length; i++) dp[i][0] = BigInteger.ZERO;
    	for (int i = 0; i < dp[0].length; i++) dp[0][i] = BigInteger.ONE;
    	for (int i = 0; i < lenB; i++)
    		for (int j = 0; j < lenA; j++)
    			dp[i+1][j+1] = (b.charAt(i) == a.charAt(j)) ? dp[i][j].add(dp[i+1][j]) : dp[i+1][j];
    	System.out.println(dp[lenB][lenA]);
    }
    sc.close();
  }
}
