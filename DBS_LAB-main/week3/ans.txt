1) 
select course_id from section where semester='Fall' and year=2009
union
select course_id from section where semester='Spring' and year=2010;

COURSE_I
--------
CS-101
CS-315
CS-319
CS-347
FIN-201
HIS-351
MU-199
PHY-101

********************************************************************************

2)
select course_id from section where semester='Fall' and year=2009
intersect 
select course_id from section where semester='Spring' and year=2010;

COURSE_I
--------
CS-101

********************************************************************************

3)
select course_id from section where semester='Fall' and year=2009
minus
select course_id from section where semester='Spring' and year=2010;]

COURSE_I
--------
CS-347
PHY-101

********************************************************************************

4)
select distinct title from course c, takes t where c.course_id not in t.course_id;

TITLE
--------------------------------------------------
Intro. to Biology
Database System Concepts
Genetics
Music Video Production
Physical Principles
Investment Banking
World History
Game Design
Image Processing
Intro. to Digital Systems
Intro. to Computer Science
Computational Biology
Robotics

********************************************************************************

5)
select course_id from section where semester='Fall' and year=2009
and course_id in
(select course_id from section where semester='Spring' and year=2010);

COURSE_I
--------
CS-101

********************************************************************************

6)
select count(distinct id) from takes
where course_id in
(select course_id from teaches where id=10101);

COUNT(DISTINCTID)
-----------------
                6

********************************************************************************

7)
select course_id from section where semester='Fall' and year=2009
and course_id not in
(select course_id from section where semester='Spring' and year=2010);

COURSE_I
--------
CS-347
PHY-101

********************************************************************************

8)
select name from student where name in
(select name from instructor);

NAME
--------------------
Brandt

********************************************************************************

9)
select name,salary from instructor
where salary> some
(select salary from instructor where dept_name='Biology');

NAME                     SALARY
-------------------- ----------
Einstein                  95000
Brandt                    92000
Wu                        90000
Gold                      87000
Kim                       80000
Singh                     80000
Katz                      75000

********************************************************************************

10)

select name,salary from instructor
where salary> all
(select salary from instructor where dept_name='Biology');

NAME                     SALARY
-------------------- ----------
Katz                      75000
Singh                     80000
Kim                       80000
Gold                      87000
Wu                        90000
Brandt                    92000
Einstein                  95000

********************************************************************************

11)
select dept_name,avg(salary) from instructor 
group by dept_name
having avg(salary)>= all 
(select avg(salary) from instructor group by dept_name);

DEPT_NAME            AVG(SALARY)
-------------------- -----------
Physics                    91000

********************************************************************************

12)
select dept_name,budget from department
where budget < (select avg(salary) from instructor);

DEPT_NAME                BUDGET
-------------------- ----------
History                   50000
Physics                   70000

********************************************************************************

13)
select course_id from section s
where semester='Fall' and year=2009 and
exists (select course_id from section r
where semester='Spring' and year=2010 and s.course_id=r.course_id);

********************************************************************************

14) ???



********************************************************************************

15)
select course_id from course c
where 1>=(select count(course_id)
from section s
where s.course_id=c.course_id and s.year=2009);

COURSE_I
--------
BIO-101
BIO-301
BIO-399
CS-101
CS-315
CS-319
CS-347
EE-181
FIN-201
HIS-351
MU-199
PHY-101

********************************************************************************

16) check
select distinct id from takes t
where 2<=(select count(course_id)
from takes s natural join course c
where t.id=s.id and dept_name='Comp. Sci.');

ID
-----
00128
98765
12345
54321
76543
45678

********************************************************************************

17)
select dept_name, avg_salary from
(select dept_name, avg(salary) avg_salary
from instructor
group by dept_name)
where avg_salary>42000;


********************************************************************************

18)



********************************************************************************

19)



********************************************************************************

20)
