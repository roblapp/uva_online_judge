import java.math.BigInteger;
import java.util.Scanner;
 
 /*
 ACCEPTED 0.306s
 Algorithm: Ad hoc/BigInteger
 Description: Just use Java's BigInteger class to perform simple
 checks to determine what type of year each input token is.
 Tips: MUST use BigInteger!!! Some numbers are between 1000 and 2000
 digits.
 */
 
public class Main {
  final static BigInteger FOUR = new BigInteger("4");
  final static BigInteger ONE_HUNDRED = new BigInteger("100");
  final static BigInteger FOUR_HUNDRED = new BigInteger("400");
  final static BigInteger FIFTEEN = new BigInteger("15");
  final static BigInteger FIFTY_FIVE = new BigInteger("55");
 
  static boolean isLeap(BigInteger year) {
    if (year.mod(FOUR_HUNDRED).compareTo(BigInteger.ZERO) == 0)
      return true;
    else if (year.mod(ONE_HUNDRED).compareTo(BigInteger.ZERO) == 0)
      return false;
    else if (year.mod(FOUR).compareTo(BigInteger.ZERO) == 0)
      return true;
    return false;
  }
 
  static boolean isHuluculu(BigInteger year) {
    return year.mod(FIFTEEN).compareTo(BigInteger.ZERO) == 0;
  }
 
  static boolean isBulukulu(BigInteger year) {
    return isLeap(year) && year.mod(FIFTY_FIVE).compareTo(BigInteger.ZERO) == 0;
  }
 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger year;
    boolean isFirst = true;
    boolean found;
    while (sc.hasNextBigInteger()) {
      year = sc.nextBigInteger();
      found = false;
      if (!isFirst) {
        System.out.println();
      }
      if (isLeap(year)) {
        found = true;
        System.out.println("This is leap year.");
      }
      if (isHuluculu(year)) {
        found = true;
        System.out.println("This is huluculu festival year.");
      }
      if (isBulukulu(year)) {
        found = true;
        System.out.println("This is bulukulu festival year.");
      }
      if (!found) {
        System.out.println("This is an ordinary year.");
      }
      isFirst = false;
    }
    sc.close();
  }
}
