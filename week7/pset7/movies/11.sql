/*
Write a SQL query to list the titles of the five highest rated movies (in order) that
Chadwick Boseman starred in, starting with the highest rated.
  - Your query should output a table with a single column for the title of each movie.
  - You may assume that there is only one person in the database with the name Chadwick Boseman.
*/
SELECT movies.title
FROM stars
JOIN movies ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;