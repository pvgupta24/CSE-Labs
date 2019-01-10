1. Create a table Faculty (FacultyId, Name,age, dept, Website, Mobile and Gender).Display the structure
of the table. USE DESCRIBE /DESC statement.

CREATE TABLE faculty (
    id INT(4) PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    age INT(3),
    dept VARCHAR(10),
    website VARCHAR(20),
    mob VARCHAR(10),
    gender VARCHAR(5)
);

DESC faculty;

2. Modify the above table such that if department name is CS, it changes to Computer Science, if it is
CE, it changes to CE and so on .USE CASE Statement.

UPDATE faculty SET dept =
    CASE
        WHEN dept = "CS" THEN "Computer Science"
        WHEN dept = "CE" THEN "Civil Engineering"
        ELSE dept
    END;

3. USE ALTER TABLE to rename the table Faculty to FacultyDetails and column Name to FName.

ALTER TABLE faculty RENAME faculty_details, CHANGE name fName VARCHAR(20);

4. USE LIKE to
a) Select Departments of those Faculties whose name contain ‘c’ at the 3 rd position.
b) Select Departments of those Faculties whose name starts with ‘k’ and contain at least 3
characters.
SELECT dept from faculty_details WHERE fname like '__c%';
SELECT dept from faculty_details WHERE fname like 'k%' AND LENGTH(fname) >= 3;

5. Find the name(s) of faculty(ies) whose age is greater than the age of faculties in the department of
Computer Science.
SELECT fname from faculty_details WHERE age > (SELECT max(age) FROM faculty_details WHERE dept = "Computer Science");

6. USE ORDER BY.
A) Sort Faculty table according to the age in ascending order.
B) Sort Faculty table according to the age in descending order.
C) Sort Faculty table first according to the Age in ascending order and then according to the FacultyId
in descending order.

SELECT * FROM faculty_details ORDER BY age;
SELECT * FROM faculty_details ORDER BY age DESC;
SELECT * FROM faculty_details ORDER BY age, id DESC;


7. USE WHERE Clause and operators –IN, BETWEEN, etc.
A) Fetch details of faculties with age equal to 30.
B) Fetch name and websites of faculties with Faculty Id greater than 4.
C) Fetch records of faculties where faculty id is in between 3 and 5. (Inclusive)
D) Fetch names and websites of faculties with age between 30 and 40. (Inclusive)
E) Fetch names and websites of faculties where age is 30 or 35 or 40.
F) Fetch names and websites of faculties where Faculty Id is in 3 or 5 or 7.

SELECT * FROM faculty_details WHERE age = 30;
SELECT fname, website FROM faculty_details WHERE id > 30;
SELECT * FROM faculty_details WHERE id BETWEEN 3 AND 5;
SELECT fname, website FROM faculty_details WHERE age BETWEEN 3 AND 40;
SELECT fname, website FROM faculty_details WHERE age in (30, 35, 40);
SELECT fname, website FROM faculty_details WHERE id in (3, 5, 7);
