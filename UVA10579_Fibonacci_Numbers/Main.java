import java.math.BigInteger;
import java.util.Scanner;

/*
Accepted: 0.082s
Category: math- bignum, fibonacci
*/

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    final int MAX_FIBS = 10000;
    int x;
    BigInteger fibs[] = new BigInteger[MAX_FIBS + 1];
    fibs[0] = BigInteger.ZERO;
    fibs[1] = BigInteger.ONE;

    for (int i = 2; i <= MAX_FIBS; i++)
      fibs[i] = fibs[i - 1].add(fibs[i - 2]);

    while (sc.hasNextInt()) {
      x = sc.nextInt();
      System.out.println(fibs[x]);
    }
    sc.close();
  }
}
