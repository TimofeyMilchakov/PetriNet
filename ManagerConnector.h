#pragma once
#include "NodeModel.cpp"
#include <string>
#include <iostream>
#include <cstring>
#include <mysql.h>

using namespace std;

const char host[] = { "localhost" };
const char user[] = { "root" };
const char password[] = { "605526" };
const char db[] = { "petrinet" };


class ManagerConnector {
private:
	ManagerConnector();
	ManagerConnector(const ManagerConnector&);
	ManagerConnector& operator=(ManagerConnector&);

public:
	static ManagerConnector& getManagerConnector();
	MYSQL_RES* query(string  query);
	void close(MYSQL* link);
};