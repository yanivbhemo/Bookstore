#include "Database.h"

Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;

	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema(DB_NAME);
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			string q = "CREATE DATABASE IF NOT EXISTS ";
			q.append(DB_NAME);
			stmt->execute(q);
			con->setSchema(DB_NAME); // switch database
			stmt->execute("CREATE TABLE book_catalog ("
				"ISBN int(10) unsigned NOT NULL AUTO_INCREMENT,"
				"author varchar(45) NOT NULL,"
				"title varchar(45) NOT NULL,"
				"publisher varchar(45) NOT NULL,"
				"issue_date date NOT NULL,"
				"discount int(2) DEFAULT NULL,"
				"PRIMARY KEY(ISBN)"
				");");
			
			stmt->execute("CREATE TABLE BookStore.book ("
				"ISBN INT UNSIGNED NOT NULL AUTO_INCREMENT,"
				"price INT(4) NULL,"
				"quantity INT(5) NULL,"
				"status VARCHAR(45) NULL,"
				"PRIMARY KEY(ISBN) "
				"FOREIGN KEY(ISBN) "
				"REFERENCES customers (book_catalog)"
				");");

			stmt->execute("CREATE TABLE BookStore.customers ("
				"id INT NOT NULL,"
				"fname VARCHAR(45) NULL,"
				"lname VARCHAR(45) NULL,"
				"phone VARCHAR(45) NULL,"
				"address VARCHAR(70) NULL,"
				"email VARCHAR(45) NULL,"
				"birthday DATE NULL,"
				"amount_of_purcheses INT NULL,"
				"PRIMARY KEY(id)"
				")");
			
			stmt->execute("CREATE TABLE BookStore.orders ("
				"order_num INT NOT NULL AUTO_INCREMENT,"
				"Client_id INT NOT NULL,"
				"books TEXT,"
				"date_of_order DATE NULL,"
				"status int NULL,"
				"PRIMARY KEY(order_num),"
				"FOREIGN KEY(Client_id)"
				"REFERENCES customers (id)"
				")");
			stmt->execute("CREATE TABLE BookStore.suppliers ("
				"supplier_id INT NOT NULL AUTO_INCREMENT,"
				"name VARCHAR(45) NULL,"
				"phone VARCHAR(45) NULL,"
				"address VARCHAR(45) NULL,"
				"PRIMARY KEY(supplier_id));"
			);

			stmt->execute("CREATE TABLE BookStore.supply_price_list ("
				"ISBN INT UNSIGNED NOT NULL,"
				"supplier_id INT NOT NULL,"
				"price_per_book INT NULL,"
				"PRIMARY KEY(ISBN),"
				"	INDEX supplier_id_idx (supplier_id ASC),"
				"	CONSTRAINT supplier_id"
				"	FOREIGN KEY(supplier_id)"
				"	REFERENCES BookStore.suppliers (supplier_id))"
				);

			stmt->execute("CREATE TABLE bookstore.order_statuses ("
				" status_id INT NOT NULL AUTO_INCREMENT,"
				"name VARCHAR(45) NULL,"
				"PRIMARY KEY(status_id));"
			);

			stmt->execute("CREATE TABLE bookstore.transactions (trans_id INT NOT NULL AUTO_INCREMENT,issue_date DATE NULL,customer_id INT NULL,discount DOUBLE NULL,total_price DOUBLE NULL,status INT NULL,PRIMARY KEY(trans_id),INDEX customer_id_idx(customer_id ASC),INDEX status_idx(status ASC),CONSTRAINT customer_id FOREIGN KEY(customer_id) REFERENCES bookstore.customers(id) ON DELETE NO ACTION ON UPDATE NO ACTION,CONSTRAINT status FOREIGN KEY(status) REFERENCES bookstore.order_statuses(status_id) ON DELETE NO ACTION ON UPDATE NO ACTION);");

			delete stmt;
		}

		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
		throw e;
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	}
	catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}

