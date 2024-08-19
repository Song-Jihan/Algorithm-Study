import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      int n=Integer.parseInt(br.readLine());
      int m=Integer.parseInt(br.readLine());
      StringTokenizer st=new StringTokenizer(br.readLine());
      int[] arr=new int[n];
      boolean[] having=new boolean[100001];
      int maxidx=-1;
      for(int i=0;i<n;i++){
        arr[i]=Integer.parseInt(st.nextToken());
        if(arr[i]>maxidx) maxidx=arr[i];
        having[arr[i]]=true;
      }
      
      int ans=0;
      for(int i=0;i<n;i++){
        if(!having[arr[i]]) continue;
        int need=m-arr[i];
        if(need>maxidx || need<=0 || need==arr[i]) continue;
        if(!having[need]) continue;
        having[need]=false;
        having[arr[i]]=false;
        ans++;
      }
      System.out.print(ans);
  }
}