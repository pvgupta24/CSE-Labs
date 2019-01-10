=========================================================================
=========================================================================

Name : Praveen Kumar Gupta
Roll No : 16CO235
Date : 21/08/2018 (Tuesday)


=========================================================================
=========================================================================

References :
https://gist.github.com/hofmannsven/9164408
https://hoelz.ro/ref/mysql-alter-table-alter-change-modify-column
https://www.w3schools.com/sql/sql_datatypes.asp


=========================================================================
=========================================================================
Login : 
telnet 10.100.12.123
co16235
<password>

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

* Q1) Write SQL statements for:
1. Creating a table student with following information: Name of
table: student, columns and data types: rollno number(6), name
varchar(20), branch varchar(20),age int(2);

        mysql> CREATE TABLE student(
            rollno INT(6),
            name VARCHAR(20),
            branch VARCHAR(20),
            age INT(2)
        );

        Query OK, 0 rows affected (0.03 sec)

        mysql> DESC student;
        +--------+-------------+------+-----+---------+-------+
        | Field  | Type        | Null | Key | Default | Extra |
        +--------+-------------+------+-----+---------+-------+
        | rollno | int(6)      | YES  |     | NULL    |       |
        | name   | varchar(20) | YES  |     | NULL    |       |
        | branch | varchar(20) | YES  |     | NULL    |       |
        | age    | int(2)      | YES  |     | NULL    |       |
        +--------+-------------+------+-----+---------+-------+
        4 rows in set (0.00 sec)


2. Inserting data into the student table

        mysql> INSERT INTO student VALUES
            (100000, 'Praveen', 'CSE', 20),
            (100001, 'Omkar', 'CSE', 20),
            (100002, 'Dibyadarshan', 'Civil', 20);

        Query OK, 3 rows affected (0.00 sec)
        Records: 3  Duplicates: 0  Warnings: 0

        mysql> SELECT * FROM student;
        +--------+--------------+--------+------+
        | rollno | name         | branch | age  |
        +--------+--------------+--------+------+
        | 100000 | Praveen      | CSE    |   20 |
        | 100001 | Omkar        | CSE    |   20 |
        | 100002 | Dibyadarshan | Civil  |   20 |
        +--------+--------------+--------+------+
        3 rows in set (0.00 sec)


3. Altering table by adding new column class varchar(20)

        mysql> ALTER TABLE student ADD class VARCHAR(20);
        Query OK, 3 rows affected (0.05 sec)
        Records: 3  Duplicates: 0  Warnings: 0

        mysql> DESC student;
        +--------+-------------+------+-----+---------+-------+
        | Field  | Type        | Null | Key | Default | Extra |
        +--------+-------------+------+-----+---------+-------+
        | rollno | int(6)      | YES  |     | NULL    |       |
        | name   | varchar(20) | YES  |     | NULL    |       |
        | branch | varchar(20) | YES  |     | NULL    |       |
        | age    | int(2)      | YES  |     | NULL    |       |
        | class  | varchar(20) | YES  |     | NULL    |       |
        +--------+-------------+------+-----+---------+-------+
        5 rows in set (0.00 sec)


4. Deleting a row from the table

        mysql> DELETE FROM student WHERE name="Omkar";
        Query OK, 1 row affected (0.00 sec)

        mysql> SELECT * FROM student;
        +--------+--------------+--------+------+-------+
        | rollno | name         | branch | age  | class |
        +--------+--------------+--------+------+-------+
        | 100000 | Praveen      | CSE    |   20 | NULL  |
        | 100002 | Dibyadarshan | Civil  |   20 | NULL  |
        +--------+--------------+--------+------+-------+
        2 rows in set (0.00 sec)


5. Drop column branch

        mysql> ALTER TABLE student DROP branch;
        Query OK, 2 rows affected (0.04 sec)
        Records: 2  Duplicates: 0  Warnings: 0

        mysql> DESC student;
        +--------+-------------+------+-----+---------+-------+
        | Field  | Type        | Null | Key | Default | Extra |
        +--------+-------------+------+-----+---------+-------+
        | rollno | int(6)      | YES  |     | NULL    |       |
        | name   | varchar(20) | YES  |     | NULL    |       |
        | age    | int(2)      | YES  |     | NULL    |       |
        | class  | varchar(20) | YES  |     | NULL    |       |
        +--------+-------------+------+-----+---------+-------+
        4 rows in set (0.01 sec)


6. Alter table by changing the data type of rollno to number(8).

        mysql> ALTER TABLE student MODIFY rollno INT(8);
        Query OK, 0 rows affected (0.05 sec)
        Records: 0  Duplicates: 0  Warnings: 0

        mysql> DESC student;
        +--------+-------------+------+-----+---------+-------+
        | Field  | Type        | Null | Key | Default | Extra |
        +--------+-------------+------+-----+---------+-------+
        | rollno | int(8)      | YES  |     | NULL    |       |
        | name   | varchar(20) | YES  |     | NULL    |       |
        | age    | int(2)      | YES  |     | NULL    |       |
        | class  | varchar(20) | YES  |     | NULL    |       |
        +--------+-------------+------+-----+---------+-------+
        4 rows in set (0.00 sec)


