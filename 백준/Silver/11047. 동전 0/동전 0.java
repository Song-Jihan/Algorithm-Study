import java.util.*;
import java.io.*;

public class Main {
  static int[] arr=new int[10];
  static int ans;
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n=Integer.parseInt(st.nextToken());
      int k=Integer.parseInt(st.nextToken());
      for(int i=0;i<n;i++){
        arr[i]=Integer.parseInt(br.readLine());
      }
      for(int i=n-1;i>=0;i--){
        if(k/arr[i]>0){
          ans+=(k/arr[i]);
          k%=arr[i];
        }
      }
      System.out.print(ans);
  }
}