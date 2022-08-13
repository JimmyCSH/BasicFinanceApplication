#include "user.h"
#include <iostream>
#include <string>

void CheckType(char& type);
void SetupUser(User* aUser, std::string username, std::string password);
void DisplayAccounts(User* aUser);

int main()
{
	// User input.
	char userType = '\0';
	char quit = '\0';

	User* aUser = new User(); // User declared.

	std::cout << "+-----------------------------+" << std::endl;
	std::cout << "|  Basic Finance Application  |" << std::endl;
	std::cout << "+-----------------------------+" << std::endl;

	std::cout << std::endl;

	CheckType(userType);

	std::string username;
	std::string password;

	std::cout << std::endl;

	std::cout << "Please enter your username: ";
	std::cin >> username;
	std::cout << std::endl;

	std::cout << "Please enter your password: ";
	std::cin >> password;
	std::cout << std::endl;

	// Setup the users account.
	SetupUser(aUser, username, password);
	aUser->InitializeAccountNames();

	DisplayAccounts(aUser);

	// Main program loop.
	while (quit != 'q')
	{
		// Prompt user with selection.
		std::cout << "Would you like to deposit (d), withdraw (w) or check you balance (b)?" << std::endl;
		std::cin >> quit;

		// Initiliaze account number and amount.
		int accountNumber = -1;
		float amount = 0.0f;

		// Deposit logic.
		if (quit == 'd')
		{
			while (!(accountNumber > 0 && accountNumber < 4))
			{
				std::cout << "How much would you like to deposit? ";
				std::cin >> amount;

				std::cout << std::endl;

				std::cout << "Which account would you like to make the deposit in? (1 - 3) ";
				std::cin >> accountNumber;
			}

			aUser->Deposit(amount, accountNumber);
			std::cout << "$" << amount << " has been deposited in " <<
				aUser->GetAccountName(accountNumber) << "." << std::endl;
		}
		// Withdraw logic.
		else if (quit == 'w')
		{
			while (!(accountNumber > 0 && accountNumber < 4))
			{
				std::cout << "How much would you like to withdraw? ";
				std::cin >> amount;

				std::cout << std::endl;

				std::cout << "Which account would you like to make the deposit in? (1 - 3) ";
				std::cin >> accountNumber;
			}

			aUser->Withdraw(amount, accountNumber);
			std::cout << "$" << amount << " has been withdrawen from " <<
				aUser->GetAccountName(accountNumber) << "." << std::endl;
		}
		// Balance logic.
		else if (quit == 'b')
		{
			DisplayAccounts(aUser);
		}
	}

	delete aUser;

	return 0;
}

void CheckType(char& type)
{
	std::cout << "Are you a user or administrator (u/a)? ";

	std::cin >> type;

	// Check user input to ensure they are a user type.
	while (type != 'u')
	{
		std::cout << "Please ensure you enter a valid user type." << std::endl;
		std::cin >> type;
	}
}

void SetupUser(User* aUser, std::string username, std::string password)
{
	aUser->SetUsername(username);
	aUser->SetPassword(password);
}

void DisplayAccounts(User* aUser)
{
	// Print account summaries to users.
	std::cout << "Your Accounts: " << std::endl;

	std::cout << "+-----------------------------------+" << std::endl;
	std::cout << "| " << aUser->GetAccountName(1) << " |  " << "\$" << aUser->GetAccountValue(1) << std::endl;
	std::cout << "+-----------------------------------+" << std::endl;
	std::cout << "| " << aUser->GetAccountName(2) << " |  " << "\$" << aUser->GetAccountValue(2) << std::endl;
	std::cout << "+-----------------------------------+" << std::endl;
	std::cout << "| " << aUser->GetAccountName(3) << " |  " << "\$" << aUser->GetAccountValue(3) << std::endl;
	std::cout << "+-----------------------------------+" << std::endl;

	std::cout << std::endl;
}
