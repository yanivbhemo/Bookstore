#include <iostream>
#include "Database.h"

bool Display_Inventory(bool in_stock);
bool Display_Orders(bool open_orders);
bool Display_Customers();
bool Display_Suppliers();

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
		cout << "3) Suppliers" << endl;
		cout << "4) Show Orders" << endl;
		cout << "5) Customers" << endl;
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
			cout << "\t1) Display all the orders records" << endl;
			cout << "\t2) Display only the open orders" << endl;
			cout << "\tSelection: ";
			cin >> sub_option01;
			if (sub_option01 == 1)
				Display_Orders(false);
			else
				Display_Orders(true);
			break;
		case 3:
			cout << "\t1) Display all suppliers" << endl;
			cout << "\tSelection: ";
			cin >> sub_option01;
			if (sub_option01 == 1)
				Display_Suppliers();
			break;
		case 5:
			cout << "\t1) Display customers which made at least 1 purchase" << endl;
			cout << "\tSelection: ";
			cin >> sub_option01;
			if (sub_option01 == 1)
				Display_Customers();
			break;
		}
	}

	return 0;
}



bool Display_Inventory(bool in_stock)
{
	//in_stock = true: Only in stock
	//in_stock = false : Display all
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
		cout << "Amount of records: " << rset->rowsCount() << endl;
		delete con;
		delete rset;
		delete stmt;
		return true;
	}
	return false;
}

bool Display_Orders(bool open_orders)
{
	//open_orders = true: Only open orders
	//open_orders = false : Display all
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset;

	if (con) {
		Statement *stmt = con->createStatement();

		if (open_orders == true) {
			rset = stmt->executeQuery("SELECT orders.order_num,orders.Client_id,orders.books,orders.date_of_order,order_statuses.name as status FROM orders INNER JOIN order_statuses ON orders.status = order_statuses.status_id where orders.status<>4");
		}
		else
		{
			rset = stmt->executeQuery("SELECT orders.order_num,orders.Client_id,orders.books,orders.date_of_order,order_statuses.name as status FROM orders INNER JOIN order_statuses ON orders.status = order_statuses.status_id");
		}

		while (rset->next())
		{
			cout << "Order num:\t" << rset->getInt("order_num") << endl;
			cout << "Client id:\t" << rset->getString("Client_id") << endl;
			cout << "books:\t\t" << rset->getString("books") << endl;
			cout << "Date Of Order:\t" << rset->getString("date_of_order") << endl;
			cout << "status:\t\t" << rset->getString("status") << endl;
			cout << "----------------------------" << endl;
		}
		cout << "Amount of records: " << rset->rowsCount() << endl;
		delete con;
		delete rset;
		delete stmt;
		return true;
	}
	return false;
}

bool Display_Customers()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset;

	if (con) {
		Statement *stmt = con->createStatement();

		rset = stmt->executeQuery("SELECT * FROM customers where amount_of_purcheses > 0");

		while (rset->next())
		{
			cout << "ID:\t\t\t" << rset->getInt("id") << endl;
			cout << "Full Name:\t\t" << rset->getString("fname") << " " << rset->getString("lname") << endl;
			cout << "Phone:\t\t\t" << rset->getString("phone") << endl;
			cout << "Address:\t\t" << rset->getString("address") << endl;
			cout << "Email:\t\t\t" << rset->getString("email") << endl;
			cout << "Birthday:\t\t" << rset->getString("birthday") << endl;
			cout << "Amount of purcheses:\t" << rset->getString("amount_of_purcheses") << endl;
			cout << "----------------------------" << endl;
		}
		cout << "Amount of records: " << rset->rowsCount() << endl;
		delete con;
		delete rset;
		delete stmt;
		return true;
	}
	return false;
}

bool Display_Suppliers()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset;

	if (con) {
		Statement *stmt = con->createStatement();

		rset = stmt->executeQuery("SELECT * FROM suppliers");

		while (rset->next())
		{
			cout << "ID:\t\t" << rset->getInt("supplier_id") << endl;
			cout << "Name:\t\t" << rset->getString("name") << endl;
			cout << "Phone:\t\t" << rset->getString("phone") << endl;
			cout << "Address:\t" << rset->getString("address") << endl;
			cout << "----------------------------" << endl;
		}
		cout << "Amount of records: " << rset->rowsCount() << endl;
		delete con;
		delete rset;
		delete stmt;
		return true;
	}
	return false;
}