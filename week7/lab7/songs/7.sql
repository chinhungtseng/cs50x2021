-- Write a SQL query that returns the average energy of songs that are by Drake.
SELECT AVG(songs.energy)
FROM songs
JOIN artists on songs.artist_id = artists.id
WHERE artists.name = "Drake";