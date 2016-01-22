
class Main {

	/*
	 * The idea is that to calculate a[i], 
	 * we can use a[j]*2 for some j < i. 
	 * But we also need to make sure that: 
	 *  
	 * 1) a[j]*2 > a[i - 1] 
	 * and 
	 * 2) j is smallest possible. 
	 * 
	 * Then, a[i] = min(a[j]*2, a[k]*3, a[t]*5). 
	 * 
	 */
	public static void main(String[] args) {

		int n = 1500;

		int last2 = 0;
		int last3 = 0;
		int last5 = 0;

		long[] result = new long[n];
		result[0] = 1;
		for (int i = 1; i < n; ++i) {
			long prev = result[i - 1];

			while (result[last2] * 2 <= prev) {
				++last2;
			}
			while (result[last3] * 3 <= prev) {
				++last3;
			}
			while (result[last5] * 5 <= prev) {
				++last5;
			}

			long candidate1 = result[last2] * 2;
			long candidate2 = result[last3] * 3;
			long candidate3 = result[last5] * 5;

			result[i] = Math.min(candidate1, Math.min(candidate2, candidate3));
		}

		System.out.println("The 1500'th ugly number is: " + result[n - 1]);

	}
}