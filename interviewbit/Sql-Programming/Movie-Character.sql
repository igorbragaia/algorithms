select concat(directors.director_first_name, directors.director_last_name) as director_name,
        movies.movie_title as movie_title
from movies_directors
    join directors on movies_directors.director_id = directors.director_id
    join movies on movies_directors.movie_id = movies.movie_id
    join movies_cast on movies_cast.movie_id = movies.movie_id
where
    movies_cast.role = 'SeanMaguire'
