-- Write a SQL query that lists the names of any songs that have danceability, energy, and valence greater than 0.75.
SELECT name
FROM songs
WHERE danceability > 0.75
AND energy > 0.75
AND valence > 0.75;