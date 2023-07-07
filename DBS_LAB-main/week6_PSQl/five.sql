set serveroutput on
declare
stgpa StudentTable.gpa%TYPE;
N number;
I number;
g varchar(2);
begin
    select count(*) into N from StudentTable;
    I := 1;
    WHILE I <= N
    LOOP
        select gpa
	  into stgpa
	  from StudentTable
	  where rollno=I;

        if stgpa>=0 and stgpa<4 then
		  g:='F';
	  elsif stgpa<5 then
		  g:='E';
	  elsif stgpa<6 then
		  g:='D';
	  elsif stgpa<7 then
		  g:='C';
	  elsif stgpa<8 then
		  g:='B';
	  elsif stgpa<9 then
		  g:='A';
	  else
		  g:='A+';
	  end if;

	  UPDATE StudentTable SET LetterGrade = g WHERE RollNo = I;

        I := I + 1;
    END LOOP;
END;
/