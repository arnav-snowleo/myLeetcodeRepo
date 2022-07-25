# using join

SELECT c.name as Customers from Customers c LEFT JOIN Orders o ON 

       (c.id = o.customerId)
       
       where o.customerId is NULL;
       
       