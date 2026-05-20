/******************************************************************************

Name: Wesley Charlton
Course: CS 2010
Class Time: 11:30AM

********************************************************************************
Program Assignment 3, Charltonw, Sunday February 23rd, 2025

     Purpose: BGSU Vending Machine Simulator (essentially), w/ recipt generation and etc.

     Input: Item selection (B/L/C/R), (L/R for non-water), payment amount(s).

     Processing: Validating inputs, calculating total cost(s), handling the payments, and calculating/checking for change.

     Output: Selected item, net total/change, and your total amount paid.

     Reflection: This program helps with referencing new library inclucsions that define
     specific quantities of constants, strings, and helps explore cases where there
     would be output errors (local to user), in case something were to go wrong. (I imagined it kind of like a fail-safe.)
     It also implements new fun ways so you don't have to write "if 'B'/if 'b'" statements.
     (toupper really came in clutch here !!) I also feel like this program was a "harder"
     one for me to do, but it was still fun writing the code regardless!)
     Side Note: I think some of my code may be redundant, but idk?


*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int main() {
	// Price constants
	const double WATER_PRICE = 1.45;
	const double LEMONADE_PRICE = 1.55;
	const double COLA_PRICE = 1.75;
	const double ROOTBEER_PRICE = 1.15;

	// Holding space for our doubles/strings/etc.
	char choice, type;
	double payment;
	double extra_payment;
	double total_paid;
	total_paid = 0.0;
	double cost;
	cost = 0.0;
	double change;
	string item_name;
	string type_name;

	// Our pretty display menu (vending machine local)
	cout << fixed << setprecision(2);
	cout << "*****************************" << endl;
	cout << "  *'bgsU-need-a-drink?'*\n";
	cout << "[B] - Bottled-water" << setw(2) << "($" << WATER_PRICE << ")" << endl;
	cout << "[L] - Lemonade" << setw(7) << "($" << LEMONADE_PRICE << ")" << endl;
	cout << "[C] - Cola" << setw(11) << "($" << COLA_PRICE << ")" << endl;
	cout << "[R] - Root-beer" << setw(6) << "($" << ROOTBEER_PRICE << ")" << endl;
	cout << "*****************************" << endl;

	// Get AND VALIDATE the choice that the user picks
	cout << "Enter selection (B/L/C/R): ";
	cin >> choice;
	choice = toupper(choice);

	if (choice != 'B' && choice != 'L' && choice != 'C' && choice != 'R') {
		cout << "Invalid Drink." << endl;
		cout << "Program Terminated!";
		return 0;
	}

	// Getting type for non-water item(s)
	if (choice != 'B') {
		cout << "Enter selection type L - Light or R - Regular: ";
		cin >> type;
		type = toupper(type);

		if (type != 'L' && type != 'R')
		{
			cout << "Invalid Drink Type." << endl;
			cout << "Program Terminated!" << endl;
			return 0;
		}
	}

	// Setting the item name and cost association
	switch(choice) {
	case 'B':
		item_name = "Bottled-water";
		cost = WATER_PRICE;
		break;

	case 'L':
		item_name = "Lemonade";
		cost = LEMONADE_PRICE;
		break;
	case 'C':
		item_name = "Cola";
		cost = COLA_PRICE;
		break;
	case 'R':
		item_name = "Root-beer";
		cost = ROOTBEER_PRICE;
		break;
	}

	// Set type name
	if (choice != 'B') {
		type_name = (type == 'L') ?
		            "Light" : "Regular";
	}

	// Getting initial payment
	cout << "Enter payment ($1-$10): ";
	cin >> payment;

	if (payment < 1.0 || payment > 10.0) {
		cout << "$" << payment << " invalid payment!" << endl;
		cout << "Program Terminated!" << endl;
		return 0;
	}

	// Handling the payment
	if (payment >= cost) {
		total_paid = payment;
		change = payment - cost;
	}
	else {
		cout << "$" << payment << " is not enough, enter added amount: ";
		cin >> extra_payment;
	}

	// I think this payment still gets calculated regardless whatever they enter?

	total_paid = payment + extra_payment;


	// Verifying if the payment is actually enough, then dispense a reciept, if not, return 0.

	// This is the payment verification code!

	if (total_paid < cost) {

		cout << "$" << total_paid << " is still not enough, money refunded, and program terminated!";
		return 0;
	}

	// This is what should happen if the User actually inputs valid payment(s).
	if (total_paid >= cost) {
		double change = total_paid - cost;

		cout << "\n--- Receipt ---\n" << "Here's your " << item_name;

		if (choice != 'B') cout << " (" << type_name << ")";
		cout << "\nTotal paid: $" << total_paid;
		cout << "\nChange due: $" << change << endl;
	}

	return 0;
}