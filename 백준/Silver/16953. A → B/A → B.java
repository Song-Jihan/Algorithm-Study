import java.util.*;
import java.io.*;

public class Main {
  static long ans,min=Integer.MAX_VALUE;
  
  static void dfs(long A,long B){
    ans++;
    //System.out.println(A+" "+ans);
    if(A==B){
      if(min>A) min=ans;
      ans--;
      return;
    }
    
    if(2*A<=B && 2*A>0){
      dfs(2*A,B);
    }
    if(10*A+1<=B && 10*A+1>0){
        dfs(10*A+1,B);
    }
    ans--;
  }
    
  public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st=new StringTokenizer(br.readLine());
      long A=Long.parseLong(st.nextToken());
      long B=Long.parseLong(st.nextToken());
      if(A==B){
        System.out.println(0);
        return;
      }
      dfs(A,B);
      if(min==Integer.MAX_VALUE) System.out.println("-1");
      else System.out.println(min);
  }
}