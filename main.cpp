#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>
#include <time.h>


 #include <postgresql/libpq-fe.h>
#include <pqxx/pqxx>


// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
int main()
{
    std::cout<<"\n\n..... Program Starting ........\n";

    std::cout << "\ncurrentDateTime()=" << currentDateTime() << std::endl;

    std::cout<<"\n\n Program Shutting down\n\n";
     pqxx::connection c("host=localhost dbname=TM_Test user=postgres password=password");
  pqxx::work txn{c};

  // Normally we'd query the DB using txn.exec().  But for querying just one
  // single value, we can use txn.query_value() as a shorthand.
  //
  // Use txn.quote() to escape and quote a C++ string for use as an SQL string
  // in a query's text.
  std::string RowInfo = "temp";// txn.exec("SELECT * FROM \"UserLogin\" ");

  std::cout << "QueryData" << RowInfo << '\n';

  // Update the employee's salary.  Use exec0() to perform a query and check
  // that it produces an empty result.  If the result does contain data, it
  // will throw an exception.
  //
  // The ID is an integer, so we don't need to escape and quote it when using
  // it in our query text.  Just convert it to its PostgreSQL string
  // representation using to_string().
//   txn.exec(
//     "UPDATE EMPLOYEE "
//     "SET salary = salary + 1 "
//     "WHERE id = " + pqxx::to_string(employee_id));

  // Make our change definite.
  txn.commit();
    return 0;
}



