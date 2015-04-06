- **Assignment operator** must, and ordinarily **compound-assignment** operators
should, be defined as members.
- The **subscript operator** must be a member function. it usually should define two versions: one that returns **a plain reference** and the other that is a **`const` member and returns a reference to `const`**.
- To be consistent with the built-in operators, the postfix operators should return the old (unincremented or undecremented) value. That value is returned **as a value, not a reference**.
