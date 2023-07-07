--q5
set serveroutput on
declare
begin
	dbms_output.put_line('Square is: '||dispq5('&Number'));    
end;
/
