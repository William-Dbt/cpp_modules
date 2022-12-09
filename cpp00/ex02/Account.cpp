#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {
	_displayTimestamp();
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	std::cout << "index:" << _accountIndex << ';';
	_amount = 0;
	std::cout << "amount:" << _amount << ';';
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "created" << std::endl;
}

Account::Account(int initial_deposit) {
	_displayTimestamp();
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	std::cout << "index:" << _accountIndex << ';';
	if (initial_deposit < 0)
		initial_deposit = 0;
	_amount = initial_deposit;
	std::cout << "amount:" << _amount << ';';
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "deposit:";
	if (deposit < 0) {
		std::cout << "refused" << std::endl;
		return ;
	}
	std::cout << deposit << ';';
	_amount += deposit;
	std::cout << "amount:" << _amount << ';';
	_totalAmount += deposit;
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "withdrawal:";
	if (withdrawal < 0 or _amount - withdrawal < 0) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ';';
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ';';
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return true;
}

int	Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t	actualTime = time(0);
	tm		*localTime = localtime(&actualTime);

	std::cout << '[';
	std::cout << 1900 + localTime->tm_year;
	if (1 + localTime->tm_mon < 10)
		std::cout << '0';
	std::cout << 1 + localTime->tm_mon;
	if (localTime->tm_mday < 10)
		std::cout << '0';
	std::cout << localTime->tm_mday;
	std::cout << '_';
	if (localTime->tm_hour < 10)
		std::cout << '0';
	std::cout << localTime->tm_hour;
	if (localTime->tm_min < 10)
		std::cout << '0';
	std::cout << localTime->tm_min;
	if (localTime->tm_sec < 10)
		std::cout << '0';
	std::cout << localTime->tm_sec;
	std::cout << "] ";
}

// int main() {
//    // current date/time based on current system
//    time_t now = time(0);

//    cout << "Number of sec since January 1,1970 is:: " << now << endl;

//    tm *ltm = localtime(&now);

//    // print various components of tm structure.
//    cout << "Year:" << 1900 + ltm->tm_year<<endl;
//    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
//    cout << "Day: "<< ltm->tm_mday << endl;
//    cout << "Time: "<< 5+ltm->tm_hour << ":";
//    cout << 30+ltm->tm_min << ":";
//    cout << ltm->tm_sec << endl;
// }