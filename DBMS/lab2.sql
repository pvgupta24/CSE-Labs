=========================================================================
=========================================================================

Name : Praveen Kumar Gupta
Roll No : 16CO235
Date : 28/08/2018 (Tuesday)


=========================================================================
=========================================================================

References :
https://gist.github.com/hofmannsven/9164408
https://www.w3schools.com/sql/sql_datatypes.asp


=========================================================================
=========================================================================
Login : 
telnet 10.100.12.43
co16235
co16235

Change Password :
passwd

=========================================================================
=========================================================================

Login MySQL : 
mysql -u 16co235 -p

Change MySQL Password : 
set password '16co235'@'localhost' = <NEW_PASSWORD>

Tip : Ctrl + L to clear MySQL command line.

=========================================================================
=========================================================================

Write SQL statements for the following:
1. Create a table student with following information: columns and data
types: name varchar(8),age number(5),Student_id
varchar(30),course_name varchar(30),marks number(3), section
varchar(2);

CREATE TABLE student(
    name VARCHAR(8) NOT NULL,
    age INT(5),
    student_id VARCHAR(30) PRIMARY KEY,
    course_name VARCHAR(30),
    marks INT(3),
    section VARCHAR(2),
    CONSTRAINT above_18 CHECK (age >= 18),
    CONSTRAINT marks_0_to_100 CHECK (marks BETWEEN 0 AND 100)
);

Query OK, 0 rows affected (0.05 sec)

mysql> DESC student;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| name        | varchar(8)  | NO   |     | NULL    |       |
| age         | int(5)      | YES  |     | NULL    |       |
| student_id  | varchar(30) | NO   | PRI | NULL    |       |
| course_name | varchar(30) | YES  |     | NULL    |       |
| marks       | int(3)      | YES  |     | NULL    |       |
| section     | varchar(2)  | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
6 rows in set (0.00 sec)


2. Include all necessary constraints.

3. Enter atleast ten tuples for the given relation.

INSERT INTO student VALUES
("Praveen", 12, "16CO235", "CN", 99, "A"),
("Omkar", 12, "16CO236", "CN2", 98, "B"),
("DD", 12, "16CO237", "CN3", 99, "C"),
("Moksh", 12, "16CO238", "CN4", 90, "A"),
("Naveen", 12, "16CO239", "CN5", 95, "B"),
("Mahim", 12, "16CO240", "CN6", 96, "C"),
("Yo", 12, "16CO241", "CN7", 90, "A"),
("You", 12, "16CO242", "CN8", 90, "B"),
("Suck", 12, "16CO243", "CN9", 92, "C"),
("Big Time", 12, "16CO244", "CN1", 90, "A");

4. Display the first three records of student table.

mysql> SELECT * FROM student LIMIT 3;
+---------+------+------------+-------------+-------+---------+
| name    | age  | student_id | course_name | marks | section |
+---------+------+------------+-------------+-------+---------+
| Praveen |   12 | 16CO235    | CN          |   105 | A       |
| Omkar   |   12 | 16CO236    | CN2         |   105 | B       |
| DD      |   12 | 16CO237    | CN3         |   105 | C       |
+---------+------+------------+-------------+-------+---------+
3 rows in set (0.00 sec)

5. Display the detail of the student whose section is not 'B'.

mysql> SELECT * FROM student WHERE section != 'B';
+----------+------+------------+-------------+-------+---------+
| name     | age  | student_id | course_name | marks | section |
+----------+------+------------+-------------+-------+---------+
| Praveen  |   12 | 16CO235    | CN          |   105 | A       |
| DD       |   12 | 16CO237    | CN3         |   105 | C       |
| Moksh    |   12 | 16CO238    | CN4         |   105 | A       |
| Mahim    |   12 | 16CO240    | CN6         |   105 | C       |
| Yo       |   12 | 16CO241    | CN7         |   105 | A       |
| Suck     |   12 | 16CO243    | CN9         |   105 | C       |
| Big Time |   12 | 16CO244    | CN1         |   105 | A       |
+----------+------+------------+-------------+-------+---------+
7 rows in set (0.00 sec)

6. List name of the student in descending order of their total marks.

mysql> SELECT name FROM student ORDER BY marks DESC;
+----------+
| name     |
+----------+
| Praveen  |
| Suck     |
| You      |
| Yo       |
| Mahim    |
| Naveen   |
| Moksh    |
| DD       |
| Omkar    |
| Big Time |
+----------+
10 rows in set (0.00 sec)

7. Display the details of the student whose marks > 50

SELECT * FROM student WHERE marks > 50;

8. List the students who scored highest.

-- SELECT * FROM student HAVING marks = max(marks);
mysql> SELECT * FROM student WHERE marks = (SELECT max(marks) from student);
+---------+------+------------+-------------+-------+---------+
| name    | age  | student_id | course_name | marks | section |
+---------+------+------------+-------------+-------+---------+
| Praveen |   12 | 16CO235    | CN          |    99 | A       |
| DD      |   12 | 16CO237    | CN3         |    99 | C       |
+---------+------+------------+-------------+-------+---------+
2 rows in set (0.00 sec)


9. Count the number of students whose name starts with 'S'.

mysql> SELECT count(*) FROM student WHERE name like 'S%';
+----------+
| count(*) |
+----------+
|        1 |
+----------+
1 row in set (0.00 sec)

10. Display student_id , name and marks of students whose age is between 20 and 22. (inclusive)

