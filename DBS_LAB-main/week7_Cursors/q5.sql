set serveroutput on
declare
g varchar(2);
cursor C is (select * from StudentTable) for update;

begin
	FOR s IN c loop
		if s.gpa>=0 and s.gpa<4 then g:='F';
		elsif s.gpa<5 then g:='E';
		elsif s.gpa<6 then g:='D';
		elsif s.gpa<7 then g:='C';
		elsif s.gpa<8 then g:='B';
		elsif s.gpa<9 then g:='A';
		else g:='A+';
		end if;
		update StudentTable set lettergrade=g where current of c;
	end loop;
end;
/