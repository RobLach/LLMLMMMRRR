#pragma once
#include <Monocle.h>
#include <Graphics/Sprite.h>
#include <Graphics/SpriteAnimation.h>
#include <Graphics/SpriteSequenceAnimation.h>
#include <Level.h>
#include "city.h"
#include <queue>

#ifdef DEBUG
#define MAX_PARTICLES 500
#else
#define MAX_PARTICLES 2500
#endif
using namespace Monocle;

namespace LL
{
	class mainScene;

	class Text: public Entity
	{
	public:
		Text(const std::string& text, FontAsset* font);

		void Render();

		void SetFont(FontAsset* font) { this->font = font; }
		void SetText(const std::string& text) { this->text = text; }

		FontAsset* font;
		std::string text;
	};

	class bgStatic : public Entity
	{
	public:
		SpriteSequenceAnimation *anim;
		float amp;
		bgStatic();
		void Update();
	};

	class menuScene : public Scene
	{
	public:
		void Begin();
		void End();
		void Update();

		Text* LL;
		Text* ML;
		Text* MM;
		Text* MR;
		Text* RR;
		Text* credit;
		Text* timer;

		Entity* bgClearer;
		Entity* logo;

		Entity* plat1;
		Entity* plat2;
		Entity* plat3;
		Entity* plat4;
		Entity* plat5;
		
		bool somethingHeld;
		double timeHeld;
		AudioDeck* bgMusic;
	};


	class Particle
	{
	public:
		Vector2 position;
		Vector2 velocity;
		float rotation;
		float rotationalVel;
		Vector2 currentGrid;
		Vector2 lastGrid;
		double lifeSpan;
		double origLife;
		Sprite* sprite;
		mainScene* scene;
		Vector2 size;
		Vector2 origSize;
		Vector2 sizeTo;
		bool alive;
		float alpha;
		Color color;
		Color origColor;
		Color colorTarget;

		Particle();
		void Init(Vector2 pos, Vector2 vel, Vector2 siz, Vector2 sizTo, float rot, float rotvel, Vector2 grid, double life, float alpha, mainScene* sce, Color colorStart, Color colorTo);
		void Update();
		void Render();
		void Die();

	};

	class Projectile: public Entity
	{
	public:
		Vector2 velocity;
		RectangleCollider* rectCollider;
		Sprite* sprite;
		Vector2 currentGrid;
		double lifeSpan;
		Vector2 size;
		std::string ignoreThis;

		mainScene* scene;
		Projectile(Vector2 pos, Vector2 vel, Vector2 grid, float rot, Vector2 size, double lifeSpan, std::string ignore);
		void Die();
		void Update();
		void Render();
	};

	class baseShip : public Entity
	{
	public:
		enum direction{ UP = 0, DOWN, LEFT, RIGHT};
		Vector2 velocity;
		Vector2 lastGrid;
		Vector2 currentGrid;
		int health;
		RectangleCollider * rectCollider;
		mainScene* scene;
		direction curDir;

		Entity* wheelTL;
		Entity* wheelTR;
		Entity* wheelBL;
		Entity* wheelBR;
		
		Entity* turretTL;
		Entity* turretTR;
		Entity* turretBL;
		Entity* turretBR;

		baseShip(Vector2 pos, mainScene* sce);

		void Update();
		void Render();
		void Die();
	};

	class Fighter : public Entity
	{
	public:
		int health;
		mainScene* scene;
		Vector2 currentGrid;
		Vector2 velocity;
		bool targeting;

		Vector2 targetDirection;


		Fighter(Vector2 pos, Vector2 vel, float rot, mainScene* sce, Vector2 curGrid);
		void Update();
		void Render();
	};

	class playerShip : public Entity
	{
	public:
		Vector2 velocity;
		Vector2 currentGrid;

		float rotationalVel;
		CircleCollider* collider;
		Sprite* sprite;

		float colorUpdater;

		float health;
		bool hitAlarm;
		bool dead;
		bool gameOver;

		float deathTimer;
		void Update();

		playerShip();
	};
	
	class mainScene : public Scene
	{
	public:
		void Begin();
		void End();
		void Update();
		void Render();

		void EmitParticle(Vector2 pos, Vector2 vel, Vector2 siz, Vector2 sizTo, float rot, float rotvel, Vector2 grid, double life, float alpha, Color colorStart, Color colorTo);
		void HSVtoRGB( float* r, float*g, float* b, float h, float s, float v);

		double time;
		double lastTime;
		double BPM;
		float gameTime;
		float winTimer;
		float inactivity;

		double ttBeat;
		double tBtwBeat;

		double ttHalf1;
		double ttHalf2;
		//double tBtwHalf;

		double ttQuarter1;
		double ttQuarter2;
		double ttQuarter3;
		double ttQuarter4;
		//double tBtwQuarter;

		bool hitBeat;
		bool hitHalf;
		bool hitQuarter;

		bool started;
		bool win;

		Vector2 camVel;
		Vector2 shakeMulti;
		std::list<Particle*> particleQ;
		std::list<Particle*> deathList;
		std::list<baseShip*> baseShips;

		Text* health;
		Text* enemies;
		Text* timer;
		
		//Text*		debugText;
		playerShip*	pShip;
		city*		 City;
		bgStatic*	bgstatic;
		
		float energyPercentage;
	};


}