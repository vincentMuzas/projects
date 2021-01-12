-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le :  Dim 26 avr. 2020 à 22:46
-- Version du serveur :  10.3.22-MariaDB-0ubuntu0.19.10.1
-- Version de PHP :  7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `dashboard`
--

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `username` varchar(128) NOT NULL,
  `passwd` varchar(128) NOT NULL,
  `uuid` varchar(48) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `user_widgets`
--

CREATE TABLE `user_widgets` (
  `id` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `widget_id` int(128) NOT NULL,
  `params` text CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `widget`
--

CREATE TABLE `widget` (
  `id` int(11) NOT NULL,
  `name` varchar(128) NOT NULL,
  `description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `widget`
--

INSERT INTO `widget` (`id`, `name`, `description`) VALUES
(1, 'google-maps', 'google maps'),
(2, 'weather', 'metéo'),
(3, 'youtube', 'regarder stats dernière vidéo d\'une chaine Youtube'),
(4, 'steam', 'non, ce n\'est pas steam, c\'est un flux RSS'),
(5, 'spotify', 'ecouter Spotify');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `username` (`username`);

--
-- Index pour la table `user_widgets`
--
ALTER TABLE `user_widgets`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `widget`
--
ALTER TABLE `widget`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `user_widgets`
--
ALTER TABLE `user_widgets`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `widget`
--
ALTER TABLE `widget`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
