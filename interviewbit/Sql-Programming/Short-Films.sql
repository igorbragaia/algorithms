select
    movies.movie_title as movie_title,
    movies.movie_year as movie_year,
    concat(directors.director_first_name, directors.director_last_name) as director_name,
    concat(actors.actor_first_name, actors.actor_last_name)  as actor_name,
    movies_cast.role as role
from
    movies
    join movies_cast on movies_cast.movie_id = movies.movie_id
    join actors on actors.actor_id = movies_cast.actor_id
    join movies_directors on movies_directors.movie_id = movies.movie_id
    join directors on directors.director_id = movies_directors.director_id
where movie_time in (select min(movie_time) from movies)
