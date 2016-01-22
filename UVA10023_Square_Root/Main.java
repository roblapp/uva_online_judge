
import java.math.BigInteger;
import java.util.Scanner;

/* ACCEPTED 0.925 */

public class Main
{	
	public static BigInteger sqrt( BigInteger x )
	{
		BigInteger temp = x.shiftRight( BigInteger.valueOf( x.bitLength() ).shiftRight(1).intValue() );
		BigInteger result = null;
		
		while ( true )
		{
			result = temp.add( x.divide( temp ) ).shiftRight( 1 );
			
			if ( !temp.equals(result) )
				temp = result;
			else
				break;
		}
		
		return result;
	}
	
	public static void main(String[] args) {
	
		int i, ncases;
		BigInteger x = null;
		Scanner sc = new Scanner( System.in );
		
		ncases = sc.nextInt();
		
		for ( i = 0; i < ncases; i++ )
		{
			x = sc.nextBigInteger();
			
			System.out.println( sqrt( x ) );
			if ( i < ncases - 1 )
				System.out.println();
		}
		
		sc.close();
	}
}


