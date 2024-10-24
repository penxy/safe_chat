#include <iostream>
#include "sqlite3.h"

void F(){
    try
    {
        // Open a database file
        SQLite::Database    db("test.db");
        
        // Compile a SQL query, containing one parameter (index 1)
        SQLite::Statement   query(db, "SELECT * FROM test WHERE size > ?");
        
        // Bind the integer value 6 to the first parameter of the SQL query
        query.bind(1, 6);
        
        // Loop to execute the query step by step, to get rows of result
        while (query.executeStep())
        {
            // Demonstrate how to get some typed column value
            int         id      = query.getColumn(0);
            const char* value   = query.getColumn(1);
            int         size    = query.getColumn(2);
            
            std::cout << "row: " << id << ", " << value << ", " << size << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
}
// void G(){
//     try
//     {
//         SQLite::Database    db("main.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
//         db.exec("DROP TABLE IF EXISTS test");
//         // Begin transaction
//         SQLite::Transaction transaction(db);

//         db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");

//         int nb = db.exec("INSERT INTO test VALUES (NULL, \"test\")");
//         std::cout << "INSERT INTO test VALUES (NULL, \"test\")\", returned " << nb << std::endl;

//         // Commit transaction
//         transaction.commit();
//     }
//     catch (std::exception& e)
//     {
//         std::cout << "exception: " << e.what() << std::endl;
//     }
// }

int main(){
    // G();
    //F();
    return 0;
}