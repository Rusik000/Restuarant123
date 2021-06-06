#pragma once

#include <Windows.h>
#include"ClientController.h"
#include"AllNotification.h"


double price = 0;

enum ClientControl {
	ShawAllMeals = 1, Detail, Search, Buy, Back
};

class Order {
	Kitchen kitch;
	Stock stock;
	vector<Notification> order;

public:
	Order(Kitchen kitch, Stock stock) {
		setKitch(kitch);
		setStock(stock);
	}

	void setKitch(Kitchen kitch) {
		this->kitch = kitch;
	}

	void setStock(Stock stock) {
		this->stock = stock;
	}

	Kitchen getKitch()const {
		return kitch;
	}

	Stock getStock()const {
		return stock;
	}

	void notificationAddIngredient() {
		order.push_back(NotificationofIngredient("Customer add new ingredient"));
	}

	bool checkAmount(int id, int amount) {
		Meal item = kitch.getMealById(id);

		if (id > kitch.getMeal().size()) {
			throw DatabaseException("There is not meal here", __FILE__, __LINE__, __DATE__, __TIME__);
		}
		else {
			if (amount > item.getAmount()) {
				return false;
			}
			return true;
		}
	}

	void buyProduct(int id, int amount) {
		Meal item = kitch.getMealById(id);
		price = price + item.getPrice() * amount;
		item.setAmount(item.getAmount() - amount);
	}

	void addMoreIngredient(int id) {
		Ingredient item = stock.getIngredientById(id);
		if (item.getIngredient_Id() == NULL || item.getAmount() == 0) {
			throw InvalidArgumentException("We can't add this ingredient", __FILE__, __LINE__, __DATE__, __TIME__);
		}
		else {
			price = price + item.getingPrice();
			item.setAmount(item.getAmount() - 1);
			notificationAddIngredient();
		}
	}

	void Menu() {
		while (true) {
		label:
			system("cls");
			system("color 4");
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "      1.Show all Meals   " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "      2.Show detail      " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "      3.Find Meal        " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "      4.Buy              " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "      5.Back             " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;


			int choice;
			cout << "Choice:";
			cin >> choice;

			switch (choice) {

			case ShawAllMeals: {

				try {
					kitch.showAllMeals();
				}
				catch (Exception ex) {
					ex.show();
				}

				char symbol = ' ';
				cout << "For return back press R key : ";
				cin >> symbol;
				if (symbol == 'R' || symbol == 'r') {
					goto label;
				}
			}

			case Detail: {

				int id;
				cout << "Input ID:";
				cin >> id;
				try {
					kitch.showMealById(id);
				}
				catch (Exception ex) {
					ex.show();
				}
				Sleep(1000);

				char symbol1 = ' ';
				cout << "For return back press R key : ";
				cin >> symbol1;
				if (symbol1 == 'R' || symbol1 == 'r') {
					goto label;
				}

			}

			case Search: {
				string name;
				cout << "Input name:";
				cin >> name;
				kitch.findMealByName(name);
				cin.ignore();
				cin.get();
				char symbol2 = ' ';
				cout << "For return back press R key : ";
				cin >> symbol2;
				if (symbol2 == 'R' || symbol2 == 'r') {
					goto label;
				}
			}
			case Buy: {

				int id, amount;
				cout << "Meal id:";
				cin >> id;

				while (id > kitch.getMealSize()) {
					cout << "Input again:";
					cin >> id;
				}

				cout << "Amount:";
				cin >> amount;

				try {
					if (checkAmount(id, amount) == true) {
						while (true) {
							char choice;
							cout << "Do you want to add Ingredient y/n ?:";
							cin >> choice;
							try {
								if (choice == 'Y' || choice == 'y')
								{
									int addingID;
									cout << "ID:";
									cin >> addingID;
									addMoreIngredient(addingID);
								}
								else {
									break;
								}
							}
							catch (Exception ex) {
								ex.show();
							}
						}

						buyProduct(id, amount);
						cout << "Enjoy your meal!!" << endl;
						cout << "Price:" << price << endl;
						char select;
						int rate;
						cout << "Do you want to Rate? Yes or No:";
						cin >> select;
						if (select == 'Y' || select == 'y') {
							cout << "Input Rate (0-9)!";
							cin >> rate;
							if (rate < 0 || rate>9)
							{
								cout << "Rate 0-9 please : ";
								cin >> rate;
							}
							cout << "Thank rate! " << rate << endl;
						}
					}
					else {
						cout << "There is no food in the kitchen:" << endl;
					}
				}
				catch (Exception ex) {
					ex.show();
				}
				char symbol3 = ' ';
				cout << "For return back press R key : ";
				cin >> symbol3;
				if (symbol3 == 'R' || symbol3 == 'r') {
					goto label;

				}
			}
			case ClientControl::Back: {
				system("cls");
				return;
			}
			}
		}
	}
};


