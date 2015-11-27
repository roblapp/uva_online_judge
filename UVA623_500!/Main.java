import java.math.BigInteger;
import java.util.Scanner;
 
/*
Accepted: 0.512s
Description: BigInteger problem
*/
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n;
    BigInteger result;
    BigInteger cache[] = new BigInteger[1000 + 1];
    cache[0] = cache[1] = BigInteger.ONE;
    while (sc.hasNextInt()) {
      n = sc.nextInt();
      if (cache[n] != null) {
        result = cache[n];
      } else {
        result = BigInteger.ONE;
        for (int i = 2; i <= n; i++) {
          result = result.multiply(BigInteger.valueOf(i));
          if (cache[i] == null)
            cache[i] = result;
        }
      }
      System.out.println(n + "!\n" + result.toString());
    }
    sc.close();
  }
}
 