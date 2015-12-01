#include <iostream>
#include <vector>

using std::vector; using std::cout;

bool is_prefix(vector<int> v1, vector<int> v2)
{
    //If vector size of v1 is larger than v2, swap their values.
	if (v1.size() > v2.size())
	{
		vector<int> tmp = v1; // Initializing temporary vector to hold v1 vector
		v1 = v2;
		v2 = tmp;
	}
	// Using vector iterators to compare elements of smallest to largest vector
	for (auto b1 = v1.cbegin(), b2 = v2.cbegin(); b1 < v1.cend(); ++b1, ++b2)
	{
	    // If vector elements doesn't match return false
		if (*b1 != *b2) return false;
	}
	// If vector elements match return true
	return true;
}

int main()
{
    vector<int> iVector1{ 0, 1, 1, 2 };  
    vecctor<int> iVector2{ 0, 1, 1, 2, 3, 5, 8 };  
	
	// Using ternary operator because it's shorter than if-else conditionals
	cout << (is_prefix(iVector1, iVector2) ? "Yes\n" : "No\n");
	
	return 0;
}
