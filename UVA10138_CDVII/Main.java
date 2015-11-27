import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
 
/*
Accepted: 0.379s
Description: data structures - maps, sorting 
 */
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int ncases, status, pos;
    int costs[] = new int[24];
    String line, car, time, statusStr;
    Map<String, Integer> costMap = new TreeMap<String, Integer>();
    Map<String, List<Data>> times = new HashMap<String, List<Data>>();
 
    ncases = sc.nextInt();
    sc.nextLine();
    sc.nextLine(); /* Drain empty line and newline */
    for (int i = 1; i <= ncases; i++) {
      costMap.clear();
      times.clear();
      for (int j = 0; j < costs.length; j++) {
        costs[j] = sc.nextInt();
      }
      sc.nextLine(); /* Drain newline */
      String data[];
      while (sc.hasNext() && (line = sc.nextLine()) != null && !line.isEmpty()) {
        data = line.trim().replaceAll(" +", " ").split(" ");
        car = data[0];
        time = data[1];
        statusStr = data[2];
        pos = Integer.parseInt(data[3]);
        if (!times.containsKey(car))
          times.put(car, new ArrayList<Data>());
        if (!costMap.containsKey(car))
          costMap.put(car, 200);
        status = statusStr.equalsIgnoreCase("enter") ? 0 : 1;
        times.get(car).add(new Data(car, time, status, pos));
      }
      for (Map.Entry<String, List<Data>> entry : times.entrySet()) {
        List<Data> tempList = entry.getValue();
        Collections.sort(tempList);
        int len = tempList.size();
        if (len > 1) {
          int j = 0, rate;
          while (j < len - 1) {
            if (tempList.get(j).status == 0 && tempList.get(j + 1).status == 1) {
              rate = costs[tempList.get(j).hour] * Math.abs(tempList.get(j).pos - tempList.get(j + 1).pos) + 100; /* One dollar per trip */
              costMap.put(tempList.get(j).car, costMap.get(tempList.get(j).car) + rate);
              j += 2;
            } else
              j++;
          }
        }
      }
      for (Map.Entry<String, Integer> entry : costMap.entrySet())
        if (entry.getValue() > 200)
          System.out.printf("%s $%d.%02d\n", entry.getKey(), entry.getValue() / 100, entry.getValue() % 100);
      if (i < ncases)
        System.out.println();
    }
    sc.close();
  }
}
 
class Data implements Comparable<Data>, Comparator<Data> {
  public int month, day, hour, minute, status, pos;
  public String car;
 
  public Data(String car, String time, int status, int pos) {
    this.car = car;
    this.status = status;
    this.pos = pos;
    String data[] = time.split(":");
    this.month = Integer.parseInt(data[0]);
    this.day = Integer.parseInt(data[1]);
    this.hour = Integer.parseInt(data[2]);
    this.minute = Integer.parseInt(data[3]);
  }
 
  @Override
  public int compareTo(Data o) {
    if (month < o.month)
      return -1;
    else if (month > o.month)
      return 1;
    else if (day < o.day)
      return -1;
    else if (day > o.day)
      return 1;
    else if (hour < o.hour)
      return -1;
    else if (hour > o.hour)
      return 1;
    else if (minute < o.minute)
      return -1;
    else if (minute > o.minute)
      return 1;
    return 0;
  }
 
  @Override
  public int compare(Data o1, Data o2) {
    return o1.compareTo(o2);
  }
}
