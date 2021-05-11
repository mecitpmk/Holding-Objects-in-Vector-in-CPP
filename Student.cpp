#include "Student.h"

vector<Student*> Student::ALL_STUDENTS; //ALL_STUDENTS is declared as static in Header file.We have to define it in CPP files again like this.
Student::Student(string name, int ALLOWED_BOOKS)
{
	this->student_name = name;
	this->ALLOWED_BOOKS_NUMBER = ALLOWED_BOOKS;
	Student::ALL_STUDENTS.push_back(this);
	cout << "Student has been created sucessfully.." << endl;
}

bool Student::checkRight()
{
	
	if (taken_books_number == ALLOWED_BOOKS_NUMBER)
	{
		return false; // FULL CANT TAKE!
	}
	return true; // Right is okay
}

int Student::getTakenBooksNumber()
{
	return taken_books_number;
}
void Student::takeBook(Book* bookObj)
{
	if (checkRight())
	{
		cout << "Student can take book!.. Checking Book" << endl;
		if (bookObj->takeBookFromStudent(this))
		{
			taken_books_number++;
		}
	}
}
void Student::printTakenBooks()
{
	if (taken_books_number > 0)
	{
		cout << "The student " << student_name << " Taked only " << taken_books_number << endl;
		for (Book* b : taken_books)
		{
			cout << "Taken Book Name is : " << b->getBookName() << endl;
		}
	}
	else
	{
		cout << "No books is taken .";
	}
}

string Student::getName()
{
	return this->student_name;
}

Book *Student::findBook(string BookName)
{
	if (taken_books.size() > 0)
	{
		for (Book* b : taken_books)
		{
			if (BookName.compare(b->getBookName()) == 0)
			{
				cout << "Book fuounded.. RETURNED ADRESS!" << endl;
				return b;
			}
		}
	}
	cout << "Book CANNT fuounded.. RETURNED Null!" << endl;
	return NULL;
}


bool Student::removeBook(Book* bookObj) // This function should trigger from Book class method which is removeStudent()
											// It means that that method will automatically triger to removeBook Method.
{

	cout << "deleted from book list.. now student delete also.." << endl;
	int ct = 0;
	bool isFounded = false;
	for (Book* b : taken_books)
	{
		if (b == bookObj) { isFounded = true;  break; }
		else ct++;
	}
	if (isFounded)
	{
		taken_books.erase(taken_books.begin() + ct);
		taken_books_number--;
	}
	return isFounded;
}

void Student::PrintAllStudents()
{
	for (Student* st : Student::ALL_STUDENTS)
	{
		cout << "Student Name -> " << st->getName() << " Total Taken Books No: " << st->getTakenBooksNumber() << endl;
	}
}