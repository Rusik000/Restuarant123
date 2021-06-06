#pragma once

#include<iostream>
#include"ClientController.h"
#include"AllNotification.h"
#include"Exception.h"
#include"StockNotification.h"
#include <synchapi.h>

using namespace std;

enum StockControl
{
	DeleteIngredients = 1, ShowAllIngredient, ShowIngedientById, Increase, Decrease,
	UpdateIngredient, goBack
};

enum MealControl
{
	DeleteMeal = 1, DeleteAllMeal, UpdateMeal, ShowMealById, ShowAllMeals,
	FindMealById, BackMeal
};


class Admin
{
	Stock stocks;
	Kitchen kitchens;
	const string username_admin = "admin";
	const string password = "admin";
	vector<NotificationofIngredient> ingredients;

public:
	Admin(Stock stocks, Kitchen kitchens)
	{
		setA(stocks);
		setB(kitchens);
	}
	void setA(Stock stocks) {
		this->stocks = stocks;
	}

	void setB(Kitchen kitchens) {
		this->kitchens = kitchens;
	}

	void deleteNotificationIngredient()
	{
		ingredients.push_back(NotificationofIngredient("Ingredient deleted"));
	}

	void increaseNotification()
	{
		ingredients.push_back(NotificationofIngredient("Ingredined increase"));
	}

	void decreaseNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Ingredient decrease:"));
	}

	void updateIngNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Ingredient Updated:"));
	}

	void deletenotNotficationIngredient()
	{
		ingredients.push_back(NotificationofIngredient("Ingredient cant be deleted"));
	}

	void increasenotNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Ingredient cant be increased"));
	}

	void decreasenotNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Ingredient cant be decrease:"));
	}

	void updateIngnotNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Ingredient cant be Updated:"));
	}

	void deleteMealNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Meal deleted"));
	}

	void deleteNotMealNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Meal cant be deleted"));
	}

	void updateMealNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Meal updated"));
	}

	void updateNotMealNotfication()
	{
		ingredients.push_back(NotificationofIngredient("Meal cant be updated"));
	}


	void showNotficationIngredient()
	{
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			i->printMessage();
		}
	}

	bool login(string username, string password)
	{

		if (username == username_admin && password == password)
		{
			system("color a");
			return true;
		}
		else if (username == username_admin && password != password)
		{
			cout << "Password is incorrect:" << endl;
			return false;
		}
		else if (username != username_admin && password == password)
		{
			cout << "Username is incorrect:" << endl;
			return false;
		}
		else if (username != username_admin && password != password)
		{
			cout << "Username and password are incorrect:" << endl;
			return false;
		}
	}

	void signin() {
		while (1) {
			system("cls");
			string username, password;
			cout << "Input username:";
			cin >> username;
			cout << "Password:";
			cin >> password;

			if (login(username, password)) {
				break;
			}
			else
			{
				cout << "Input again" << endl;
			}
		}
	}

	void stockControl()
	{
		while (true) {

			system("color b");
			cout << "1.Delete Ingredient:" << endl;
			cout << "2.Show All Ingredients:" << endl;
			cout << "3.Show Ingredient by id:" << endl;
			cout << "4.Increase ingredient:" << endl;
			cout << "5.Decrease ingredient:" << endl;
			cout << "6.Update ingredient:" << endl;
			cout << "7.Back:" << endl;

			int choice;
			cout << "Choice:";
			cin >> choice;

			switch (choice)
			{
			case DeleteIngredients: {
				try {
					int delet;
					cout << "Input id:";
					cin >> delet;
					stocks.deleteIngredientById(delet);
					deleteMealNotfication();
				}
				catch (Exception ex) {
					deletenotNotficationIngredient();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowAllIngredient:
				try {
					stocks.showAllIngredients();
				}
				catch (Exception ex)
				{
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;

			case ShowIngedientById: {
				try
				{
					int id_;
					cout << "Input id:";
					cin >> id_;
					stocks.showIngredientById(id_);
				}
				catch (Exception ex)
				{
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}

			case Increase:
				try {
					int id_increase, amount_increase;
					cout << "Input id:";
					cin >> id_increase;
					cout << "Amount:";
					cin >> amount_increase;
					stocks.increment(id_increase, amount_increase);
					increaseNotification();
				}
				catch (Exception ex) {
					increasenotNotfication();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;

			case Decrease:
				try {
					int id_decrease, amount_decrease;
					cout << "Input id:";
					cin >> id_decrease;
					cout << "Amount:";
					cin >> amount_decrease;
					stocks.decrement(id_decrease, amount_decrease);
					decreaseNotfication();
				}
				catch (Exception ex) {
					decreasenotNotfication();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;

			case UpdateIngredient: {
				try {
					int update;
					cout << "Input id:";
					cin >> update;
					stocks.updateIngredientById(update);
					updateIngNotfication();
				}
				catch (Exception ex) {
					updateIngnotNotfication();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}

			case goBack:
				return;
				break;
			}
		}
	}

	void mealControl() {
		while (1) {
			system("color 2");
			cout << "1.Delete Meal :" << endl;
			cout << "2.Delete All Meal :" << endl;
			cout << "3.Update Meal :" << endl;
			cout << "4.Show Meal by Id :" << endl;
			cout << "5.Show All Meal :" << endl;
			cout << "6.Search meal by name :" << endl;
			cout << "7.Back : " << endl;
			int choice;
			cout << "Choice:";
			cin >> choice;
			switch (choice) {

			case DeleteMeal: {
				try {
					int id;
					cout << "Input id:";
					cin >> id;
					kitchens.deleteMealById(id);
					deleteMealNotfication();
				}
				catch (Exception ex) {
					deleteNotMealNotfication();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}

			case DeleteAllMeal: {
				kitchens.deleteAllMeals();
				cout << "All meals Deleted:" << endl;
				cin.ignore();
				cin.get();
				break;
			}

			case UpdateMeal: {
				try {
					int id;
					cout << "Input id:";
					cin >> id;
					kitchens.updateMealById(id);
					updateMealNotfication();
				}
				catch (Exception ex)
				{
					updateNotMealNotfication();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowMealById: {
				try {
					int id;
					cout << "Input id:";
					cin >> id;
					kitchens.showMealById(id);
				}
				catch (Exception ex) {
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}

			case ShowAllMeals: {
				try {
					kitchens.showAllMeals();

				}
				catch (Exception ex) {
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case FindMealById: {
				string _name;
				cout << "Input name:";
				cin >> _name;
				kitchens.findMealByName(_name);
				cin.ignore();
				cin.get();
				break;
			}
			case BackMeal:
				return;
				break;
			}
		}
	}

	void showNotfication() {
		showNotficationIngredient();
	}
};




