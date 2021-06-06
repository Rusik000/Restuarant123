#pragma once

#include <iostream>

using namespace std;

class Exception {

protected:

	string text;
	string source;
	int line;
	string date;
	string time;

public:

	string getText()const {
		return text;
	}

	string getSource()const {
		return source;
	}

	int getLine()const {
		return line;
	}

	string getDate()const {
		return date;
	}

	string getTime()const {
		return time;
	}


	void setText(const string& text) {
		this->text = text;
	}

	void setSource(const string& source) {
		this->source = source;
	}

	void setLine(const int line) {
		this->line = line;
	}

	void setDate(const string& date) {
		this->date = date;
	}

	void setTime(const string& time) {
		this->time = time;
	}

	Exception(string text, string source, int line, string date, string time)
		: text(text), source(source), line(line), date(date), time(time)
	{
	}

	void show() const {
		cout << "+++++++++++++ ERROR INFO +++++++++++++" << endl;
		cout << "Error Content : " << getText() << endl;
		cout << "Source : " << getSource() << endl;
		cout << "Line number : " << getLine() << endl;
		cout << "Date : " << getDate() << endl;
		cout << "Time : " << getTime() << endl;
	}

};

class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(string text, string source, int line, string date, string time)
		:Exception(text, source, line, date, time)
	{
	}
};
class DatabaseException :public Exception {
public:
	DatabaseException(string text, string source, int line, string date, string time)
		:Exception(text, source, line, date, time)
	{

	}
};

