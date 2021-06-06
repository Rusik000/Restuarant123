#pragma once

#include<iostream>

using namespace std;

class Notification {
	string text;
	string date;
	int notificationID;

public:
	static int id;

	Notification() : text(" ") {}

	Notification(const string& text)
	{
		this->notificationID = ++id;
		setText(text);
		setDate();
	}

	void setText(const string& text)
	{
		this->text = text;
	}

	string getText() const {
		return text;
	}

	void setDate()
	{
		this->date = __TIME__;
	}

	int getId() {
		return notificationID;
	}

	string getDate() const {
		return this->date;
	}

	void printMessage();

};

int Notification::id = 0;

class NotificationofIngredient :public Notification {
public:
	NotificationofIngredient(string text) :Notification(text) {}
	void printMessage()
	{
		cout << "======Notification=====" << endl;
		cout << "ID:" << getId() << endl;
		cout << "Text:" << getText() << endl;
		cout << "Time:" << getDate() << endl;
	}
};



