#include <kipr/wombat.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <string>

using string=std::string;

void createTable();
int hi=0;
string hi="bruh"<<hi;
void createTable(){
	
}

int main()
{
    sqlite3 *db;
    int cursor = sqlite3_open("config.db", &db);
    int clicked = 0;
    while (clicked == 0){
        msleep(10);
        clicked = a_button();
    }
    
    printf("Yay i've been clicked");
    motor(0, 100);
    motor(2, 100);
    msleep(1000);
    sqlite3_close(db)
    return 0;
}
