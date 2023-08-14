/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:48:54 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 01:02:54 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << " accounts:" << std::to_string(getNbAccounts()) << ";total:" << std::to_string(getTotalAmount())
			<< ";deposits:" << std::to_string(getNbDeposits()) << ";withdrawals:" << std::to_string(getNbWithdrawals()) << std::endl;
}

Account::Account( int initial_deposit ){
	Account::_accountIndex = _nbAccounts;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << std::to_string(_accountIndex) << ";amount:" << std::to_string(_amount) << ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += Account::_amount;
}

Account::~Account( void ){
	Account::_displayTimestamp();
	std::cout << " index:" << std::to_string(_accountIndex) << ";amount:" << std::to_string(_amount) << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout << " index:" << std::to_string(_accountIndex) << ";p_amount:" << std::to_string(this->checkAmount());
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";deposit:" << std::to_string(deposit) << ";amount:" << std::to_string(this->checkAmount())
			<< ";nb_deposits:" << std::to_string(this->_nbDeposits) << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout << " index:" << std::to_string(_accountIndex) << ";p_amount:" << std::to_string(this->checkAmount());
	if (withdrawal > this->checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << std::to_string(withdrawal) << ";amount:" << std::to_string(this->checkAmount())
			<< ";nb_withdrawals:" << std::to_string(this->_nbWithdrawals) << std::endl;
	return true;
}

int		Account::checkAmount( void ) const{
	return this->_amount;
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << " index:" << std::to_string(_accountIndex) << ";amount:" << std::to_string(this->checkAmount())
			<< ";deposits:" << std::to_string(this->_nbDeposits) << ";withdrawals:" << std::to_string(this->_nbWithdrawals) << std::endl;
}

void	Account::_displayTimestamp( void ){
	char buff[20];
	time_t now = time(NULL);
	strftime(buff, 18, "%Y%m%d_%H%M%S", localtime(&now));
	std::cout << "[" <<buff << "]";
}