7. Alter the table by adding new column DOB(DD/MM/YYYY).

        mysql> ALTER TABLE student ADD DOB DATE;
        Query OK, 2 rows affected (0.05 sec)
        Records: 2  Duplicates: 0  Warnings: 0

        mysql> DESC student;
        +--------+-------------+------+-----+---------+-------+
        | Field  | Type        | Null | Key | Default | Extra |
        +--------+-------------+------+-----+---------+-------+
        | rollno | int(8)      | YES  |     | NULL    |       |
        | name   | varchar(20) | YES  |     | NULL    |       |
        | age    | int(2)      | YES  |     | NULL    |       |
        | class  | varchar(20) | YES  |     | NULL    |       |
        | DOB    | date        | YES  |     | NULL    |       |
        +--------+-------------+------+-----+---------+-------+
        5 rows in set (0.00 sec)


8. Update the age of student for a particular rollno.

        mysql> SELECT * FROM student;
        +--------+--------------+------+-------+------+
        | rollno | name         | age  | class | DOB  |
        +--------+--------------+------+-------+------+
        | 100000 | Praveen      |   20 | NULL  | NULL |
        | 100002 | Dibyadarshan |   20 | NULL  | NULL |
        +--------+--------------+------+-------+------+
        2 rows in set (0.00 sec)

        mysql> UPDATE student SET age=25 WHERE rollno=100002;
        Query OK, 1 row affected (0.00 sec)
        Rows matched: 1  Changed: 1  Warnings: 0

        mysql> SELECT * FROM student;
        +--------+--------------+------+-------+------+
        | rollno | name         | age  | class | DOB  |
        +--------+--------------+------+-------+------+
        | 100000 | Praveen      |   20 | NULL  | NULL |
        | 100002 | Dibyadarshan |   25 | NULL  | NULL |
        +--------+--------------+------+-------+------+
        2 rows in set (0.00 sec)


9. Delete all the data from student table.

        mysql> TRUNCATE TABLE student;
        Query OK, 0 rows affected (0.00 sec)

        mysql> SELECT * FROM student;
        Empty set (0.00 sec)


10. Delete the table.
        mysql> DROP TABLE student;
        Query OK, 0 rows affected (0.00 sec)

        mysql> SHOW TABLES;
        Empty set (0.00 sec)

=========================================================================
=========================================================================

* Q2) Write SQL statements for:
1. Creating a table Emp with following information: 
Emp (fname, Lname, phono, desg, salary, Dept, Emp_no, age)

        mysql> CREATE TABLE Emp(
                    fname VARCHAR(20),
                    lname VARCHAR(20),
                    phono BIGINT(10),
                    desg VARCHAR(10),
                    salary INT(8),
                    Dept VARCHAR(30),
                    Emp_no INT(5) PRIMARY KEY,
                    age INT(2)
                );
        Query OK, 0 rows affected (0.04 sec)

        mysql> DESC Emp;
        +--------+-------------+------+-----+---------+-------+
        | Field  | Type        | Null | Key | Default | Extra |
        +--------+-------------+------+-----+---------+-------+
        | fname  | varchar(20) | YES  |     | NULL    |       |
        | lname  | varchar(20) | YES  |     | NULL    |       |
        | phono  | bigint(10)  | YES  |     | NULL    |       |
        | desg   | varchar(10) | YES  |     | NULL    |       |
        | salary | int(8)      | YES  |     | NULL    |       |
        | Dept   | varchar(30) | YES  |     | NULL    |       |
        | Emp_no | int(5)      | NO   | PRI | NULL    |       |
        | age    | int(2)      | YES  |     | NULL    |       |
        +--------+-------------+------+-----+---------+-------+
        8 rows in set (0.00 sec)


2. Inserting data into the Emp table

        mysql> INSERT INTO Emp VALUES
            ('Praveen', 'Gupta', 9738013574, "SWE", 80000, "Cloud Infrastructure", 100001, 20),
            ('Moksh', 'Jain', 9876543210, "SWE", 87500, "Azure - Hyperledger Docs", 100002, 20),
            ('Mahim', 'Agarwal', 9738012457, "SysAdmin", 87500, "Linux in IRIS", 100003, 20);
        Query OK, 3 rows affected (0.00 sec)
        Records: 3  Duplicates: 0  Warnings: 0

        mysql> SELECT * FROM Emp;
        +---------+---------+------------+----------+--------+--------------------------+--------+------+
        | fname   | lname   | phono      | desg     | salary | Dept                     | Emp_no | age  |
        +---------+---------+------------+----------+--------+--------------------------+--------+------+
        | Praveen | Gupta   | 9738013574 | SWE      |  80000 | Cloud Infrastructure     | 100001 |   20 |
        | Moksh   | Jain    | 9876543210 | SWE      |  87500 | Azure - Hyperledger Docs | 100002 |   20 |
        | Mahim   | Agarwal | 9738012457 | SysAdmin |  87500 | Linux in IRIS            | 100003 |   20 |
        +---------+---------+------------+----------+--------+--------------------------+--------+------+
        3 rows in set (0.00 sec)


