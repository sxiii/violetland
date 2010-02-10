#include <stdlib.h>
#include <iostream>
#include <vector>
#include "SDL_opengl.h"
#include "SDL_mixer.h"
#include "../system/graphic/Texture.h"
#include "../system/utility/ImageUtility.h"
#include "../system/sound/Sound.h"
#include "bullets/StandardBullet.h"
#include "bullets/LaserBullet.h"
#include "bullets/GrenadeBullet.h"

#ifndef WEAPON_H_
#define WEAPON_H_

class Weapon {
private:
	int m_fireDelay;
	int m_reload;
	Texture *m_droppedTex;
	Texture *m_bulletTex;
	Texture *m_playerTex;
	Sound* m_shotSound;
	Sound* m_reloadSound;
	int m_reloadSndCh;
public:
	Weapon(Texture* droppedTex, Texture* playerTex, Sound* shotSound,
			Sound* reloadSound);
	void setBulletImage(std::string image);
	void process(int deltaTime);
	std::vector<Bullet*> *fire(float x, float y, float dX, float dY);
	bool reload(float timeMod);
	void pickup();
	float getReloadState();
	void deleteResources();
	Texture *getDroppedTex();
	Texture *getPlayerTex();
	~Weapon();
	Sprite* ShellSprite;
	Bullet::BulletType Type;
	std::string Name;
	int FireDelayTime;
	int ReloadTime;
	int AmmoClipSize;
	int Ammo;
	float Damage;
	float BulletSpeed;
	float FireRange;
	float ReturnForce;
	int BulletsAtOnce;
	float XDiff;
	float YDiff;

	bool Poisoned;
};

#endif /* WEAPON_H_ */