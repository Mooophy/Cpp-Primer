#include "andquery.h"
#include <memory>
#include <algorithm>
/**
 * @brief AndQuery::eval
 * @return  the intersection of its operands' result sets
 */
QueryResult AndQuery::eval(const TextQuery &text) const
{
    //! virtual calls through the Query operands to get result sets for the operands
    QueryResult left = lhs.eval(text), right = rhs.eval(text);

    //! set to hold the intersection of the left and right
    std::shared_ptr<std::set<line_no>>
                   ret_lines = std::make_shared<std::set<line_no>>();

    //! writes the intersection of two ranges to a destination iterator
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}
