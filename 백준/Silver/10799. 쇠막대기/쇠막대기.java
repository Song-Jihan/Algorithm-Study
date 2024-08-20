import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        Stack<Character> stack=new Stack<>();
        String prthes=br.readLine();
        int sum=0;
        char input;
        for(int i=0;i<prthes.length();i++){
            input=prthes.charAt(i);
            if(input=='('){
                stack.push(input);
            }
            else{
                if(prthes.charAt(i-1)=='('){
                    sum+=(stack.size()-1);
                }
                else{ 
                    sum++;
                }
                stack.pop();
            }
        }
        System.out.print(sum);
    }
}
