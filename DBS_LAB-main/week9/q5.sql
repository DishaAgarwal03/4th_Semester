--q5

savepoint S1;

drop view advisor_student;
select * from advisor;

create view advisor_student as
select s.id s_id, i.id i_id, s.name s_name, i.name i_name
from advisor a, student s, instructor i
where a.s_id=s.id and a.i_id=i.id;

create or replace trigger t5
instead of delete on advisor_student                         
for each row
begin
	delete from advisor where s_id= :OLD.s_id and i_id= :OLD.i_id;
end;
/

delete from advisor_student where i_id='10101';
select * from advisor;
