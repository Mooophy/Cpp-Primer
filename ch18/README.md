##Exercise 18.4

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
