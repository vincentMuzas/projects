<?php

class Personage
{
	private $_force;
	private $_emplacement;
	private $_expérience;
	private $_dégats;


	function __construct()
	{
		$_force = 10;
		$_emplacement = 0;
		$_expérience = 0;
		$_dégats = "tamer";
	}
	public function deplacer()
	{
		$this->_emplacement++;
		print $this->_emplacement;
	}
}
?>