1)
create table employee
(
    EmpNo number(5),
    EmpName varchar(20),
    Gender char(1),
    Salary number(7),
    Address varchar(20),
    DNo number(5)
);

alter table employee add constraint employee_pk primary key(EmpNo);
alter table employee modify empname varchar(20) not null;
alter table employee modify gender char(1) not null check(Gender in ('M','F'));
alter table employee modify address varchar(20) not null;
alter table employee modify salary number(7) not null;
***********************************************************************************************

2)
create table department
(
    DeptNo number(5),
    deptname varchar(10),
    Location varchar(20)
);

alter table department add constraint dept_pk primary key(deptno);
alter table department add constraint dept_uq unique(deptname);
***********************************************************************************************

3)
alter table employee
add foreign key(dno) references department(deptno);
***********************************************************************************************

4)
insert into department values(123,'CSE','AB5');
insert into department values(124,'ICT','AB5');
insert into employee values(100,'aaa','M',60000,'siliguri',123);
insert into employee values(101,'bbb','F',80000,'goa',124);
***********************************************************************************************

5)
insert into department values(123,'EEE','AB5');

insert into department values(123,'EEE','AB5')
*
ERROR at line 1:
ORA-00001: unique constraint (DBL62.DEPT_PK) violated
-------------------------------------------------------------------
insert into employee values(110,NULL,'F',80000,'goa',124);

insert into employee values(110,NULL,'F',80000,'goa',124)
                                *
ERROR at line 1:
ORA-01400: cannot insert NULL into ("DBL62"."EMPLOYEE"."EMPNAME")
***********************************************************************************************

6)
DELETE FROM DEPARTMENT WHERE DEPTNO=123;

DELETE FROM DEPARTMENT WHERE DEPTNO=123
*
ERROR at line 1:
ORA-02292: integrity constraint (DBL62.SYS_C00183751) violated - child record
found
***********************************************************************************************

7)
ALTER TABLE EMPLOYEE DROP CONSTRAINT SYS_C00183751;
ALTER TABLE EMPLOYEE ADD FOREIGN KEY(DNO) REFERENCES DEPARTMENT(DEPTNO) ON DELETE CASCADE;
***********************************************************************************************

8)
ALTER TABLE EMPLOYEE MODIFY (constraint cdefault SALARY NUMBER(7) DEFAULT 10000);
***********************************************************************************************
rename department to department1;
***********************************************************************************************

//primary key, check, foreign key, unique->these are table level constraints. therefore, alter+add can be used but for others i.e column level constraints, modify needs to be used

//ALWAYS name the contraints addition or modification to change it later. if forget to do that then, violate it. o/p shows a value starting from SYS. that is the name of the constraint.