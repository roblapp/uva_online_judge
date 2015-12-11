import java.math.BigInteger;
import java.util.Scanner;

/*
 Accepted: 0.079s
 Description: big integer problem
 */

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger a, b;
    String op;

    while (sc.hasNext()) {
      a = sc.nextBigInteger();
      op = sc.next();
      b = sc.nextBigInteger();
      if (op.equals("/"))
        System.out.println(a.divide(b));
      else
        System.out.println(a.mod(b));
    }
    sc.close();
  }
}
