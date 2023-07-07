--q3

CREATE OR REPLACE TRIGGER q3
BEFORE INSERT or update ON instructor
for each row
DECLARE
sal NUMBER;
budg NUMBER;
BEGIN
IF LENGTH(TRIM(TRANSLATE(:NEW.name, 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', ' '))) > 0 THEN
    RAISE_APPLICATION_ERROR(-20100,'Name must contain only alphabets');
ELSE
    IF :NEW.salary < 1 THEN
        RAISE_APPLICATION_ERROR(-20100,'Salary must be greater than 0');
    ELSE
        SELECT SUM(salary) INTO sal FROM instructor WHERE dept_name = :NEW.dept_name;
        SELECT budget INTO budg FROM department WHERE dept_name = :NEW.dept_name;
        IF sal + :NEW.salary > budg THEN
            RAISE_APPLICATION_ERROR(-20100,'Not enough department budget'); 
	  ELSE
		dbms_output.put_line('Inserted'); 
        END IF;
    END IF;
END IF;
END;
/