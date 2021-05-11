#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Student; // We can't include Header of Student in Header file because of fact that
				// We dont want to trigger	inf loop .
						// We will include Student header file in CPP file.
class Book
{
	private:
		string book_name;
		int page_number;
		int NO_COPIES = 2;
	public:
		Book(string book_name, int Copy_No = 2);
		vector<Student*> taken_from;
		static vector<Book*> ALL_BOOKS;

		bool checkAllTaked(); // check all of the books taked or not?
		int getNoCopy(); // get number of copies.
		bool takeBookFromStudent(Student* std); // if the permission allowed, return true. It means that student can take this book. 
		string getBookName();  // return book name 
		void printTakerStudents(); // print taker student as cout
		bool removeStudent(Student* std); // remove students from vector also triggers Student class method to remove this book.
		Student* findStudent(string StudentName); // find student in the vector. if param is exist,  return its adress.
		static void PrintAllBooks();

};