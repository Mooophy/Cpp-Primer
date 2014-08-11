#include "notquery.h"
#include <memory>
/**
 * @brief NotQuery::eval
 * @return the lines not in its operand's result set
 */
QueryResult NotQuery::eval(const TextQuery &text) const
{
    //! virtual call to eval through the Query operand
    QueryResult result = query.eval(text);

    //! start out with an empty result set
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