SELECT name, marks FROM student WHERE age BETWEEN 20 AND 22;

Empty set (0.00 sec)



===================================================================================================
===================================================================================================

Write SQL statements for:
1. Create the tables with following information: 
FLIGHT(flno: int, fname:string, fromplace: string, toplace: string,
distance: int, departss: string, arrivess: string, price: real)

CREATE TABLE FLIGHT (
    flno INT(5) PRIMARY KEY,
    fname VARCHAR(20),
    fromplace VARCHAR(20),
    toplace VARCHAR(20),
    distance INT(8),
    departss VARCHAR(10),
    arrivess VARCHAR(10),
    price DECIMAL(10,2)
);

2. Inserting data into the flight with eight or more entries.

INSERT INTO FLIGHT VALUES
(0, "DD", "madison", "newyork", 1000, "12:00", "15:00", 70000),
(1, "Pv", "madison", "chennai", 1000, "11:00", "17:00", 50000),
(2, "Omi", "delhi", "mumbai", 2000, "12:00", "15:00", 25000),
(3, "Yo", "kolkata", "banglore", 3000, "10:00", "11:00", 30000),
(4, "This", "madison", "newyork", 1000, "10:15", "10:50", 70000),
(5, "Flight", "bangalore", "chennai", 3000, "12:00", "15:00", 90000),
(6, "Sucks", "madison", "newyork", 1000, "12:00", "15:00", 20000),
(7, "ok", "bangalore", "kolkata", 1000, "12:00", "15:00", 30000),
(8, "bye", "mumbai", "delhi", 2000, "12:00", "15:00", 10000);

3. Describe the table flight with attributes and its datatypes.
DESC FLIGHT;
+-----------+---------------+------+-----+---------+-------+
| Field     | Type          | Null | Key | Default | Extra |
+-----------+---------------+------+-----+---------+-------+
| flno      | int(5)        | NO   | PRI | NULL    |       |
| fname     | varchar(20)   | YES  |     | NULL    |       |
| fromplace | varchar(20)   | YES  |     | NULL    |       |
| toplace   | varchar(20)   | YES  |     | NULL    |       |
| distance  | int(8)        | YES  |     | NULL    |       |
| departs   | varchar(10)   | YES  |     | NULL    |       |
| arrives   | varchar(10)   | YES  |     | NULL    |       |
| price     | decimal(10,2) | YES  |     | NULL    |       |
+-----------+---------------+------+-----+---------+-------+
8 rows in set (0.00 sec)


4. Write sql query to return a flight number and name for the flights that are
scheduled between '10:00' and '11:00'.

SELECT flno, fname FROM FLIGHT WHERE arrives >= "10:00" AND departs <= "11:00";
+------+-------+
| flno | fname |
+------+-------+
|    1 | Pv    |
|    3 | Yo    |
|    4 | This  |
+------+-------+
3 rows in set (0.00 sec)

5. Find the number of flights that flies from 'madison' to 'newyork'.

SELECT count(*) as "Madison to New York" FROM FLIGHT WHERE (fromplace, toplace) = ("madison", "newyork");
+---------------------+
| Madison to New York |
+---------------------+
|                   3 |
+---------------------+
1 row in set (0.00 sec)

6. Write an SQL statement that reduces the price of flights to 20000 if they
departs in the morning (before 12:00 midday) and currently have a price
above 50000.

UPDATE FLIGHT SET price=20000 WHERE departs < "12:00" AND price > 50000;

Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

7. Write an SQL statement that deletes all the flights from 'Bangalore' to
'Kolkata'.

DELETE FROM FLIGHT WHERE (fromplace, toplace) = ("Bangalore", "Kolkata");

Query OK, 1 row affected (0.00 sec)

8. List all the name of the flights which has 'I' in its name.

SELECT * FROM FLIGHT WHERE fname like "%I%";

+------+--------+-----------+---------+----------+---------+---------+----------+
| flno | fname  | fromplace | toplace | distance | departs | arrives | price    |
+------+--------+-----------+---------+----------+---------+---------+----------+
|    2 | Omi    | delhi     | mumbai  |     2000 | 12:00   | 15:00   | 25000.00 |
|    4 | This   | madison   | newyork |     1000 | 10:15   | 10:50   | 20000.00 |
|    5 | Flight | bangalore | chennai |     3000 | 12:00   | 15:00   | 90000.00 |
+------+--------+-----------+---------+----------+---------+---------+----------+
3 rows in set (0.00 sec)

9. Create a back up copy of FLIGHT table.
CREATE TABLE FLIGHT_BACKUP as (SELECT * FROM FLIGHT);

Query OK, 8 rows affected (0.05 sec)
Records: 8  Duplicates: 0  Warnings: 0

10. Create an alias for toplace as dest and using that alias retrieve the details
of all flights flying to Chennai.

SELECT *, toplace as dest FROM FLIGHT having dest="Chennai";

+------+--------+-----------+---------+----------+---------+---------+----------+---------+
| flno | fname  | fromplace | toplace | distance | departs | arrives | price    | dest    |
+------+--------+-----------+---------+----------+---------+---------+----------+---------+
|    1 | Pv     | madison   | chennai |     1000 | 11:00   | 17:00   | 50000.00 | chennai |
|    5 | Flight | bangalore | chennai |     3000 | 12:00   | 15:00   | 90000.00 | chennai |
+------+--------+-----------+---------+----------+---------+---------+----------+---------+
2 rows in set (0.00 sec)