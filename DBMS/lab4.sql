1. For the following relation schema:
employee(employee-name, street, city)
works(employee-name, company-name, salary)
company(company-name, city)
manages(employee-name, manager-name)

mysql> create table employee (
        emp_name varchar(10),
        street varchar(10),
        city varchar(10)
    );
Query OK, 0 rows affected (0.05 sec)

mysql> desc employee;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| emp_name | varchar(10) | YES  |     | NULL    |       |
| street   | varchar(10) | YES  |     | NULL    |       |
| city     | varchar(10) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

=====================================================================

mysql> create table works (
            emp_name varchar(10),
            comp_name varchar(10),
            salary int(10)
        );
Query OK, 0 rows affected (0.04 sec)

mysql> desc works;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| emp_name  | varchar(10) | YES  |     | NULL    |       |
| comp_name | varchar(10) | YES  |     | NULL    |       |
| salary    | int(10)     | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql>
===========================================================================


mysql> create table company (
            comp_name varchar(10),
            city varchar(10)
        );
Query OK, 0 rows affected (0.05 sec)

mysql> desc company
   -> ;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| comp_name | varchar(10) | YES  |     | NULL    |       |
| city      | varchar(10) | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

========================================================================

 create table manages (emp_name varchar(10), manager_name varchar(10));

insert into employee values
("e1", "s1", "c1"),
("e2", "s2", "c2"),
("e3", "s3", "c3"),
("e4", "s1", "c3"),
("e5", "s5", "c3"),
("e6", "s3", "c3")
;

insert into company values  
("co1", "c1"),
("co3", "c2"),
("co2", "c3");

insert into works values
("e1", "co1", 10),
("e2", "co2", 20),
("e3", "co3", 30),
("e4", "co1", 20),
("e5", "co2", 30),
("e6", "co2", 40);

insert into manages values
("e1", "e2"),
("e4", "e5"),
("e6", "e3");


Give an expression in SQL for each of the following queries:
a) Find the names, street address, and cities of residence for all employees who work for
'State Bank Of India' and earn more than $10,000.

SELECT emp_name, street, city FROM employee NATURAL JOIN works WHERE comp_name="co2" AND salary>25;

b) Find the names of all employees in the database who live in the same cities as the
companies for which they work.

SELECT emp_name FROM employee NATURAL JOIN works NATURAL JOIN company WHERE employee.city = company.city;


c) Find the names of all employees in the database who live in the same cities and on the
same streets as do their managers.

SELECT e.emp_name AS "Employee Name", m.emp_name AS "Manager Name"
FROM employee m NATURAL JOIN manages m1, employee e JOIN manages m2 ON (e.emp_name = m2.manager_name)
WHERE e.city = m.city AND e.street=m.street;

d) Find the names of all employees in the database who do not work for 'co1'.
Assume that all people work for exactly one company.

SELECT emp_name FROM employee NATURAL JOIN works WHERE comp_name!="co1";

e) Find the names of all employees in the database who earn more than every employee of
'co2'. Assume that all people work for at most one company.

SELECT emp_name FROM employee NATURAL JOIN works
    WHERE salary > (SELECT MAX(salary) FROM employee NATURAL JOIN works WHERE comp_name="co2");

f) Assume that the companies may be located in several cities. Find all companies
located in every city in which 'co2' is located.

SELECT s.comp_name FROM company s WHERE NOT EXISTS
(
    (SELECT city FROM company x WHERE x.comp_name = 'co2')
    EXCEPT
    (SELECT city FROM company t WHERE s.comp_name = t.comp_name)
);

(SELECT x.city FROM company x WHERE x.comp_name = 'co2') 
NOT IN
(SELECT t.city FROM company t WHERE t.comp_name = 'co1');



SELECT x1.cname FROM 
(SELECT count(*) as cc1, cname FROM 
    (SELECT city FROM company WHERE cname='co1') as a, company WHERE a.city=company.city GROUP BY cname) as x1
WHERE x1.cc1= (SELECT COUNT(city) FROM company WHERE cname='co1') AND x1.cname != 'co1';


g) Find the names of all employees who earn more than the average salary of all
employees of their company. Assume that all people work for at most one company.

SELECT emp_name FROM works a WHERE a.salary > (SELECT AVG(salary) from works b WHERE a.comp_name = b.comp_name);

--  AVG(salary) GROUP BY comp_name;

h) Find the name of the company that has the smallest payroll.

SELECT comp_name FROM works GROUP BY comp_name ORDER BY SUM(salary) LIMIT 1;


-- employee(employee-name, street, city)
-- works(employee-name, company-name, salary)
-- company(company-name, city)
-- manages(employee-name, manager-name)

salary same as one another in same TABLE

SELECT emp_name, salary FROM works a WHERE salary IN (SELECT salary FROM works b WHERE a.emp_name != b.emp_name);

-- select emp_name , salary, count(1) from works GROUP BY salary having count(1) > 1;

employees whose comp name has at least 3 is;

SELECT emp_name FROM works where comp_name like "%i%i%i%";

highest or second highest

SELECT x.emp_name, x.salary FROM works x NATURAL JOIN
(SELECT DISTINCT y.salary FROM works y ORDER BY y.salary DESC LIMIT 2) as T2;


 WHERE salary IN (
    SELECT DISTINCT salary FROM works
    ORDER BY salary DESC LIMIT 2
);

SELECT emp_name, DISTINCT salary FROM works
ORDER BY salary DESC LIMIT 2;