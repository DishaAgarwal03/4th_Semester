set serveroutput on
declare
doi date;
dor date;
d number(3);
f number(2);
begin
	doi:='&date_of_issue';
	dor:='&date_of_return';
	d:=dor-doi;
	
	if d<=7 then
		f:=0;
	elsif d<=15 then
		f:=d-7;
	elsif d<=30 then
		f:=8+(d-15)*2;
	else
		f:=43;
	end if;
	dbms_output.put_line('Fine: '||f);
end;
/