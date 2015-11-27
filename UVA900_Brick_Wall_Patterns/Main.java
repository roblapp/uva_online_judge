import java.math.BigInteger;
import java.util.Scanner;
 
public class Main {
  private static BigInteger fib(int n) {
    BigInteger prev = BigInteger.ONE, back = BigInteger.ZERO, temp = BigInteger.ZERO;
    for (int i = 1; i <= n; i++) {
      temp = back.add(prev);
      back = prev;
      prev = temp;
    }
    return temp;
  }
 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n;
    while (sc.hasNextInt()) {
      n = sc.nextInt();
      if (n == 0)
        break;
      System.out.println(fib(n));
    }
    sc.close();
  }
}