3. Altering table by adding new column address varchar(50)

        mysql> ALTER TABLE Emp ADD address VARCHAR(50);
        Query OK, 3 rows affected (0.05 sec)
        Records: 3  Duplicates: 0  Warnings: 0

        mysql> DESC Emp;
        +---------+-------------+------+-----+---------+-------+
        | Field   | Type        | Null | Key | Default | Extra |
        +---------+-------------+------+-----+---------+-------+
        | fname   | varchar(20) | YES  |     | NULL    |       |
        | lname   | varchar(20) | YES  |     | NULL    |       |
        | phono   | bigint(10)  | YES  |     | NULL    |       |
        | desg    | varchar(10) | YES  |     | NULL    |       |
        | salary  | int(8)      | YES  |     | NULL    |       |
        | Dept    | varchar(30) | YES  |     | NULL    |       |
        | Emp_no  | int(5)      | NO   | PRI | NULL    |       |
        | age     | int(2)      | YES  |     | NULL    |       |
        | address | varchar(50) | YES  |     | NULL    |       |
        +---------+-------------+------+-----+---------+-------+
        9 rows in set (0.00 sec)


4. Deleting a row from the table

        mysql> DELETE FROM Emp where fname="Mahim";
        Query OK, 1 row affected (0.00 sec)

        mysql> SELECT * FROM Emp;
        +---------+-------+------------+------+--------+--------------------------+--------+------+---------+
        | fname   | lname | phono      | desg | salary | Dept                     | Emp_no | age  | address |
        +---------+-------+------------+------+--------+--------------------------+--------+------+---------+
        | Praveen | Gupta | 9738013574 | SWE  |  80000 | Cloud Infrastructure     | 100001 |   20 | NULL    |
        | Moksh   | Jain  | 9876543210 | SWE  |  87500 | Azure - Hyperledger Docs | 100002 |   20 | NULL    |
        +---------+-------+------------+------+--------+--------------------------+--------+------+---------+
        2 rows in set (0.00 sec)


5. Drop column phono

        mysql> ALTER TABLE Emp DROP phono;
        Query OK, 2 rows affected (0.05 sec)
        Records: 2  Duplicates: 0  Warnings: 0

        mysql> DESC Emp;
        +---------+-------------+------+-----+---------+-------+
        | Field   | Type        | Null | Key | Default | Extra |
        +---------+-------------+------+-----+---------+-------+
        | fname   | varchar(20) | YES  |     | NULL    |       |
        | lname   | varchar(20) | YES  |     | NULL    |       |
        | desg    | varchar(10) | YES  |     | NULL    |       |
        | salary  | int(8)      | YES  |     | NULL    |       |
        | Dept    | varchar(30) | YES  |     | NULL    |       |
        | Emp_no  | int(5)      | NO   | PRI | NULL    |       |
        | age     | int(2)      | YES  |     | NULL    |       |
        | address | varchar(50) | YES  |     | NULL    |       |
        +---------+-------------+------+-----+---------+-------+
        8 rows in set (0.00 sec)


6. Update the age of employee for particular Emp_no

        mysql> UPDATE Emp SET age=25 WHERE Emp_no=100002;
        Query OK, 1 row affected (0.00 sec)
        Rows matched: 1  Changed: 1  Warnings: 0

        mysql> SELECT * FROM Emp;
        +---------+-------+------+--------+--------------------------+--------+------+---------+
        | fname   | lname | desg | salary | Dept                     | Emp_no | age  | address |
        +---------+-------+------+--------+--------------------------+--------+------+---------+
        | Praveen | Gupta | SWE  |  80000 | Cloud Infrastructure     | 100001 |   20 | NULL    |
        | Moksh   | Jain  | SWE  |  87500 | Azure - Hyperledger Docs | 100002 |   25 | NULL    |
        +---------+-------+------+--------+--------------------------+--------+------+---------+
        2 rows in set (0.00 sec)


7. Delete all the data from Employee table.

        mysql> TRUNCATE TABLE Emp;
        Query OK, 0 rows affected (0.00 sec)

        mysql> SELECT * FROM Emp;
        Empty set (0.01 sec)


8. Delete the table.

        mysql> DROP TABLE Emp;
        Query OK, 0 rows affected (0.00 sec)

        mysql> SHOW TABLES;
        Empty set (0.00 sec)



=========================================================================
=========================================================================
