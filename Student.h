#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"


using namespace std;


class Student
{
	private :
		string student_name;
		int ALLOWED_BOOKS_NUMBER = 5;
		bool isRightFull = false;
		int taken_books_number = 0;

	public :
		static vector<Student*> ALL_STUDENTS;
		vector <Book*> taken_books;
		Student(string student_name, int ALLOWED_BOOKS = 5); // Defalt Allowed Books is 5!
		
		bool checkRight(); //check if the student exceed the allowed books number or not?
		int getTakenBooksNumber(); // get total taken books number.
		void takeBook(Book* bookObj); // pass a parameeter type of Book , program will automatically added to vector List both.
		void printTakenBooks(); // print taken books as cout
		string getName(); // return student name.
		bool removeBook(Book* bookObj); // remove book from vector list, decrease taken book number, triggered from Book class method 
		Book *findBook(string BookName); // Check given parameeter(string) is avaialbe in vector. if exist return its adress.

		static void PrintAllStudents();
};