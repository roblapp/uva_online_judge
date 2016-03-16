import java.math.BigDecimal;
import java.util.Scanner;

/*
Accepted: 0.092s
Category: math- bignum, floating point precision
*/

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int c = 0, n = sc.nextInt();
    BigDecimal x, sum = BigDecimal.ZERO;

    while (c < n) {
      x = sc.nextBigDecimal();
      if (x.compareTo(BigDecimal.ZERO) == 0) {
        System.out.println(sum.stripTrailingZeros().toPlainString());
        sum = BigDecimal.ZERO;
        c++;
      } else {
        sum = sum.add(x);
      }
    }
    sc.close();
  }
}
