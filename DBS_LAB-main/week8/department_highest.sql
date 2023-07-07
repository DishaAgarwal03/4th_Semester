create or replace 
function department_highest(dname varchar) return varchar as
	cursor c2(d varchar) is select salary,name from instructor where dept_name=d;
	mname varchar(20);
	m integer;
begin
	m:=0;

	for i in c2(dname) loop
		if m<i.salary then	
			m:=i.salary;
			mname:=i.name;
		end if;	
	end loop;

	return mname;
end;
 /