=====================================================================
=====================================================================

https://www.guru99.com/joins.html
http://www.mysqltutorial.org/mysql-self-join/

=====================================================================
mysql> create table employee (
        fname varchar(10),
        lname varchar(10),
        eid int primary key,
        start_date date,
        office varchar(10),
        salary int,
        dno int,
        bonus int,
        email varchar(10)
    );
Query OK, 0 rows affected (0.04 sec)

mysql> desc employee;

+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| fname      | varchar(10) | YES  |     | NULL    |       |
| lname      | varchar(10) | YES  |     | NULL    |       |
| eid        | int(11)     | NO   | PRI | NULL    |       |
| start_date | date        | YES  |     | NULL    |       |
| office     | varchar(10) | YES  |     | NULL    |       |
| salary     | int(11)     | YES  |     | NULL    |       |
| dno        | int(11)     | YES  |     | NULL    |       |
| bonus      | int(11)     | YES  |     | NULL    |       |
| email      | varchar(10) | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
9 rows in set (0.00 sec)

=====================================================================
mysql> insert into employee values (
                "John",
                "Taylor",
                1777,
                "2012-04-13",
                "Chicago",
                20000,
                4,
                400,
                "jtaylor@yahoo.com"
            ),( 
                "Trevor",
                "Williams",
                1945,
                "1980-06-23",
                "London",
                55055,
                4,
                1000,
                "trev_william@gmail.com"
            ),(
                "Zoe",
                "Johnson",
                2050,
                "1992-06-23",
                "Paris",
                55055,
                5,
                2000,
                "zoe777@msn.com"
            ),(
                "Kathy",
                "Franklin",
                2051,
                "2013-06-29",
                "Chicago",
                20000,
                5,
                0,
                "kathyfrank@gmail.com"
            ),(
                "Trevor",
                "Jacob",
                2398,
                "1999-06-23",
                "London",
                55055,
                4,
                0,
                "trevorJ235@aol.com"
            ),(
                "John",
                "Owens",
                7777,
                "2004-12-04",
                "London",
                130000,
                4,
                3500,
                "mailjude@yahoo.com"
            ),(
                "Alice",
                "Bright",
                8888,
                "1973-12-19",
                "London",
                111114,
                7,
                3000,
                "ab23@gmail.com"
            );
Query OK, 7 rows affected, 7 warnings (0.00 sec)
Records: 7  Duplicates: 0  Warnings: 7

mysql> select * from employee;
+--------+----------+------+------------+---------+--------+------+-------+------------+
| fname  | lname    | eid  | start_date | office  | salary | dno  | bonus | email      |
+--------+----------+------+------------+---------+--------+------+-------+------------+
| John   | Taylor   | 1777 | 2012-04-13 | Chicago |  20000 |    4 |   400 | jtaylor@ya |
| Trevor | Williams | 1945 | 1980-06-23 | London  |  55055 |    4 |  1000 | trev_willi |
| Zoe    | Johnson  | 2050 | 1992-06-23 | Paris   |  55055 |    5 |  2000 | zoe777@msn |
| Kathy  | Franklin | 2051 | 2013-06-29 | Chicago |  20000 |    5 |     0 | kathyfrank |
| Trevor | Jacob    | 2398 | 1999-06-23 | London  |  55055 |    4 |     0 | trevorJ235 |
| John   | Owens    | 7777 | 2004-12-04 | London  | 130000 |    4 |  3500 | mailjude@y |
| Alice  | Bright   | 8888 | 1973-12-19 | London  | 111114 |    7 |  3000 | ab23@gmail |
+--------+----------+------+------------+---------+--------+------+-------+------------+
7 rows in set (0.00 sec)

mysql> 
==========================================================================================

mysql> CREATE TABLE currency_table (
        location VARCHAR(10) PRIMARY KEY,
        currency_code VARCHAR(10)
    );
Query OK, 0 rows affected (0.04 sec)

