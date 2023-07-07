--q3
set serveroutput on
declare
cursor c1 is (select dept_name from department);
begin
	for i in c1 loop
		course_popular(i.dept_name);
	end loop;    
end;
/
