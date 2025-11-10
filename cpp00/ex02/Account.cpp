#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ){
    return _nbAccounts;
}

int Account::getTotalAmount( void ){
    return _totalAmount;
}

int Account::getNbDeposits( void ){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout  << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" << "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << std::endl; 
}

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
    _nbAccounts += 1;
    this->_accountIndex  = getNbAccounts() - 1;

    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout  << "index:" << this->_accountIndex << ";" << "amount:" << checkAmount() << ";" << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
  std::cout  << "index:" << this->_accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" 
              << "p_amount:" << checkAmount() << ";" 
              << "deposit:" << deposit << ";";

    this->_amount += deposit;      
    _totalAmount += deposit;
    std::cout << "amount:" << checkAmount() << ";";
    
    this->_nbDeposits += 1;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;  

    _totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" 
              << "p_amount:" << checkAmount() << ";";
    
    if(withdrawal > checkAmount())
        return (std::cout << "withdrawal:refused" << std::endl, false);
    
    std::cout << "withdrawal:" << withdrawal << ";";

    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "amount:" << checkAmount() << ";";
    
    this->_nbWithdrawals += 1;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

    _totalNbWithdrawals += 1;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return this->_amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
    
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm*	ltm = std::localtime(&now);

	std::cout << "["
	<< 1900 + ltm->tm_year
	<< (ltm->tm_mon + 1 < 10 ? "0" : "") << ltm->tm_mon + 1
	<< (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
	<< "_"
	<< (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
	<< (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
	<< (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
	<< "] ";
}