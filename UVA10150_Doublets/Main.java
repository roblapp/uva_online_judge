
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static final int MAXV = 25143;
	public static final int MAXLEN = 16;
	
	private AdjacencyList graphs[] = new AdjacencyList[MAXLEN + 1];
	private List> data = new ArrayList>(MAXLEN + 1);
	Map indexer = new HashMap();
	
	public Main() {
		for ( int i = 0; i < MAXLEN + 1; i++ )
			graphs[i] = new AdjacencyList();
		for ( int i = 0; i < MAXLEN + 1; i++ )
			data.add( new ArrayList() );
	}
	
	boolean isDoublet( String a, String b ) {
		int nmc = 0;
		for ( int i = 0; i < a.length(); i++ )
			if ( a.charAt(i) != b.charAt(i) ) nmc++;
		return ( nmc == 1 );
	}
	
	void printSolution( int v, int parent[], int len ) {
		if ( v != -1 ) {
			printSolution( parent[v], parent, len );
			System.out.println( data.get( len ).get( v ) );
		}
	}
	
	void buildGraph( Map indexer, int length ) {
		List list = data.get( length );
		for ( int i = 0; i < list.size() - 1; i++ ) {
			for ( int j = i + 1; j < list.size(); j++ ) {
				if ( isDoublet( list.get( i ), list.get( j ) ) ) {
					graphs[length].addNeighbor( i,  j );
				}
			}
		}
	}
	
	void bfs(int src, int dst, int length) {
		int parent[] = new int[MAXV];
		boolean visited[] = new boolean[MAXV];
		Vertex v[] = graphs[length].getList();
		Arrays.fill( parent, -1 );
		Queue q = new LinkedList();
		q.add( src );
		visited[src] = false;
		while ( !q.isEmpty() ) {
			int x = q.poll();
			if ( x == dst ) {
				printSolution( dst, parent, length );
				return;
			}
			Vertex temp = v[x];
			int n = temp.getX();
			while ( temp != null ) {
				if ( !visited[n] ) {
					q.add( n );
					visited[n] = true;
					parent[n] = x;
				}
				temp = temp.getNext();
			}
		}
		System.out.println("No solution.");
	}
	
	void solve() throws FileNotFoundException {
		Scanner sc = new Scanner( System.in );
		/*Scanner sc = new Scanner( new FileInputStream("test.txt" ) );
		 */
		String a, b, line;
		int n = 0;
		while ( ( line = sc.nextLine() ).length() > 0 ) {
			data.get( line.length() ).add( line );
			indexer.put( line, data.get( line.length() ).size() - 1 );
		}
		while ( sc.hasNextLine() ) {
			if ( n++ > 0 ) System.out.println();
			String t[] = sc.nextLine().split(" ");
			if ( t.length != 2 ) {
				System.out.println("No solution.");
			} else {
				a = t[0];
				b = t[1];
				int al = a.length();
				int bl = b.length();
				if ( al != bl || al > MAXLEN || !indexer.containsKey( a ) || !indexer.containsKey( b ) ) {
					System.out.println("No solution.");
				} else {
					if ( !graphs[al].hasElements() )
						buildGraph(indexer, al );
					bfs( indexer.get( a ), indexer.get( b ), al );
				}
			}
			
		}
		sc.close();
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		new Main().solve();
	}
}

class AdjacencyList {
	
	private Vertex list[];
	private boolean hasElements = false;
	
	public AdjacencyList() { list = new Vertex[Main.MAXV]; }
	
	public void addNeighbor(int src, int dst) {
		addNeighbor(src, dst, true );
		hasElements = true;
	}
	
	public Vertex[] getList() { return list; }
	
	public boolean hasElements() { return hasElements; }
	
	private void addNeighbor( int src, int dst, boolean x ) {
		list[src] = new Vertex( dst, list[src] );
		if ( x ) {
			addNeighbor( dst, src, false );
		}
	}
}

class Vertex {
	
	private int x;
	private Vertex next;
	
	public Vertex(int x) {
		this(x, null);
	}
	
	public Vertex( int x, Vertex next ) {
		this.x = x;
		this.next = next;
	}
	
	public int getX() { return x; }
	
	public Vertex getNext() { return next; }
}

