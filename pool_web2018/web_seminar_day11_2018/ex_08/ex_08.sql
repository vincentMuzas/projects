SELECT title FROM movies WHERE genre_id IN (SELECT id FROM genres WHERE name = 'action' OR name = 'romance');