echo on 
Sales_data < data/add_item

for %%i in (compounddecls.exe convs.exe dbl_ptr.exe 
		   decl-ex.exe escape.exe inits.exe 
		   literals.exe ref-ex.exe 
		   scope_levels.exe unsigned.exe ) do %%i
