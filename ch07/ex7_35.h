#ifndef EX7_35_H_INCLUDED
#define EX7_35_H_INCLUDED


typedef std::string Type;
Type initVal();

class Exercise
{
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};


Exercise::Type Exercise::initVal()
{
  // todo
    return 0.0;
}

Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}
#endif // TEST_H_INCLUDED
