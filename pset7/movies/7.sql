SELECT title,rating FROM ratings INNER JOIN movies ON ratings.movie_id == movies.id WHERE year LIKE 2010
ORDER BY rating DESC,title;