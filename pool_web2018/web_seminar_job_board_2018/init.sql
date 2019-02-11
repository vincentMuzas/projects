DROP DATABASE IF EXISTS job_board;
CREATE DATABASE job_board;

USE job_board;

CREATE TABLE advertisements (
	id INT NOT NULL AUTO_INCREMENT,
	company_id INT NOT NULL,
	title VARCHAR(128),
	summary VARCHAR(8000),
	wages VARCHAR(128),
	working_time VARCHAR(128),
	PRIMARY KEY (id)
	);

CREATE TABLE companies (
	id INT NOT NULL AUTO_INCREMENT,
	name VARCHAR(128),
	address VARCHAR(1024),
	phone VARCHAR(32),
	PRIMARY KEY (id)
);

CREATE TABLE people (
	id INT NOT NULL AUTO_INCREMENT,
	name VARCHAR(128),
	birthdate DATE,
	address VARCHAR(1024),
	phone VARCHAR(32),
	PRIMARY KEY (id)
);

CREATE TABLE application (
	id INT NOT NULL AUTO_INCREMENT,
	people_id INT NOT NULL,
	advertisement_id INT NOT NULL,
	message VARCHAR(8000),
	PRIMARY KEY (id)
);