@ C:\Users\Student\Desktop\210905412_DBS\week2\University.sql
@ C:\Users\Student\Desktop\210905412_DBS\week2\smallRelations.sql


9)
select name,dept_name
from student;

NAME                 DEPT_NAME
-------------------- --------------------
Zhang                Comp. Sci.
Shankar              Comp. Sci.
Brandt               History
Chavez               Finance
Peltier              Physics
Levy                 Physics
Williams             Comp. Sci.
Sanchez              Music
Snow                 Physics
Brown                Comp. Sci.
Aoi                  Elec. Eng.

NAME                 DEPT_NAME
-------------------- --------------------
Bourikas             Elec. Eng.
Tanaka               Biology

******************************************************************************************

10)
select * from instructor where dept_name='Comp. Sci.';

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
10101 Srinivasan           Comp. Sci.                65000
45565 Katz                 Comp. Sci.                75000
83821 Brandt               Comp. Sci.                92000

******************************************************************************************

11)
select title from course where dept_name='Comp. Sci.' and credits=3;

TITLE
--------------------------------------------------
Robotics
Image Processing
Database System Concepts

******************************************************************************************

12)why are they different??
/////////////
select course_id,title from student natural join course where id=12345;

COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
CS-190   Game Design
CS-315   Robotics
CS-319   Image Processing
CS-347   Database System Concepts

////////////
select course_id,title from takes natural join course where id=12345;

COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
CS-190   Game Design
CS-315   Robotics
CS-347   Database System Concepts

******************************************************************************************

13)
select * from instructor where salary between 40000 and 90000;

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
10101 Srinivasan           Comp. Sci.                65000
12121 Wu                   Finance                   90000
15151 Mozart               Music                     40000
32343 El Said              History                   60000
33456 Gold                 Physics                   87000
45565 Katz                 Comp. Sci.                75000
58583 Califieri            History                   62000
76543 Singh                Finance                   80000
76766 Crick                Biology                   72000
98345 Kim                  Elec. Eng.                80000

******************************************************************************************

14) 
select distinct instructor.id from instructor, teaches where instructor.id not in teaches.id;

ID
-----
22222
58583
12121
76766
33456
83821
10101
15151
32343
45565
98345

ID
-----
76543

check what's wrong->
select distinct instructor.id from instructor except select distinct instructor.id from instructor natural join teaches;

******************************************************************************************

<<<<<do 15-17>>>>>


******************************************************************************************

18)
select name from instructor where dept_name like '%ch%';

no rows selected

*******************************************************************************************

19)
select name,length(name) length from student;

NAME                     LENGTH
-------------------- ----------
Zhang                         5
Shankar                       7
Brandt                        6
Chavez                        6
Peltier                       7
Levy                          4
Williams                      8
Sanchez                       7
Snow                          4
Brown                         5
Aoi                           3

NAME                     LENGTH
-------------------- ----------
Bourikas                      8
Tanaka                        6

*******************************************************************************************

20)
select dept_name,substr(dept_name,3,3) from department;

DEPT_NAME            SUB
-------------------- ---
Biology              olo
Comp. Sci.           mp.
Elec. Eng.           ec.
Finance              nan
History              sto
Music                sic
Physics              ysi

*******************************************************************************************

21)
select upper(name) name from instructor;

NAME
--------------------
SRINIVASAN
WU
MOZART
EINSTEIN
EL SAID
GOLD
KATZ
CALIFIERI
SINGH
CRICK
BRANDT

NAME
--------------------
KIM

********************************************************************************************

22)
<<<<<<DO 22>>>>>>

********************************************************************************************

23)
select salary, round(salary/3,-2) from instructor;

    SALARY ROUND(SALARY/3,-2)
---------- ------------------
     65000              21700
     90000              30000
     40000              13300
     95000              31700
     60000              20000
     87000              29000
     75000              25000
     62000              20700
     80000              26700
     72000              24000
     92000              30700

    SALARY ROUND(SALARY/3,-2)
---------- ------------------
     80000              26700