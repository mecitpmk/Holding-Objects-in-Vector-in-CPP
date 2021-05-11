// LibraryProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
    cout << "Hello World!\n\n";

    Student* mecit = new Student("Mecit");
    Book* HarryPotter = new Book("Harry Potter");
    Book* Mahmudi = new Book("Mahmudi");
    cout << endl;

    mecit->takeBook(HarryPotter);
    mecit->printTakenBooks();
    cout << endl;

    HarryPotter->printTakerStudents();
    cout << endl;

    HarryPotter->removeStudent(mecit);
    mecit->printTakenBooks();
    cout << "\n" << endl;

    mecit->takeBook(HarryPotter);
    cout << endl;
    mecit->findBook("Harry Potter");
    HarryPotter->findStudent("Mecit");
    cout << endl;
    mecit->takeBook(Mahmudi);
    Mahmudi->printTakerStudents();

    cout << "\n\nCalling Static method, Acessing Static vector.. " << endl;
    Book::PrintAllBooks();
    Student::PrintAllStudents();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
