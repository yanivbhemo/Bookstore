#include <iostream>
#include <string>
#include "Database.h"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std;

bool Display_Inventory(int type);
bool Display_Orders(int type);
bool Display_Customers();
bool Display_Suppliers();
bool Display_Transactions(int type);
int GetCustomerID();

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
		cout << "6) Transactions" << endl;
		cout << "7) More options" << endl;
		cout << "99) Exit" << endl;
		cout << "Selection: ";
		cin >> option;

		switch (option) {
		case 1:
			cout << "\t1) Display the entire book catalog" << endl;
			cout << "\t2) Display only the books that excist in the inventory" << endl;
			cout << "\t3) Display only the books with discount" << endl;
			cout << "\t4) Check if a book is in stock" << endl;
			cout << "\t5) Display suppliers of specific book" << endl;
			cout << "\tSelection: ";
			cin >> sub_option01;
			Display_Inventory(sub_option01);
			break;
		case 2:
			cout << "\t1) Display all the orders records" << endl;
			cout << "\t2) Display only the open orders" << endl;
			cout << "\tSelection: ";
			cin >> sub_option01;
			Display_Orders(sub_option01);
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
		case 6:
			cout << "\t1) Display transaction between dates" << endl;
			cout << "\t2) Display amount of X book purchases above Y date" << endl;
			cout << "\t3) How many books customer X purchased since Z date" << endl;
			cout << "\t4) Display the customer that purchased the largest amount of books" << endl;
			cout << "\tSelection: ";
			cin >> sub_option01;
			Display_Transactions(sub_option01);
			break;
		}
	}

	return 0;
}



