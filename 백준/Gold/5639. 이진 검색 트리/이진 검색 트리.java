import java.io.*;
import java.util.*;

public class Main {
    static class Node{
        int v;
        Node left,right;

        Node(int v){
            this.v=v;
            this.left=null;
            this.right=null;
        }

        void insert(int n){
            if(n<this.v){
                if(this.left==null){
                    this.left=new Node(n);
                }
                else this.left.insert(n);
            }
            else{
                if(this.right==null){
                    this.right=new Node(n);
                }
                else this.right.insert(n);
            }
        }
    }

    static void postorder(Node n){
        if(n==null) return;
        postorder(n.left);
        postorder(n.right);
        System.out.println(n.v);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        Node root=new Node(Integer.parseInt(br.readLine()));
        String input;
        while(true){
            input=br.readLine();
            if(input==null || input.equals("")) break;
            root.insert(Integer.parseInt(input));
        }  
        postorder(root);
    }
}
