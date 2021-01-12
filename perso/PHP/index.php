<?php
require "test.php";

$perso = new Personage;
$_i = 0;
while ($_i < 11) {
	$perso->deplacer();
	print "\n";
	$_i++;
}
?>