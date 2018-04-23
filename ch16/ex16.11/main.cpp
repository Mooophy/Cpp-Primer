template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
//              ^~~~~~~~
//  use of class template 'ListItem' requires template arguments; argument deduction not allowed in function prototype
//  Fix:
//  void insert(ListItem<elemType> *ptr, elemType value);


private:
    ListItem *front, *end;
//  ^~~~~~~~
//  use of class template 'ListItem' requires template arguments; argument deduction not allowed in non-static class member
//  Fix:
//  ListItem<elemType> *front, *end;
}
