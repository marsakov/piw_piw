/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:58:46 by msakovyc          #+#    #+#             */
/*   Updated: 2018/10/07 22:38:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

int checkCoord(Bullet & bullet, Player & player) {
	for (unsigned int i = 0; i < Bullet::bulletPoolSize && Bullet::bulletPool[i]; i++) {
		if (Bullet::bulletPool[i] != &bullet &&
		 Bullet::bulletPool[i]->getHealth() != 0 &&
		  Bullet::bulletPool[i]->getX() == bullet.getX() &&
		   Bullet::bulletPool[i]->getY() == bullet.getY()) 
		{
			Bullet::bulletPool[i]->takeDamage(bullet.getDamage());
			bullet.takeDamage(100);
			return (0);
		}
	}
	for (unsigned int i = 0; i < Enemy::warriorPoolSize && Enemy::warriorPool[i]; i++) {
		if (Enemy::warriorPool[i]->getHealth() != 0 &&
		 (Enemy::warriorPool[i]->getX() == bullet.getX() 
		 	|| Enemy::warriorPool[i]->getX() + 1 == bullet.getX()
		 	|| Enemy::warriorPool[i]->getX() + 2 == bullet.getX()
		 	|| Enemy::warriorPool[i]->getX() + 3 == bullet.getX() 
		 	|| Enemy::warriorPool[i]->getX() + 4 == bullet.getX())
		 && Enemy::warriorPool[i]->getY() == bullet.getY())
		{
			Enemy::warriorPool[i]->takeDamage(bullet.getDamage());
			bullet.takeDamage(100);
			return (0);
		}
	}
	if (player.getHealth() != 0 && (player.getX() == bullet.getX() 
		|| player.getX() + 1 == bullet.getX() 
		|| player.getX() + 2 == bullet.getX() 
		|| player.getX() + 3 == bullet.getX() 
		|| player.getX() + 4 == bullet.getX()) 
		&& player.getY() == bullet.getY()) 
	{
		player.takeDamage(bullet.getDamage());
		bullet.takeDamage(100);
	}
	return (1);
}

void	movePlayerMove(Player &player)
{
	int	c;

	if ((c = getch()) != 'q')
	{
		if (c == KEY_LEFT)
		{
			if (player.getX() > 0)
			{
				player.clear();
				player.setPos(player.getX() - 1, player.getY());
			}
		}
		if (c == KEY_RIGHT)
		{
			if (player.getX() < COLS - 1)
			{
				player.clear();
				player.setPos(player.getX() + 1, player.getY());
			}
		}
		if (c == 32)
		{
			player.shoot();
		}
	}
}

void	moveBullets(Enemy enemy, int eRows, int eCols)
{
	for (int i = 0; i < eRows; ++i) {
		for (int j = 0; j < eCols; ++j) {
			for (int k = 1; k <= eRows - i; k++) {
				if ((i * eCols + j) + k * eCols < eCols * eRows && enemy.warriorPool[(i * eCols + j) + k * eCols]->isAlive()) {
					break;
				}
				if (k == eRows - i && enemy.warriorPool[(i * eCols + j)]->isAlive())
					enemy.warriorPool[(i * eCols + j)]->shoot();
			}
		}
	}
}


int 	moveAll(Enemy enemy, int &directionVector, int eCols, int eRows) {

	mvprintw(LINES - 5, 0, "                                ");
	if (directionVector == -1 && enemy.warriorPool[0] && enemy.warriorPool[0]->getX() - 1 == -1) {
		directionVector = 1;
		for (int i = 0; i < eCols * eRows; i++) {
			enemy.warriorPool[i]->clear();
			if (!enemy.warriorPool[i]->setPos(enemy.warriorPool[i]->getX() + directionVector, enemy.warriorPool[i]->getY() + 1))
				return (0);
			if (enemy.warriorPool[i]->isAlive())
				enemy.warriorPool[i]->drawEntity();
		}
	}
	else if (directionVector == 1 && enemy.warriorPool[eCols - 1]->getX() + 1 == COLS) {
		directionVector = -1;
		for (int i = 0; i < eCols * eRows; i++) {
			enemy.warriorPool[i]->clear();
			if (!enemy.warriorPool[i]->setPos(enemy.warriorPool[i]->getX() + directionVector, enemy.warriorPool[i]->getY() + 1))
				return (0);
			if (enemy.warriorPool[i]->isAlive())
				enemy.warriorPool[i]->drawEntity();
		}
	}
	else {
		for (int i = 0; i < eCols * eRows; i++) {
			enemy.warriorPool[i]->clear();
			if (!enemy.warriorPool[i]->setPos(enemy.warriorPool[i]->getX() + directionVector, enemy.warriorPool[i]->getY()))
				return (0);
			if (enemy.warriorPool[i]->isAlive())
				enemy.warriorPool[i]->drawEntity();
		}
	}

	for (unsigned int i = 0; Bullet::bulletPool[i] && i < Bullet::bulletPoolSize; i++)
	{
		Bullet::bulletPool[i]->clear();
		if (Bullet::bulletPool[i]->getPvsE())
			Bullet::bulletPool[i]->setY(Bullet::bulletPool[i]->getY() + 1);
		else
			Bullet::bulletPool[i]->setY(Bullet::bulletPool[i]->getY() - 1);
		if (Bullet::bulletPool[i]->getY() < 0 || Bullet::bulletPool[i]->getY() > LINES - 1)
			Bullet::bulletPool[i]->takeDamage(100);
		if (Bullet::bulletPool[i]->isAlive())
			Bullet::bulletPool[i]->drawEntity();
	}
	return (1);
}

int		allAlive() {
	int result = 0;
	for (unsigned int i = 0; i < Enemy::warriorPoolSize && Enemy::warriorPool[i]; i++) {
		if (Enemy::warriorPool[i]->isAlive()) {
			result = 1;
		}
	}
	return (result);
}

void	init(int *eCols, int *eRows, Enemy *enemy) {

	initscr();
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(4, COLOR_BLACK, COLOR_RED);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);

	cbreak();
	nodelay(stdscr, true);

	keypad(stdscr, TRUE);
	curs_set(0);
	refresh();

	attron(COLOR_PAIR(1));
	mvprintw(LINES / 2, COLS / 2 - 10, "Press [ENTER] to start game");
	attroff(COLOR_PAIR(2));
	char c = 0;
	while (c != '\n')
		c = getch();
	mvprintw(LINES / 2, 0, "%*.*s", COLS, COLS - 1, " ");

	nodelay(stdscr, true);

	if (COLS % 2 == 0)
		*eCols = COLS * 3 / 43 - 1;
	else
		*eCols = COLS * 3 / 43;

	if ((LINES / 2) % 2 == 0)
		*eRows = LINES / 8 - 1;
	else
		*eRows = LINES / 8;

	for (int i = 0; i < *eRows; ++i)
	{
		for (int j = 0; j < *eCols; ++j)
		{
			enemy->addToWarriorPool(new Enemy(10 * (j + 1), 4 * (i + 1), 100));
			if (j == 1)
				enemy->warriorPool[i * *eCols + j]->setLeftChap();
			if (j == *eCols)
				enemy->warriorPool[i * *eCols + j]->setRightChap();
		}
	}
}



int		main(void) {
	int	eCols;
	int eRows;
	Enemy enemy;
	Player* player;
	double duration;
	char c = 0;

	init(&eCols, &eRows, &enemy);

	std::clock_t start = std::clock();
	player = new Player(COLS / 2, LINES - 1, 100);

	int directionVector = -1;

	int counter = 0;
	while (player->isAlive())
	{
		if (!allAlive()) {
			attron(COLOR_PAIR(1));
			mvprintw(LINES / 2, COLS / 2 - 10, "YOU WON [press ENTER]");
			attroff(COLOR_PAIR(1));
			c = 0;
			while (c != '\n')
				c = getch();
			endwin();
			exit(0);
		}
		if (counter % 1000 == 0)
			if (!moveAll(enemy, directionVector, eCols, eRows))
				break;
		if (counter == 5000) {
			moveBullets(enemy, eRows, eCols);
			counter = 0;
		}
		player->drawEntity();

		for (int i = 0; i < eRows; ++i) {
			for (int j = 0; j < eCols; ++j) {
				if (enemy.warriorPool[(i * eCols + j)]->isAlive())
					enemy.warriorPool[(i * eCols + j)]->drawEntity();
			}
		}
		for (unsigned int i = 0; i < Bullet::bulletPoolSize && Bullet::bulletPool[i]; i++) {
			checkCoord(*Bullet::bulletPool[i], *player);
		}
		movePlayerMove(*player);
		refresh();
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
		attron(COLOR_PAIR(1));
		mvprintw(0, COLS - 10, "%f", duration);
		attroff(COLOR_PAIR(1));
		counter++;
	}
	attron(COLOR_PAIR(4));
	mvprintw(LINES / 2, COLS / 2 - 10, "GAME END [press ENTER]");
	attroff(COLOR_PAIR(4));
	c = 0;
	while (c != '\n')
		c = getch();
	refresh();
	nodelay(stdscr, false);
	getch();
    endwin();
	return (0);
}
