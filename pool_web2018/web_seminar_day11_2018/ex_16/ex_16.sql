SELECT MONTHNAME(birthdate)
FROM profiles 
WHERE id IN (SELECT profile_id FROM member WHERE id BETWEEN 42 AND  84);