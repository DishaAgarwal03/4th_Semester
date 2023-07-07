--dispq5
create or replace 
function dispq5(a number) 
return number as
	sq number;
begin
	sq:= a*a;
	return sq;
end;
 /