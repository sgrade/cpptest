# 182. Duplicate Emails
# https://leetcode.com/problems/duplicate-emails/

# Write your MySQL query statement below
select Email
from Person
group by Email
having count(Email) > 1;
