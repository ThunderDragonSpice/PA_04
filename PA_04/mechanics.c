/*
	Author: Nathan Brown
	Created: 10/01/2019
	Modified:
	Description: Terminal version of the game Blackjack Dice for 2-5 players. Function definitions.
*/

#include "mechanics.h"

/*
	Function: display_menu()
	Date Created: 10/01/2019
	Last Modified:
	Description: Displays game menu. Redisplays until receiving valid input. Calls other functions based on input. May remove switch and place in main. Haven't decided yet.
	Input parameters: None
	Returns: None
	Preconditions: None
	Postconditions: Secondary menu displayed, playing game, or exited program.
*/
void display_menu(int funds[])
{
	int option = 0;
	int money = 0;
	//Display menu until receiving valid input
begin_menu:
	option = 0;
	while (option < 1 || option > 4)
	{
		printf("\n~~~~~~ MAIN MENU ~~~~~~\n\n");
		printf("1. Display game rules.\n");
		printf("2. Edit player funds.\n");
		printf("3. Begin game.\n");
		printf("4. Exit.\n");
		printf("Select an option by typing the corresponding number.\n");
		scanf("%d", &option);

		//Run process based on input
		switch (option)
		{
		case RULES:
			game_rules();
			display_menu(funds);
			break;
		case FUNDS:
			money = funds_def();
			funds_reset(funds, money);
			goto begin_menu;//display_menu(funds);
			break;
			//Leave switch and while loop to begin playing game
		case PLAY:
			break;
			//Exit program
		case EXIT:
			exit(0);
			break;
		default:
			break;
		}

	}
}
/*
	Function: game_rules()
	Date Created: 10/02/2019
	Last Modified:
	Description: Displays the rules of the game.
	Input parameters: None
	Returns: None
	Preconditions: None
	Postconditions: Rules displayed, main menu brought up.
*/
void game_rules(void)
{
	printf("\nBlackjack dice is played with 2-5 people. It is primarily a game of chance but involves some strategy.\nPlayers take turns in order. On a player's turn, he/she rolls one six-sided die. They continue rolling until the sum of the rolls is greater than 21 or they choose to stop rolling. A player has the option to stop rolling after the roll sum reaches 16.\nA player wins by having the greatest sum of all players. However, if that value is greater than 21, that player loses. Therefore, it is a competition to see who can arrive the closest to 21 without going over. The game ends when all players have either gone over 21 or chosen to stop rolling.\n\nAt the beginning of their turn and once before each roll, players have the option to place bets. The amount they win is decided at the end of the game.\nIf a player rolls 21, they get 2x their total bet.\nIf a player has the highest roll in the group but did not roll 21 exactly, they get 1.5x their total bet.\nIf two players tie for highest roll, they both get only 1x their total bet.\nThose who lose the game also lose their bets.\n\nIn this version of the game, you have the option to save a record of each player's funds to continue the same game at a different time.\n");
}
/*
	Function: funds_view()
	Date Created: 10/02/2019
	Last Modified:
	Description: Retrieves data for player money from file, outputs to screen
	Input parameters: None
	Returns: None
	Preconditions: File containing player data available but not open
	Postconditions: Info output to screen
*/
void funds_view(void)
{
	int player1 = 0, player2 = 0, player3 = 0, player4 = 0, player5 = 0;
	FILE* iofile = NULL;
	iofile = fopen("funds.dat", "r");
	fscanf(iofile, "%d%d%d%d%d", &player1, &player2, &player3, &player4, &player5);
	fclose(iofile);

	printf("\nCurrently, players have the following amounts of money:\n\n");
	printf("Player 1: $%d\n", player1);
	printf("Player 2: $%d\n", player2);
	printf("Player 3: $%d\n", player3);
	printf("Player 4: $%d\n", player4);
	printf("Player 5: $%d\n", player5);
}
/*
	Function: funds_reset()
	Date Created: 10/02/2019
	Last Modified:
	Description: Calls funds_view() and then gives option to reset player funds to default value.
	Input parameters: None
	Returns: None
	Preconditions: Data file with player funds available but not open
	Postconditions: Either funds reset or message displayed that they were not changed
*/
void funds_reset(int funds[], int starting_funds)
{
	funds[0] = starting_funds;
	funds[1] = starting_funds;
	funds[2] = starting_funds;
	funds[3] = starting_funds;
	funds[4] = starting_funds;
}
/*
	Function: funds_def()
	Date Created: 10/01/2019
	Last Modified: 10/02/2019 Nerfed due to conflicts
	Description: Meant to allow player to change default value for player funds
	Input parameters: None
	Returns: None
	Preconditions: Default fund value set
	Postconditions: Default fund value either changed or player changed their mind
*/
int funds_def(void)
{
	int new_def = 0;

	while (new_def < 1)
	{
		printf("How much money would you like players to start with?\n$");
		scanf("%d", &new_def);
		if (new_def < 1)
			printf("Invalid input.\n");
	}
	return new_def;
}
/*
	Function: funds_store()
	Date Created: 10/01/2019
	Last Modified: 10/02/2019 Began building
	Description: Allows user to store game data at the end of a round to continue with the same info at a later date.
	Input parameters: Player funds as integers
	Returns: None
	Preconditions: Fund values available for use
	Postconditions: Fund values stored to player data file
*/
void funds_store(void)
{
	//Save values of current funds to file
	return;
}
/*
	Function: bet_initial()
	Date Created: 10/01/2019
	Last Modified:
	Description: Accepts player's first bet. Mandatory.
				 Calls bet_check to verify player has enough money.
	Input parameters: Player (int)
	Returns: Bet amount (int)
	Preconditions: Turn begun, player specified
	Postconditions: Bet logged
*/
int bet_initial(void)
{
	int bet = 0;
	while (bet < 1)
	{
		printf("How much would you like to bet?\n$");
		scanf("%d", &bet);
		if (bet < 1)
			printf("Invalid entry.\n");
	}
	return bet;
}
/*
	Function: bet_sub()
	Date Created: 10/01/2019
	Last Modified: 10/02/2019 Filled in
	Description: Takes subsequent (after first roll) bets from player. Optional.
	Input parameters: None
	Returns: Bet value (int)
	Preconditions: Player number established and available
	Postconditions: Bet value returned
*/
int bet_sub(void)
{
	int bet = 0;
	printf("How much would you like to bet? You may choose to bet $0.\n$");
	scanf("%d", &bet);
	if (bet < 0)
	{
		printf("Invalid entry.\n");
		while (bet < 0)
		{
			printf("How much would you like to bet? You may choose to bet $0.\n$");
			scanf("%d", &bet);
			if (bet < 0)
				printf("Invalid entry.\n");
		}
	}

	return bet;

}
/*
	Function: bet_check()
	Date Created: 10/01/2019
	Last Modified: 10/02/2019 Fleshed out
	Description: Compares funds to bet to confirm that they have enough money to make a given bet.
	Input parameters: Current bet and funds
	Returns: True/False
	Preconditions: Player number established and available
	Postconditions: T/F returned
*/
bool bet_check(int current_bet, int player_funds)
{
	bool validity = false;
	if (current_bet <= player_funds)
		validity = true;
	else
		validity = false;
	return validity;
}
/*
	Function: roll_die()
	Date Created: 10/01/2019
	Last Modified:
	Description: Generates a random integer 1-6
	Input parameters: None
	Returns: Integer die roll
	Preconditions: srand() called once previously to seed with time(NULL)
	Postconditions: Die roll returned
*/
int roll_die(void)
{
	int roll = rand() % 6 + 1;
	return roll;
}
/*
	Function: old_money()
	Date Created: 10/01/2019
	Last Modified: 10/03/2019
	Description: Checks data file to see if funds have been changed. If so, asks player whether to use those values or reset them to the default value.
	Input parameters: None
	Returns: None
	Preconditions: Data file must exist but not be open.
	Postconditions:	If player chooses, funds reset. Otherwise, no change made.
*/
void old_money(void)
{
	printf("Function currently under construction.\n");
	//char option = '\0';
	//int money_check1 = 0, money_check2 = 0, money_check3 = 0, money_check4 = 0, money_check5 = 0;

	////Check to see if a previous game's money values are stored in data file.
	//FILE* iofile = NULL;
	//iofile = fopen("funds.dat", "r");
	//fscanf(iofile, "%d%d%d%d%d", &money_check1, &money_check2, &money_check3, &money_check4, &money_check5);

	////If any funds differ from default, prompt user to save or overwrite these values.
	//if (money_check1 != DEFAULT_FUNDS || money_check2 != DEFAULT_FUNDS || money_check3 != DEFAULT_FUNDS || money_check4 != DEFAULT_FUNDS || money_check5 != DEFAULT_FUNDS)
	//{
	//	while (option != 'y' && option != 'n')
	//	{
	//		printf("Would you like to retain the funds from the end of your last game? (y/n)\n");
	//		scanf(" %c", &option);
	//		if (option == 'n')
	//			funds_reset();
	//	}
	//}
	//fclose(iofile);
}
/*
	Function: game_intro()
	Date Created: 10/01/2019
	Last Modified: 10/02/2019 Fleshed out
	Description: Begins the game. Checks to see if data file holds any values other than defaults. If so, asks user whether they want to use those values or not. Prompts for number of players.
	Input parameters: None
	Returns: Number of players (int)
	Preconditions: Data file exists for player funds but is not open
	Postconditions: Player funds possibly reset to default. Number of players set for the course of the game.
*/
int game_intro(void)
{
	int player_count = 0;
	//old_money();

	//Prompt for number of players
	while (2 > player_count || 5 < player_count)
	{
		printf("Please enter the number of players (2-5): ");
		scanf("%d", &player_count);
		if (2 > player_count || 5 < player_count)
			printf("Invalid entry.\n");
	}

	return player_count;
}
/*
	Function: max_roll()
	Date Created: 10/02/2019
	Last Modified:
	Description: Determines which roll was the highest
	Input parameters: Sum of rolls as array
	Returns: Highest roll, winner #
	Preconditions: Game over. Roll sums available.
	Postconditions: Max roll returned.
*/
int max_roll(int rolls[])
{
	int max = rolls[0];
	for (int i = 1; i < 5; i++)
	{
		if (rolls[i] > max && rolls[i] <= 21)
			max = rolls[i];
	}
	return max;
}
char roll_check(int rolls[], int i)
{
	char cont = 'y';
	if (21 == rolls[i])
	{
		printf("Congratulations! You have rolled a perfect 21!\n");
		cont = 'n';
	}
	else if (rolls[i] > 21)
	{
		printf("Sorry! You went over 21. You lose!\n");
		cont = 'n';
	}
	else if (rolls[i] >= 16)
	{
		do
		{
			printf("You are at %d and may choose to end your turn. Would you like to continue rolling? (y/n)\n", rolls[i]);
			scanf(" %c", &cont);
			if (cont != 'y' && cont != 'n')
				printf("Invalid entry.\n");
		} while (cont != 'y' && cont != 'n');

	}
	else
		printf("You are at %d.\n", rolls[i]);
	return cont;
}
int multi(int rolls[], double multiplier[], int max)
{
	int winners = 0;
	for (int i = 0; i < 5; i++)
	{
		if (rolls[i] != max)
			multiplier[i] = 0;
		else if (rolls[i] == 21)
		{
			multiplier[i] = 2;
			winners++;
		}
		else if (rolls[i] == max)
		{
			multiplier[i] = 1.5;
			winners++;
		}
	}
	printf("multipliers at end of function: %d, %d, %d, %d, %d\n", multiplier[0], multiplier[1], multiplier[2], multiplier[3], multiplier[4]);
	return winners;
}
void tie_fighter(double multiplier[], int tie[], int bets[], int funds[], int winners, int max)
{
		int j = 0;
		for (int i = 0; i < 5; i++)
		{
			if (multiplier[i] > 0)
			{
				multiplier[i] = 1;
				tie[j] = i + 1;
				j++;
			}
		}

		if (winners == 2)
		{
			printf("We have a 2-way tie! Both Player %d and Player %d rolled %d!\n", tie[0], tie[1], max);
			for (int i = 0; i < winners; i++)
			{
				funds[tie[i]] += bets[tie[i]];
			}
		}
		else if (winners == 3)
		{
			printf("We have a 3-way tie! Player %d, Player %d, and Player %d all rolled %d!\n", tie[0], tie[1], tie[2], max);
			for (int i = 0; i < winners; i++)
			{
				funds[tie[i]] += bets[tie[i]];
			}
		}
		else if (winners == 4)
		{
			printf("We have a 4-way tie!! Player %d, Player %d, Player %d, and Player %d all rolled %d!\n", tie[0], tie[1], tie[2], tie[3], max);
			for (int i = 0; i < winners; i++)
			{
				funds[tie[i]] += bets[tie[i]];
			}
		}
		else if (winners == 5)
		{
			printf("We have a 5-way tie!!!! All players rolled %d!\n", max);
			for (int i = 0; i < winners; i++)
			{
				funds[tie[i]] += bets[tie[i]];
			}

		}
		printf("All players who tied get their bets back but do not win any extra money.\n");
}
void chicken_dinner(int multiplier[], int bets[], int rolls[], int funds[])
{
	int winner = 0, winnings = 0;
	for (int i = 0; i < 5; i++)
	{
		if (multiplier[i] > 0)
		{
			winner = i + 1;
			break;
		}
	}
	//In case somehow this variable gets set to 0, which should never happen
	if (winner == 0)
		exit(7331);
	winnings = bets[winner - 1] * multiplier[winner - 1];
	printf("The congratulations go to Player %d, with a roll of %d!\n", winner, rolls[winner - 1]);
	printf("Since you bet $%d, you win $%d!\n", bets[winner - 1], winnings);
	funds[winner - 1] += winnings;
}
void die_graphic(int single_die)
{
	if (single_die == 6)
	{
		printf("\n ______________\n");
		printf("|              |\n");
		printf("|    0    0    |\n");
		printf("|              |\n");
		printf("|    0    0    |\n");
		printf("|              |\n");
		printf("|    0    0    |\n");
		printf("|______________|\n\n");
		//How the graphic should display
		/*
			 ____________
			|			 |
			|	0	 0	 |
			|	0	 0	 |
			|	0	 0	 |
			|____________|
		*/
	}
	else if (single_die == 5)
	{

		printf("\n ______________\n");
		printf("|              |\n");
		printf("|   0     0    |\n");
		printf("|              |\n");
		printf("|      0       |\n");
		printf("|              |\n");
		printf("|   0     0    |\n");
		printf("|______________|\n\n");

		//How the graphic should display
		/*
			 ____________
			|			 |
			|  0	 0	 |
			|	  0	     |
			|  0	 0	 |
			|____________|
		*/
	}
	else if (single_die == 4)
	{
		printf("\n ______________\n");
		printf("|              |\n");
		printf("|   0     0    |\n");
		printf("|              |\n");
		printf("|              |\n");
		printf("|              |\n");
		printf("|   0     0    |\n");
		printf("|______________|\n\n");
		//How the graphic should display
		/*
			 ____________
			|			 |
			|	0	 0	 |
			|		 	 |
			|	0	 0	 |
			|____________|
		*/
	}
	else if (single_die == 3)
	{
		printf("\n ______________\n");
		printf("|              |\n");
		printf("|         0    |\n");
		printf("|              |\n");
		printf("|      0       |\n");
		printf("|              |\n");
		printf("|   0          |\n");
		printf("|______________|\n\n");
		//How the graphic should display
		/*
			 ____________
			|			 |
			|   	 0	 |
			|	  0	     |
			|  0	 	 |
			|____________|
		*/
	}
	else if (single_die == 2)
	{
		printf("\n ______________\n");
		printf("|              |\n");
		printf("|         0    |\n");
		printf("|              |\n");
		printf("|              |\n");
		printf("|              |\n");
		printf("|   0          |\n");
		printf("|______________|\n\n");
		//How the graphic should display
		/*
			 ____________
			|			 |
			|   	 0	 |
			|	  	     |
			|  0	 	 |
			|____________|
		*/
	}
	else if (single_die == 1)
	{
	printf("\n ______________\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|      0       |\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|______________|\n\n");
	//How the graphic should display
		/*
			 ____________
			|			 |
			|   	 	 |
			|	  0	     |
			|   	 	 |
			|____________|
		*/
	}
}