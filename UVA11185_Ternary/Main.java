public class Main {
  private static String toBaseN(int x, int n) {
    if (x == 0)
      return "0";
    StringBuilder sb = new StringBuilder("");
    while (x > 0) {
      sb.append(x % n);
      x /= n;
    }
    return sb.reverse().toString();
  }
 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int x;
    String line;
    while (sc.hasNextLine()) {
      line = sc.nextLine();
      x = Integer.parseInt(line);
      if (x < 0)
        break;
      System.out.println(toBaseN(x, 3));
    }
    sc.close();
  }
}
