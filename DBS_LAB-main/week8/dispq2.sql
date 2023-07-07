--dispq2
create or replace 
procedure dispq2(dname varchar) is
	cursor c1(d varchar) is select id,name from instructor where dept_name=d;
	cursor c2(d varchar) is select course_id,title from course where dept_name=d;
begin

	dbms_output.put_line('ID		    NAME');
	for i in c1(dname) loop
		dbms_output.put_line(i.id||'		'||i.name);
	end loop;

	dbms_output.put_line('COURSE_ID		  TITLE');
	for i in c2(dname) loop
		dbms_output.put_line(i.course_id||'		'||i.title);
	end loop;

end;
 /