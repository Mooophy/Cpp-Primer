#include <algorithm>
#include "query.h"
/**
 * @brief AndQuery::eval
 * @return the intersection of its operands' result sets
 */
QueryResult AndQuery::eval(const TextQuery &text) const
{
    // virtual calls through the Query operands to get result sets for the operands
    QueryResult left = lhs.eval(text), right = rhs.eval(text);

    // set to hold the intersection of the left and right
    std::shared_ptr<std::set<line_no>>
                   ret_lines = std::make_shared<std::set<line_no>>();

    // writes the intersection of two ranges to a destination iterator
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}

/**
 * @brief OrQuery::eval
 * @return the union of its operands' result sets
 */
QueryResult OrQuery::eval(const TextQuery &text) const
{
    QueryResult right = rhs.eval(text), left= lhs.eval(text);

    // copy the left-hand operand into the result set
    std::shared_ptr<std::set<line_no>> ret_lines =
            std::make_shared<std::set<line_no>>(left.begin(), left.end());

    // inert lines from the right-hand operand
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}

/**
 * @brief NotQuery::eval
 * @return the lines not in its operand's result set
 */
QueryResult NotQuery::eval(const TextQuery &text) const
{
    // virtual call to eval through the Query operand
    QueryResult result = query.eval(text);

    // start out with an empty result set
    std::shared_ptr<std::set<line_no>>
            ret_lines = std::make_shared<std::set<line_no>>();

    std::set<TextQuery::line_no>::iterator
            begin = result.begin(),
            end   = result.end();

    StrBlob::size_type sz = result.get_file().size();

    for(std::size_t n = 0; n != sz; ++n)
    {
        if(begin == end || *begin != n)
            ret_lines->insert(n);
        else if (begin != end)
            ++begin;
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}