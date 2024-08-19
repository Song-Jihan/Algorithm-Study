import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      String doc=br.readLine();
      String find=br.readLine();
      
      int dl=doc.length();
      int fl=find.length();
      
      doc=doc.replace(find,"");
      System.out.print((dl-doc.length())/fl);
  }
}