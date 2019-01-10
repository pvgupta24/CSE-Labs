-- **Order is a keyword,so [Order] has to be used.**

-- List all suppliers from the USA, UK, OR Japan
SELECT companyname, country FROM Supplier WHERE country in ('USA', 'UK', 'Japan');

-- List all products that are not exactly $10, $20, $30, $40, or $50.
SELECT Productname FROM Product WHERE unitprice NOT IN (10, 20, 30, 40, 50);

-- List all customers that are from the same countries as the suppliers.
SELECT Id, FirstName, LastName, Country
FROM Customer WHERE Country IN (SELECT Country FROM Supplier);

-- List all orders with customer information 
SELECT * FROM [Order] AS o JOIN Customer ON o.CustomerId = Customer.Id;

-- List all orders with product names, quantities, and prices.
SELECT o.OrderNumber, p.ProductName, i.quantity, i.unitprice 
FROM [Order] o  JOIN Order_Item i ON o.Id = i.OrderId JOIN Product p ON p.Id = i.ProductId;

-- List customers that have not placed orders.
SELECT TotalAmount, FirstName, LastName, City, Country
FROM [Order] o RIGHT JOIN Customer c ON o.CustomerId = c.Id WHERE TotalAmount IS NULL;

-- Match all customers and suppliers by country.
SELECT c.Fname, c.country, s.companyName
FROM Customer c JOIN Supplier s ON c.Country = s.Country;

-- Match customers that are from the same city and country.
SELECT c1.Fname+' '+ c1.Lname AS Customer1, c2.Fname + ' ' + c2.Lname) AS Customer2, c2.City, c2.Country
FROM Customer c1, Customer c2 WHERE c1.Id != c2.Id AND c1.City = c2.City AND c1.Country = c2.Country;

-- List all contacts, i.e., suppliers and customers.
SELECT 'Customer' AS "Customer/Supplier", FirstName + ' ' + LastName AS ContactName FROM Customer
UNION SELECT 'Supplier', ContactName FROM Supplier;

-- List products with order quantities greater than 100.
SELECT ProductName FROM Product 
 WHERE Id IN (SELECT ProductId FROM Order_Item WHERE quantity > 100);

-- List all customers with their total number of orders.
SELECT FName + ' ' + LName AS Name, "Total Orders" = (SELECT COUNT(o.Id) FROM [Order] o WHERE o.CustomerId = c.Id) FROM Customer c; 

-- Which products were sold by the unit (i.e. quantity = 1).
SELECT ProductName FROM Product WHERE Id IN (SELECT ProductId FROM Order_Item WHERE quantity = 1);
