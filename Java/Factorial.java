import java.util.Scanner;

/**
 * Factorial
 */
public class Factorial {

    static int factorial(int a) {
        if (a==0 || a==1) {
            return 1;
        }
        else {
            return factorial(a-1)*a;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a number: ");
        System.out.println("Factorial = "+factorial(in.nextInt())); 
        in.close();
    }
}
