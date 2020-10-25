package com.company;

import java.util.Random;
import java.util.Scanner;

class GuessingGame{
    private static final Random random = new Random();
    private static final Scanner scanner = new Scanner(System.in);
    private int noOfGuesses = 0;
    private int randomNo;
    public int userInput; // Can be taken byte but if user entered a non-byte value i.e. more than 127 it will throw an error

    public GuessingGame(){
        randomNo = (random.nextInt(100) + 1); // As the line generates a random no between 0~99 but we want it to be 1~100 so 1 is added
    }

    public static boolean wantToPlay(){
        System.out.println("Do you want to play the Guessing Game again (Y/N)?: ");
        char play = scanner.next().charAt(0);
        return play == 'y' || play == 'Y';
    }

    public void takeUserInput(){
        System.out.println("Please guess a number between 1~100: ");
        userInput = scanner.nextInt();
        if(userInput>100 || userInput<1){
            System.out.println("[-] Invalid Number entered!!!");
            takeUserInput(); // will cause recursion if user entered an invalid value
        }
    }

    public boolean isCorrectNumber(){
        noOfGuesses++; // add 1 to noOfGuesses
        if (userInput<randomNo){
            System.out.println("* Please guess a larger no!");
            return false;
        }else if (userInput>randomNo){
            System.out.println("* Please guess a smaller no!");
            return false;
        }else {
            System.out.println("** Genius you guessed it right");
            return true;
        }
    }

    public int getNoOfGuesses() {
        return noOfGuesses;
    }

    public int getComputerChoice(){
        return randomNo;
    }

    public void playGame(){
        playGame(false, false);
    } // Overloaded for default parameters

    public void playGame(boolean displayComputerChoice, boolean displayComputerChoiceInBeginning){
        if(displayComputerChoice && displayComputerChoiceInBeginning){
            System.out.println("The Number chosen by the computer is: " + getComputerChoice()); // for cheating the game
        }
        boolean win = false;
        while (!win){
            takeUserInput();
            win = isCorrectNumber();
        }
        System.out.println("You guessed it in " + getNoOfGuesses() + " Guesses");
        if(displayComputerChoice && (!displayComputerChoiceInBeginning)){
            System.out.println("The Number chosen by the computer was: " + getComputerChoice());
        }
    }

    public void regenerateComputerChoice(){
        randomNo = (random.nextInt(100) + 1); // Same as in the constructor
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("*** Hello & Welcome to Guessing Game! *****");
        GuessingGame game = new GuessingGame();
        boolean play = true;
        // for playing multiple times the following loop is used
        while (play) {
            game.playGame();
            play = GuessingGame.wantToPlay();
            game.regenerateComputerChoice(); // To choose another random number
        }
        System.out.println("******** thank you for playing **********");
    }
}
