
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/* ACCEPTED 1.076s */
/* CRAPPY RUNTIME!!! 
 * 
 * I tried doing this problem in C but kept getting TLE. I tried
 * a variety of hash functions and nothing worked. I guess I am going
 * to be researching hash table implementations to improve my C hash
 * table.
 * 
 * */

public class Main {
	
	static Map map = new HashMap();
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		String line = null, maxStr = null, subStr;
		int len, max;
		
		while (sc.hasNextInt()) {
			max = 0;
			len = sc.nextInt();
			do {
				line = sc.next();
			} while (line.length() == 0);
				map.clear();
				int strlen = line.length();
				for (int i = 0; i <= strlen - len; i++) {
					subStr = line.substring(i,  i + len);
					Integer x = map.get(subStr);
					int res = 1;
					if (x == null) {
						map.put(subStr, 1);
					} else {
						map.put(subStr, x + 1);
						res = x + 1;
					}
					if (res > max) {
						max = res;
						maxStr = subStr;
					}
				}
				System.out.println(maxStr);
		}
		sc.close();
	}
}
