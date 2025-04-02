/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:04:22 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/02 16:53:49 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <sstream>
#include <ctime>
#include <iomanip>
#include <iostream>

// TIL you can just do that.
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ************************************************************************** //
// Constructor

Account::Account( int initial_deposit ) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
};

Account::~Account( void ) {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
};

// ************************************************************************** //
// Private Methods


std::string getFormattedTime() {
	std::ostringstream oss;
	std::time_t t = std::time(NULL);
	std::tm tm = *std::localtime(&t);

	// Format manuel de la date et de l'heure
	oss << "[" << (tm.tm_year + 1900)  // Année
		<< std::setw(2) << std::setfill('0') << (tm.tm_mon + 1)  // Mois
		<< std::setw(2) << std::setfill('0') << tm.tm_mday       // Jour
		<< "_"
		<< std::setw(2) << std::setfill('0') << tm.tm_hour       // Heure
		<< std::setw(2) << std::setfill('0') << tm.tm_min        // Minute
		<< std::setw(2) << std::setfill('0') << tm.tm_sec        // Seconde
		<< "]";
	return oss.str();
}

void	Account::_displayTimestamp( void )
{
	std::ostringstream oss;
	oss << getFormattedTime() << " ";
	std::cout << oss.str();
}

// ************************************************************************** //
// Public Methods

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount 
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (1);
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << _amount 
	<< ";nb_withdrawals:" << _nbWithdrawals
	<< std::endl;
	return (0);
}