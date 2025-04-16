#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
          << ";amount:" << _amount
          << ";created" << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
          << ";amount:" << _amount
          << ";closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	int hour = ltm->tm_hour;
	int min = ltm->tm_min;
	int sec = ltm->tm_sec;

	std::cout << "[" << year;

	if (month < 10)
		std::cout << "0";
	std::cout << month;
	
	if (day < 10)
		std::cout << "0";
	std::cout << day;
	
	std::cout << "_";
	
	if (hour < 10)
		std::cout << "0";
	std::cout << hour;
	
	if (min < 10)
		std::cout << "0";
	std::cout << min;
	
	if (sec < 10)
		std::cout << "0";
	std::cout << sec;
	
	std::cout << "] ";
}

// Functions

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount+= deposit;
}
// bool	Account::makeWithdrawal(int withdrawal)
// {

// }
// int		Account::checkAmount(void) const
// {

// }

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}


// Getters 
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