mysql> DESC currency_table;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| location      | varchar(10) | NO   | PRI | NULL    |       |
| currency_code | varchar(10) | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql>
================================================================================================

mysql> INSERT INTO currency_table VALUES
        ("Chicago", "USD"),
        ("London", "GBP"),
        ("Paris", "EUR");
Query OK, 3 rows affected (0.00 sec)
Records: 3  Duplicates: 0  Warnings: 0

select * from currency_table;
--------------------------+
| location | currency_code |
--------------------------+
| Chicago  | USD           |
| London   | GBP           |
| Paris    | EUR           |
+----------+---------------+
3 rows in set (0.00 sec)

mysql> 
================================================================================================
1)

mysql> SELECT employee.office, employee.eid, concat( employee.salary, " ", currency_table.currency_code) as salary from employee, currency_table where employee.office = currency_table.location;
+---------+------+------------+
| office  | eid  | salary     |
+---------+------+------------+
| Chicago | 1777 | 20000 USD  |
| London  | 1945 | 55055 GBP  |
| Paris   | 2050 | 55055 EUR  |
| Chicago | 2051 | 20000 USD  |
| London  | 2398 | 55055 GBP  |
| London  | 7777 | 130000 GBP |
| London  | 8888 | 111114 GBP |
+---------+------+------------+
7 rows in set (0.00 sec)

===================================================================================================
2) SELECT name, eid from employee where fname in (SELECT fname FROM employee GROUP BY fname HAVING count(fname) > 1);
+-----------------+------+
| name            | eid  |
+-----------------+------+
| John Taylor     | 1777 |
| Trevor Williams | 1945 |
| Trevor Jacob    | 2398 |
| John Owens      | 7777 |
+-----------------+------+
4 rows in set (0.00 sec)

======================================================================================================

3)

mysql> SELECT 0.05 * salary AS deduction, 0.95 * salary + bonus AS final_salary FROM employee;
+-----------+--------------+
| deduction | final_salary |
+-----------+--------------+
|   1000.00 |     19400.00 |
|   2752.75 |     53302.25 |
|   2752.75 |     54302.25 |
|   1000.00 |     19000.00 |
|   2752.75 |     52302.25 |
|   6500.00 |    127000.00 |
|   5555.70 |    108558.30 |
+-----------+--------------+
7 rows in set (0.00 sec)

=============================================================================================================
4)
mysql> SELECT * FROM employee ORDER BY salary DESC, lname;
+--------+----------+------+------------+---------+--------+------+-------+------------+
| fname  | lname    | eid  | start_date | office  | salary | dno  | bonus | email      |
+--------+----------+------+------------+---------+--------+------+-------+------------+
| John   | Owens    | 7777 | 2004-12-04 | London  | 130000 |    4 |  3500 | mailjude@y |
| Alice  | Bright   | 8888 | 1973-12-19 | London  | 111114 |    7 |  3000 | ab23@gmail |
| Trevor | Jacob    | 2398 | 1999-06-23 | London  |  55055 |    4 |     0 | trevorJ235 |
| Zoe    | Johnson  | 2050 | 1992-06-23 | Paris   |  55055 |    5 |  2000 | zoe777@msn |
| Trevor | Williams | 1945 | 1980-06-23 | London  |  55055 |    4 |  1000 | trev_willi |
| Kathy  | Franklin | 2051 | 2013-06-29 | Chicago |  20000 |    5 |     0 | kathyfrank |
| John   | Taylor   | 1777 | 2012-04-13 | Chicago |  20000 |    4 |   400 | jtaylor@ya |
+--------+----------+------+------------+---------+--------+------+-------+------------+
7 rows in set (0.00 sec)

================================================================================================================

5)

mysql> SELECT DISTINCT dno FROM employee WHERE bonus != 0; 
+------+
| dno  |
+------+
|    4 |
|    5 |
|    7 |
+------+
3 rows in set (0.00 sec)