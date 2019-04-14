select distinct(movies.movie_title) as movie_title
from movies
    join movies_cast on movies.movie_id = movies_cast.movie_id
    join actors on movies_cast.actor_id = actors.actor_id
where
actors.actor_id in
                    (
                        select distinct(actors.actor_id)
                        from movies
                            join movies_cast on movies.movie_id = movies_cast.movie_id
                            join actors on movies_cast.actor_id = actors.actor_id
                        group by actors.actor_id
                        having count(actors.actor_id) > 1
                    )
