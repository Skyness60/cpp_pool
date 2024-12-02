// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int main( void ) {

	// Typedefs pour simplifier les noms complexes
	// `accounts_t` : représente une liste de comptes bancaires (vector d'Account::t)
	typedef std::vector<Account::t> accounts_t;

	// `ints_t` : représente une liste d'entiers (vector<int>)
	typedef std::vector<int> ints_t;

	// `acc_int_t` : représente un couple d'itérateurs pour parcourir les comptes et les entiers
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	// Tableau des montants initiaux pour chaque compte
	int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };

	// Taille du tableau des montants
	size_t const amounts_size( sizeof(amounts) / sizeof(int) );

	// Création d'un vecteur `accounts` à partir des montants initiaux
	accounts_t accounts( amounts, amounts + amounts_size );

	// Itérateurs pour parcourir le vecteur `accounts`
	accounts_t::iterator acc_begin = accounts.begin();
	accounts_t::iterator acc_end = accounts.end();

	// Tableau des montants à déposer
	int const d[] = { 5, 765, 564, 2, 87, 23, 9, 20 };

	// Taille du tableau des dépôts
	size_t const d_size( sizeof(d) / sizeof(int) );

	// Création d'un vecteur `deposits` à partir des montants de dépôt
	ints_t deposits( d, d + d_size );

	// Itérateurs pour parcourir le vecteur `deposits`
	ints_t::iterator dep_begin = deposits.begin();
	ints_t::iterator dep_end = deposits.end();

	// Tableau des montants à retirer
	int const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };

	// Taille du tableau des retraits
	size_t const w_size( sizeof(w) / sizeof(int) );

	// Création d'un vecteur `withdrawals` à partir des montants de retrait
	ints_t withdrawals( w, w + w_size );

	// Itérateurs pour parcourir le vecteur `withdrawals`
	ints_t::iterator wit_begin = withdrawals.begin();
	ints_t::iterator wit_end = withdrawals.end();

	// Affichage des informations globales sur les comptes
	Account::displayAccountsInfos();

	// Affichage du statut de chaque compte (solde initial)
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Boucle pour effectuer les dépôts
	for ( acc_int_t it( acc_begin, dep_begin );  // Couple d'itérateurs (compte, dépôt)
		  it.first != acc_end && it.second != dep_end;  // Tant qu'il y a des comptes et des dépôts
		  ++(it.first), ++(it.second) ) {  // Avance les deux itérateurs

		// Effectue un dépôt pour chaque compte
		(*(it.first)).makeDeposit( *(it.second) );
	}

	// Affichage des informations globales après les dépôts
	Account::displayAccountsInfos();

	// Affichage du statut de chaque compte après les dépôts
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Boucle pour effectuer les retraits
	for ( acc_int_t it( acc_begin, wit_begin );  // Couple d'itérateurs (compte, retrait)
		  it.first != acc_end && it.second != wit_end;  // Tant qu'il y a des comptes et des retraits
		  ++(it.first), ++(it.second) ) {  // Avance les deux itérateurs

		// Effectue un retrait pour chaque compte
		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// Affichage des informations globales après les retraits
	Account::displayAccountsInfos();

	// Affichage du statut de chaque compte après les retraits
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;  // Fin du programme
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
