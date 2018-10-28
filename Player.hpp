#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Bullet.hpp"
#include "GameEntity.hpp"


class Player : public GameEntity
{

public:

	Player(int x, int y, int damage);
	Player(Player const & player);
	~Player();

	Player & operator=(Player const & player);

	void move(int x, int y);
	void clear(void) const;
	void shoot(void);
	void drawEntity(void);

private:
	int _damage;
	//int _speed;
};

#endif
