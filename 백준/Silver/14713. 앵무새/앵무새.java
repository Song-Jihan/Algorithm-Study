import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;
      int n=Integer.parseInt(br.readLine());
      Queue<String> q[]=new LinkedList[n];
      for(int i=0;i<n;i++){
        q[i]=new LinkedList<String>();
        st=new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
          q[i].offer(st.nextToken());
        }
      }
      st=new StringTokenizer(br.readLine());
      while(st.hasMoreTokens()){
        String tmp=st.nextToken();
        for(int i=0;i<n;i++){
          if(tmp.equals(q[i].peek())){
            q[i].poll();
            break;
          }
          else{
            if(i==n-1){
              System.out.print("Impossible");
              return;
            }
          }
        }
      }
      for(int i=0;i<n;i++){
        if(!q[i].isEmpty()){
          System.out.print("Impossible");
          return;
        }
      }
      System.out.print("Possible");
  }
}