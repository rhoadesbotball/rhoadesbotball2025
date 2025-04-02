#include <kipr/wombat.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <string>
#include <sstream>
#include <iostream>

using string=std::string;
using stream=std::stringstream;

/*

template <typename T> struct row {
    using valueType = T;
	string name;
    T value;
};

void createTable(auto cursor, string tablename, row<int> [1]);

void createTable(auto cursor, string tablename, row<typename> tableRows[1], row<typename> row1){
    stream fstring;
    string row1name = row1->name;
    using type = row1.T;
    fstring << "CREATE TABLE " << tablename << "(ID INT PRIMARY KEY NOT NULL, " << row1name << ' ' << type << "NOT NULL;";
    
}

*/

int main(int argc,char** argv)
{
    char *sql;
    sqlite3 *db;
    auto cursor = sqlite3_open("config.db", &db);
    sqlite3_stmt* stmt;
    sql = "SELECT * FROM YAY;";
    int accesscursor = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_step(stmt);
    const char* columnname = sqlite3_column_name(stmt, 0);
    std::cout << columnname;
    
    /*
    sql = "CREATE TABLE YAY("
        "ID INT PRIMARY KEY NOT NULL,"
        "CB INT NOT NULL );";
    sqlite3_exec(db, sql, NULL, 0, NULL);
    */
    sqlite3_close(db);
    /*
    int clicked = 0;
    while (clicked == 0){
        msleep(10);
        clicked = a_button();
    }
    
    printf("Yay i've been clicked");
    motor(0, 100);
    motor(2, 100);
    msleep(1000);
 	//
    row<int> row1;
    string tablename = "table1";
    row1.name = "row1";
    row1.value = 5;
    row<int> tableRows[]={row1};
    createTable(cursor, tablename, tableRows, row1);
    sqlite3_close(db);
    */
    return 0;
}
