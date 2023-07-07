--q4

create table client_master(
	client_no number(4) primary key,
	name varchar(10),
	address varchar(20),
	bal_due number(8,2)
);

insert into client_master values(1234, 'Nia', 'Goa', 20000);
insert into client_master values(1235, 'John', 'Goa', 60000);

create table auditclient(
	client_no number(4),
	name varchar(10),
	bal_due number(8,2),
	operation varchar(6),
	userid varchar(5),
	opdate date
);

create or replace trigger t4
before                                
	delete or update                          
on client_master
for each row
begin
	case
	when updating then
		insert into auditclient values(:OLD.client_no, :OLD.name, :OLD.bal_due, 'Update', 1111, current_date);
	when deleting then
		insert into auditclient values(:OLD.client_no, :OLD.name, :OLD.bal_due, 'Delete', 1111, current_date);
	end case;

end;
/

update client_master set bal_due=70000 where client_no=1235;
delete from client_master where client_no=1234;

select * from auditclient;




-------------------------------------------------------------------------------------
Table created.


1 row created.


1 row created.


Table created.


Trigger created.


1 row updated.


1 row deleted.


 CLIENT_NO NAME          BAL_DUE OPERAT USERI OPDATE
---------- ---------- ---------- ------ ----- ---------
      1235 John            60000 Update 1111  21-APR-23
      1234 Nia             20000 Delete 1111  21-APR-23
