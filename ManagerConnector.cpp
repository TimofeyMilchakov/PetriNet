#include "ManagerConnector.h"



ManagerConnector::ManagerConnector() {}

ManagerConnector& ManagerConnector::getManagerConnector()
{
	static ManagerConnector theSingleInstance;
	return theSingleInstance;
}

MYSQL_RES* ManagerConnector::query(string  query) {

	MYSQL* connection, mysql;
	try {
		int query_state;
		mysql_init(&mysql);
		connection = mysql_real_connect(&mysql, host, user, password, db, 3306, 0, 0);
		query_state = mysql_query(connection, query.c_str());
		if (query_state != 0) {
			std::cout << mysql_error(connection) << std::endl;
		}
		return mysql_store_result(connection);
	}
	finally{
		mysql_close(connection);
	}
}

void ManagerConnector::close(MYSQL* link) {
	mysql_close(link);
}