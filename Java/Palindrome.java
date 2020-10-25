// Statement : A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward or forward.
// If given String is palindrome output Yes otherwise No.
// Input:hactoberfest // output:No
// Input : madam // output:Yes

import java.io.*;
import java.util.*;

public class Palindrome{

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        int t=A.length();
        
        if(t%2==0)
        { int sum=0;
           for(int x=0; x<=(t/2)-1; x++)
           {
               if(A.charAt(x)==A.charAt(t-(x+1)))
               sum++;
           }
           if(sum==t/2)
           System.out.println("Yes");
           else
           System.out.println("No");
        }
        else
        {
            int add=0;
            for(int y=0; y<(t-1)/2; y++)
            {
                if(A.charAt(y)==A.charAt(t-(y+1)))
                add++;
            }
            if(add==(t-1)/2)
            System.out.println("Yes");
            else
            System.out.println("No");
        }
        
    }
}

