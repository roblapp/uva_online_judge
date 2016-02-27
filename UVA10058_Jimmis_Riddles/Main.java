import java.util.Scanner;

/*
 Accepted: 0.079s
 Category: string processing, regular expressions
 Algorithm: Java RegEx API
 Info: I also supplied a C++ solution that was faster :)
 */

class Main {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    final String NOUNS = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
    final String VERBS = "(hate|love|know|like)s*";
    final String ARTICLE = "(a|the)";
    final String ACTOR = "(" + NOUNS + "|" + ARTICLE + " " + NOUNS + ")";
    final String ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
    final String ACTION = ACTIVE_LIST + " " + VERBS + " " + ACTIVE_LIST;
    final String STATEMENT = ACTION + "( , " + ACTION + ")*";

    while (sc.hasNextLine()) {
      System.out.println(sc.nextLine().replaceAll(" +", " ").trim().matches(STATEMENT) ? "YES I WILL" : "NO I WON'T");
    }
    sc.close();
  }
}