bool Display_Inventory(int type)
{
	//type = 1 : Only in stock
	//type = 2 : Display all
	//type = 3 : All the books with discount
	//type = 4 : Check if specific book is in stock
	//type = 5 : Check who are the suppliers of specific book
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset;
	char title[100], author[100];
	string tmp1,tmp2;

	if (con) {
		Statement *stmt = con->createStatement();

		if (type == 1) {
			rset = stmt->executeQuery("SELECT book_catalog.ISBN as ISBN, book_catalog.title as title, book_catalog.author as author, book_catalog.publisher as publisher, book.quantity as quantity,book.discount as discount, book.price as price FROM book_catalog INNER JOIN book on book_catalog.ISBN = book.ISBN WHERE book.quantity > 0;");
		}
		if (type == 2) {
			rset = stmt->executeQuery("SELECT book_catalog.ISBN as ISBN, book_catalog.title as title, book_catalog.author as author, book_catalog.publisher as publisher, book.quantity as quantity,book.discount as discount, book.price as price FROM book_catalog INNER JOIN book on book_catalog.ISBN = book.ISBN;");
		}
		if (type == 3) {
			rset = stmt->executeQuery("SELECT book_catalog.ISBN as ISBN, book_catalog.title as title, book_catalog.author as author, book_catalog.publisher as publisher, book.quantity as quantity,book_catalog.discount as discount, book.price as price FROM book_catalog INNER JOIN book on book_catalog.ISBN = book.ISBN WHERE book_catalog.discount > 0;");
		}
		if (type == 4) {
			cin.clear();    // Restore input stream to working state
			cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered
			cout << "\t\tTitle: ";
			cin.getline(title, sizeof(title));
			//cin.clear();    // Restore input stream to working state
			//cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered
			cout << "\t\tAuthor: ";
			cin.getline(author, sizeof(author));
			tmp1 = title; tmp2 = author;
			if (title[0] != '\0' && author[0] != '\0') {
				PreparedStatement *pstmt = con->prepareStatement("SELECT ISBN FROM book_catalog WHERE title = ? AND author = ?");
				pstmt->setString(1, tmp1);
				pstmt->setString(2, tmp2);
				rset = pstmt->executeQuery();
				if (rset->rowsCount() == 0) {
					cout << "\t\tError: The book was not found." << endl; return false;
				}
				else {
					rset->first();
					int isbn = rset->getInt("ISBN");
					PreparedStatement *pstmt = con->prepareStatement("SELECT quantity FROM book WHERE ISBN = ?");
					pstmt->setInt(1, isbn);
					rset = pstmt->executeQuery();
					if (rset->rowsCount() == 0)
						cout << "\t\tError: The book is out of stock";
					else {
						rset->first();
						cout << "\t\tThe book is in stock - " << rset->getInt("quantity") << " left." << endl; return true;
					}
				}
			}
			if (title[0] != '\0' && author[0] == '\0') {
				PreparedStatement *pstmt = con->prepareStatement("SELECT ISBN FROM book_catalog WHERE title = ? LIMIT 1");
				pstmt->setString(1, tmp1);
				rset = pstmt->executeQuery();
				if (rset->rowsCount() == 0) {
					cout << "\t\tError: The book was not found." << endl; return false;
				}
				else {
					rset->first();
					int isbn = rset->getInt("ISBN");
					PreparedStatement *pstmt = con->prepareStatement("SELECT quantity FROM book WHERE ISBN = ? LIMIT 1");
					pstmt->setInt(1, isbn);
					rset = pstmt->executeQuery();
					if (rset->rowsCount() == 0)
						cout << "\t\tError: The book is out of stock" << endl;
					else {
						rset->first();
						cout << "\t\tThe book is in stock - " << rset->getInt("quantity") << " left." << endl; return true;
					}
				}
			}
			if (title[0] == '\0' && author[0] != '\0') {
				PreparedStatement *pstmt = con->prepareStatement("SELECT ISBN FROM book_catalog WHERE author = ? LIMIT 1");
				pstmt->setString(1, tmp2);
				rset = pstmt->executeQuery();
				if (rset->rowsCount() == 0) {
					cout << "\t\tError: The book was not found." << endl; return false;
				}
				else {
					rset->first();
					int isbn = rset->getInt("ISBN");
					PreparedStatement *pstmt = con->prepareStatement("SELECT quantity FROM book WHERE ISBN = ? LIMIT 1");
					pstmt->setInt(1, isbn);
					rset = pstmt->executeQuery();
					if (rset->rowsCount() == 0)
						cout << "\t\tError: The book is out of stock" << endl;
					else {
						rset->first();
						cout << "\t\tThe book is in stock - " << rset->getInt("quantity") << " left." << endl; return true;
					}
				}
			}
		}
		if (type == 5) {
			int book_isbn;
			cout << "\t\tBook ISBN: ";
			cin >> book_isbn;

			PreparedStatement *pstmt = con->prepareStatement("SELECT suppliers.name "
				"FROM supply_price_list "
				"INNER JOIN suppliers "
				"ON supply_price_list.supplier_id = suppliers.supplier_id "
				"WHERE supply_price_list.ISBN = ? "
			);
			pstmt->setInt(1, book_isbn);
			rset = pstmt->executeQuery();
			cout << endl;
			while (rset->next())
			{
				cout << "\t\tSupplier:\t" << rset->getString("name") << endl;
			}
			cout << endl;
		}
		while (rset->next())
		{
			cout << "ID:\t\t\t" << rset->getInt("ISBN") << endl;
			cout << "Title:\t\t\t" << rset->getString("title") << endl;
			cout << "Author:\t\t\t" << rset->getString("author") << endl;
			cout << "Publisher:\t\t" << rset->getString("publisher") << endl;
			cout << "Quantity:\t\t" << rset->getString("quantity") << endl;
			cout << "Discount:\t\t" << rset->getString("discount") << endl;
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

bool Display_Orders(int type)
{
	//type = 1: Display all orders
	//type = 2 : Only open orders
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset, *rset2;

	if (con) {
		Statement *stmt = con->createStatement();

		if (type == 2) {
			rset = stmt->executeQuery("SELECT orders.order_num,orders.Client_id,orders.date_of_order,order_statuses.name as status FROM orders INNER JOIN order_statuses ON orders.status = order_statuses.status_id where orders.status<>4");
		}
		if(type == 1)
		{
			rset = stmt->executeQuery("SELECT orders.order_num,orders.Client_id,orders.date_of_order,order_statuses.name as status FROM orders INNER JOIN order_statuses ON orders.status = order_statuses.status_id");
		}
		cout << endl;
		while (rset->next())
		{
			cout << "Order num:\t" << rset->getInt("order_num") << endl;
			cout << "Client id:\t" << rset->getString("Client_id") << endl;
			cout << "Date Of Order:\t" << rset->getString("date_of_order") << endl;
			cout << "status:\t\t" << rset->getString("status") << endl;
			cout << "books orderd:" << endl;
			PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM orders_books WHERE order_id = ?");
			pstmt->setInt(1, rset->getInt("order_num"));
			rset2 = pstmt->executeQuery();
			while (rset2->next())
			{
				cout << "\t\tbook ISBN: " << rset2->getString("ISBN") << endl;
			}
			cout << endl;
			cout << "----------------------------" << endl;
		}
		delete con;
		delete rset;
		delete rset2;
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

bool Display_Transactions(int type)
{
//type = 1 -> Display transactions between dates
//type = 2 -> Display amount of X book purchases above Y date
//type = 3 -> How many books customer X purchased since Z date
//type = 4 -> Display the customer that purchased the largest amount of books
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset, *rset2;

	if (con) {
		Statement *stmt = con->createStatement();
		if (type == 1)
		{
			string start_date, end_date;
			bool flag = true;
			while (flag)
			{
				cout << "\t\tStart Date (YYYY-MM-DD): ";
				cin >> start_date;
				cout << "\t\tEnd Date (YYYY-MM-DD): ";
				cin >> end_date;
				date start_date_formal(from_simple_string(start_date));
				date end_date_formal(from_simple_string(end_date));
				if (start_date_formal > end_date_formal) { cout << "\tError: Start date is above the End date! Write again please." << endl; }
				else { 
					PreparedStatement *pstmt = con->prepareStatement("SELECT transactions.trans_id,transactions.issue_date,transactions.customer_id,transactions.discount,transactions.total_price,order_statuses.name as status FROM transactions INNER JOIN order_statuses ON transactions.status = order_statuses.status_id where issue_date >= ? AND issue_date <= ?");
					pstmt->setString(1, to_iso_extended_string(start_date_formal));
					pstmt->setString(2, to_iso_extended_string(end_date_formal));
					rset = pstmt->executeQuery();
					flag = false; 
				}
			}

			while (rset->next())
			{
				cout << "ID:\t\t" << rset->getInt("trans_id") << endl;
				cout << "Issue date:\t" << rset->getString("issue_date") << endl;
				cout << "Customer ID:\t" << rset->getString("customer_id") << endl;
				cout << "Discount:\t" << rset->getString("discount") << endl;
				cout << "Total Price:\t" << rset->getString("total_price") << endl;
				cout << "Status:\t\t" << rset->getString("status") << endl;
				cout << "----------------------------" << endl;
			}
			cout << "Amount of records: " << rset->rowsCount() << endl;
		}
		if (type == 2)
		{
			string issue_date;
			int book_id, counter=0, trans_id;
			cout << "\t\tTransaction issue Date (YYYY-MM-DD): ";
			cin >> issue_date;
			cout << "\t\tBood ISBN: ";
			cin >> book_id;
			date start_date_formal(from_simple_string(issue_date));
			PreparedStatement *pstmt = con->prepareStatement("SELECT trans_id FROM transactions where issue_date >= ?");
			pstmt->setString(1, to_iso_extended_string(start_date_formal));
			rset = pstmt->executeQuery();
			while (rset->next())
			{
				trans_id = rset->getInt("trans_id");
				PreparedStatement *pstmt2 = con->prepareStatement("SELECT * FROM transactions_books WHERE trans_id = ? AND ISBN = ?");
				pstmt2->setInt(1, trans_id);
				pstmt2->setInt(2, book_id);
				rset2 = pstmt2->executeQuery();
				rset2->first();
				if (rset2->rowsCount() > 0) 
					counter++;
			}
			cout << "\t\t\n- The book: " << book_id << " purchased " << counter << " times since " << issue_date << endl;
		}
		if (type == 3)
		{
			string issue_date;
			int customer_id, counter = 0, trans_id;
			cout << "\t\tSearch from Date (YYYY-MM-DD): ";
			cin >> issue_date;
			customer_id = -1;
			while (customer_id == -1) { customer_id = GetCustomerID(); }
			date start_date_formal(from_simple_string(issue_date));
			PreparedStatement *pstmt = con->prepareStatement(
				"SELECT trans_id FROM transactions "
				"WHERE issue_date > ? AND customer_id = ?"
			);
			pstmt->setString(1, to_iso_extended_string(start_date_formal));
			pstmt->setInt(2, customer_id);
			rset = pstmt->executeQuery();
			while (rset->next())
			{
				trans_id = rset->getInt("trans_id");
				PreparedStatement *pstmt2 = con->prepareStatement(
					"SELECT COUNT(ISBN) as counter FROM transactions_books "
					"WHERE trans_id = ?"
				);
				pstmt2->setInt(1, trans_id);
				rset2 = pstmt2->executeQuery();
				rset2->first();
				counter += rset2->getInt("counter");
			}
			cout << "\n\t\t- Amount of books customer " << customer_id << " made: " << counter << endl;
		}
		if (type == 4)
		{
			string issue_date;
			int max_customer_id, max_counter = 0;
			PreparedStatement *pstmt = con->prepareStatement(
				"SELECT trans_id,customer_id FROM transactions"
			);
			rset = pstmt->executeQuery();
			rset->first();
			max_customer_id = rset->getInt("customer_id");
			while (rset->next())
			{
				PreparedStatement *pstmt2 = con->prepareStatement(
					"SELECT COUNT(trans_id) as count FROM transactions_books WHERE trans_id = ?"
				);
				pstmt2->setInt(1, rset->getInt("trans_id"));
				rset2 = pstmt2->executeQuery();
				rset2->first();
				if (rset2->getInt("count") > max_counter) {
					max_counter = rset2->getInt("count");
					max_customer_id = rset->getInt("customer_id");
				}
			}
			cout << "\n\t\t- The customer whom purchased the largest amount of books is: " << max_customer_id << endl;
		}
		delete con;
		delete rset;
		delete stmt;
		return true;
	}
	return false;
}

int GetCustomerID()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	ResultSet *rset;

	char fname[40], lname[40], id[10], phone[20];
	int i_id;
	string s_fname, s_lname, s_id, s_phone;
	cin.clear();    // Restore input stream to working state
	cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered
	cout << "\t\tCustomer first name: ";
	cin.getline(fname, sizeof(fname));
	cout << "\t\tCustomer last name: ";
	cin.getline(lname, sizeof(lname));
	cout << "\t\tCustomer id: ";
	cin.getline(id, sizeof(id));
	cout << "\t\tCustomer phone number: ";
	cin.getline(phone, sizeof(phone));

	s_fname = fname; s_lname = lname; s_id = id, s_phone = phone;
	if( id[0] != '\0') i_id = std::stoi(s_id);

	if (fname[0] != '\0' && lname[0] != '\0' && id[0] == '\0' && phone[0] == '\0')
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT id FROM customers WHERE fname = ? AND lname = ?");
		pstmt->setString(1, s_fname);
		pstmt->setString(2, s_lname);
		rset = pstmt->executeQuery();
		if (rset->rowsCount() > 1 || rset->rowsCount() == 0) {
			cout << "\n\t\tError: The system didnt find any customer with these details" << endl;
			return -1;
		}
		rset->first();
		return rset->getInt("id");
	}
	if (fname[0] != '\0' && lname[0] != '\0' && id[0] != '\0' && phone[0] == '\0')
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT id FROM customers WHERE fname = ? AND lname = ? AND id = ?");
		pstmt->setString(1, s_fname);
		pstmt->setString(2, s_lname);
		pstmt->setInt(3, i_id);
		rset = pstmt->executeQuery();
		if (rset->rowsCount() > 1 || rset->rowsCount() == 0) {
			cout << "\n\t\tError: The system didnt find any customer with these details" << endl;
			return -1;
		}
		rset->first();
		return rset->getInt("id");
	}
	if (fname[0] != '\0' && lname[0] != '\0' && id[0] != '\0' && phone[0] != '\0')
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT id FROM customers WHERE fname = ? AND lname = ? AND id = ? AND phone = ?");
		pstmt->setString(1, s_fname);
		pstmt->setString(2, s_lname);
		pstmt->setInt(3, i_id);
		pstmt->setString(4, s_phone);
		rset = pstmt->executeQuery();
		if (rset->rowsCount() > 1 || rset->rowsCount() == 0) {
			cout << "\n\t\tError: The system didnt find any customer with these details" << endl;
			return -1;
		}
		rset->first();
		return rset->getInt("id");
	}
	if (fname[0] != '\0' && lname[0] != '\0' && id[0] == '\0' && phone[0] != '\0')
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT id FROM customers WHERE fname = ? AND lname = ? AND phone = ?");
		pstmt->setString(1, s_fname);
		pstmt->setString(2, s_lname);
		pstmt->setString(3, s_phone);
		rset = pstmt->executeQuery();
		if (rset->rowsCount() > 1 || rset->rowsCount() == 0) {
			cout << "\n\t\tError: The system didnt find any customer with these details" << endl;
			return -1;
		}
		rset->first();
		return rset->getInt("id");
	}

	return 0;
}