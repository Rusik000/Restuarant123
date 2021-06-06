#include<iostream>
#include<Windows.h>
#include<fstream>
#include"ClientController.h"
#include"AdminController.h"
#include"Order.h"
#include"FileHelper.h"


using namespace std;


void Start() {

	Ingredient mushroom("Mushroom", 3, 4, 8, 12, 21, 40);
	Ingredient meat("Meat", 2, 2, 2, 2, 8, 2);
	Ingredient cheese("Cheese", 3, 3, 3, 3, 7, 6);
	Ingredient olive("Olive", 4, 4, 4, 4, 5, 3);
	Ingredient spice("Spice", 5, 5, 5, 5, 8, 2);


	Stock ingredient;
	ingredient.addIngredient(mushroom);
	ingredient.addIngredient(meat);
	ingredient.addIngredient(cheese);
	ingredient.addIngredient(olive);
	ingredient.addIngredient(spice);


	Meal pizza("Pizza", "Fast Food", 8, 15, 2, 15);
	Meal pulov("Mushroom Soup", "Weak Food", 7.5, 5, 3, 28);
	Meal kabab("Kabab", "Category", 9.9, 25, 3, 35);

	pizza.addIngredient(mushroom);
	pizza.addIngredient(olive);

	pulov.addIngredient(spice);
	pulov.addIngredient(cheese);

	kabab.addIngredient(meat);
	kabab.addIngredient(mushroom);



	Kitchen meal;
	meal.addMeal(pizza);
	meal.addMeal(pulov);
	meal.addMeal(kabab);

	Admin admin(ingredient, meal);

	Order o(meal, ingredient);

	int num, select;

	while (true) {
	label:
		system("cls");
		system("color b");
		cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
		cout << "\t\t\t\t\t" << char(179) << "       1.Admin           " << char(179) << endl;
		cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
		cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
		cout << "\t\t\t\t\t" << char(179) << "       2.Client          " << char(179) << endl;
		cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
		cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
		cout << "\t\t\t\t\t" << char(179) << "       3.Exit            " << char(179) << endl;
		cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;

		cin >> num;
		while (num != 1 && num != 2 && num != 3) {
			cout << "Input again:";
			cin >> num;
		}
		if (num == 1) {
			admin.signin();
			while (true) {
				system("cls");
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << "   1.Stock control       " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << "   2.Meal Control        " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << "   3.Show Notification   " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << "   4.Back                " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;



				cin >> select;

				while (select != 1 && select != 2 && select != 3 && select != 4) {
					cout << "Input again:";
					cin >> select;
				}

				if (select == 1) {
					admin.stockControl();
				}

				else if (select == 2) {
					admin.mealControl();
				}

				else if (select == 3) {
					admin.showNotfication();
					Sleep(1000);
					cin.ignore();
					cin.get();
				}
				else if (select == 4) {
					goto label;
				}
			}
		}
		else if (num == 2)
		{
			system("cls");
			while (true) {
				system("color 9");
				int num_;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << "   1.Go Order            " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << "   2.Back                " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cin >> num_;
				while (num_ != 1 && num_ != 2) {
					cout << "Input again:";
					cin >> num_;
				}

				if (num_ == 1) {
					system("cls");
					o.Menu();
				}

				else if (num_ == 2) {
					system("cls");
					break;
				}
			}
		}

		else if (num == 3) {
			cout << "You leave !!!" << endl;
			Sleep(2000);
			exit(0);
		}

	}

}


