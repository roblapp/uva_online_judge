import java.math.BigDecimal;
import java.util.Scanner;

/*
Accepted: 0.229s
Category: math- bignum, floating point precision, bignum precision 
*/

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String num;
    BigDecimal temp;

    for (int i = 0; i < n; i++) {
      temp = sc.nextBigDecimal().add(sc.nextBigDecimal()).stripTrailingZeros();
      if (temp.compareTo(BigDecimal.ZERO) == 0) {
        System.out.println("0.0");
      } else {
        num = temp.toPlainString();
        if (!num.contains(".")) {
          System.out.println(num + ".0");
        } else {
          System.out.println(num);
        }
      }
    }
    sc.close();
  }
}
