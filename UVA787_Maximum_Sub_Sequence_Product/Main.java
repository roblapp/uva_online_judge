import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
Accepted: 0.368s
Description: BigInteger problem
*/

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final BigInteger STOP = BigInteger.valueOf(-999999);
		final BigInteger TEMP_MAX = BigInteger.valueOf(-1000000).pow(99);
		
		while (sc.hasNextBigInteger()) {
			BigInteger x;
			List<BigInteger> v = new ArrayList<BigInteger>();
			while (true) {
				x = sc.nextBigInteger();
				if (x.compareTo(STOP) == 0)
					break;
				v.add(x);
			}
			BigInteger maxNum = TEMP_MAX, temp;
			for (int i = 0, len = v.size(); i < len; i++) {
				temp = BigInteger.ONE;
				for (int j = i; j < len; j++) {
					temp = temp.multiply(v.get(j));
					maxNum = maxNum.max(temp);
				}
			}
			System.out.println(maxNum);
		}
		sc.close();
	}
}

