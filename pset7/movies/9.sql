SELECT name FROM people WHERE id IN (SELECT DISTINCT stars.person_id FROM stars WHERE movie_id IN (SELECT id FROM movies
WHERE year LIKE 2004)) ORDER BY birth;