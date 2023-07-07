set serveroutput on
declare
cursor C is (select * from Studenttable);

begin
	FOR BK IN c loop
			dbms_output.put_line(BK.GPA);
	end loop;
end;
/