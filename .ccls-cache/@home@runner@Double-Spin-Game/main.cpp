/*
 * Program Name: DOUBLE SPIN
 * Author:       Emily Huynh
 * Date Created: 05/06/2022
 * Description:  This program will run a DOUBLE SPIN game where the user enters in two colours to see if they win or lose points. 
 */

#include <iostream>
using namespace std;

int main() 
{
  bool spin = true, colourSpin=true, start = true, again=false; //these variables are the conditions for the while loops to keep running 
  int score=1000; //stores the number of points, the number of points starts at 1000 everytime a user starts the game
  char playGame, restart; //Variables for yes or no answers to continue or start playing the game, or to restart the game
  string colour1, colour2; //These variables store the inputted colours

  //Information about the game and instructions
  cout << "Welcome to DOUBLE SPIN! Here you can enter the colours of your spins to see if you win or lose. \nYour total score will be shown after each spin.\nAt the start of each game, you are given 1000 points. Certain colour combinations will earn you points or lose you points. Others will not add or subtract from your score. If the number of points is less than 0, you lose the game. If the score reaches 2000 points, you win the game.\nThis game will only accept the colours blue, black, yellow, red, and green.\n\n";

  while (start)
  {
    //This will ask the user if they would like to continue to start the game or to continue playing the game, their answer will be stored in playGame variable
    cout << "\n\nWould you like to play? (Enter 'y' for yes or 'n' for no): ";
    cin >> playGame;
    if (playGame == 'y')   //If the user enters 'y' for yes, the program will move on to next part
    {
      spin = true;
      start = false;
    }
    else if (playGame == 'n')  // If the user enters 'n' for no, the program will jump to the end, say "Goodbye" and then end the program.
    {
      spin = false;
      start = false;
    }
    else //If the user enters neither 'y' nor 'n', they the answer will be invalid and the question will repeat itself until the user enters a valid answer.
    {
      cout << "Invalid response. Please try again. \n";
      continue; 
    }

    GameReset: //This GameReset is where the program will go to after losing or winning the whole game (to play again)

    while (spin)
    {
      start = true; //start = true for the program to run the while loop again to ask if the user wants to continue playing after the round

      cout << "Enter the colour of the first spin (lowercase letters only): "; //User will enter the colours of the first spin, this will be stored in the colour1 variable
      cin >> colour1;

      //If the user enters anything that is not a valid colour, then they will have to enter a valid colour before moving on
      if (colour1 != "red" and colour1 != "blue" and colour1 != "green" and colour1 != "black" and colour1 != "yellow") 
      {
        cout << "Colour not found. Please try again.\n";
        continue;
      }

      while (colourSpin)
      {
        cout << "Enter the colour of the second spin (lowercase letters only): "; //User enters colour of the second spin, this will be stored in the colour2 variable
        cin >> colour2;
        //If the colour of the second spin is not a valid colour, then they will have to enter a valid colour before moving on
        if (colour2 != "red" and colour2 != "blue" and colour2 != "green" and colour2 != "black" and colour2 != "yellow") 
        {
          cout << "Colour not found. Please try again.\n";
          continue;
        }
        else
        {
          break;
        }
      }

      //If both spins are red or both spins are green, 100 points will be added to the score
      if (colour1 == "red" and colour2 == "red" or colour1 == "green" and colour2 == "green")
      {
        score = score + 100;
        cout << "YOU ARE A WINNER! You won 100 points.";
      }

      //If both spins are yellow, 100 points will be subtracted from the score
      else if (colour1 == "yellow" and colour2 == "yellow")
      {
        score = score - 100;
        cout << "SORRY, you lose 100 points.";
      }

      //If both spins are black, 200 points will be subtracted from the score
      else if (colour1 == "black" and colour2 == "black")
      {
        score = score - 200;
        cout << "SORRY, you LOSE 200 points.";
      }

      else //If both spins are neither red, green, yellow, or black, no points will be added to or subtracted from the score
      {
        cout << "You neither WON or LOST.";
      }

      if (score >=0 and score < 2000)
      {
      cout << "\nYou currently have a total of " << score << " points.";
      }

      //If the score is less than 0, the user loses the game and the game will end
      else if (score <0)
      {
        cout << "\nYour score is less than 0 points.\n\nGAME OVER. You LOST the game.\n\n";
; //You lose ASCII art

        start = false;
        //goto RestartGame will have the program jump to the option of restarting the game 
        again = true;
      }

      //If score is 2000 points or higher, the user wins the game and the game will end
      else if (score >=2000)
      {
        cout << "\nYour score has reached 2000 points.\n\nCONGRATULATIONS, you WON the game!\n\n";
        start = false;
        again = true;
      }

      while (again)
      {
        cout << "\n\nWould you like to play again? ";  //The user is asked if they would like to play the game again (restart) after the game ends. 
        cin >> restart;
        //If the user enter 'y', the game will restart and the program will go back and start from the top (where GameReset is located)
        if (restart == 'y')
        {
          cout << "RESTARTING GAME...\n\n\n\n";
          again = false;
          spin = true;
          score = 1000;
          goto GameReset;
        }
        //If the user enters 'n' for no, the program will end.
        else if (restart == 'n')
        {
          cout << "\nThank you for playing.\n";
          break;
        }
        else //If the user enters an invalid response, the question will be repeated until they enter a valid response
        {
          cout << "Invalid response. Please try again.";
          continue;
        }
      }
      spin = false;
    }
  }
  cout << "\nGoodbye."; //The program says goodbye and ends. 
  return 0;
}