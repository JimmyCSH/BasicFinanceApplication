#include "user.h"
#include <string>
#include <iostream>

User::User()
{
	std::cout << "Your user account has been created." << std::endl;

	for (int x = 0; x < 3; x++)
	{
		m_pAccounts[x] = 0.0f;
	}
}

User::~User()
{
	std::cout << "Your user account has been removed." << std::endl;
}

void User::Deposit(float amount, int accountNumber)
{
	m_pAccounts[accountNumber - 1] += amount;
}

void User::Withdraw(float amount, int accountNumber)
{
	m_pAccounts[accountNumber - 1] -= amount;
}

void User::InitializeAccounts()
{
	for (int accountCount = 0; accountCount < 5; accountCount++)
	{
		m_pAccounts[accountCount] = 0.0f;
	}
}

float User::GetAccountValue(int accountNumber)
{
	return m_pAccounts[accountNumber - 1];
}

void User::InitializeAccountNames()
{
	m_pAccountNames[0] = "Account 1";
	m_pAccountNames[1] = "Account 2";
	m_pAccountNames[2] = "Account 3";
}

std::string User::GetAccountName(int accountNumber)
{
	return m_pAccountNames[accountNumber - 1];
}

void User::SetAccountName(std::string accountName, int accountNumber)
{
	m_pAccountNames[accountNumber - 1] = accountName;
}

void User::SetUsername(std::string username)
{
	m_pUsername = username;
}

std::string User::GetUsername() const
{
	return m_pUsername;
}

void User::SetPassword(std::string password)
{
	m_pPassword = password;
}

std::string User::Getpassword() const
{
	return m_pPassword;
}