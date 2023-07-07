--q2

create table old_data_instructor
(
	ID VARCHAR(5),
 	NAME VARCHAR(20),
	DEPT_NAME VARCHAR(20),
      SALARY NUMBER(8,2)
);

create or replace trigger t2
before                                
	update                          
on instructor
for each row
begin
	insert into old_data_instructor values(:OLD.id, :OLD.name, :OLD.dept_name, :OLD.salary);  
end;
/

------------------------------------------------------------------------------------------------
update instructor set salary=90000 where id='10101';

1 row updated.

SQL> select * from old_data_instructor;

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
10101 Srinivasan           Comp. Sci.                65000
