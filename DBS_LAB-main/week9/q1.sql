--q1

create table log_change_Takes
(
	time_of_change timestamp,
	ID VARCHAR(5),
 	COURSE_ID VARCHAR(8),
 	SEC_ID VARCHAR(8),
 	SEMESTER VARCHAR(6),
 	YEAR NUMBER(4),
      GRADE VARCHAR(2)
);


create or replace trigger t1
after                                
	update                          
on takes
for each row
begin
	insert into log_change_Takes values(current_timestamp, :NEW.id, :NEW.course_id, :NEW.sec_id, :NEW.semester, :NEW.year, :NEW.grade);  
end;
/

---------------------------------------------------------------------------------------
update takes set grade='A' where id='45678';

1 row updated.

SQL> select * from log_change_takes;

TIME_OF_C ID    COURSE_I SEC_ID   SEMEST       YEAR GR
--------- ----- -------- -------- ------ ---------- --
21-APR-23 45678 CS-319   1        Spring       2010 A

