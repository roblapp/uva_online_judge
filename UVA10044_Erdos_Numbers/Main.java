
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

/*
ACCEPTED 1.742s

*/
public class Main {

	Graph g = new Graph();
	Map map = new HashMap(1 << 12);
	int index;
	
	private void processNames(String data[]) {
		int i, j, src, dst;
		for (i = 0; i < data.length - 1; i++) {
			if (!map.containsKey(data[i])) {
				map.put(data[i], index++);
			}
			src = map.get(data[i]);
			for (j = i + 1; j < data.length; j++) {
				if (!map.containsKey(data[j])) {
					map.put(data[j], index++);
				}
				dst = map.get(data[j]);
				g.insertEdge(src, dst);
			}
		}
	}

	public int getErdos() {
		return map.containsKey("Erdos, P.") ? map.get("Erdos, P.") : -1;
	}
	
	public int getD( String data ) {
		return  map.containsKey( data ) ? map.get( data ) : -1;
	}

	void showMap() {
		for (Map.Entry entry : map.entrySet()) {
			String key = entry.getKey();
			int value = entry.getValue();
			System.out.println(">" + key + "<  " + value);
		}
	}

	public static void main(String[] args) throws Exception {

		Main m = new Main();
		int i, j, ncases, ndata, nq, res, distance[];
		/* Scanner sc = new Scanner(new FileInputStream("test.txt")); */
		Scanner sc = new Scanner( System.in );
		ncases = sc.nextInt();
		sc.nextLine();

		for (i = 0; i < ncases; i++) {

			ndata = sc.nextInt();
			nq = sc.nextInt();
			sc.nextLine();

			m.index = 0;
			m.g.deleteGraph();
			m.map.clear();

			for (j = 0; j < ndata; j++) {
				String temp = sc.nextLine();
				if ( temp.length() == 0 ) {
					j--;
				} else {
					m.processNames(m.processLine( temp ));
				}
			}
			
			int src = m.getErdos();

			System.out.println("Scenario " + (i + 1));

			if (src == -1) {
				for (j = 0; j < nq; j++) {
					String temp = sc.nextLine().trim();
					if ( temp.length() == 0 ) {
						j--;
					} else {
						System.out.println( temp + " infinity");
					}
				}
			} else {
				distance = m.g.bfs(src);
				for (j = 0; j < nq; j++) {
					String temp = sc.nextLine().trim();
					if ( temp.length() == 0 ) {
						j--;
					} else {
						res = m.getD( temp );
						System.out.print( temp  + " ");
						if (res == -1) {
							System.out.println("infinity");
						} else {
							int td = distance[res];
							if ( td == -1 ) {
								System.out.println("infinity");
							} else {
								System.out.println( distance[ res ] );
							}
						}
					}
				}
			}
		}
		sc.close();
	}
	
	private String[] processLine(String line) {

		int i = 0, j = 0, k = 0, cc = 0;
		char c, temp[] = new char[10000];
		boolean st = false, pn = false;
		String res[] = new String[1000];
		
		while ( i < line.length() && ( ( c = line.charAt( i ) ) != ':') ) {
			
			if ( Character.isLetterOrDigit( c ) || c == '.' ) {
				st = true;
				pn = false;
				temp[j++] = c;
			} else if ( c == ' ' && st ) {
				temp[j++] = c;
				pn = false;
				st = true;
			} else if ( c == ',' ) {
				cc++;
				if ( cc != 2 ) {
					temp[j++] = c;
					st = true;
					pn = false;
				} else {
					pn = true;
					st = false;
				}
			} else {
				st = false;
				pn = false;
			}
			
			if ( pn ) {
				/* System.out.println( new String( temp, 0, j )); */
				res[k++] = new String( temp, 0, j );
				j = cc = 0;
				pn = st = false;
			}
			i++;
		}
		
		if ( st && cc != 0 ) {
			/* System.out.println( new String( temp, 0, j )); */
			res[k++] = new String( temp, 0, j );
		}
		
		return Arrays.copyOf( res, k );
	}
}

class Graph {
	public static final int MAX_VERTICES = 5000;
	
	static class Vertex {
		int y;
		Vertex next;
		public Vertex( int y, Vertex next ) {
			this.y = y;
			this.next = next;
		}
	}
	
	Vertex vertices[];
	
	public Graph() {
		vertices = new Vertex[MAX_VERTICES];
	}
	
	void deleteGraph() {
		for ( int i = 0; i < vertices.length; i++ ) vertices[i] = null;
	}
	
	public void insertEdge( int src, int dst ) {
		insertEdge( src, dst, true );
	}
	
	private void insertEdge( int src, int dst, boolean b ) {
		vertices[src] = new Vertex( dst, vertices[src] );
		if ( b ) { insertEdge( dst, src, false ); }
	}
	
	int[] bfs( int src ) {
		
		int i, x, d;
		boolean discovered[] = new boolean[MAX_VERTICES];
		int parent[] = new int[MAX_VERTICES];
		int distance[] = new int[MAX_VERTICES];
		Queue q = new LinkedList();
		Vertex temp;
		
		for ( i = 0; i < MAX_VERTICES; i++ ) {
			parent[i] = distance[i] = -1;
		}
		
		q.add( src );
		discovered[src] = true;
		distance[src] = 0;
		
		while ( !q.isEmpty() ) {
			x = q.poll();
			temp = vertices[x];
			d = distance[x];
			
			while ( temp != null ) {
				if ( !discovered[temp.y] ) {
					q.add( temp.y );
					discovered[temp.y]= true; 
					parent[temp.y] = x;
					distance[temp.y]= d + 1; 
				}
				temp = temp.next;
			}
		}
		return distance;
	}
}

