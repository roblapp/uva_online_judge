
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main { 
	public static void main(String[] args) {
		final BufferedReader in; 
		try {
			long[] data; 
			in = new BufferedReader( new InputStreamReader( System.in ) ); 
			String str = in.readLine(); 
			int caseCount = 0, numCases = 0; 
			
			numCases = Integer.parseInt(str); 
			data = new long[ numCases ]; 
			
			while (caseCount < numCases) { 
				String input = in.readLine(); 
				data[ caseCount ] = Long.parseLong( input ); 
				caseCount++; 
			}

			for (int i = 0; i < data.length; i++) { 
				int count = 0; 
				long sum = data[i];
				while (sum != reverse(sum)) {
					sum = sum + reverse(sum); 
					count++; 
				} 
				System.out.println(count + " " + sum); 
			} 
			in.close();
			
		}catch(Exception e) {  System.exit( 0 );  } 
	} 
	
	static long reverse(long n) { 
		long result = 0; 
		while (n > 0) { 
			result = result*10 + n%10; 
			n /= 10; 
		} 
		return result; 
	} 
}


