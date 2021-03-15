/*
Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
  - Your query should output a table with a single column for the name of each person.
  - There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
  - Kevin Bacon himself should not be included in the resulting list.
*/
WITH kevin_bacon_movie_id AS (
    SELECT movie_id
    FROM stars
    WHERE person_id = (SELECT id FROM people
                       WHERE name = "Kevin Bacon"
                       AND birth = 1958)
)
SELECT DISTINCT people.name
FROM stars
JOIN people ON stars.person_id = people.id
WHERE stars.movie_id IN kevin_bacon_movie_id
AND people.name != "Kevin Bacon";
