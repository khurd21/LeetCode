/* **********************************************************************
 * Link: https://leetcode.com/problems/combine-two-tables/
 * Author: Kyle Hurd
 * **********************************************************************
 *
 * **********************************************************************
 * Problem: Combine Two Tables
 * 
 * Table: Person
 *
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | personId    | int     |
 * | lastName    | varchar |
 * | firstName   | varchar |
 * +-------------+---------+
 * personId is the primary key column for this table.
 * This table contains information about the ID of some persons and their first and last names. 
 * 
 * Table: Address
 *
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | addressId   | int     |
 * | personId    | int     |
 * | city        | varchar |
 * | state       | varchar |
 * +-------------+---------+
 * addressId is the primary key column for this table.
 * This table contains information about the ID of some addresses, their cities and states, and the ID of the person who lives there.
 *
 * Write a SQL query for a report that provides the following information for each person in the Person table,
 * regardless if there is an address for each of those people:
 *
 * FirstName, LastName, City, State
 *
 * **********************************************************************/

SELECT firstName, lastName, city, state
FROM Person
LEFT JOIN Address ON Person.personId=Address.personId;
