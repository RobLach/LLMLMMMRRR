#include "city.h"

namespace LL
{

		Sprite* roadEWsprite;
		Sprite* roadNSsprite;
		Sprite* roadEScornersprite;
		Sprite* roadWScornersprite;
		Sprite* roadENcornersprite;
		Sprite* roadWNcornersprite;
		Sprite* roadNSEsprite;
		Sprite* roadNSWsprite;
		Sprite* roadSEWsprite;
		Sprite* roadNEWsprite;
		Sprite* roadIntersectionsprite;
		Sprite* square00sprite;
		Sprite* square01sprite;
		Sprite* square02sprite;
		Sprite* square10sprite;
		Sprite* square11sprite;
		Sprite* square12sprite;
		Sprite* square20sprite;
		Sprite* square21sprite;
		Sprite* square22sprite;
		Sprite* mayor00sprite;
		Sprite* mayor10sprite;
		Sprite* mayor20sprite;
		Sprite* mayor01sprite;
		Sprite* mayor11sprite;
		Sprite* mayor21sprite;
		Sprite* park0sprite;
		Sprite* park1sprite;
		Sprite* park2sprite;
		Sprite* bldg1x1_1sprite;
		Sprite* bldg1x1_2sprite;
		Sprite* bldg1x1_3sprite;
		Sprite* bldg1x1_4sprite;
		Sprite* bldg1x1_5sprite;
		Sprite* bldg2x2_1sprite;
		Sprite* bldg2x2_2sprite;
		Sprite* bldg2x2_3sprite;
		Sprite* bldg2x2_4sprite;
		Sprite* bldg2x2_5sprite;
		Sprite* bldg3x3_1sprite;
		Sprite* bldg3x3_2sprite;
		Sprite* bldg3x3_3sprite;
		Sprite* bldg3x3_4sprite;
		Sprite* bldg3x3_5sprite;
		Sprite* bldg4x4_1sprite;
		Sprite* bldg4x4_2sprite;
		Sprite* bldg4x4_3sprite;
		Sprite* bldg5x5sprite;

		Sprite* blank;


	cityTile::cityTile(){
		Entity();
		type = empty;
		floors = 0;
		onFire = false;
		health = 100;
		position = Vector2(0,0);
		width = 128;
		height = 128;
		//SetLayer(floors);
		rectCollider = new RectangleCollider(width,height);
		SetCollider(rectCollider);
		//color = Color(1,1,1, 0.1f);
		
	}

	cityTile::cityTile(tileType typ, int floorr, city* rent){
		Entity();
		parentCity = rent;
		type = typ;
		floors = floors;
		onFire = false;
		health = 100;
		position = Vector2(0,0);
		width = 128;
		height = 128;
		//SetLayer(floors);
		rectCollider = new RectangleCollider(width,height);
		SetCollider(rectCollider);
		//color = Color(1,1,1, 0.1f); //lloks awesome
		color = Color::white;
		targetColor = Color::white;
		grayScale = Color::white;
	}

	void cityTile::setHouse(int typ){
		//Entity();
		health = 100;
		onFire = false;
		
		targetColor = Color(Random::Float(0,1),Random::Float(0,1),Random::Float(0,1),color.a);	
		
		if(typ == 1)
		{
			floors = Random::Int(1,3);

			float rand = Random::Percent();

			if(rand<=1.0f/5.0f){
				type = bldg1x1_1;
			}
			else if(rand>1.0f/5.0f && rand <= 2.0f/5.0f){
				type = bldg1x1_2;
			}
			else if(rand>2.0f/5.0f && rand <= 3.0f/5.0f){
				type = bldg1x1_3;
			}
			else if(rand>3.0f/5.0f && rand <= 4.0f/5.0f){
				type = bldg1x1_4;
			}
			else if(rand > 4.0f/5.0f){
				type = bldg1x1_5;
			}
		}

		if(typ == 2)
		{
			floors = Random::Int(3,15);
			
			float rand = Random::Percent();

			if(rand<=1.0f/4.0f){
				type = bldg2x2_1;
			}
			else if(rand>1.0f/4.0f && rand <= 2.0f/4.0f){
				type = bldg2x2_2;
			}
			else if(rand>2.0f/4.0f && rand <= 3.0f/4.0f){
				type = bldg2x2_3;
			}
			else{
				type = bldg2x2_4;
			}

		}

		if(typ == 3)
		{
			floors = Random::Int(10,30);
			
			float rand = Random::Percent();

			if(rand<=1.0f/3.0f){
				type = bldg3x3_1;
			}
			else if(rand>1.0f/3.0f && rand <= 2.0f/3.0f){
				type = bldg3x3_2;
			}
			else{
				type = bldg3x3_3;
			}
		}

		if(typ == 4)
		{
			floors = Random::Int(35,55);
			
			float rand = Random::Percent();

			if(rand<=1.0f/2.0f){
				type = bldg4x4_1;
			}
			else{
				type = bldg4x4_2;
			}
		}

		if(typ == 5)
		{
			floors = Random::Int(90,110);
			type = bldg5x5;
		}

		setGraphic();
	}

	void cityTile::setTile(tileType setTo, int floorsTo, city* rent){
		parentCity = rent;
		type = setTo;
		floors = floorsTo;
		onFire = false;
		health = 100;
		setGraphic();
		//SetLayer(0);
	}

	void cityTile::setFrom(cityTile* tile){
		parentCity = tile->parentCity;
		type = tile->type;
		floors = tile->floors;
		onFire = false;
		health = 100;
		setGraphic();
		//SetLayer(0);
		color = tile->color;
		targetColor = tile->targetColor;
		grayScale = tile->grayScale;
	}

	void cityTile::takeHit(){
		--health;
	}

