##Exercise 18.1

> What is the type of the exception object in the following throws?
> 
> **(a)**`range_error r("error");`
> `throw r`;
> **(b)**`exception *p = &r;`
> `throw *P;`

>What would happen if the `throw` in **(b)** were written as `throw p`?

	The type of the exception object in (a) is range_error which is used to report range errors in internal computations.
	The type of the exception object in (b) is exception.
	If the "throw" in (b) were written as "throw p", there will be a runtime error.


##Exercise 18.2

> Explain what happens if an exception occurs at the indicated point:


```cpp
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	// exception occurs here
}
```

The space "p" points will not be free. There will be a memory leak.

##Exercise 18.3

##Exercise 18.21

>Explain the following declarations. Identify any that are in error and explain why they are incorrect:
>**(a)**
```cpp
class CAD{};
class Vehicle{};

class CADVehicle : public CAD, Vehicle{};
```


CAD Vehicle publicly inherits from CAD and privaetely inherits from Vehicle.  CADVehicle gets
all the  public and private methods that Vehicle has but cant be cast to a Vehicle argument.
It is an "inaccessible" base.
for example

```cpp
CadVehicle example;

void foo(Vehicle){/*do something*/};

foo(CADVehicle);//will not work, will work if Vehicle were public
```

>**(b)**
```cpp
class DBList: public List,public List {/*do something*/};
```

Error because you are trying to derive from the same base class twice.  If two different 
libraries or header files define the same named class,you need to specify with
a scope resolution operator, i.e. headerfile_name::List.

>**(c)**
```cpp
class iostream : public istream, public ostream{/*do something*/};
```


Ok. 
