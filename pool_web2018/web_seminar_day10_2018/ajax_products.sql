-- phpMyAdmin SQL Dump
-- version 4.4.10
-- http://www.phpmyadmin.net
--
-- Client :  localhost:8889
-- Généré le :  Sam 02 Avril 2016 à 14:51
-- Version du serveur :  5.5.42
-- Version de PHP :  5.6.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Base de données :  `ajax_products`
--

-- --------------------------------------------------------

--
-- Structure de la table `products`
--

CREATE TABLE `products` (
  `id` int(11) NOT NULL,
  `type` varchar(255) DEFAULT NULL,
  `brand` varchar(255) DEFAULT NULL,
  `price` int(10) unsigned NOT NULL,
  `stock` int(11) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `products`
--

INSERT INTO `products` (`id`, `type`, `brand`, `price`, `stock`) VALUES
(1, 'shoes', 'geox', 50, 10),
(2, 'shoes', 'vans', 90, 5),
(3, 'shoes', 'swaggy_300', 10, 140),
(4, 'shoes', 'bigfeet', 40, 0),
(13, 'shoes', 'reebok', 38, 40),
(14, 'jeans', 'diesel', 70, 15),
(15, 'jeans', 'fatass', 40, 4),
(16, 'jeans', 'celio', 60, 50),
(17, 'jeans', 'bonobo', 120, 0),
(18, 'cap', 'psg', 38, 60),
(19, 'cap', 'buffalo', 14, 9),
(20, 'cap', 'nike', 25, 12),
(21, 'coat', 'kiabi', 90, 0),
(22, 'coat', 'sport2000', 130, 14),
(23, 'coat', 'unistars', 70, 18),
(24, 'coat', 'megacoat', 52, 14),
(25, 'watch', 'laclass', 1360, 2),
(26, 'watch', 'rolex', 2400, 8),
(27, 'watch', 'matuvue', 18750, 1),
(28, 'watch', 'cresus', 4300, 0),
(29, 'watch', 'omega', 6000, 4),
(30, 'glass', 'google', 418, 88),
(31, 'glass', 'fly', 74, 22),
(32, 'glass', 'polnareff', 2, 10),
(33, 'underpants', 'h&m', 24, 42),
(35, 'underpants', 'slip-tiptop', 5, 12),
(36, 'underpants', 'pony-zone', 35, 0),
(37, 'underpants', 'psg', 6, 82),
(38, 't-shirt', 'lacoste', 48, 2),
(39, 't-shirt', 'oxbow', 20, 8),
(40, 't-shirt', 'love_london', 30, 42);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `products`
--
ALTER TABLE `products`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=41;