	void cityTile::setGraphic(){
		ClearTags();
		switch(type){
		//THESE BREAKS AREN'T NEEDED DUMBASS
		case roadEW:
			SetGraphic(new Sprite(roadEWsprite));
			AddTag("road");
			SetLayer(0);
			break;
		
		case roadNS:
			SetGraphic(new Sprite(roadNSsprite));
			AddTag("road");
			SetLayer(0);
			break;
		
		case roadNSE:
			SetGraphic(new Sprite(roadNSEsprite));
			AddTag("road");
			SetLayer(0);
			break;
		
		case roadNSW:
			SetGraphic(new Sprite(roadNSWsprite));
			AddTag("road");
			SetLayer(0);
			break;
		
		case roadSEW:
			SetGraphic(new Sprite(roadSEWsprite));
			AddTag("road");
			SetLayer(0);
			break;
		
		case roadNEW:
			SetGraphic(new Sprite(roadNEWsprite));
			AddTag("road");
			SetLayer(0);
			break;
		
		case roadEScorner:
			SetGraphic(new Sprite(roadEScornersprite));
			AddTag("road");
			SetLayer(0);
			break;
		
		case roadWScorner:
			SetGraphic(new Sprite(roadWScornersprite));
			AddTag("road");
			SetLayer(0);
			break;

		case roadENcorner:
			SetGraphic(new Sprite(roadENcornersprite));
			AddTag("road");
			SetLayer(0);
			break;

		case roadWNcorner:
			SetGraphic(new Sprite(roadWNcornersprite));
			AddTag("road");
			SetLayer(0);
			break;

		case roadIntersection:
			SetGraphic(new Sprite(roadIntersectionsprite));
			AddTag("road");
			SetLayer(0);
			break;
		case square00:
			SetGraphic(new Sprite(square00sprite));
			//AddTag("squareOut");
			break;
		case square01:
			SetGraphic(new Sprite(square01sprite));
			//AddTag("squareOut");
			break;
		case square02:
			SetGraphic(new Sprite(square02sprite));
			break;
		case square10:
			SetGraphic(new Sprite(square10sprite));
			break;
		case square11:
			SetGraphic(new Sprite(square11sprite));
			AddTag("bldg");
			break;
		case square12:
			SetGraphic(new Sprite(square12sprite));
			break;
		case square20:
			SetGraphic(new Sprite(square20sprite));
			break;
		case square21:
			SetGraphic(new Sprite(square21sprite));
			break;
		case square22:
			SetGraphic(new Sprite(square22sprite));
			break;
		case mayor00:
			SetGraphic(new Sprite(mayor00sprite));
			AddTag("bldg");
			break;
		case mayor10:
			SetGraphic(new Sprite(mayor10sprite));
			AddTag("bldg");
			break;
		case mayor20:
			SetGraphic(new Sprite(mayor20sprite));
			AddTag("bldg");
			break;
		case mayor01:
			SetGraphic(new Sprite(mayor01sprite));
			AddTag("bldg");
			break;
		case mayor11:
			SetGraphic(new Sprite(mayor11sprite));
			AddTag("bldg");
			break;
		case mayor21:
			SetGraphic(new Sprite(mayor21sprite));
			AddTag("bldg");
			break;
		case park0:
			SetGraphic(new Sprite(park0sprite));
			break;
		case park1:
			SetGraphic(new Sprite(park1sprite));
			break;
		case park2:
			SetGraphic(new Sprite(park2sprite));
			break;
		case bldg1x1_1:
			SetGraphic(new Sprite(bldg1x1_1sprite));
			AddTag("bldg");
			break;
		case bldg1x1_2:
			SetGraphic(new Sprite(bldg1x1_2sprite));
			AddTag("bldg");
			break;
		case bldg1x1_3:
			SetGraphic(new Sprite(bldg1x1_3sprite));
			AddTag("bldg");
			break;
		case bldg1x1_4:
			SetGraphic(new Sprite(bldg1x1_4sprite));
			AddTag("bldg");
			break;
		case bldg1x1_5:
			SetGraphic(new Sprite(bldg1x1_5sprite));
			AddTag("bldg");
			break;
		case bldg2x2_1:
			SetGraphic(new Sprite(bldg2x2_1sprite));
			AddTag("bldg");
			break;
		case bldg2x2_2:
			SetGraphic(new Sprite(bldg2x2_2sprite));
			AddTag("bldg");
			break;
		case bldg2x2_3:
			SetGraphic(new Sprite(bldg2x2_3sprite));
			AddTag("bldg");
			break;
		case bldg2x2_4:
			SetGraphic(new Sprite(bldg2x2_4sprite));
			AddTag("bldg");
			break;
		case bldg3x3_1:
			SetGraphic(new Sprite(bldg3x3_1sprite));
			AddTag("bldg");
			break;
		case bldg3x3_2:
			SetGraphic(new Sprite(bldg3x3_2sprite));
			AddTag("bldg");
			break;
		case bldg3x3_3:
			SetGraphic(new Sprite(bldg3x3_3sprite));
			AddTag("bldg");
			break;
		case bldg4x4_1:
			SetGraphic(new Sprite(bldg4x4_1sprite));
			AddTag("bldg");
			break;
		case bldg4x4_2:
			SetGraphic(new Sprite(bldg4x4_2sprite));
			AddTag("bldg");
			break;
		case bldg5x5:
			SetGraphic(new Sprite(bldg5x5sprite));
			AddTag("bldg");
			break;
		}
		origSprite = (Sprite*) GetGraphic();
	}

	bool cityTile::isRoad(){
		switch(type){
		//THESE BREAKS AREN'T NEEDED DUMBASS
		case roadEW:
			return true;
			break;
		
		case roadNS:
			return true;
			break;
		
		case roadNSE:
			return true;
			break;
		
		case roadNSW:
			return true;
			break;
		
		case roadSEW:
			return true;
			break;
		
		case roadNEW:
			return true;
			break;
		
		case roadEScorner:
			return true;
			break;
		
		case roadWScorner:
			return true;
			break;

		case roadENcorner:
			return true;
			break;

		case roadWNcorner:
			return true;
			break;

		case roadIntersection:
			return true;
			break;
		default:
			return false;
		}

		return false;
	}

	void cityTile::Update(){
		//Entity::Update();
		GetGraphic()->Update();
		float maxColor = MAX( MAX(targetColor.r,targetColor.g) , targetColor.b);
		float amplifier = parentCity->colorAmp / maxColor;
		color = targetColor;
		color.r *= amplifier;
		color.g *= amplifier;
		color.b *= amplifier;

		if(parentCity->colorShift){
			float which = Random::Percent();
			if(which <= 1.0/2.0){
				float oldr = targetColor.r;
				targetColor.r = targetColor.g;
				targetColor.g = targetColor.b;
				targetColor.b = oldr;
			}
			else
			{
				float oldr = targetColor.r;
				targetColor.r = targetColor.b;
				targetColor.b = targetColor.g;
				targetColor.g = oldr;
				
			}


		}
	}

