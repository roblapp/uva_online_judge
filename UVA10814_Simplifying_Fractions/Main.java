import java.math.BigInteger;
import java.util.Scanner;

/*
Accepted: 0.072s
Category: math- big num 
*/

class Main {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    BigInteger p, q, gcd;

    for (int i = 0; i < n; i++) {
      p = sc.nextBigInteger();
      sc.next(); /* drain '/' symbol */
      q = sc.nextBigInteger();
      gcd = p.gcd(q);
      System.out.println(p.divide(gcd) + " / " + q.divide(gcd));
    }
    sc.close();
  }
}
