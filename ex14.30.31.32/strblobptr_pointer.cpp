#include "strblobptr_pointer.h"


StrBlobPtr&
StrBlobPtr_pointer::operator *()
{
    return *(this->pointer);
}

StrBlobPtr*
StrBlobPtr_pointer::operator ->()
{
    return & this->operator *();
}
