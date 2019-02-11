/*
** EPITECH PROJECT, 2018
** exo-1.c
** File description:
**
*/

#include "ex00.h"

void attack(cthulhu_t *this)
{
	if (this->m_power >= 42) {
		this->m_power -= 42;
		printf("%s attacks and destroys the city\n", this->m_name);
	} else
		printf("%s can't attack, he doesn't have enough power\n",
		       this->m_name);
}

void sleeping(cthulhu_t *this)
{
	this->m_power += 42000;
	printf("%s sleeps\n", this->m_name);
}


void eat(koala_t *this)
{
	this->m_parent.m_power += 42;
	printf("%s eats\n", this->m_parent.m_name);
}

void print_power(cthulhu_t *this)
{
	printf("Power => %d\n", this->m_power);
}

static void CthulhuInitializer(cthulhu_t *this)
{
	printf ("----\nBuilding Cthulhu\n");
	this->m_name = strdup("Cthulhu");
	this->m_power = 42;
}

cthulhu_t *new_cthulhu()
{
	cthulhu_t *this;

	if ((this = malloc(sizeof(this))) == NULL)
		return (NULL);
	CthulhuInitializer(this);
	return (this);
}

static void KoalaInitializer(koala_t *this, char *name, char _isALegend)
{
	this->KoalaInitializer = &KoalaInitializer;
	this->CthulhuInitializer = &CthulhuInitializer;
	this->m_isALegeend = _isALegend;
	this->m_parent = *new_cthulhu();
	this->m_parent.m_name = strdup(name);
	if (!_isALegend)
		this->m_parent.m_power = 0;
	printf("Building %s\n", name);
}

koala_t *new_koala(char *name, char _isALegend)
{
	koala_t *this;

	if ((this = malloc(sizeof this)) == NULL)
		return (NULL);
	KoalaInitializer(this, name, _isALegend);
	return (this);
}
