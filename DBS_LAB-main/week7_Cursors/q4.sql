/*
DELETE IF CS-101 AND CREDITS<30(DIFFERENT FROM Q4)

set serveroutput on
declare
cursor C is (select * from takes where course_id='CS-101' and ID in (Select ID from student where tot_cred<30)) for update;

begin
	FOR s IN c loop
			delete from takes where current of c;
			if c%FOUND THEN
				dbms_output.put_line(c%ROWCOUNT||' rows deleted');
			end if;
	end loop;
end;
/
*/

SET SERVEROUTPUT ON

DECLARE
    CURSOR C IS SELECT * FROM takes WHERE course_id = 'CS-101';
    creds student.tot_cred%TYPE;
BEGIN
    FOR I IN C
    LOOP
	  dbms_output.put_line(I.ID||'   '||I.COURSE_ID);
        SELECT tot_cred INTO creds FROM student WHERE ID = I.ID;
        IF creds < 40 THEN
            DELETE FROM takes WHERE ID = I.ID AND course_id = I.course_id;
        END IF;
    END LOOP;
END;
/