import java.math.BigDecimal;
import java.util.Scanner;

/*
 Accepted: 0.069s
 Description: BigDecimal problem
 Info: Read problem description carefully! leading and trailing 0's MUST be stripped
 */

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n;
    BigDecimal r, temp;
    String s;

    while (sc.hasNextBigDecimal()) {
      r = sc.nextBigDecimal();
      n = sc.nextInt();
      temp = r.pow(n).stripTrailingZeros(); /* Strip trailing 0's */
      s = temp.toPlainString();
      /* Strip leading 0's - Note: cannot have a 0 so this loop will always terminate */
      for (n = 0; s.charAt(n) == '0'; n++);
      System.out.println(s.substring(n));
    }
    sc.close();
  }
}
