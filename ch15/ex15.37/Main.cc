#include "Query"

int
main()
{
    TextQuery   file("15_37.txt");
    Query       q2("Daddy");
    print(cout,q2.eval(file));

    Query q3 = ~Query("Alice"); 
    print(cout,q3.eval(file));

    Query q4 = Query("hair") | Query("Alice");
    print(cout,q4.eval(file));

    Query q5 = Query("hair") & Query("Alice");
    print(cout,q5.eval(file));
    return 0;
}
