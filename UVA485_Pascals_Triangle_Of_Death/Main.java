import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/*
Accepted: 0.318s
Category: math- bignum, dynamic programming, pascals triangle 
*/

class Main {
  static void printRow(List<BigInteger> list) {
    boolean first = true;
    for (Iterator<BigInteger> it = list.iterator(); it.hasNext();) {
      if (first) {
        System.out.print(it.next().toString());
      } else {
        System.out.print(" " + it.next().toString());
      }
      first = false;
    }
    System.out.println();
  }

  public static void main(String[] args) {
    BigInteger temp = null;
    final BigInteger MAX = BigInteger.TEN.pow(60);
    int currentRow = 0;
    boolean shouldBreak = false;
    List<BigInteger> prevRow = null, row = null;

    while (!shouldBreak) {
      row = new ArrayList<BigInteger>();
      for (int j = 0; j <= currentRow; j++) {
        if (j == 0 || j == currentRow) {
          row.add(BigInteger.ONE);
        } else {
          temp = prevRow.get(j - 1).add(prevRow.get(j));
          row.add(temp);
          if (temp.compareTo(MAX) >= 0) {
            shouldBreak = true;
          }
        }
      }
      printRow(row);
      prevRow = row;
      currentRow++;
    }
  }
}
