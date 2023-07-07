set serveroutput on
declare
cursor C is (select * from Studenttable);
stu studenttable%ROWTYPE;
begin
	OPEN C;
		loop
			fetch C into stu;
			exit when C%NOTFOUND;
			dbms_output.put_line(stu.GPA);
		end loop;
	CLOSE C;
end;
/