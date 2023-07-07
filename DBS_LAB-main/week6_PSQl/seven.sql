//check

set serveroutput on
declare
stgpa StudentTable.gpa%TYPE;
roll number(1);
g varchar(2);
begin
	roll:=1;
	<<up>>

	select gpa
	into stgpa
	from StudentTable
	where rollno=roll;
	
	if stgpa>=0 and stgpa<4 then
		g:='F';
	elsif stgpa<5 then
		g:='E';
	elsif stgpa<6 then
		g:='D';
	elsif stgpa<7 then
		g:='C';
	elsif stgpa<8 then
		g:='B';
	elsif stgpa<9 then
		g:='A';
	else
		g:='A+';
	end if;

	dbms_output.put_line('Roll: '||roll||'   GPA: '||stgpa||'   Grade: '||g);
	dbms_output.new_line;


	if roll<=5 then
		GOTO up;	
end;
/