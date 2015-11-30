import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int n = sc.nextInt();
    for (int i = 0; i < n; i++) {
      int ns = sc.nextInt();
      double a[] = new double[ns];
      double avg = 0.0f;
      int aa = 0;
      for (int j = 0; j < ns; j++) {
        a[j] = sc.nextDouble();
        avg += a[j];
      }
      avg /= ns;
      for (int j = 0; j < ns; j++) {
        if (a[j] > avg) {
          aa++;
        }
      }
      System.out.printf("%.3f%%\n", (100.0 * (1.0 * aa)/ns));
    }
    sc.close();
  }
}
