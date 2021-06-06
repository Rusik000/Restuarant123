#pragma once
#include<iostream>
#include<fstream>
#include"ClientController.h"


using namespace std;

class FileHelper {
public:
	static string filename;
	static void Save(Stock s) {
		ofstream fout(filename, ios::app);
		if (fout.is_open()) {
			//fout << "Error : " << endl;
			fout << "Count :" << 8;
			for (int i = 0; i < 8; i++)
			{
				fout << "ID : " << s.ingredient[i].getIngredient_Id() << endl;
				fout << "Name :" << s.ingredient[i].getName() << endl;
				fout << "Protein :" << s.ingredient[i].getProtein() << endl;
				fout << "Amount :" << s.ingredient[i].getAmount() << endl;
				fout << "Carbogydrates : " << s.ingredient[i].getCarbogydrates() << endl;
				fout << "Fat : " << s.ingredient[i].getFat() << endl;
				fout << "Price : " << s.ingredient[i].getingPrice() << endl;
			}


		}
	}
};
string FileHelper::filename = "Restaurant123.txt";




