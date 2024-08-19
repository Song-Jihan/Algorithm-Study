import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      int n=Integer.parseInt(br.readLine());
      int cnt=3;
      int[] dp=new int[11];
      dp[0]=1; dp[1]=1; dp[2]=2;
      
      for(int i=0;i<n;i++){
        int num=Integer.parseInt(br.readLine());
        if(num==1 || num==2) {
          System.out.println(num);
          continue;
        }
        while(cnt!=num+1){
          dp[cnt]=dp[cnt-3]+dp[cnt-2]+dp[cnt-1];
          cnt++;
        }
        System.out.println(dp[num]);
        cnt=3;
      }
  }
}