#pragma once
#include <Monocle.h>
#include <Level.h>
#include <Input.h>
#include <Macros.h>
#include <stdlib.h>
#include <Graphics/Sprite.h>
#include <Graphics/SpriteAnimation.h>
//#include "LL.h"

using namespace Monocle;

namespace LL
{
		enum tileType{
		empty = 0,
		roadEW,
		roadNS,
		roadEScorner,
		roadWScorner,
		roadENcorner,
		roadWNcorner,
		roadNSE,
		roadNSW,
		roadSEW,
		roadNEW,
		roadIntersection,
		square00,
		square01,
		square02,
		square10,
		square11,
		square12,
		square20,
		square21,
		square22,
		mayor00,
		mayor10,
		mayor20,
		mayor01,
		mayor11,
		mayor21,
		park0,
		park1,
		park2,
		bldg1x1_1,
		bldg1x1_2,
		bldg1x1_3,
		bldg1x1_4,
		bldg1x1_5,

		bldg2x2_1,
		bldg2x2_1_TL,
		bldg2x2_1_TR,
		bldg2x2_1_BL,
		bldg2x2_1_BR,
		
		bldg2x2_2,
		bldg2x2_2_TL,
		bldg2x2_2_TR,
		bldg2x2_2_BL,
		bldg2x2_2_BR,

		bldg2x2_3,
		bldg2x2_3_TL,
		bldg2x2_3_TR,
		bldg2x2_3_BL,
		bldg2x2_3_BR,


		bldg2x2_4,
		bldg2x2_4_TL,
		bldg2x2_4_TR,
		bldg2x2_4_BL,
		bldg2x2_4_BR,


		bldg3x3_1,
		bldg3x3_1_00,
		bldg3x3_1_10,
		bldg3x3_1_20,
		bldg3x3_1_01,
		bldg3x3_1_11,
		bldg3x3_1_21,
		bldg3x3_1_02,
		bldg3x3_1_12,
		bldg3x3_1_22,

		bldg3x3_2,
		bldg3x3_2_00,
		bldg3x3_2_10,
		bldg3x3_2_20,
		bldg3x3_2_01,
		bldg3x3_2_11,
		bldg3x3_2_21,
		bldg3x3_2_02,
		bldg3x3_2_12,
		bldg3x3_2_22,

		bldg3x3_3,
		bldg3x3_3_1,
		bldg3x3_3_2,
		bldg3x3_3_3,

		bldg4x4_1,
		bldg4x4_1_00,
		bldg4x4_1_10,
		bldg4x4_1_20,
		bldg4x4_1_30,
		bldg4x4_1_01,
		bldg4x4_1_11,
		bldg4x4_1_21,
		bldg4x4_1_31,
		bldg4x4_1_02,
		bldg4x4_1_12,
		bldg4x4_1_22,
		bldg4x4_1_32,
		bldg4x4_1_03,
		bldg4x4_1_13,
		bldg4x4_1_23,
		bldg4x4_1_33,


		bldg4x4_2,

		bldg5x5,
		bldg5x5TL,
		bldg5x5TR,
		bldg5x5BL,
		bldg5x5BR,
		bldg5x5SI,
		bldg5x5CE,
	};

	class city;
	class cityTile : public Entity
	{
	public:
		tileType type;
		int floors;
		bool onFire;
		int health;
		int width, height;
		city* parentCity;
		Sprite* origSprite;

		Color targetColor;
		Color grayScale;

		cityTile();
		RectangleCollider* rectCollider;
		cityTile(tileType type, int floors, city* parent);
		//cityTile(int bldgType); //bldgtype = 1, 2, 3 ,4, 5
		void setHouse(int type);
		void setTile(tileType setType, int floors, city* parent);
		void setFrom(cityTile* tile);
		void takeHit();
		bool isRoad();

		void setGraphic();

		void Update();
		void Render();
	};
	
	class renderItem{
	public:
		cityTile* tile;
		int floor;
	};


	class city : public Entity{
	public:
		int width;
		int height;
		Scene* parentScene;
		std::map<int, std::map<int, std::list<renderItem*>>> renderLists;
		std::list<renderItem*> renderList;

		bool hitBeat;
		bool hitHalfBeat;
		bool hitQuarterBeat;
		bool colorShift;

		int centerX;
		int centerY;

		float multi;

		int cameraX;
		int cameraY;

		float colorAmp;

		cityTile*** tiles;
		
		city(int width, int height, Scene* scene);
		~city();
		
		
		void generate();
		void fixRoads();
		void loadSprites();
		void buildRenderList();
		void Render();
		void Update();
	};


}