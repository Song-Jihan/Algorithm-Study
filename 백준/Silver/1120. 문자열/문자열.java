import java.util.*;

public class Main {
    public static void main(String[] args) {
      Scanner scanner=new Scanner(System.in);
      String A=scanner.next(); 
      String B=scanner.next();
      int min=50;
      int a=A.length();
      int b=B.length();
      for(int i=0;i<=b-a;i++){
        int cnt=0;
        for(int j=0;j<a;j++){
          if(A.charAt(j)!=B.charAt(j+i)){
            cnt++;
          }
        }
        if(min>cnt) min=cnt;
      }
      System.out.print(min);
      scanner.close();
    }
}