/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       31  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.34: For the expression built in Figure 15.3 (p. 638):
//     (a) List the constructors executed in processing that expression.
//          Query q = Query("fiery") & Query("bird") | Query("wind");
//      1:  Query::Query(const std::string& s) where s == "fiery","bird" and "wind"
//      2:  WordQuery::WordQuery(const std::string& s) where s == "fiery","bird" and "wind"
//      3:  AndQuery::AndQuery(const Query& left, const Query& right);
//      4:  BinaryQuery(const Query&l, const Query& r, std::string s);
//      5:  Query::Query(std::shared_ptr<Query_base> query) 2times
//      6:  OrQuery::OrQuery(const Query& left, const Query& right);
//      7:  BinaryQuery(const Query&l, const Query& r, std::string s);
//      8:  Query::Query(std::shared_ptr<Query_base> query) 2times
//
//     (b) List the calls to rep that are made from cout << q.
//      query.rep() inside the operator <<()
//      q->rep()    insede the member function rep()
//      OrQuery::rep() which is inherited from BinaryQuery
//      BinaryQuery::rep()
//      Query::rep() for lhs and rhs
//          for rhs which is a WordQuery : WordQuery::rep() where query_word("wind") is returned.
//          for lhs which is an AndQuery:
//              AndQuery::rep()     --which is inherited from BinaryQuery
//              BinaryQuer::rep()
//                  for rhs: WordQuery::rep()   where query_word("fiery") is returned
//                  for lhs: WordQuery::rep()   where query_word("bird" ) is returned
//
//     (c) List the calls to eval made from q.eval().
//      q.eval()
//      q->rep()    where q is a pointer to OrQuary
//      QueryResult eval(const TextQuery& )const override -- is called but this one has not been defined yet.
//
// Exercise 15.35:
// Implement the Query and Query_base classes, including a definition of
// rep but omitting the definition of eval.
//
// Exercise 15.36:
// Put print statements in the constructors and rep members and run your code
// to check your answers to (a) and (b) from the first exercise.
//
//      Query q = Query("fiery") & Query("bird") | Query("wind");
//
//     WordQuery::WordQuery(wind)
//     Query::Query(const std::string& s) where s=wind
//     WordQuery::WordQuery(bird)
//     Query::Query(const std::string& s) where s=bird
//     WordQuery::WordQuery(fiery)
//     Query::Query(const std::string& s) where s=fiery
//     BinaryQuery::BinaryQuery()  where s=&
//     AndQuery::AndQuery()
//     Query::Query(std::shared_ptr<Query_base> query)
//     BinaryQuery::BinaryQuery()  where s=|
//     OrQuery::OrQuery
//     Query::Query(std::shared_ptr<Query_base> query)
//     Press <RETURN> to close this window...
//
//
//
//      std::cout << q <<std::endl;
//
//     Query::rep()
//     BinaryQuery::rep()
//     Query::rep()
//     WodQuery::rep()
//     Query::rep()
//     BinaryQuery::rep()
//     Query::rep()
//     WodQuery::rep()
//     Query::rep()
//     WodQuery::rep()
//     ((fiery & bird) | wind)
//     Press <RETURN> to close this window...
//
// Exercise 15.37:
// What changes would your classes need if the derived classes had
// members of type shared_ptr<Query_base> rather than of type Query?
//      not done
//
// Exercise 15.38:
// Are the following declarations legal?
// If not, why not? If so, explain what the declarations mean.
//     BinaryQuery a = Query("fiery") & Query("bird");
//          Illegal. Because BinaryQuery is an abstract class.
//     AndQuery b = Query("fiery") & Query("bird");
//          Illegal. Because operator & returns a Query which can not convert to an AndQuery object.
//     OrQuery c = Query("fiery") & Query("bird");
//          Illegal. Because operator & returns a Query which can not convert to an OrQuery object.
//


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"



int main()
{

    return 0;
}
