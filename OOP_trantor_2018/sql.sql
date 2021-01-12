DROP DATABASE IF EXISTS zappy;

CREATE DATABASE zappy;

USE zappy;

CREATE TABLE teams (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR (50),
  skill_mu INT,
  skill_sigma INT,
  PRIMARY KEY (id)
);

CREATE TABLE matches (
    id INT NOT NULL AUTO_INCREMENT,
    id_team1 INT NOT NULL,
    id_team2 INT NOT NULL,
    start DATE,
    end DATE,
    winner INT,
    PRIMARY KEY (id),
    FOREIGN KEY (id_team1) REFERENCES teams (id) ON DELETE CASCADE,
    FOREIGN KEY (id_team2) REFERENCES teams (id) ON DELETE CASCADE
);