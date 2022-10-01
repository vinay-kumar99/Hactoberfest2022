package basics;

import java.util.Objects;
import java.util.Scanner;
public class Calculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input First Number : ");
        int x = sc.nextInt();
        System.out.print("Input Second Number : ");
        int y = sc.nextInt();
        System.out.print(" Enter the Operator : ");
        String res = sc.next();

//        ___________________If_Else______________________
//
//        if (Objects.equals(res, "+")){
//            System.out.println(x+y);
//        }
//        else if (Objects.equals(res, "-")){
//            System.out.println(x-y);
//        }
//        else if (Objects.equals(res, "*")){
//            System.out.println(x*y);
//        }
//        else if (Objects.equals(res,"/")){
//            System.out.println(x/y);
//        }
//        else if (Objects.equals(res,"%")){
//            System.out.println(x%y);
//        }
//        else {
//            System.out.println("--------ERROR--------RORRE------------------------RORRE--------ERROR--------");
//        }



//        ___________________Normal_Switch_Case_________________
//
//        switch (res) {
//            case ("+"):
//                System.out.println(x + y);
//                break;
//            case ("-"):
//                System.out.println(x - y);
//                break;
//            case ("*"):
//                System.out.println(x * y);
//                break;
//            case ("/"):
//                System.out.println(x / y);
//                break;
//            case ("%"):
//                System.out.println(x % y);
//                break;
//        }


//        ____________________Enhanced_Switch_Case_______________________
        switch (res) {
            case "+" -> System.out.println(x + y);
            case "-" -> System.out.println(x - y);
            case "*" -> System.out.println(x * y);
            case "/" -> System.out.println(x / y);
            case "%" -> System.out.println(x % y);
        }
    }
}
