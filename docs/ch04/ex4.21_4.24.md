##Exercise 4.23
>The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

Operator Precedence: `?:` < `+`
Fix it:
```cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

##Exercise 4.24
>Our program that distinguished between high pass, pass,
and fail depended on the fact that
the conditional operator is right associative.
Describe how that operator would be evaluated
if the operator were left associative.

if the operator were left associative.
```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```
would same as :
```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```
if `grade > 90`, first conditional operator's result is `high pass`. so the finalgrade is always fail.
It's contradictory obviously.
