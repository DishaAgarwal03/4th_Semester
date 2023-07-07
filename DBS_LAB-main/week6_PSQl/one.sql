set serveroutput on
declare
stgpa StudentTable.gpa%TYPE;
begin
	select gpa
	into stgpa
	from StudentTable
	where rollno='&roll';
	dbms_output.put_line('GPA of given student is '||stgpa);
end;
/