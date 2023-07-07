create or replace 
procedure course_popular(dname varchar) is
	cursor c2(d varchar) is select count(*) coun,course_id from course natural join takes where dept_name=d group by course_id;
	mcourse varchar(20);
	m integer;
begin
	m:=-1;

	for i in c2(dname) loop
		if m<i.coun then	
			m:=i.coun;
			mcourse:=i.course_id;
		end if;	
	end loop;

	dbms_output.put_line('Most popular course of '||dname||' is '||mcourse);
end;
 /