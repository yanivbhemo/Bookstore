#include <iostream>
#include "Database.h"

bool Display_Inventory(bool in_stock);

int main()
{
	Database &db = Database::getInstance();
	//Lecturer *yaniv;
	//
	//string bdate = "1993/03/09";
	//date d(from_string(bdate));
	//
	//yaniv = Lecturer::create("8", "yaniv", "ben hamo", "rishon", "hashnaim",22, d);
	//yaniv = Lecturer::getById("3");
	//yaniv->SetFirstname("BABI");
	//yaniv->update();
	cout << "Welcome to your book store management system" << endl;
	
	int option = -1;
	int sub_option01 = -1;

	while (option != 99)
	{
		cout << endl << "Please choose an option" << endl;
		cout << "----------------------------" << endl;
		cout << "1) Inventory" << endl;
		cout << "2) Orders" << endl;
		cout << "3) Show suppliers" << endl;
		cout << "4) Show Orders" << endl;
		cout << "5) Show Customers" << endl;
		cout << "6) More options" << endl;
		cout << "99) Exit" << endl;
		cout << "Selection: ";
		cin >> option;

		switch (option) {
		case 1:
			cout << "\t1) Display the entire book catalog" << endl;
			cout << "\t2) Display only the books that excist in the inventory" << endl;
			cout << "\tSelection: ";
			cin >> sub_option01;
			if (sub_option01 == 1)
				Display_Inventory(false);
			else
				Display_Inventory(true);
			break;
		case 2:
			cout << "\t1) Place an order" << endl;
		}
	}

	return 0;
}



bool Display_Inventory(bool in_stock)
{
	//in_stock = true: Only in stock
	//in_stock = false : Display all
	cout << in_stock;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset;

	if (con) {
		Statement *stmt = con->createStatement();

		if (in_stock == true) {
			rset = stmt->executeQuery("SELECT book_catalog.ISBN as ISBN, book_catalog.title as title, book_catalog.author as author, book_catalog.publisher as publisher, book.quantity as quantity, book.price as price FROM book_catalog INNER JOIN book on book_catalog.ISBN = book.ISBN WHERE book.quantity > 0;");
		}
		else
		{
			rset = stmt->executeQuery("SELECT book_catalog.ISBN as ISBN, book_catalog.title as title, book_catalog.author as author, book_catalog.publisher as publisher, book.quantity as quantity, book.price as price FROM book_catalog INNER JOIN book on book_catalog.ISBN = book.ISBN;");
		}

		while (rset->next())
		{
			cout << "ID:\t\t\t" << rset->getInt("ISBN") << endl;
			cout << "Title:\t\t\t" << rset->getString("title") << endl;
			cout << "Author:\t\t\t" << rset->getString("author") << endl;
			cout << "Publisher:\t\t" << rset->getString("publisher") << endl;
			cout << "Quantity:\t\t" << rset->getString("quantity") << endl;
			cout << "Price:\t\t\t" << rset->getString("price") << endl;
			cout << "----------------------------" << endl;
		}
		delete con;
		delete rset;
		delete stmt;
		return true;
	}
	return false;
}
