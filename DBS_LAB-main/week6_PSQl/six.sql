set serveroutput on
declare
stgpa StudentTable.gpa%TYPE;
maxgpa number(2,1);
maxroll number(3);
begin
	maxroll:=1;
	FOR roll IN 1..5 LOOP
	select gpa
	into stgpa
	from StudentTable
	where rollno=roll;
	
	if roll=1 then
		maxgpa:=stgpa;	
	elsif maxgpa<stgpa then
		maxgpa:=stgpa;
		maxroll:=roll;
	end if;
	END LOOP;
	dbms_output.put_line('Roll: '||maxroll||'  Max GPA: '||maxgpa);
end;
/