//
//  ex9_32.cpp
//  Exercise 9.32
//
//  Created by pezy on 12/3/14.
//
//  @Brief  In the program on page 354 would it be legal to write the call to insert as follows?
//          If not, why not?
//          iter = vi.insert(iter, *iter++);
//  @Answer the statement is illegal, because as said in Standard [5.2.2] :
//          "The order of evaluation of arguments is unspecified."
//          As a result, after entering function insert,
//          iter could be its original value or original value + 1 or even anything else,
//          depending on how compiler implemented.
//  @Discuss    https://github.com/Mooophy/Cpp-Primer/issues/125

int main()
{
    return 0;
}
