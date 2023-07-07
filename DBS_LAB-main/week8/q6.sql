--q6
set serveroutput on
declare
cursor c1 is (select dept_name from department);
begin
	for i in c1 loop
		dbms_output.put_line('Highest paid instructor of '||i.dept_name||' is '||department_highest(i.dept_name));
	end loop;    
end;
/
