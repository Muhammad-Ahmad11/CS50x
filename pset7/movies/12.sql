SELECT title FROM movies WHERE id IN (SELECT stars.movie_id FROM stars WHERE person_id IN (SELECT id FROM people
WHERE name == "Johnny Depp") INTERSECT SELECT stars.movie_id FROM stars WHERE person_id IN (SELECT id FROM people
WHERE name == "Helena Bonham Carter"));
