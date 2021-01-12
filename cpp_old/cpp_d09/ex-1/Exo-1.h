/*
** EPITECH PROJECT, 2018
** exo1.h
** File description:
**
*/

#ifndef EXO_1_H_
# define EXO_1_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_cthulhu cthulhu_t;
typedef struct s_koala koala_t;

koala_t *NewKoala(char *name, char _isALegend);
cthulhu_t *NewCthulhu();

void Eat(koala_t *this);

void PrintPower(cthulhu_t *this);
void Attack(cthulhu_t *this);
void Sleeping(cthulhu_t *this);


struct s_koala
{
	struct s_cthulhu
	{
		int m_power;
		char *m_name;
	} m_parent;
	char m_isALegeend;
	void (*KoalaInitializer)(koala_t *this, char *_name, char _isALegend);
	void (*CthulhuInitializer)(cthulhu_t *this);
};

#endif /* !EXO-1_H_ */
