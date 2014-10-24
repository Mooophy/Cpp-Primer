#include "Item_data.h"

Book_data trans, total;

int Main()
{
  // Get the first data from input
    total.GetData();

  // Get the following data from input
    while (trans.GetData())
    {
      // If the following data is same book with the previous one, then calculate the revenue and aver. price
        if (trans.book_no == total.book_no)
        {
            total.revenue += trans.revenue;
            total.sale_num += trans.sale_num;
        }
        // If not the same book, show the sum and aver. result of last book
        // and assign the different new book info to total object
        else
        {
            total.Show_data();
            total.Set_data(trans);
        }
    }

    return 0;
}