	void cityTile::Render(){
		//if(!isRoad()){
		//	blank->position = position;
		//	blank->Render(this);
		//}

		//origSprite->Render(this);
		
		//Entity::Render();

		Sprite* spr = (Sprite*)GetGraphic();
		spr->position = position;
		Graphics::PushMatrix();
        
            // Calculate proper offset
            Vector2 offset = spr->trimOffset;

			Graphics::Translate(position.x, position.y, 0.0f);
			Graphics::Rotate(spr->rotation, 0, 0, 1);
            Graphics::Scale( spr->trimScale );
			Graphics::BindTexture(spr->texture);
			Graphics::SetBlend(spr->blend);
            Graphics::SetColor(color);


			Graphics::RenderQuad(width, height, spr->textureOffset, spr->textureScale);

		Graphics::PopMatrix();
	}

	city::city(int widt, int heigh, Scene* scene){
		loadSprites();
		parentScene = scene;
		width = widt;
		height = heigh;

		hitBeat = false;
		hitHalfBeat = false;
		hitQuarterBeat = false;

		cameraX = 0;
		cameraY = 0;

		colorAmp = 0.0f;

		multi = 0.095f;

		if(width < 16) width = 16;
		if(height < 16) height = 16;

		tiles = new cityTile**[height];
		for(int i = 0 ; i < width; i++){
			tiles[i] = new cityTile*[width];
			for(int j = 0; j < height; j++){
				tiles[i][j] = new cityTile(empty, 0, this);
			}
		}
		
		generate();

		
		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				tiles[i][j]->position = Vector2((i*128.0f)-(centerX*128.0f), (j*128.0f)-(centerY*128.0f));
				scene->Add(tiles[i][j]);
			}
		}

		buildRenderList();
	}

	void city::loadSprites(){
		blank = new Sprite("blank.png",FILTER_NONE,128,128);

		roadEWsprite = new Sprite("roadStraight.png",FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadNSsprite = new Sprite("roadStraight.png",FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadNSsprite->rotation = 90.0f;
		
		roadWNcornersprite = new Sprite("roadCorner.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		//roadWNcornersprite->rotation = 90;

		roadEScornersprite = new Sprite("roadCorner.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadEScornersprite->rotation = 180;

		roadWScornersprite = new Sprite("roadCorner.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadWScornersprite->rotation = -90;

		roadENcornersprite = new Sprite("roadCorner.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadENcornersprite->rotation = 90;

		roadSEWsprite = new Sprite("road3way.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadNSEsprite = new Sprite("road3way.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadNSEsprite->rotation = -90.0f;
		roadNSWsprite = new Sprite("road3way.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadNSWsprite->rotation = 90.0f;
		roadNEWsprite = new Sprite("road3way.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		roadNEWsprite->rotation = 180.0f;

		roadIntersectionsprite = new Sprite("roadIntersection.png", FilterType::FILTER_NONE, 128.0f, 128.0f);


		square00sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square01sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square02sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square10sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square11sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square12sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square20sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square21sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		square22sprite = new Sprite("yellow.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		mayor00sprite = new Sprite("purple.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		mayor10sprite = new Sprite("purple.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		mayor20sprite = new Sprite("purple.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		mayor01sprite = new Sprite("purple.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		mayor11sprite = new Sprite("purple.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		mayor21sprite = new Sprite("purple.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		park0sprite = new Sprite("green.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		park1sprite = new Sprite("green.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		park2sprite = new Sprite("green.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg1x1_1sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg1x1_2sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg1x1_3sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg1x1_4sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg1x1_5sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg2x2_1sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg2x2_2sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg2x2_3sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg2x2_4sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg2x2_5sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg3x3_1sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg3x3_2sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg3x3_3sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg3x3_4sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg3x3_5sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg4x4_1sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg4x4_2sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg4x4_3sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
		bldg5x5sprite = new Sprite("red.png", FilterType::FILTER_NONE, 128.0f, 128.0f);
	}

	city::~city(){
		renderLists.clear();
		renderList.clear();
		for(int i = 0; i < width; i++){
			for(int j = 0; j < width; j++){
				tiles[i][j]->RemoveSelf();
			}
		}
		scene->ResolveEntityChanges();
		for(int j = 0; j < height; j++){
				delete [] tiles[j];
		}
		delete [] tiles;
		RemoveSelf();
	}

	void city::generate(){

		//printf("\nSTARTING CITY GENERATION ------ \n");


		//Clear it all 
		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				tiles[i][j]->setTile(empty,0, this);
			}
		}

		//Generate Borders
		
		//edge houses
		for(int i = 0; i<width; i++)
		{
			tiles[i][0]->setHouse(3);
			tiles[i][height-1]->setHouse(3);
		}

		for(int i = 1 ; i < height-1; i++)
		{
			tiles[0][i]->setHouse(3);
			tiles[width-1][i]->setHouse(3);
		}

		//edge streetcorners
		tiles[1][1]->setTile(roadEScorner, 0, this);				// topleft Corner
		tiles[width-2][1]->setTile(roadWScorner, 0, this);			// toprigh Corner
		tiles[1][height-2]->setTile(roadENcorner, 0, this);			// botleft Corner
		tiles[width-2][height-2]->setTile(roadWNcorner, 0, this);	// botright Corner

		//edge streets
		for(int i = 2; i<width-2; i++)
		{
			tiles[i][1]->setTile(roadEW,0, this);
			tiles[i][height-2]->setTile(roadEW,0, this);
		}

		for(int i = 2 ; i < height-2; i++)
		{
			tiles[1][i]->setTile(roadNS,0, this);
			tiles[width-2][i]->setTile(roadNS,0, this);
		}


		//place square

		bool placedSquare;
		int iterations = 0;
		do{
			iterations++;
			//printf("Iteration Placed Square: %d\n", iterations);

			if(iterations > 50){
				generate();
				return;
			}

			placedSquare = true; // reset to default
			
			//defined corners;
			int topLeftX = Random::Int(5,width-8);
			int topLeftY = Random::Int(5,height-8);
			int bottomLeftX = topLeftX;
			int bottomLeftY = topLeftY+2;
			int topRightX = topLeftX+2;
			int topRightY = topLeftY;
			int bottomRightX = topRightX;
			int bottomRightY = bottomLeftY;

/*			if(topLeftX == 0 || topLeftX == 1 || topLeftX == 3){
				placedSquare = false;
				continue;
			}

			if(topRightX == width -1 || topRightX == width - 2 || topRightX == width - 4){
				placedSquare = false;
				continue;
			}

			if(topLeftY == 0 || topLeftY == 1 || topLeftY == 3){
				placedSquare = false;
				continue;
			}

			if(bottomLeftY == height - 1 || bottomLeftY == height - 2 || bottomLeftY == height - 4){
				placedSquare = false;
				continue;
			}
			*/

			//at this point we're good, so place square tiles down
			tiles[topLeftX][topLeftY]->setTile(square00,0, this);
			tiles[topLeftX+1][topLeftY]->setTile(square10,0, this);
			tiles[topLeftX+2][topLeftY]->setTile(square20,0, this);
			tiles[topLeftX][topLeftY+1]->setTile(square01,0, this);
			tiles[topLeftX+1][topLeftY+1]->setTile(square11,2, this);
			tiles[topLeftX+2][topLeftY+1]->setTile(square21,0, this);
			tiles[topLeftX][topLeftY+2]->setTile(square02,0, this);
			tiles[topLeftX+1][topLeftY+2]->setTile(square12,0, this);
			tiles[topLeftX+2][topLeftY+2]->setTile(square22,0, this);

			//now to place appropriate roads
			tiles[topLeftX-1][topLeftY]->setTile(roadNS, 0, this);
			tiles[topLeftX-1][topLeftY+1]->setTile(roadNS, 0, this);
			tiles[topLeftX-1][topLeftY+2]->setTile(roadNS, 0, this);
			tiles[topRightX+1][topLeftY]->setTile(roadNS, 0, this);
			tiles[topRightX+1][topLeftY+1]->setTile(roadNS, 0, this);
			tiles[topRightX+1][topLeftY+2]->setTile(roadNS, 0, this);

			tiles[topLeftX][topLeftY-1]->setTile(roadEW,0, this);
			tiles[topLeftX+1][topLeftY-1]->setTile(roadEW,0, this);
			tiles[topLeftX+2][topLeftY-1]->setTile(roadEW,0, this);
			tiles[topLeftX][bottomLeftY+1]->setTile(roadEW,0, this);
			tiles[topLeftX+1][bottomLeftY+1]->setTile(roadEW,0, this);
			tiles[topLeftX+2][bottomLeftY+1]->setTile(roadEW,0, this);

			//road corners
			tiles[topLeftX-1][topLeftY-1]->setTile(roadEScorner,0, this);
			tiles[bottomLeftX-1][bottomLeftY+1]->setTile(roadENcorner,0, this);
			tiles[topRightX+1][topRightY-1]->setTile(roadWScorner,0, this);
			tiles[bottomRightX+1][bottomRightY+1]->setTile(roadWNcorner,0, this);

			placedSquare = true;

		}while(!placedSquare);


		bool placedMayor;
		iterations = 0;
		do{
			iterations++;
			//printf("Iteration Placed Mayor: %d\n", iterations);

			if(iterations > 50){
				generate();
				return;
			}

			placedMayor = true;
			int topLeftX = Random::Int(2,width-5);
			int topLeftY = Random::Int(2,height-5);


			//first check for open spot.
			for(int i = 0; i < 3; i++){
				if(tiles[topLeftX+i][topLeftY]->type != empty) placedMayor = false;
				if(tiles[topLeftX+i][topLeftY+1]->type != empty) placedMayor = false;
				if(tiles[topLeftX+i][topLeftY+2]->type != empty) placedMayor = false;
			}

			if(placedMayor == false) continue;
			
			//now see if roads will fit

			//Top and Bottom
			for(int i = 0; i< 5; i++){
				if(tiles[topLeftX-1+i][topLeftY-1]->type != empty){
					placedMayor = false;
					if(tiles[topLeftX-1+i][topLeftY-1]->isRoad()){
						placedMayor = true;
					}
				}
				if(tiles[topLeftX-1+i][topLeftY+2]->type != empty){
					placedMayor = false;
					if(!tiles[topLeftX-1+i][topLeftY+2]->isRoad()){
						placedMayor = true;
					}
				}
			}
			if(placedMayor == false) continue;

			//sides
			for(int i = 0; i< 2; i++){
				if(tiles[topLeftX-1][topLeftY+i]->type != empty){
					placedMayor = false;
					if(!tiles[topLeftX-1][topLeftY+i]->isRoad()){
						placedMayor = true;
					}
				}
				if(tiles[topLeftX+1][topLeftY+i]->type != empty){
					placedMayor = false;
					if(!tiles[topLeftX+1][topLeftY+i]->isRoad()){
						placedMayor = true;
					}
				}
			}
			if(placedMayor == false) continue;

			//roads seem to be ok, now to check for at least 2 square spacing

			//verticals
			for(int i =0 ; i<height; i++){
				if(tiles[topLeftX][i]->type != empty){
					if(tiles[topLeftX][i]->type == roadNS) placedMayor = false;
				}

				if(tiles[topLeftX+1][i]->type != empty){
					if(tiles[topLeftX+1][i]->type == roadNS) placedMayor = false;
				}
				
				if(tiles[topLeftX-2][i]->type != empty){
					if(tiles[topLeftX-2][i]->type == roadNS) placedMayor = false;
				}
				if(topLeftX - 3 > 0){
					if(tiles[topLeftX-3][i]->type != empty){
						if(tiles[topLeftX-3][i]->type == roadNS) placedMayor = false;
					}
				}


				if(tiles[topLeftX+2][i]->type != empty){
					if(tiles[topLeftX+2][i]->type == roadNS) placedMayor = false;
				}

				if(tiles[topLeftX+4][i]->type != empty){
					if(tiles[topLeftX+4][i]->type == roadNS) placedMayor = false;
				}
				if(topLeftX+5 < width){
					if(tiles[topLeftX+5][i]->type != empty){
						if(tiles[topLeftX+5][i]->type == roadNS) placedMayor = false;
					}
				}
			}
			if(placedMayor == false) continue;

			//horizontals
			for(int i =0 ; i<width; i++){
				if(tiles[i][topLeftY]->type != empty){
					if(tiles[i][topLeftY]->type == roadEW) placedMayor = false;
				}
				if(tiles[i][topLeftY+1]->type != empty){
					if(tiles[i][topLeftY+1]->type == roadEW) placedMayor = false;
				}
				if(tiles[i][topLeftY-2]->type != empty){
					if(tiles[i][topLeftY-2]->type == roadEW) placedMayor = false;
				}
				if(topLeftY-3 > 0){
					if(tiles[i][topLeftY-3]->type != empty){
						if(tiles[i][topLeftY-3]->type == roadEW) placedMayor = false;
					}
				}
				if(tiles[i][topLeftY+1]->type != empty){
					if(tiles[i][topLeftY+1]->type == roadEW) placedMayor = false;
				}
				if(tiles[i][topLeftY+3]->type != empty){
					if(tiles[i][topLeftY+3]->type == roadEW) placedMayor = false;
				}
				if(topLeftY+4 < height){
					if(tiles[i][topLeftY+4]->type != empty){
						if(tiles[i][topLeftY+4]->type == roadEW) placedMayor = false;
					}
				}

			}
			if(placedMayor == false) continue;

			//Everything good, now to place.
			tiles[topLeftX][topLeftY]->setTile(mayor00,1, this);
			tiles[topLeftX+1][topLeftY]->setTile(mayor10,1, this);
			tiles[topLeftX+2][topLeftY]->setTile(mayor20,1, this);
			tiles[topLeftX][topLeftY+1]->setTile(mayor01,1, this);
			tiles[topLeftX+1][topLeftY+1]->setTile(mayor11,1, this);
			tiles[topLeftX+2][topLeftY+1]->setTile(mayor21,1, this);
			
			//roads
			//top
			if(tiles[topLeftX][topLeftY-1]->type == empty) tiles[topLeftX][topLeftY-1]->setTile(roadEW,0, this);
			if(tiles[topLeftX+1][topLeftY-1]->type == empty) tiles[topLeftX+1][topLeftY-1]->setTile(roadEW,0, this);
			if(tiles[topLeftX+2][topLeftY-1]->type == empty) tiles[topLeftX+2][topLeftY-1]->setTile(roadEW,0, this);
			if(tiles[topLeftX][topLeftY+2]->type == empty) tiles[topLeftX][topLeftY+2]->setTile(roadEW,0, this);
			if(tiles[topLeftX+1][topLeftY+2]->type == empty) tiles[topLeftX+1][topLeftY+2]->setTile(roadEW,0, this);
			if(tiles[topLeftX+2][topLeftY+2]->type == empty) tiles[topLeftX+2][topLeftY+2]->setTile(roadEW,0, this);
			
			//sides
			if(tiles[topLeftX-1][topLeftY]->type == empty) tiles[topLeftX-1][topLeftY]->setTile(roadNS,0, this);
			if(tiles[topLeftX-1][topLeftY+1]->type == empty) tiles[topLeftX-1][topLeftY+1]->setTile(roadNS,0, this);
			if(tiles[topLeftX+3][topLeftY]->type == empty) tiles[topLeftX+3][topLeftY]->setTile(roadNS,0, this);
			if(tiles[topLeftX+3][topLeftY+1]->type == empty) tiles[topLeftX+3][topLeftY+1]->setTile(roadNS,0, this);

			//corners
			if(tiles[topLeftX-1][topLeftY-1]->type == empty) tiles[topLeftX-1][topLeftY-1]->setTile(roadEScorner,0, this);
			if(tiles[topLeftX-1][topLeftY+2]->type == empty) tiles[topLeftX-1][topLeftY+2]->setTile(roadENcorner,0, this);
			if(tiles[topLeftX+3][topLeftY-1]->type == empty) tiles[topLeftX+3][topLeftY-1]->setTile(roadWScorner,0, this);
			if(tiles[topLeftX+3][topLeftY+2]->type == empty) tiles[topLeftX+3][topLeftY+2]->setTile(roadWNcorner,0, this);
		}while(!placedMayor);

		//PARK TIME
		bool placedPark;
		iterations = 0;
		do{
			placedPark = true;
			iterations++;

			if(iterations > 500){
				generate();
				return;
			}

			//printf("Iteration Placed Park: %d\n", iterations);

			int topLeftX = Random::Int(2,width-5);
			int topLeftY = Random::Int(2,height-5);
			int parkWidth = Random::Int(10,14);
			int parkHeight = Random::Int(4,6);

			centerX = topLeftX + parkWidth/2;
			centerY = topLeftY + parkHeight/2;

			if(topLeftX+parkWidth+2 > width - 3){
				placedPark = false;
				continue;
			}

			if(topLeftY+parkHeight+2 > height - 3){
				placedPark = false;
				continue;
			}

			//check space

			for(int i = topLeftX; i < topLeftX+parkWidth; i++){
				for(int j = topLeftY; j < topLeftY+parkHeight; j++){
					if(tiles[i][j]->type != empty){
						placedPark = false;
					}
				}
			}

			if(placedPark == false)
				{
					continue;
			}

			//space is OK
			//Check road placement
			
			//top
			for(int i = topLeftX-1; i<topLeftX+parkWidth+1; i++){
				if(tiles[i][topLeftY-1]->type != empty){
					 placedPark = false;
					 if(tiles[i][topLeftY-1]->isRoad()){
						placedPark = true;
					 }
				}
				if(placedPark == false) break;
			}

			if(placedPark == false) continue;

			//bottom
			for(int i = topLeftX-1; i<topLeftX+parkWidth+1; i++){
				if(tiles[i][topLeftY+parkHeight]->type != empty){
					 placedPark = false;
					 if(tiles[i][topLeftY+parkHeight]->isRoad()){
						placedPark = true;
					 }
				}
				if(placedPark == false) break;
			}

			if(placedPark == false) continue;

			//left
			for(int i = topLeftY; i<topLeftY+parkHeight; i++){
				if(tiles[topLeftX-1][i]->type != empty){
					 placedPark = false;
					 if(tiles[topLeftX-1][i]->isRoad()){
						placedPark = true;
					 }
				}
				if(placedPark == false) break;
			}
			if(placedPark == false) continue;

			//right
			for(int i = topLeftY; i<topLeftY+parkHeight; i++){
				if(tiles[topLeftX+parkWidth][i]->type != empty){
					 placedPark = false;
					 if(tiles[topLeftX+parkWidth][i]->isRoad()){
						placedPark = true;
					 }
				}
				if(placedPark == false) break;
			}
			if(placedPark == false) continue;
			
			//Road placement should be good
			//now to ensure 2 block divisions.


			//verticals
			for(int i =2 ; i<height-3; i++){
				if(tiles[topLeftX][i]->type != empty){
					if(tiles[topLeftX][i]->type == roadNS) placedPark = false;
				}

				if(tiles[topLeftX+1][i]->type != empty){
					if(tiles[topLeftX+1][i]->type == roadNS) placedPark = false;
				}
				
				if(tiles[topLeftX-2][i]->type != empty){
					if(tiles[topLeftX-2][i]->type == roadNS) placedPark = false;
				}

				if(topLeftX-3>0){
					if(tiles[topLeftX-3][i]->type != empty){
						if(tiles[topLeftX-3][i]->type == roadNS) placedPark = false;
					}
				}
				
				if(tiles[topLeftX+parkWidth-2][i]->type != empty){
					if(tiles[topLeftX+parkWidth-2][i]->type == roadNS) placedPark = false;
				}

				if(tiles[topLeftX+parkWidth-1][i]->type != empty){
					if(tiles[topLeftX+parkWidth-1][i]->type == roadNS) placedPark = false;
				}

				if(tiles[topLeftX+parkWidth+1][i]->type != empty){
					if(tiles[topLeftX+parkWidth+1][i]->type == roadNS) placedPark = false;
				}

				if(tiles[topLeftX+parkWidth][i]->type != empty){
					if(tiles[topLeftX+parkWidth][i]->type == roadNS) placedPark = false;
				}


				if(topLeftX+parkWidth+3 < width){
					if(tiles[topLeftX+parkWidth+2][i]->type != empty){
						if(tiles[topLeftX+parkWidth+2][i]->type == roadNS) placedPark = false;
					}
				}
			}
			if(placedPark == false) continue;

			//horizontals
			for(int i =2 ; i<width-3; i++){
				if(tiles[i][topLeftY]->type != empty){
					if(tiles[i][topLeftY]->type == roadEW) placedPark = false;
				}
				if(tiles[i][topLeftY+1]->type != empty){
					if(tiles[i][topLeftY+1]->type == roadEW) placedPark = false;
				}
				if(tiles[i][topLeftY-2]->type != empty){
					if(tiles[i][topLeftY-2]->type == roadEW) placedPark = false;
				}
				if(topLeftY-3 > 0){
					if(tiles[i][topLeftY-3]->type != empty){
						if(tiles[i][topLeftY-3]->type == roadEW) placedPark = false;
					}
				}

				if(tiles[i][topLeftY+parkHeight-1]->type != empty){
					if(tiles[i][topLeftY+parkHeight-1]->type == roadEW) placedPark = false;
				}
				if(tiles[i][topLeftY+parkHeight-2]->type != empty){
					if(tiles[i][topLeftY+parkHeight-2]->type == roadEW) placedPark = false;
				}
				if(tiles[i][topLeftY+parkHeight+1]->type != empty){
					if(tiles[i][topLeftY+parkHeight+1]->type == roadEW) placedPark = false;
				}
				if(topLeftY+parkHeight+3 < height){
					if(tiles[i][topLeftY+parkHeight+2]->type != empty){
						if(tiles[i][topLeftY+parkHeight+2]->type == roadEW) placedPark = false;
					}
				}
			}
			if(placedPark == false) continue;

			//should be good

			//place down park
			for(int i = topLeftX; i < topLeftX+parkWidth; i++)
			{
				for(int j = topLeftY; j < topLeftY+parkHeight; j++)
				{
					float cent = Random::Percent();
					if(cent <= 1.0f/3.0f){
						tiles[i][j]->setTile(park0, 0, this);
					}
					else if(cent > 1.0f/3.0f && cent <= 2.0f/3.0f) {
						tiles[i][j]->setTile(park1, 0, this);
					}
					else{
						tiles[i][j]->setTile(park2, 0, this);
					}
				}
			}

			//place roads
			//Top+bottom
			for(int i = topLeftX; i < topLeftX+parkWidth; i++)
			{
				tiles[i][topLeftY-1]->setTile(roadEW,0, this);
				tiles[i][topLeftY+parkHeight]->setTile(roadEW,0, this);
			}
			//sides
			for(int i = topLeftY-1; i < topLeftY+parkHeight+1; i++)
			{
				tiles[topLeftX-1][i]->setTile(roadNS,0, this);
				tiles[topLeftX+parkWidth][i]->setTile(roadNS,0, this);
			}

		}while(!placedPark);

		fixRoads();


		// Extend Square roads
		//find square first
		{
			int squareX, squareY;
			for(int i=0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(tiles[j][i]->type == square00){
						squareX = j;
						squareY = i;
					}
				}
			}

			//find positions
			int roadTop = squareY - 1;
			int roadBottom = squareY + 3;
			int roadLeft = squareX - 1;
			int roadRight = squareX + 3;

			//Horizontals
			for(int i = roadLeft - 1; i > 0 ; i--){
				if(tiles[i][roadTop]->type == empty){
					tiles[i][roadTop]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadLeft - 1; i > 0 ; i--){
				if(tiles[i][roadBottom]->type == empty){
					tiles[i][roadBottom]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadRight + 1; i < width ; i++){
				if(tiles[i][roadTop]->type == empty){
					tiles[i][roadTop]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadRight + 1; i < width ; i++){
				if(tiles[i][roadBottom]->type == empty){
					tiles[i][roadBottom]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			//verticals

			for(int i = roadTop - 1; i > 0 ; i--){
				if(tiles[roadLeft][i]->type == empty){
					tiles[roadLeft][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadTop - 1; i > 0 ; i--){
				if(tiles[roadRight][i]->type == empty){
					tiles[roadRight][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadBottom + 1; i < height; i++){
				if(tiles[roadLeft][i]->type == empty){
					tiles[roadLeft][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadBottom + 1; i < height; i++){
				if(tiles[roadRight][i]->type == empty){
					tiles[roadRight][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			fixRoads();
		}

		// Extend Mayor roads
		{
			int squareX, squareY;
			for(int i=0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(tiles[j][i]->type == mayor00){
						squareX = j;
						squareY = i;
					}
				}
			}

			//find positions
			int roadTop = squareY - 1;
			int roadBottom = squareY + 2;
			int roadLeft = squareX - 1;
			int roadRight = squareX + 3;

			//Horizontals
			for(int i = roadLeft - 1; i > 0 ; i--){
				//if(tiles[i][roadTop]->isRoad()) continue;
				if(tiles[i][roadTop]->type == empty){					
					tiles[i][roadTop]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadLeft - 1; i > 0 ; i--){
				//if(tiles[i][roadBottom]->isRoad()) continue;
				if(tiles[i][roadBottom]->type == empty){
					tiles[i][roadBottom]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadRight + 1; i < width ; i++){
				//if(tiles[i][roadTop]->isRoad()) continue;
				if(tiles[i][roadTop]->type == empty){
					tiles[i][roadTop]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadRight + 1; i < width ; i++){
				//if(tiles[i][roadBottom]->isRoad()) continue;
				if(tiles[i][roadBottom]->type == empty){
					tiles[i][roadBottom]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			//verticals

			for(int i = roadTop - 1; i > 0 ; i--){
				//if(tiles[roadLeft][i]->isRoad()) continue;
				if(tiles[roadLeft][i]->type == empty){
					tiles[roadLeft][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadTop - 1; i > 0 ; i--){
				//if(tiles[roadRight][i]->isRoad()) continue;
				if(tiles[roadRight][i]->type == empty){
					tiles[roadRight][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadBottom + 1; i < height; i++){
				//if(tiles[roadLeft][i]->isRoad()) continue;
				if(tiles[roadLeft][i]->type == empty){
					tiles[roadLeft][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadBottom + 1; i < height; i++){
				//if(tiles[roadRight][i]->isRoad()) continue;
				if(tiles[roadRight][i]->type == empty){
					tiles[roadRight][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			fixRoads();
		}

		// Extend Park Roads
		{
			int squareX, squareY;
			for(int i=0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(tiles[j][i]->type == park0 || tiles[j][i]->type == park1 || tiles[j][i]->type == park2){
						squareX = j;
						squareY = i;
						i = j = 1000;
					}
				}
			}

			//find positions
			int roadTop = squareY - 1;
			int roadLeft = squareX - 1;
			int roadBottom;
			int roadRight;

			for(int i = squareX; i < width; i++){
				roadRight = i+1;
				if(tiles[i+1][squareY]->isRoad()) break;
			}

			for(int i = squareY; i < height; i++){
				roadBottom = i+1;
				if(tiles[squareX][i+1]->isRoad()) break;
			}



			//Horizontals
			for(int i = roadLeft - 1; i > 0 ; i--){
				//if(tiles[i][roadTop]->isRoad()) continue;
				if(tiles[i][roadTop]->type == empty){					
					tiles[i][roadTop]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadLeft - 1; i > 0 ; i--){
				//if(tiles[i][roadBottom]->isRoad()) continue;
				if(tiles[i][roadBottom]->type == empty){
					tiles[i][roadBottom]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadRight + 1; i < width ; i++){
				//if(tiles[i][roadTop]->isRoad()) continue;
				if(tiles[i][roadTop]->type == empty){
					tiles[i][roadTop]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			for(int i = roadRight + 1; i < width ; i++){
				//if(tiles[i][roadBottom]->isRoad()) continue;
				if(tiles[i][roadBottom]->type == empty){
					tiles[i][roadBottom]->setTile(roadEW,0, this);
				}
				else	{break;}
			}

			//verticals

			for(int i = roadTop - 1; i > 0 ; i--){
				//if(tiles[roadLeft][i]->isRoad()) continue;
				if(tiles[roadLeft][i]->type == empty){
					tiles[roadLeft][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadTop - 1; i > 0 ; i--){
				//if(tiles[roadRight][i]->isRoad()) continue;
				if(tiles[roadRight][i]->type == empty){
					tiles[roadRight][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadBottom + 1; i < height; i++){
				//if(tiles[roadLeft][i]->isRoad()) continue;
				if(tiles[roadLeft][i]->type == empty){
					tiles[roadLeft][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			for(int i = roadBottom + 1; i < height; i++){
				//if(tiles[roadRight][i]->isRoad()) continue;
				if(tiles[roadRight][i]->type == empty){
					tiles[roadRight][i]->setTile(roadNS,0, this);
				}
				else	{break;}
			}

			fixRoads();
		}


		//Split large sections with roads

		int largestBlock = 0;
		int largestBlockLeft = 0;
		int largestBlockRight = 0;
		int largestBlockTop = 0;
		int largestBlockBottom = 0;
		
		iterations = 0;

		do{
			iterations++;
			//printf("Iteration Find Block: %d\n", iterations);

			if(iterations > 50){
				generate();
				return;
			}

			largestBlock = 0;
			largestBlockLeft = 0;
			largestBlockRight = 0;
			largestBlockTop = 0;
			largestBlockBottom = 0;
			
			for(int i = 2; i <width - 2; i++){
				for(int j = 2; j < height - 2; j++){
					if(tiles[i][j]->type == empty){
						int left = i;
						int right = i;
						int top = j;
						int bottom = j;

						while(tiles[left][j]->type == empty) left--;
						while(tiles[right][j]->type == empty) right++;
						while(tiles[i][top]->type == empty) top--;
						while(tiles[i][bottom]->type == empty) bottom++;

						int size = (bottom-top)*(right-left);
						if(size > largestBlock){
							largestBlock = size;
							largestBlockLeft = left;
							largestBlockRight = right;
							largestBlockTop = top;
							largestBlockBottom = bottom;
						}
					}
				}
			}
			if(largestBlock > 35){
				//got the largest block, now to split it;
				if((largestBlockRight-largestBlockLeft) > (largestBlockBottom - largestBlockTop)){
					// wider
					int midpoint = (largestBlockRight + largestBlockLeft)/2;
					int splitPoint = midpoint;

					for(int m = 2; midpoint + m < largestBlockRight-2; m++){
						if(tiles[midpoint+m][largestBlockTop-1]->type == roadNEW){ splitPoint = midpoint+m; break;}
						if(tiles[midpoint+m][largestBlockBottom+1]->type == roadSEW){ splitPoint = midpoint+m; break;}
						if(tiles[midpoint-m][largestBlockTop-1]->type == roadNEW){ splitPoint = midpoint-m; break;}
						if(tiles[midpoint-m][largestBlockBottom+1]->type == roadSEW){ splitPoint = midpoint-m; break;}
					}

					for(int m = largestBlockTop; m < largestBlockBottom; m++){
						tiles[splitPoint][m]->setTile(roadNS, 0, this);
					}
				}
				else
				{
					//taller
					int midpoint = (largestBlockBottom + largestBlockTop)/2;
					int splitPoint = midpoint;

					for(int m = 2; midpoint + m < largestBlockBottom-2; m++){
						if(tiles[largestBlockLeft-1][midpoint+m]->type == roadNSW){ splitPoint = midpoint+m; break;}
						if(tiles[largestBlockRight+1][midpoint+m]->type == roadNSE){ splitPoint = midpoint+m; break;}
						if(tiles[largestBlockLeft-1][midpoint-m]->type == roadNSW){ splitPoint = midpoint-m; break;}
						if(tiles[largestBlockRight+1][midpoint-m]->type == roadNSE){ splitPoint = midpoint-m; break;}
					}

					for(int m = largestBlockLeft; m < largestBlockRight; m++){
						tiles[m][splitPoint]->setTile(roadEW, 0, this);
					}
				}
			}

			fixRoads();
		}while(largestBlock > 35);

		//Time to add buildings
		for(int i = 2; i < width -2; i++){
			for(int j = 2; j < height - 2; j++){
				if(tiles[i][j]->type == empty){
					int size = 0;
					int x = i;
					int y = j;
					while(tiles[x][y]->type == empty){ x++; y++; size++;}
					tiles[i][j]->setHouse(size);
					for(int m = 0; m < size; m++){
						for(int n = 0; n < size; n++){
							tiles[i+m][j+n]->setFrom(tiles[i][j]);
						}
					}
				}
			}
		}


		///Finished adding buildings

		//for(int i=0; i < height; i++){
		//	for(int j = 0; j < width; j++){
		//		printf("%d\t", tiles[j][i]->type);
		//	}
		//	printf("\n");
 		//}
		//printf("FINISHED CITY GENERATION ------ \n\n");
	}

	void city::fixRoads(){
		for(int x = 1; x < width-1; x++){
			for(int y = 1; y < height-1; y++){
				if(tiles[x][y]->isRoad()){
					bool roadEast = false;
					bool roadNorth = false;
					bool roadSouth = false;
					bool roadWest = false;

					if(tiles[x+1][y]->isRoad()) roadEast = true;
					if(tiles[x-1][y]->isRoad()) roadWest = true;
					if(tiles[x][y-1]->isRoad()) roadNorth = true;
					if(tiles[x][y+1]->isRoad()) roadSouth = true;

					if(roadEast && roadWest && roadNorth && roadSouth)	{ tiles[x][y]->setTile(roadIntersection,0, this);}
					else if(roadEast && roadWest && roadNorth)			{ tiles[x][y]->setTile(roadNEW,0, this);}
					else if(roadEast && roadWest && roadSouth)			{ tiles[x][y]->setTile(roadSEW,0, this);}
					else if(roadEast && roadSouth && roadNorth)			{ tiles[x][y]->setTile(roadNSE,0, this);}
					else if(roadWest && roadSouth && roadNorth)			{ tiles[x][y]->setTile(roadNSW,0, this);}
					else if(roadWest && roadNorth)						{ tiles[x][y]->setTile(roadWNcorner,0, this);}
					else if(roadWest && roadSouth)						{ tiles[x][y]->setTile(roadWScorner,0, this);}
					else if(roadEast && roadNorth)						{ tiles[x][y]->setTile(roadENcorner,0, this);}
					else if(roadEast && roadSouth)						{ tiles[x][y]->setTile(roadEScorner,0, this);}
					else if(roadEast && roadWest)						{ tiles[x][y]->setTile(roadEW,0, this);}
					else if(roadNorth && roadSouth)						{ tiles[x][y]->setTile(roadNS,0, this);}
					}
				}
			}
		}

	void city::buildRenderList(){



		//Center
		for(int m  = 0; m < width; m++){
			for(int n = 0; n < height; n++){
				renderLists[m][n].clear();

				int startX = -3;
				int startY = -3;

				while(startX + m < 0)		startX++;
				while(startX + m + 7 >= width)	startX--;
				while(startY + n < 0)		startY++;
				while(startY + n + 7 >= height) startY--;

				for(int j = 1 ; j < 110; j++){
					for(int x = startX; x <= startX+7; x++){
						for(int y = startY; y <= startY+7; y++){
							if(tiles[m+x][n+y]->floors >= j)
							{
								renderItem* temp = new renderItem();
								temp->tile = tiles[m+x][n+y];
								temp->floor = j;
								renderLists[m][n].push_back(temp);
				}	}	}	}
			}
		}
	}

	void city::Update(){
		Entity::Update();
		colorShift = false;

		if(Input::IsKeyMaskHeld("MM")){
			if(hitBeat){ 
				colorAmp = 1.3f;
				colorShift = true;
			}
		}
		
		if(Input::IsKeyMaskHeld("MR")){
			if(hitHalfBeat){ 
				colorAmp = 1.25f;
				colorShift = true;
			}
		}

		if(Input::IsKeyMaskHeld("ML")){
			if(hitHalfBeat){ 
				colorAmp = 1.25f;
				colorShift = true;
			}
		}

		if(Input::IsKeyMaskHeld("RR")){
			if(hitQuarterBeat){ 
				colorAmp = 1.2f;
				colorShift = true;
			}
		}

		if(Input::IsKeyMaskHeld("LL")){
			if(hitQuarterBeat){ 
				colorAmp = 1.2f;
				colorShift = true;
			}
		}
	}

	void city::Render(){
		if(multi > 0.088) multi = (multi + multi)/2.01;
		for (std::list<renderItem*>::iterator i = renderLists[cameraX][cameraY].begin(); i != renderLists[cameraX][cameraY].end(); ++i)
		{
			
			Sprite* spr = (Sprite*)(*i)->tile->GetGraphic();
			Vector2 shipPos = parentScene->GetCamera()->position;
			
			Graphics::PushMatrix();
				Vector2 diff = (*i)->tile->position - shipPos;
				diff*= (multi * (*i)->floor);
				Graphics::Translate((*i)->tile->position.x+diff.x, (*i)->tile->position.y+diff.y, 0);
				Graphics::Rotate(spr->rotation, 0, 0, 1);
				Graphics::Scale( (*i)->tile->scale );
				Graphics::BindTexture(spr->texture);
				Graphics::SetBlend(spr->blend);
				Graphics::SetColor((*i)->tile->color);
				Graphics::RenderQuad((*i)->tile->width+((*i)->tile->width*(multi * (*i)->floor)), (*i)->tile->height+((*i)->tile->height*(multi * (*i)->floor)), spr->textureOffset, spr->textureScale);
			Graphics::PopMatrix();
		}
	}
}

