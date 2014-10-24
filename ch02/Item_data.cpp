#include "Item_data.h"

Book_data trans, total;

int main()
{
	total.GetData();

	while (trans.GetData())
	{

		if (trans.book_no == total.book_no)
		{
			total.revenue += trans.revenue;
			total.sale_num += trans.sale_num;
		}
		else
		{
			total.Show_data();
			total.Set_data(trans);
		}
	}

	return 0;
}
