
//Exercise 13.4: Assuming Point is a class type with a public copy constructor, 
//identify each use of the copy constructor in this program fragment:

Point global;
Point foo_bar(Point arg)
{
    Point local = arg/*copy constructor*/, *heap = new Point(global/*copy constructor*/);
    *heap = local;
    Point pa[ 4 ] = { local, *heap };//copy constructor
    return *heap;//copy constructor
}
