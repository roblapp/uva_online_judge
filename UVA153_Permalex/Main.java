import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/*
Accepted: 0.109s
Description: counting problem
*/

class Main {
	static BigInteger factorial(int n) {
		BigInteger result = BigInteger.ONE;
		for (int i = 2; i <= n; i++)
			result = result.multiply(BigInteger.valueOf(i));
		return result;
	}
	
	static int process(String line, int len) {
		if (len == 1)
			return 0;
			
		int freq[] = new int[26];
		int i, n = len - 1;
		Set<Character> uniqueChars = new HashSet<Character>(),
				charsLessThan = new HashSet<Character>();
		for (i = 0; i < len; i++) {
			uniqueChars.add(line.charAt(i));
			freq[line.charAt(i) - 'a']++;
		}
		for (i = 1; i < len; i++)
			if (line.charAt(0) > line.charAt(i))
				charsLessThan.add(line.charAt(i));
		
		int count, sum = 0;
		BigInteger temp;
		List<Integer> denom = new ArrayList<Integer>();
		for (char c : charsLessThan) {
			denom.clear();
			for (char cp : uniqueChars) {
				count = freq[cp - 'a'];
				if (c == cp)
					count--;
				if (count > 0)
					denom.add(count);
			}
			temp = BigInteger.ONE;
			for (int x : denom)
				temp = temp.multiply(factorial(x));
			sum += (factorial(n).divide(temp)).intValue();
		}
		return sum + process(line.substring(1), len - 1);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String line = null;
		int len;
		
		while (true) {
			line = sc.nextLine();
			if (line.equals("#")) {
				break;
			}
			if (line.isEmpty() || (len = line.length()) == 0)
				System.out.printf("%10d\n", 1);
			else
				System.out.printf("%10d\n", process(line, len) + 1);
		}
		sc.close();
	}
}
