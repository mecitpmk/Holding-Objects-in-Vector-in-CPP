#include "Book.h"
#include "Student.h"

vector<Book*> Book::ALL_BOOKS; // ALL_BOOKS is declared as static in Header file. We have to define it in CPP files again like this.
Book::Book(string book_name, int Copy_No)
{
	this->book_name = book_name;
	this->NO_COPIES = Copy_No;
	Book::ALL_BOOKS.push_back(this);
	cout << "The book has been created sucessfully.." << endl;
}

void Book::PrintAllBooks()
{
	for (Book* b : Book::ALL_BOOKS)
	{
		cout << "Book Name -> " << b->getBookName() << " Available copy : " << b->getNoCopy() << endl;
	}
}

bool Book::checkAllTaked()
{
	if (NO_COPIES == 0)
	{
		return true;
	}
	return false;
}
int Book::getNoCopy()
{
	return NO_COPIES;
}

string Book::getBookName()
{
	return this->book_name;
}

bool Book::takeBookFromStudent(Student* std)
{

	if (!checkAllTaked())
	{
		cout << "Allowed .. Book is not full student will take now.." << endl;
		taken_from.push_back(std);
		std->taken_books.push_back(this);
		NO_COPIES--;
		return true;
		
	}
	else cout << "Sorry.. Book is full." << endl;
	return false;

}


void Book::printTakerStudents()
{
	if (taken_from.size() > 0)
	{
		cout << "The book " << book_name << " is taken from " << taken_from.size() << " Student." << endl;
		for (Student* std : taken_from)
		{
			cout << "The book is taken from Student -> " << std->getName() << endl;
		}
	}
}


bool Book::removeStudent(Student* std)
{
	
	int ct = 0;
	bool Founded = false;
	for (Student* st : taken_from)
	{
		if (st == std)
		{
			Founded = true; break;
		}
		else ct++;
	}
	if (Founded)
	{
		taken_from[ct]->removeBook(this);
		taken_from.erase(taken_from.begin() + ct);
		NO_COPIES++;
	}
	
	return Founded;
}

Student* Book::findStudent(string StudentName)
{
	if (taken_from.size() > 0)
	{
		for (Student* st : taken_from)
		{
			if (StudentName.compare(st->getName()) == 0)
			{
				cout << "Stdent fuounded.. RETURNED ADRESS!" << endl;
				return st;
			}
		}
	}
	cout << "Student couldnt founded.. NULL RETURNED." << endl;
	return NULL;
}