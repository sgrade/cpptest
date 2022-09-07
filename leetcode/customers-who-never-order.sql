# 183. Customers Who Never Order
# https://leetcode.com/problems/customers-who-never-order/

# Write your MySQL query statement below
SELECT
    customers.name AS 'Customers'
FROM customers
WHERE customers.id NOT IN
(
    SELECT customerid FROM orders
)
;
