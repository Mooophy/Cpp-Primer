//@Squawk09

//18.18
//Given the following typical definition of swap 13.3 (p.157) determine which version of swap is used
//if mem1 is a string. What if mem1 is an int?
//Explain how name lookup works in both cases.

void swap(T v1,Tv2)
{
    using std::swap;
    swap(vq.mem1,v2.mem1);
    //swap remaining members of type T
}

//Swap is a template function defined by the standard library.
//By stating we are using std::swap all the following uses of swap in the scope of the function will
//look for the matching template for its argument types in the standard library.
//If mem1 is a string the program will use the standard library function that has string arguments.
//If mem1 is int, it will use the standard library template version with int arguments.


//18.19
//What if the call to swap was std::swap(v1.mem1,v2.mem1);

//The function would use the matching std version of swap for that specific call.
//It would not necessarily use the matching standard library version of swap for the following calls.
