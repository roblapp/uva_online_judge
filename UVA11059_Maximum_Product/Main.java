import java.math.BigInteger;
import java.util.Scanner;
 
/*
Accepted: 0.096s
Description: ad-hoc, brute force
Info: Since the input only has 18 elements at most, an N^2 algorithm will
be OK. What is a better way to do this problem?
*/

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n, N = 1;
    BigInteger a[];
    BigInteger prod, maxProd;
    
    while (sc.hasNextInt()) {
    	n = sc.nextInt();
    	a = new BigInteger[n];
    	for (int i = 0; i < n; i++)
    		a[i] = sc.nextBigInteger();
    	maxProd = BigInteger.ZERO;
    	for (int i = 0; i < n; i++) {
    		prod = BigInteger.ZERO;
    		for (int j = i; j < n; j++) {
    			if (prod.compareTo(BigInteger.ZERO) == 0)
    				prod = a[j];
    			else
    				prod = prod.multiply(a[j]);
    			if (prod.compareTo(maxProd) > 0)
    				maxProd = prod;
    		}
    	}
    	System.out.println("Case #" + N++ + ": The maximum product is " + maxProd.toString() + ".\n");
    }
    sc.close();
  }
}
