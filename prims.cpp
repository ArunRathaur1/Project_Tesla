-- Drop if already exists
create Database DB1;
use DB1;
DROP TABLE IF EXISTS Emp;
DROP TABLE IF EXISTS Dept;
DROP TABLE IF EXISTS Location;
DROP TABLE IF EXISTS Salgrade;

-- Location Table
CREATE TABLE Location (
    locno INT PRIMARY KEY,
    city VARCHAR(50) NOT NULL
);

-- Department Table
CREATE TABLE Dept (
    deptno INT PRIMARY KEY,
    deptname VARCHAR(50) NOT NULL,
    locno INT,
    FOREIGN KEY (locno) REFERENCES Location(locno)
);

-- Salary Grade Table
CREATE TABLE Salgrade (
    grade INT PRIMARY KEY,
    lowsal DECIMAL(10,2),
    hisal DECIMAL(10,2)
);

-- Employee Table
CREATE TABLE Emp (
    empno INT PRIMARY KEY,
    empname VARCHAR(50) NOT NULL,
    hire_date DATE,
    mgr INT,
    job VARCHAR(50),
    salary DECIMAL(10,2),
    commission DECIMAL(10,2),
    deptno INT,
    grade INT,
    FOREIGN KEY (mgr) REFERENCES Emp(empno),
    FOREIGN KEY (deptno) REFERENCES Dept(deptno),
    FOREIGN KEY (grade) REFERENCES Salgrade(grade)
);

-- Insert into Location
INSERT INTO Location VALUES 
(10, 'New York'),
(20, 'Los Angeles'),
(30, 'Chicago'),
(40, 'Houston');

-- Insert into Dept
INSERT INTO Dept VALUES
(101, 'HR', 10),
(102, 'Finance', 20),
(103, 'IT', 30),
(104, 'Sales', 40);

-- Insert into Salgrade
INSERT INTO Salgrade VALUES
(1, 1000, 2000),
(2, 2001, 4000),
(3, 4001, 6000),
(4, 6001, 9000),
(5, 9001, 15000);

-- Insert into Emp
INSERT INTO Emp VALUES
(1001, 'John Smith', '2015-03-12', NULL, 'Manager', 12000, NULL, 101, 5),
(1002, 'Alice Johnson', '2017-06-25', 1001, 'Clerk', 1800, NULL, 101, 1),
(1003, 'Michael Brown', '2018-08-10', 1001, 'Analyst', 3500, NULL, 102, 2),
(1004, 'David Lee', '2020-02-18', 1003, 'Clerk', 2200, NULL, 102, 2),
(1005, 'Sophia Wilson', '2019-12-01', 1001, 'Salesman', 5000, 800, 104, 3),
(1006, 'Emma Davis', '2021-04-05', 1005, 'Salesman', 4500, 600, 104, 3),
(1007, 'James Miller', '2022-09-11', 1001, 'IT Support', 2800, NULL, 103, 2),
(1008, 'Olivia Garcia', '2023-01-14', 1007, 'Programmer', 6000, NULL, 103, 4);

select d.deptname,e.empname,d.deptno from Dept as d left join Emp as e on d.deptno=e.deptno; 
select e.job,l.city from Dept as d left join Location as l on d.locno=l.locno left join Emp as e on d.deptno=e.deptno
 where d.deptno=101;
 
 SELECT e.empname, d.deptname, d.locno, l.city
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno
JOIN Location l ON d.locno = l.locno
WHERE e.commission IS NOT NULL;

SELECT e.empname, e.job, e.deptno, d.deptname
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno
JOIN Location l ON d.locno = l.locno
WHERE l.city = 'Toronto';

SELECT e.empname AS Employee, e.empno AS EmpNo,
       m.empname AS Manager, m.empno AS MgrNo
FROM Emp e
LEFT JOIN Emp m ON e.mgr = m.empno;

SELECT e1.empname AS Employee, e1.deptno,
       e2.empname AS Colleague
FROM Emp e1
JOIN Emp e2 ON e1.deptno = e2.deptno
WHERE e1.empname = 'Smith'
  AND e1.empno <> e2.empno;

SELECT e.empname, e.hire_date
FROM Emp e
WHERE e.hire_date > (
    SELECT hire_date
    FROM Emp
    WHERE empname = 'Davies'
);

SELECT e.empname, e.job, d.deptname, e.salary, s.grade
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno
JOIN Salgrade s ON e.grade = s.grade;


