#ifndef __USER_H__
#define __USER_H__

#include <string>

class User
{
public:
	User();
	~User();

	void Deposit(float amount, int accountNumber);
	void Withdraw(float amount, int accountNumber);

	void InitializeAccounts();
	float GetAccountValue(int accountNumber);

	void InitializeAccountNames();
	std::string GetAccountName(int accountNumber);
	void SetAccountName(std::string accountName, int accountNumber);

	void SetUsername(std::string username);
	std::string GetUsername() const;

	void SetPassword(std::string password);
	std::string Getpassword() const;

protected:
	float m_pAccounts[3];

	std::string m_pAccountNames[3];

private:
	std::string m_pUsername;
	std::string m_pPassword;
};

#endif // _USER_H__