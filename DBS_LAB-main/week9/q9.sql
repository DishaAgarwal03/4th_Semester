
CREATE OR REPLACE TRIGGER instrInsert
BEFORE INSERT ON instructor
for each row
BEGIN
IF LENGTH(TRIM(TRANSLATE(:NEW.name, 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', ' '))) > 0 THEN
    RAISE_APPLICATION_ERROR(-20100,'Name must contain only alphabets');
ELSE
     IF :NEW.salary < 1 THEN
        RAISE_APPLICATION_ERROR(-20100,'Salary must be greater than 0');
	end if;
END IF;
END;
/