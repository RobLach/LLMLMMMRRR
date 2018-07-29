#include "LL.h"
#include <Input.h>
#include <Level.h>
#include <Monocle.h>
#include <Macros.h>

#include <stdlib.h>

namespace LL
{
	AudioAsset* LL; // Left Gun
	AudioDeck* LLdeck;
	
	AudioAsset* ML; // Left Thruster
	AudioDeck* MLdeck;

	AudioAsset* MM; // Central Thruster
	AudioDeck* MMdeck;

	AudioAsset* MR; // Right Thruster
	AudioDeck* MRdeck;

	AudioAsset* RR; // Right Gun
	AudioDeck* RRdeck;

	AudioAsset* loop;
	AudioDeck* Loopdeck;

	Sprite* blankSpr;


	void menuScene::Begin(){
		Scene::Begin();
    
        Graphics::SetBackgroundColor(Color::black);

		//set screen size
		Graphics::Set2D(512, 320);
		//Graphics::SetCameraPosition(Vector2(80, 60));
		GetCamera()->position = Vector2(0,0);
		Assets::SetContentPath("../Content/");

		bgMusic = Audio::PlayMusic(Assets::RequestAudio("menu.ogg",true));

		bgClearer = new Entity();
		SpriteSequenceAnimation* spr = new SpriteSequenceAnimation("/static/staticthree270.png", FILTER_NONE, 640, 640);
		spr->AddFrame(new Sprite("/static/staticthree271.png", FILTER_NONE));
		spr->AddFrame(new Sprite("/static/staticthree272.png", FILTER_NONE));
		spr->AddFrame(new Sprite("/static/staticthree273.png", FILTER_NONE));
		spr->AddFrame(new Sprite("/static/staticthree274.png", FILTER_NONE));
		spr->AddFrame(new Sprite("/static/staticthree275.png", FILTER_NONE));
		spr->AddFrame(new Sprite("/static/staticthree276.png", FILTER_NONE));
		spr->AddFrame(new Sprite("/static/staticthree277.png", FILTER_NONE));
		spr->Add("h",0,7,10);
		spr->Play("h");

		bgClearer->SetGraphic(spr);
		bgClearer->position = Vector2::zero;
		Add(bgClearer);

		LL = new Text("LL", Assets::RequestFont("font.ttf", 64));
		ML = new Text("ML", Assets::RequestFont("font.ttf", 64));
		MM = new Text("MM", Assets::RequestFont("font.ttf", 64));
		MR = new Text("MR", Assets::RequestFont("font.ttf", 64));
		RR = new Text("RR", Assets::RequestFont("font.ttf", 64));


		Add(LL);
		Add(ML);
		Add(MM);
		Add(MR);
		Add(RR);

		credit = new Text("BY ROB LACH - ROB@ROBLACH.COM - @LACHROB",Assets::RequestFont("font.ttf", 64));
		credit->scale = Vector2(0.25f,0.25f);
		credit->position = Vector2(-90,124);
		Add(credit);

		plat1 = new Entity();
		plat1->SetGraphic(new Sprite("platform.png", FILTER_NONE));
		plat1->position = Vector2(-256+64,0);
		plat1->scale = Vector2(3,3);

		plat2 = new Entity();
		plat2->SetGraphic(new Sprite("platform.png", FILTER_NONE));
		plat2->position = Vector2(-128+32,0);
		plat2->scale = Vector2(3,3);

		plat3 = new Entity();
		plat3->SetGraphic(new Sprite("platform.png", FILTER_NONE));
		plat3->position = Vector2(-0,0);
		plat3->scale = Vector2(3,3);

		plat4 = new Entity();
		plat4->SetGraphic(new Sprite("platform.png", FILTER_NONE));
		plat4->position = Vector2(128-32,0);
		plat4->scale = Vector2(3,3);

		plat5 = new Entity();
		plat5->SetGraphic(new Sprite("platform.png", FILTER_NONE));
		plat5->position = Vector2(256-64,0);
		plat5->scale = Vector2(3,3);

		Add(plat1);
		Add(plat2);
		Add(plat3);
		Add(plat4);
		Add(plat5);


		Input::DefineMaskKey("LL",KeyCode::KEY_1);
		Input::DefineMaskKey("ML",KeyCode::KEY_2);
		Input::DefineMaskKey("MM",KeyCode::KEY_3);
		Input::DefineMaskKey("MR",KeyCode::KEY_4);
		Input::DefineMaskKey("RR",KeyCode::KEY_5);

		logo = new Entity();
		logo->SetGraphic(new Sprite("logo.png", FILTER_NONE));
		logo->position = Vector2(-256+32,160-64);
		Add(logo);
		timeHeld = 0.0;
		somethingHeld = false;

		timer = new Text("placeholder", Assets::RequestFont("font.ttf", 64));
		timer->position = Vector2(-160,-20);
		timer->isVisible = false;
		timer->scale = Vector2(0.5f,0.5f);
		Add(timer);
	}

	void menuScene::Update(){
		Scene::Update();
		Color extreme = Color(Random::Percent(),Random::Percent(),Random::Percent(),0.1f);
		float amp = MAX( extreme.r , MAX( extreme.g, extreme.b ));
		amp = 0.3f/amp;
		bgClearer->color.r = extreme.r * amp;
		bgClearer->color.g = extreme.g * amp;
		bgClearer->color.b = extreme.b * amp;

		bgClearer->position = Vector2::zero + Vector2::Random()* 4.f;

		LL->scale = Vector2(Random::Float(0.95f,1.05f),Random::Float(0.95f,1.05f));
		ML->scale = Vector2(Random::Float(0.95f,1.05f),Random::Float(0.95f,1.05f));
		MM->scale = Vector2(Random::Float(0.95f,1.05f),Random::Float(0.95f,1.05f));
		MR->scale = Vector2(Random::Float(0.95f,1.05f),Random::Float(0.95f,1.05f));
		RR->scale = Vector2(Random::Float(0.95f,1.05f),Random::Float(0.95f,1.05f));

		LL->position = Vector2(-256+32,-90) + Vector2::Random()*1.0f;
		ML->position = Vector2(-128-16, -90)+ Vector2::Random()*1.0f;
		MM->position = Vector2(-48,-90)+ Vector2::Random()*1.0f;
		MR->position = Vector2(128-64, -90)+ Vector2::Random()*1.0f;
		RR->position = Vector2(256-96, -90)+ Vector2::Random()*1.0f;


		extreme = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		amp = MAX( extreme.r , MAX( extreme.g, extreme.b ));
		amp = 1.0f/amp;

		LL->color.r = extreme.r * amp;
		LL->color.g = extreme.g * amp;
		LL->color.b = extreme.b * amp;

		
		extreme = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		amp = MAX( extreme.r , MAX( extreme.g, extreme.b ));
		amp = 1.0f/amp;

		ML->color.r = extreme.r * amp;
		ML->color.g = extreme.g * amp;
		ML->color.b = extreme.b * amp;

		
		extreme = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		amp = MAX( extreme.r , MAX( extreme.g, extreme.b ));
		amp = 1.0f/amp;

		MM->color.r = extreme.r * amp;
		MM->color.g = extreme.g * amp;
		MM->color.b = extreme.b * amp;

		
		extreme = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		amp = MAX( extreme.r , MAX( extreme.g, extreme.b ));
		amp = 1.0f/amp;

		MR->color.r = extreme.r * amp;
		MR->color.g = extreme.g * amp;
		MR->color.b = extreme.b * amp;

		
		extreme = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		amp = MAX( extreme.r , MAX( extreme.g, extreme.b ));
		amp = 1.0f/amp;

		RR->color.r = extreme.r * amp;
		RR->color.g = extreme.g * amp;
		RR->color.b = extreme.b * amp;


		plat1->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		plat2->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		plat3->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		plat4->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		plat5->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);

		plat1->scale = Vector2(3,3);
		plat2->scale = Vector2(3,3);
		plat3->scale = Vector2(3,3);
		plat4->scale = Vector2(3,3);
		plat5->scale = Vector2(3,3);

		if(Input::IsKeyMaskPressed("LL")){
			Audio::PlaySound(Assets::RequestAudio("onPad.ogg",true),1,1,-1,Random::Float(.5,1.5));
		}
		if(Input::IsKeyMaskPressed("ML")){
			Audio::PlaySound(Assets::RequestAudio("onPad.ogg",true),1,1,-0.5,Random::Float(.5,1.5));
		}
		if(Input::IsKeyMaskPressed("MM")){
			Audio::PlaySound(Assets::RequestAudio("onPad.ogg",true),1,1,0,Random::Float(.5,1.5));
		}
		if(Input::IsKeyMaskPressed("MR")){
			Audio::PlaySound(Assets::RequestAudio("onPad.ogg",true),1,1,0.5,Random::Float(.5,1.5));
		}
		if(Input::IsKeyMaskPressed("RR")){
			Audio::PlaySound(Assets::RequestAudio("onPad.ogg",true),1,1,1,Random::Float(.5,1.5));
		}

		somethingHeld = false;

		if(Input::IsKeyMaskHeld("LL")){
			somethingHeld = true;
			float damn = Random::Float(0,0.5f);
			plat1->color = Color(1,damn,damn,1);
			plat1->scale = Vector2(3,3) + Vector2::one * cos(timeHeld*20);
		}
		if(Input::IsKeyMaskHeld("ML")){
			somethingHeld = true;
			float damn = Random::Float(0,0.5f);
			plat2->color = Color(1,damn,damn,1);
			plat2->scale = Vector2(3,3) + Vector2::one * cos(timeHeld*16.3);
		}
		if(Input::IsKeyMaskHeld("MM")){
			somethingHeld = true;
			float damn = Random::Float(0,0.5f);
			plat3->color = Color(1,damn,damn,1);
			plat3->scale = Vector2(3,3) + Vector2::one * sin(timeHeld*20);
		}

		if(Input::IsKeyMaskHeld("MR")){
			somethingHeld = true;
			float damn = Random::Float(0,0.5f);
			plat4->color = Color(1,damn,damn,1);
			plat4->scale = Vector2(3,3) + Vector2::one * cos(timeHeld*13.1);
		}

		if(Input::IsKeyMaskHeld("RR")){
			somethingHeld = true;
			float damn = Random::Float(0,0.5f);
			plat5->color = Color(1,damn,damn,1);
			plat5->scale = Vector2(3,3) + Vector2::one * cos(timeHeld*-11);
		}


		if(somethingHeld){
			timeHeld += Monocle::deltaTime;
			if(timeHeld <5.9){
				char temp[32];
				sprintf(temp,"TIME LEFT TO START: %.1f", 6-timeHeld);
				timer->SetText(temp);
			}
		}
		else
		{
			timeHeld = 0.0f;
		}

		if(timeHeld > 1.0){
			timer->isVisible = true;
			if(timeHeld > 6.0){
				End();
			}
		}
		else{
			timer->isVisible = false;
		}
	}

	void menuScene::End(){
		Scene::End();
		Audio::StopMusic();
		game->SetScene(new mainScene());
	}

	//Text bullshit
	Text::Text(const std::string& text, FontAsset* font)
		: Entity(), font(font), text(text)
	{
	}

	void Text::Render()
	{
		Graphics::PushMatrix();
		//Graphics::Rotate(rotation,0,0,1);
		Graphics::Translate(position);
		Graphics::Scale(Vector2(scale.x,scale.y));
		Graphics::Rotate(rotation,0,0,1);
		Graphics::SetBlend(BLEND_ALPHA);
		Graphics::SetColor(color);
		Graphics::BindFont(font);
		Graphics::RenderText(*font, text, 0, 0);
		Graphics::PopMatrix();
	}


	/// BG STATIC
	bgStatic::bgStatic(){
		Entity();
		amp = 0.5f;
		position *= 0.f;
		anim = new SpriteSequenceAnimation("static/staticone000.png",FilterType::FILTER_NONE, 640,640);
		char numTemp[4];
		
		for(int i = 1; i <= 4; i++)
		{
			sprintf(numTemp, "%03d", i);
			anim->AddFrame(new Sprite("static/staticone"+std::string(numTemp)+".png",FilterType::FILTER_NONE));
		}
		anim->Add("static1",0,5,10.0f,true);
		anim->Play("static1");
		
		/*
		for(int i = 0; i <= 67; i++){
			sprintf(numTemp, "%03d", i);
			anim->AddFrame(new Sprite("static/statictwo"+std::string(numTemp)+".png", FilterType::FILTER_NONE));
		}
		anim->Add("static2",46,113,10.0f,true);
		*/
		
		
		//anim = new SpriteSequenceAnimation("static/staticthree000.png",FilterType::FILTER_NONE, 640,640);
		//for(int i = 1/*0*/; i <= 349; i++){
		//	sprintf(numTemp, "%03d", i);
		//	anim->AddFrame(new Sprite("static/staticthree"+std::string(numTemp)+".png", FilterType::FILTER_NONE));
		//}
		//anim->Add("static3", 114, 463, 10.0f, true);
		//anim->Add("static3", 0, 349, 10.0f, true);
		//anim->Play("static3");
		
		SetGraphic(anim);
	}

	void bgStatic::Update(){
		Entity::Update();
		position = GetScene()->GetCamera()->position;
		mainScene* scene = (mainScene*)GetScene();
		if(scene->hitBeat){
			color = Color(Random::Float(0.5,1),Random::Float(0.5,1),Random::Float(0.5,1),0.12f);
			float max = MAX( color.r , MAX( color.g, color.b) );
			color.r *= amp/max; 
			color.g *= amp/max;
			color.b *= amp/max;
		};
	}


	void mainScene::Begin()
	{
		Scene::Begin();
    
        Graphics::SetBackgroundColor(Color::black);

		//set screen size
		Graphics::Set2D(512, 320);
		//Graphics::SetCameraPosition(Vector2(80, 60));
		GetCamera()->position = Vector2(0,0);
		Assets::SetContentPath("../Content/");
		Level::SetScene(this);

		energyPercentage = 0.0f;
		shakeMulti = Vector2::zero;
		winTimer = 0;

		started = false;
		win = false;
		health = new Text("health", Assets::RequestFont("font.ttf",64));
		health->position = Vector2(-250,-120);
		health->scale = Vector2(0.5f,0.5f);

		timer = new Text("timer", Assets::RequestFont("font.ttf",64));
		timer->position = Vector2(0-64,-140);
		timer->scale = Vector2(0.5,0.5);

		enemies = new Text("ENEMIES: %d", Assets::RequestFont("font.ttf",64));
		enemies->position = Vector2(256-60,-120);
		enemies->scale = Vector2(0.5f,0.5f);

		blankSpr = new Sprite("blank.png", FILTER_NONE);

		for(int i =0; i < MAX_PARTICLES; i++) particleQ.push_front(new Particle());

		//KEYMASKS

		Input::DefineMaskKey("LL",KeyCode::KEY_1);
		Input::DefineMaskKey("ML",KeyCode::KEY_2);
		Input::DefineMaskKey("MM",KeyCode::KEY_3);
		Input::DefineMaskKey("MR",KeyCode::KEY_4);
		Input::DefineMaskKey("RR",KeyCode::KEY_5);
		
		Input::DefineMaskKey("LL",KeyCode::KEY_Q);
		Input::DefineMaskKey("LL",KeyCode::KEY_A);
		Input::DefineMaskKey("LL",KeyCode::KEY_Z);

		Input::DefineMaskKey("ML",KeyCode::KEY_W);
		Input::DefineMaskKey("ML",KeyCode::KEY_S);
		Input::DefineMaskKey("ML",KeyCode::KEY_X);

		Input::DefineMaskKey("MM",KeyCode::KEY_E);
		Input::DefineMaskKey("MM",KeyCode::KEY_D);
		Input::DefineMaskKey("MM",KeyCode::KEY_C);

		Input::DefineMaskKey("MR",KeyCode::KEY_R);
		Input::DefineMaskKey("MR",KeyCode::KEY_F);
		Input::DefineMaskKey("MR",KeyCode::KEY_V);

		Input::DefineMaskKey("RR",KeyCode::KEY_T);
		Input::DefineMaskKey("RR",KeyCode::KEY_G);
		Input::DefineMaskKey("RR",KeyCode::KEY_B);

		//BEAT SHIT
		time = 0.0;
		lastTime = 0.0;
		BPM =  120.0;

		ttBeat		= 1 / (BPM / 60.0); 
		tBtwBeat	= ttBeat;
		//tBtwHalf	= tBtwBeat / 2.0;
		//tBtwQuarter = tBtwHalf / 2.0;

		ttHalf1 = ttBeat/2.0;
		ttHalf2 = ttBeat;

		ttQuarter1 = ttBeat/4.0;
		ttQuarter2 = ttBeat/2.0;
		ttQuarter3 = ttQuarter1 + ttQuarter2;
		ttQuarter4 = ttBeat;


		camVel = Vector2(0,0);
		
		pShip = new playerShip();
		
		Add(bgstatic = new bgStatic());
		bgstatic->color.a = 0.1f;
		City = new city(32,32, this);
		Add(pShip);

		std::vector<Vector2> isections;
			
		for(int i = 0; i < City->width; i++){
			for(int j =0; j < City->width; j++){
				if(City->tiles[i][j]->type == roadIntersection){
					isections.push_back(Vector2(i,j));
				}
			}
		}

		for(int i =0; i < 9; i++){
			int accessor = Random::Int(0, isections.size());
			Vector2 gridPos = isections[accessor];
			baseShip* temp = new baseShip(gridPos, this);
			baseShips.push_front(temp);
			Add(temp);
			isections.erase(isections.begin()+accessor);
		}
		
		GetCamera()->position = pShip->position;

		/// LOAD AUDIO
		loop = Assets::RequestAudio("bg.ogg");
		MM = Assets::RequestAudio("main.ogg");		// Center thruster
		LL = Assets::RequestAudio("leftGun.ogg");		// Left Gun
		ML = Assets::RequestAudio("leftThrust.ogg");	// Left Thruster
		MR = Assets::RequestAudio("rightThrust.ogg");	// Right Thruster
		RR = Assets::RequestAudio("rightGun.ogg");		// Right Gun

		Loopdeck = loop->Play(0);
		Loopdeck->Pause();

		MMdeck = MM->Play(0);
		MMdeck->SetVolume(0.0f);
		MMdeck->Pause();
		
		MRdeck = MR->Play(0);
		MRdeck->SetVolume(0.0f);
		MRdeck->Pause();

		RRdeck = RR->Play(0);
		RRdeck->SetVolume(0.0f);
		RRdeck->Pause();

		MLdeck = ML->Play(0);
		MLdeck->SetVolume(0.0f);
		MLdeck->Pause();

		LLdeck = LL->Play(0);
		LLdeck->SetVolume(0.0f);
		LLdeck->Pause();
		
		gameTime = 0;
	}

	void mainScene::Update()
	{
		if(pShip->gameOver){
			End();
			return;
		}

		Scene::Update();

		City->Update();

		if(pShip->dead){
			health->SetText("YOU SUCK");
			enemies->SetText("SO DEAD");
		}

		if(win){
			health->SetText("CONGRATULATIONS!");
			enemies->SetText("NICE!");
			winTimer+=Monocle::deltaTime;
			if(winTimer > 15){
				LLdeck->Stop();
				MLdeck->Stop();
				MMdeck->Stop();
				MRdeck->Stop();
				RRdeck->Stop();
				Loopdeck->Stop();
				End();
			}
		}

		if(!pShip->dead && !win){
			gameTime+=Monocle::deltaTime;
			inactivity += Monocle::deltaTime;
			if(inactivity > 20.0f){
				pShip->dead = true;
				pShip->deathTimer = 10.0f;
			}
			char temp[64];
			sprintf(temp, "HEALTH: %.1f/%", pShip->health);
			health->SetText(temp);
			Vector2 setup;
			setup.SetFromAngleDegrees(-pShip->rotation);
			Vector2 setup2 = setup.GetPerpendicularLeft().GetNormalized(300);
			setup.Normalize(80);
			health->position = pShip->position + setup + setup2;
			health->rotation = pShip->rotation;
			health->color = Color(((100- pShip->health)/100.f),pShip->health/100.f,0,1);

			sprintf(temp, "ENEMIES: %d", baseShips.size());
			enemies->SetText(temp);
			setup.SetFromAngleDegrees(-pShip->rotation);
			setup2 = setup.GetPerpendicularRight().GetNormalized(160);
			setup.Normalize(80);
			enemies->position = pShip->position + setup + setup2;
			enemies->rotation = pShip->rotation;
			enemies->color = Color(1,Random::Percent(),Random::Percent(),1);


			sprintf(temp, "%.0f", gameTime);
			timer->SetText(temp);
			setup.SetFromAngleDegrees(-pShip->rotation);
			setup2 = setup.GetPerpendicularLeft().GetNormalized(0);
			setup.Normalize(-250);
			timer->position = pShip->position + setup + setup2;
			timer->rotation = pShip->rotation;
			timer->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);






		Vector2 pShipPos;
		pShipPos.SetFromAngleDegrees(pShip->rotation);
		pShipPos.y *= -70.0f;
		pShipPos.x *= 70.0f;
		//pShipPos = pShipPos * 30.0f;
		pShipPos = pShip->position + pShipPos + pShip->velocity * 50.0f;
		camVel.x = pShipPos.x - GetCamera()->position.x;
		camVel.y = pShipPos.y - GetCamera()->position.y;
		camVel *= 3.0f;
		camVel.Clamp(250.0f);

		GetCamera()->rotation = -pShip->rotation;
		//GetCamera()->scale = Vector2(0.75f,0.75f);
		GetCamera()->scale = Vector2(0.05f,0.05f);

		bgstatic->scale = 1 / GetCamera()->scale;
		GetCamera()->scale *= 1-(pShip->velocity.GetMagnitude()/20.0f);


		float gridChangeY = (GetCamera()->position.y + 64.f)/128.0f;
		float gridChangeX = (GetCamera()->position.x + 64.f)/128.0f;

		City->cameraX = floor(City->centerX+gridChangeX);
		City->cameraY = floor(City->centerY+gridChangeY);

		//if(pShip->currentGrid.x < 2.5f) camVel.x = 0; 
		//if(pShip->currentGrid.y < 2.5f) camVel.y = 0;
		//if(pShip->currentGrid.x > City->width - 3.5f) camVel.x = 0; 
		//if(pShip->currentGrid.y > City->height - 3.5f) camVel.y = 0;

		Vector2 cameraLock = GetCamera()->position + (camVel * Monocle::deltaTime);
		cameraLock.x = City->centerX + ( cameraLock.x + 64.0f)/128.0f;
		cameraLock.y = City->centerY + (cameraLock.y + 64.0f)/128.0f;

		if(cameraLock.x < 2.0f) camVel.x = 0; 
		if(cameraLock.y < 2.0f) camVel.y = 0;
		if(cameraLock.x > City->width - 2.0f) camVel.x = 0; 
		if(cameraLock.y> City->height - 2.0f) camVel.y = 0;

		GetCamera()->position = GetCamera()->position + (camVel * Monocle::deltaTime);
		GetCamera()->position += Vector2::Random() * Random::Float(0,5) * shakeMulti;
		if((GetCamera()->position - pShip->position).GetMagnitude() > 390) GetCamera()->position = pShip->position;




		//time += Monocle::deltaTime;

		hitBeat = false;
		hitHalf = false;
		hitQuarter = false;

		time += (Loopdeck->GetChannelStream()->GetOutputTime() - lastTime) / 1000.0;
		lastTime = Loopdeck->GetChannelStream()->GetOutputTime();
		
		if(time > ttBeat){
			ttBeat += tBtwBeat;
			hitBeat = true;
		}
			
		if(time > ttHalf1){
			ttHalf1 += tBtwBeat;
			hitHalf = true;
		}

		if(time > ttHalf2){
			ttHalf2 += tBtwBeat;
			hitHalf = true;
		}

		if(time > ttQuarter1){
			ttQuarter1 += tBtwBeat;
			hitQuarter = true;
		}

		if(time > ttQuarter2){
			ttQuarter2 += tBtwBeat;
			hitQuarter = true;
		}
		
		if(time > ttQuarter3){
			ttQuarter3 += tBtwBeat;
			hitQuarter = true;
		}

		if(time > ttQuarter4){
			ttQuarter4 += tBtwBeat;
			hitQuarter = true;
		}


		if(baseShips.size() == 0){
			win = true;
			for(int i = 0; i < 1900; i++){
					EmitParticle(
						pShip->position, 
						Vector2::Random() * Random::Float(30,600), 
						Vector2(10,10),
						Vector2(95,95),
						Random::Float(0,90),
						Random::Float(-720,720),
						pShip->currentGrid,
						13,
						0.95f,
						Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f),
						Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f));
				}
		}


		Input::IsKeyMaskHeld("LL")?LLdeck->SetVolume(1.0f):LLdeck->SetVolume(0.0f);
		Input::IsKeyMaskHeld("ML")?MLdeck->SetVolume(1.0f):MLdeck->SetVolume(0.0f);
		Input::IsKeyMaskHeld("MM")?MMdeck->SetVolume(1.0f):MMdeck->SetVolume(0.0f);
		Input::IsKeyMaskHeld("MR")?MRdeck->SetVolume(1.0f):MRdeck->SetVolume(0.0f);
		Input::IsKeyMaskHeld("RR")?RRdeck->SetVolume(1.0f):RRdeck->SetVolume(0.0f);

		if( Input::IsKeyMaskHeld("LL")||
			Input::IsKeyMaskHeld("ML")||
			Input::IsKeyMaskHeld("MM")||
			Input::IsKeyMaskHeld("MR")||
			Input::IsKeyMaskHeld("RR")){ inactivity = 0.0f;}


		shakeMulti *= 0.81f;

		//City->colorAmp *= 0.9f;
		City->colorAmp = 1.0f;

		


		City->hitBeat = hitBeat;
		City->hitHalfBeat = hitHalf;
		City->hitQuarterBeat = hitQuarter;
		
		if(!started && Loopdeck->IsPaused()){
			Loopdeck->Play();
			MMdeck->Play();
			MRdeck->Play();
			RRdeck->Play();
			MLdeck->Play();
			LLdeck->Play();
			started=true;
		}

		int numRemoved = 0;
		for (std::list<Particle*>::iterator i = deathList.begin(); (i != deathList.end() && numRemoved<25) || deathList.size() > MAX_PARTICLES / 0.75f; ++i)
		{
			particleQ.remove((*i));
			particleQ.push_front((*i));
			numRemoved++;
		}
		
		for(int i = 0; i < numRemoved; i++) deathList.pop_front();

		for (std::list<Particle*>::reverse_iterator i = particleQ.rbegin(); i != particleQ.rend(); ++i)
		{
			if((*i)->alive){
				(*i)->Update();
			}
			else{	break;	}
		}

		//printf("Particles\t%d\n", particleQ.size());
		//printf("Death List\t%d\n", deathList.size());
		}
		else{
			GetCamera()->scale = Vector2::one - (pShip->deathTimer / 18.0f) * Vector2(0.75f,0.75f);
			bgstatic->scale = 1 / GetCamera()->scale;

					int numRemoved = 0;
			for (std::list<Particle*>::iterator i = deathList.begin(); (i != deathList.end() && numRemoved<25) || deathList.size() > MAX_PARTICLES / 0.75f; ++i)
			{
				particleQ.remove((*i));
				particleQ.push_front((*i));
				numRemoved++;
			}
		
			for(int i = 0; i < numRemoved; i++) deathList.pop_front();

			for (std::list<Particle*>::reverse_iterator i = particleQ.rbegin(); i != particleQ.rend(); ++i)
			{
				if((*i)->alive){
					(*i)->Update();
				}
				else{	break;	}
			}
		}
	}

	void mainScene::HSVtoRGB( float* r, float*g, float* b, float h, float s, float v){
		int i;
        float f, p, q, t;
 
        if( s == 0 ) {
                *r = *g = *b = v; // achromatic (grey)
                return;
        }
 
        h /= 60;                        // sector 0 to 5
        i = floor( h );
        f = h - i;                      // factorial part of h
        p = v * (1-s);
        q = v * (1-s*f);
        t = v * (1-s*(1-f));
 
        switch(i)
        {
                case 0:
                        *r = v;
                        *g = t;
                        *b = p;
                        break;
                case 1:
                        *r = q;
                        *g = v;
                        *b = p;
                        break;
                case 2:
                        *r = p;
                        *g = v;
                        *b = t;
                        break;
                case 3:
                        *r = p;
                        *g = q;
                        *b = v;
                        break;
                case 4:
                        *r = t;
                        *g = p;
                        *b = v;
                        break;
                default:
                        *r = v;
                        *g = p;
                        *b = q;
                        break;
        }

	}

	void mainScene::EmitParticle(Vector2 pos, Vector2 vel, Vector2 siz, Vector2 sizTo, float rot, float rotvel, Vector2 grid, double life, float alpha, Color colorStart, Color colorTo){
		Particle* temp = particleQ.front();
		temp->Init(pos,vel,siz,sizTo,rot,rotvel,grid,life,alpha,this,colorStart,colorTo);
		particleQ.push_back(temp);
		particleQ.pop_front();
	}

	void mainScene::Render(){
		if(!pShip->gameOver){
			Scene::Render();
			for (std::list<Particle*>::reverse_iterator i = particleQ.rbegin(); i != particleQ.rend(); ++i)
			{
				if((*i)->alive){
					(*i)->Render();
				}
				else{	break;	}
			}
			City->Render();
		}

		health->Render();
		timer->Render();
		enemies->Render();
	}

	void mainScene::End()
	{
		//Remove(City);
		Scene::End();
		//LLdeck->Stop();
	//	MLdeck->Stop();
	//	MMdeck->Stop();
	//	MRdeck->Stop();
	//	RRdeck->Stop();
	//	Loopdeck->Stop();
		game->SetScene(new menuScene());
	}

	Particle::Particle(){
		sprite = new Sprite("blank.png",FILTER_NONE);
		alive = false;
	}

	void Particle::Init(Vector2 pos, Vector2 vel, Vector2 siz, Vector2 sizTo, float rot, float rotvel, Vector2 grid, double life, float alpha, mainScene* sce, Color colorStart, Color colorTo){
		position = pos;
		velocity = vel;
		size = siz;
		origSize = siz;
		sizeTo = sizTo;
		rotation = rot;
		rotationalVel = rotvel;
		lifeSpan = life;
		origLife = life;
		currentGrid = grid;
		scene = sce;
		alive = true;
		colorTarget = colorTo;
		//color = Color(Random::Percent(),Random::Percent(),Random::Percent(),alpha);
		//float maxColor = MAX( MAX(color.r,color.g) , color.b);
		//float amplifier = 1.0f / maxColor;
		//color.r *= amplifier;
		//color.g *= amplifier;
		//color.b *= amplifier;
		color = colorStart;
		origColor = color;
		this->alpha = alpha;
	}

	void Particle::Update(){
		lifeSpan -= Monocle::deltaTime;
		if(lifeSpan < 0){
			Die();
		}
		else{
			position += velocity * Monocle::deltaTime;
			velocity *= 0.995f; // friction
			rotation += rotationalVel * Monocle::deltaTime;
			lastGrid = currentGrid;
			currentGrid.x = floor(scene->City->centerX + (position.x + 64.f)/128.0f);
			currentGrid.y = floor(scene->City->centerY + (position.y + 64.f)/128.0f);
			sprite->Update();
			size = (origSize*(lifeSpan/origLife)) + (sizeTo*((origLife-lifeSpan)/origLife));
			if(currentGrid.x < 0 || currentGrid.x > 31 || currentGrid.y < 0 || currentGrid.y > 31){
				Die();
				return;
			}

			if(lastGrid != currentGrid){
				if(scene->City->tiles[(int)currentGrid.x][(int)currentGrid.y]->HasTag("bldg")){
					if(currentGrid.x != lastGrid.x) velocity.x *= -1;
					if(currentGrid.y != lastGrid.y) velocity.y *= -1;
					velocity+= Vector2::Random() * Random::Float(0,10);
				}
			}
			sprite->position = position;
			sprite->rotation = rotation;
			
			color.r = (origColor.r*(lifeSpan/origLife)) + (colorTarget.r*((origLife-lifeSpan)/origLife));
			color.g = (origColor.g*(lifeSpan/origLife)) + (colorTarget.g*((origLife-lifeSpan)/origLife));
			color.b = (origColor.b*(lifeSpan/origLife)) + (colorTarget.b*((origLife-lifeSpan)/origLife));

			//float maxColor = MAX( MAX(color.r,color.g) , color.b);
			//float amplifier = 1.0 / maxColor;
			//color.r *= amplifier;
			//color.g *= amplifier;
			//color.b *= amplifier;
			color.a = alpha * (lifeSpan/origLife);
		}
	}

	void Particle::Die(){
		alive = false;
		scene->deathList.push_back(this);
	}

	void Particle::Render(){
		Graphics::PushMatrix();
        
            // Calculate proper offset
            Vector2 offset = sprite->trimOffset;

			Graphics::Translate(sprite->position.x+offset.x, sprite->position.y-offset.y, 0.0f);
			Graphics::Rotate(sprite->rotation, 0, 0, 1);
            Graphics::Scale( sprite->trimScale );
			Graphics::BindTexture(sprite->texture);
			Graphics::SetBlend(sprite->blend);
            Graphics::SetColor(color);

			Graphics::RenderQuad(size.x, size.y);

		Graphics::PopMatrix();
		Shader::None();
	}

	Projectile::Projectile(Vector2 pos, Vector2 vel, Vector2 grid, float rot, Vector2 siz, double life, std::string ignore){
		Entity();
		//Disable();
		size = siz;
		rectCollider = new RectangleCollider(size.x,size.y);
		SetCollider(rectCollider);
		AddTag("shot");
		lifeSpan = 0.0;
		sprite = new Sprite("blank.png", FILTER_NONE,size.x,size.y);
		SetGraphic(sprite);
		position = pos;
		velocity = vel;
		rotation = rot;
		lifeSpan = life;
		ignoreThis = ignore;
		
	}
	
	void Projectile::Die(){
		Disable();
		SetCollider(NULL);
		RemoveSelf();
	}

	void Projectile::Update(){
		scene = (mainScene*)GetScene();
		//if(IsEnabled()){
			Entity::Update();
			color = Color(Random::Float(0.5,1),Random::Float(0.5,1),Random::Float(0.5,1),1.f);
			lifeSpan -= Monocle::deltaTime;
			if(lifeSpan > 0.0){ 
				position += velocity * Monocle::deltaTime;
				float gridChangeY = (position.y + 64.f)/128.0f;
				float gridChangeX = (position.x + 64.f)/128.0f;
				currentGrid = Vector2(floor(scene->City->centerX+gridChangeX),floor(scene->City->centerY+gridChangeY));
				
			//colisions UGH
				if(currentGrid.x>0 && currentGrid.y>0 && currentGrid.x<31 && currentGrid.y<31){
					bool collided = false;
					int toplX = (int)currentGrid.x - 1;
					int toplY = (int)currentGrid.y - 1;
					CollisionData* cData = new CollisionData();
					
					//baseships
					if(ignoreThis.compare("enemy")){
						for(std::list<baseShip*>::iterator m = scene->baseShips.begin(); m != scene->baseShips.end(); ++m){
							if(Collider::Collide(rectCollider, (*m)->rectCollider, cData))
							{
								collided = true;
								(*m)->health-=1.0f;
								(*m)->color = Color::red;
								for(int m = 0; m < 5; m++){
									float crap = Random::Float(0,.1f);
										scene->EmitParticle(position,
											velocity * -0.2f + Vector2::Random() * Random::Float(1,100), 
											Vector2(4.0f,4.0f), 
											Vector2(8,8),
											Random::Float(0,360), 
											Random::Float(360,720),
											currentGrid,
											1,
											1.0f,
											Color(Random::Float(0.9f,1.f),crap,crap,1.0f),
											Color::white);
								}
								Die();
								return;
							}
						}
					}

					if(ignoreThis.compare("player")){
						CollisionData* cData;
						///if(Collider::Collide(rectCollider, scene->pShip->collider, cData)){
						if( ( scene->pShip->position - position).GetMagnitude() < 10.0f){
							scene->pShip->health -= 1.0f;
							collided = true;
							scene->pShip->color = Color::red;

							for(int m = 0; m < 5; m++){
								float crap = Random::Float(0,.1f);
								scene->EmitParticle(position,
									velocity * -0.2f + Vector2::Random() * Random::Float(1,100), 
									Vector2(4.0f,4.0f), 
									Vector2(8,8),
									Random::Float(0,360), 
									Random::Float(360,720),
									currentGrid,
									1,
									1.0f,
									Color(Random::Float(0.9f,1.f),crap,crap,1.0f),
									Color::white);
							}
							Die();
							return;
						}
					}
					

					//City
					for(int i = 0; i < 3 && !collided; i++){
						for(int j = 0; j < 3; j++){

							//City
							if(scene->City->tiles[toplX+i][toplY+j]->HasTag("bldg")){
								if(Collider::Collide(rectCollider, scene->City->tiles[toplX+i][toplY+j]->collider, cData)){
									//Debug::Log(cData->normal);
									collided = true;
									for(int m = 0; m < 25; m++){
										scene->EmitParticle(position - velocity * Monocle::deltaTime,
											velocity.Reflect(cData->normal) * 0.2f + Vector2::Random() * Random::Float(0,30), 
											Vector2(1.0f,1.0f), 
											Vector2(8,8),
											Random::Float(0,360), 
											Random::Float(360,1080),
											currentGrid,
											1,
											1.0f,
											scene->City->tiles[toplX+i][toplY+j]->color,
											Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f)
											);
									}
								}
							}
							if(collided) break;
						}
						if(collided) break;
					}
					if(collided){
						Die();
					}
				}
				else{
					for(int m = 0; m < 25; m++){
					scene->EmitParticle(position - velocity * Monocle::deltaTime,
						velocity * -0.2f + Vector2::Random() * Random::Float(0,30), 
						Vector2(1.0f,1.0f), 
						Vector2(8,8),
						Random::Float(0,360), 
						Random::Float(360,1080),
						currentGrid,
						1,
						1.0f,
						Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f),
						Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f));	
					}
					Die();

				}
			}
			else { Die(); }
		//}
	}

	void Projectile::Render(){
		if(IsEnabled()){
			blankSpr->width = size.x;
			blankSpr->height = size.y;
			Entity::Render();
		}
	}


	playerShip::playerShip()
	{
		Entity();
		collider = new CircleCollider(10.0f);
		SetCollider(collider);
		velocity = Vector2(0,0);
		rotationalVel = 0.0f;
		rotation = 0.0f;
		position = Vector2(0,0);
		deathTimer = 0.0;

		AddTag("player");

		sprite = new Sprite("ship.png", FilterType::FILTER_NONE);
		SetGraphic(sprite);
		mainScene* scene = (mainScene*)this->GetScene();
		SetLayer(0);

		color = Color::white;
		health = 100.0f;
		hitAlarm = false;
		dead = false;
		gameOver = false;
		colorUpdater = 0.0;
	}

	void playerShip::Update()
	{
		Entity::Update();
		mainScene* scene = (mainScene*)this->GetScene();
		
		colorUpdater += Monocle::deltaTime;
		if(colorUpdater > 360) colorUpdater -= 360.0f;
		if(!dead){
			position+=velocity;
		
			rotation+=rotationalVel;
			while(rotation > 360) rotation-=360;
			while(rotation < 0) rotation+=360;

			velocity /= 1.008f;
			rotationalVel /= 1.024f;
			float gridChangeY = (position.y + 64.f)/128.0f;
			float gridChangeX = (position.x + 64.f)/128.0f;
			currentGrid = Vector2(floor(scene->City->centerX+gridChangeX),floor(scene->City->centerY+gridChangeY));
		
			//Debug::Log(scene->City->tiles[(int)currentGrid.x][(int)currentGrid.y]->type);

			if(scene->City->colorShift){
				color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
			}

			if(health < 8.0f && !hitAlarm){
				hitAlarm = true;
				Audio::PlaySound(Assets::RequestAudio("alarm.ogg"), 5);
			}

			if(hitAlarm) color = Color::red;
			if(health < 0.0f && !dead){
				dead = true;
				Audio::PlaySound(Assets::RequestAudio("exploSmall.ogg"));
				Audio::PlaySound(Assets::RequestAudio("exploSmall.ogg"));
				Audio::PlaySound(Assets::RequestAudio("exploSmall.ogg"));
				this->isVisible = false;

				for(int i = 0; i < 1900; i++){
					colorUpdater += Monocle::deltaTime;
					scene->EmitParticle(
						position, 
						Vector2::Random() * Random::Float(30,600), 
						Vector2(10,10),
						Vector2(95,95),
						Random::Float(0,90),
						Random::Float(-720,720),
						currentGrid,
						13,
						0.95f,
						Color(1,0,0,1),
						Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f));
				}
			}

			float maxColor = MAX( MAX(color.r,color.g) , color.b);
			float amplifier = scene->City->colorAmp / maxColor;
			color.r *= amplifier;
			color.g *= amplifier;
			color.b *= amplifier;

			if(scene->started){
				if(scene->hitQuarter) rotationalVel -= 0.2f;
				rotationalVel += 1.6 * Monocle::deltaTime;
			}

			scene->bgstatic->amp = 0.6f;
		
			if(Input::IsKeyMaskHeld("LL"))
			{
				LLdeck->SetVolume(1.0f);
				if(scene->hitQuarter){
					rotationalVel -= 0.2f;
					Vector2 temp;
					temp.SetFromAngleDegrees(rotation);
					temp.y = -temp.y;
					temp.Normalize(0.35f/8.0f);
					velocity -= temp;
					
					Vector2 offs;
					offs.SetFromAngleDegrees(rotation);
					offs.y *= -1;
					offs = offs.GetPerpendicularRight().GetNormalized(14.f);
					//offs.Normalize(14.f);
					offs += offs.GetPerpendicularRight().GetNormalized(-1.0f);

					Vector2 rands;
					rands.SetFromAngleDegrees(Random::Float(0,360));
					rands.Normalize(20.f);

					temp.Normalize(650);
					scene->Add(new Projectile(position+offs,velocity+temp+rands,currentGrid,rotation,Vector2(2,8),1, "player"));
				}
				scene->bgstatic->amp = 0.1f;
			}
		


			if(Input::IsKeyMaskHeld("ML"))
			{
				MLdeck->SetVolume(1.0f);

				Vector2 temp;
				temp.SetFromAngleDegrees(rotation);
				temp.y = -temp.y;
				temp.Normalize(0.35f);
				velocity+= temp * Monocle::deltaTime;

				rotationalVel += 1.6 * Monocle::deltaTime;

				Vector2 offs;
				offs.SetFromAngleDegrees(rotation);
				offs.y *= -1;
				offs = offs.GetPerpendicularRight().GetNormalized(8.f);
				//offs.Normalize(14.f);
				offs += offs.GetPerpendicularRight().GetNormalized(14.0f);

				Vector2 vel;
				vel.SetFromAngleDegrees(rotation+180);
				vel.y *= -1;

				for(int i = 0; i < 2; i++){
					float crap = Random::Float(.5f,.9f);
					colorUpdater+=Monocle::deltaTime;
					float r,g,b;
					scene->HSVtoRGB(&r, &g, &b, colorUpdater,1.0f,1.0f);
					scene->EmitParticle(						
						position + offs, 
						velocity + vel.GetNormalized(Random::Float(40,100))+Vector2::Random()*10, 
						Vector2(4,4),
						Vector2(30,30),
						Random::Float(0,90),
						Random::Float(-720,720),
						currentGrid,
						6,
						0.5f,
						Color(r,g,b,1.0f),
						Color(r,g,b,1.0f));
				}
			}
		
			if(Input::IsKeyMaskHeld("MM"))
			{	
				MMdeck->SetVolume(1.0f);
				Vector2 temp;
				temp.SetFromAngleDegrees(rotation);
				temp.y = -temp.y;
				temp.Normalize(1.2f);
				velocity+= temp * Monocle::deltaTime;



				Vector2 vel;
				vel.SetFromAngleDegrees(rotation+180);
				vel.y *= -1;

				for(int i = 0; i < 4; i++){
					colorUpdater+=Monocle::deltaTime;
					float crap = Random::Float(.5f,.9f);
					float r,g,b;
					scene->HSVtoRGB(&r, &g, &b, colorUpdater,1.0f,1.0f);
					scene->EmitParticle(
						position + vel.GetNormalized(16.f), 
						velocity + vel.GetNormalized(Random::Float(60,140))+Vector2::Random()*20, 
						Vector2(6,6),
						Vector2(40,40),
						Random::Float(0,90),
						Random::Float(-720,720),
						currentGrid,
						7,
						0.5f,
						Color(r,g,b,1.0f),
						Color(r,g,b,1.0f));
				}

			
			}
		
			if(Input::IsKeyMaskHeld("MR"))
			{
				MRdeck->SetVolume(1.0f);

				Vector2 temp;
				temp.SetFromAngleDegrees(rotation);
				temp.y = -temp.y;
				temp.Normalize(0.35f);
				velocity+= temp * Monocle::deltaTime;

				rotationalVel -= 1.6 *Monocle::deltaTime;



				Vector2 offs;
				offs.SetFromAngleDegrees(rotation);
				offs.y *= -1;
				offs = offs.GetPerpendicularLeft().GetNormalized(8.f);
				//offs.Normalize(14.f);
				offs += offs.GetPerpendicularLeft().GetNormalized(14.0f);

				Vector2 vel;
				vel.SetFromAngleDegrees(rotation+180);
				vel.y *= -1;

				for(int i = 0; i < 2; i++){
					float crap = Random::Float(.5f,.9f);
					colorUpdater+=Monocle::deltaTime;
					float r,g,b;
					scene->HSVtoRGB(&r, &g, &b, colorUpdater,1.0f,1.0f);
					scene->EmitParticle(
						position + offs, 
						velocity + vel.GetNormalized(Random::Float(40,100))+Vector2::Random()*10, 
						Vector2(4,4),
						Vector2(30,30),
						Random::Float(0,90),
						Random::Float(-720,720),
						currentGrid,
						6,
						0.5f,
						Color(r,g,b,1.0f),
						Color(r,g,b,1.0f));
				}


			}
		
			if(Input::IsKeyMaskHeld("RR"))
			{
				RRdeck->SetVolume(1.0f);
				if(scene->hitQuarter){
					rotationalVel += 0.2f;

					Vector2 temp;
					temp.SetFromAngleDegrees(rotation);
					temp.y = -temp.y;
					temp.Normalize(0.35f/8.0f);
					velocity -= temp;

					Vector2 offs;
					offs.SetFromAngleDegrees(rotation);
					offs.y *= -1;
					offs = offs.GetPerpendicularLeft().GetNormalized(14.0f);
					offs += offs.GetPerpendicularLeft().GetNormalized(-1.f);


					Vector2 rands;
					rands.SetFromAngleDegrees(Random::Float(0,360));
					rands.Normalize(20.f);

					temp.Normalize(650);
					scene->Add(new Projectile(position+offs,velocity+temp+rands,currentGrid,rotation,Vector2(2,8),1, "player"));
				}
				scene->bgstatic->amp = 0.1f;
			}

			if(currentGrid.x>0 && currentGrid.y>0 && currentGrid.x<31 && currentGrid.y<31){
				bool collided = false;
				int toplX = (int)currentGrid.x - 1;
				int toplY = (int)currentGrid.y - 1;
				CollisionData* cData = new CollisionData();


				//City
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						if(scene->City->tiles[toplX+i][toplY+j]->HasTag("bldg")){

							if(Collider::Collide(collider, scene->City->tiles[toplX+i][toplY+j]->collider, cData)){
								collided = true;
								health -= cData->penetration * 3;
								Audio::PlaySound(Assets::RequestAudio("crash.ogg"),1,1,0,Random::Float(.25f,1.5f));
							}
						}
						if(collided) break;
					}
					if(collided) break;
				}
				if(collided){
					float rot = rotation - 90.0f;
					while(rot<0)rot+=360;
				
					float forward = abs(rot-velocity.GetAngleDegrees());
					while(forward>180) forward -= 360;
					forward = (forward - 90.0f) / 90.0f;

					//printf("Collided: %f\n", velocity.GetMagnitude());

					//position -= velocity * Monocle::deltaTime;
					position += cData->normal * cData->penetration;
					velocity.Reflect(cData->normal);
					velocity*=0.95f;
					Vector2 diff = position - cData->hitPoint;
					float angleBetween = cData->normal.GetAngleDegrees() - rotation - 90.0f;
					while(angleBetween<0) angleBetween += 360.0f;
					while(angleBetween>360) angleBetween -= 360.0f;
 
					if(angleBetween > 180.0f && angleBetween < 360.0f){
						rotationalVel += 2.65f * forward * velocity.GetMagnitude() / 4.1f;
					}
					else if(angleBetween < 180.0f && angleBetween > 0.0f){
						rotationalVel -= 2.65f * forward * velocity.GetMagnitude() / 4.1f;
					}
				}
			}
		}
		else{
			position = position;
			deathTimer += Monocle::deltaTime;
			scene->City->colorAmp = 1.0f;
			velocity =  Vector2::one * (0 + 20 *deathTimer/40.0f);
			if(deathTimer > 15){
				gameOver = true;
				LLdeck->Stop();
				MLdeck->Stop();
				MMdeck->Stop();
				MRdeck->Stop();
				RRdeck->Stop();
				Loopdeck->Stop();
			}
		}
	}

	Fighter::Fighter(Vector2 pos, Vector2 vel, float rot, mainScene* sce, Vector2 curGrid){
		Entity();
		position = pos;
		velocity = vel;
		rotation = rot;
		scene = sce;
		currentGrid = curGrid;
		SetGraphic(new Sprite("fighter.png", FILTER_NONE, 16, 16));
		targeting = false;
		targetDirection = vel;
	}

	void Fighter::Update(){
		Entity::Update();
		position += velocity * Monocle::deltaTime;
		float gridChangeY = (position.y + 64.f)/128.0f;
		float gridChangeX = (position.x + 64.f)/128.0f;
		currentGrid = Vector2(floor(scene->City->centerX+gridChangeX),floor(scene->City->centerY+gridChangeY));

		velocity.SetFromAngleDegrees(rotation);
		velocity.Normalize(50.0f);

		targetDirection *= 0;
		if(currentGrid.y < scene->pShip->currentGrid.y){
			targetDirection.y = 1; // go down
		}
		else if(currentGrid.y > scene->pShip->currentGrid.y){
			targetDirection.y = -1; //go up
		}
		if(currentGrid.x < scene->pShip->currentGrid.x){
			targetDirection.x = 1; // go right
		}
		else if(currentGrid.x > scene->pShip->currentGrid.x){
			targetDirection.x = -1; //go left
		}

		float targetRot = targetDirection.GetAngleDegrees();

		while(rotation > 360) rotation-=360;
		while(rotation < 0) rotation+=360;
		while(targetRot > 360) targetRot-=360;
		while(targetRot < 0) targetRot+=360;

		float distLeft = rotation - targetRot;
		float distRight = targetRot - rotation;

		if(distRight > distLeft){
			rotation += 360 * Monocle::deltaTime;
		}
		else{
			rotation -= 360 * Monocle::deltaTime;
		}
	}

	void Fighter::Render(){
		Entity::Render();
	}

	baseShip::baseShip(Vector2 gridPos, mainScene* sce){
		Entity();
		health = 100;
		SetGraphic(new Sprite("/base/base.png",FILTER_NONE,128,128));
		velocity = Vector2::zero;

		scene = sce;

		rectCollider = new RectangleCollider(128,128);
		AddTag("enemy");
		SetCollider(rectCollider);

		currentGrid = gridPos;
		lastGrid = currentGrid;
		position.x = (gridPos.x - scene->City->centerX) * 128.0f;// - 64.0f;
		position.y = (gridPos.y - scene->City->centerY) * 128.0f;// - 64.0f;
		
		wheelTL = new Entity();
		wheelTL->rotation = Random::Float(0,360);
		wheelTL->SetParent(this);
		wheelTL->color = Color::white;
		wheelTL->SetGraphic(new Sprite("/base/wheel.png", FILTER_NONE, 28,28));
		wheelTL->position = Vector2(-64+16,-64+16);

		wheelTR = new Entity();
		wheelTR->rotation = Random::Float(0,360);
		wheelTR->SetParent(this);
		wheelTR->color = Color::white;
		wheelTR->SetGraphic(new Sprite("/base/wheel.png", FILTER_NONE, 28,28));
		wheelTR->position = Vector2(64-16,-64+16);

		wheelBL = new Entity();
		wheelBL->rotation = Random::Float(0,360);
		wheelBL->SetParent(this);
		wheelBL->color = Color::white;
		wheelBL->SetGraphic(new Sprite("/base/wheel.png", FILTER_NONE, 28,28));
		wheelBL->position = Vector2(-64+16,64-16);

		wheelBR = new Entity();
		wheelBR->rotation = Random::Float(0,360);
		wheelBR->SetParent(this);
		wheelBR->color = Color::white;
		wheelBR->SetGraphic(new Sprite("/base/wheel.png", FILTER_NONE, 28,28));
		wheelBR->position = Vector2(64-16,64-16);

		turretTL = new Entity();
		turretTL->rotation = 0;
		turretTL->SetParent(this);
		turretTL->SetGraphic(new Sprite("/base/turret.png",FILTER_NONE,12,20));
		turretTL->position = Vector2(-30,-34);

		turretTR = new Entity();
		turretTR->rotation = 0;
		turretTR->SetParent(this);
		turretTR->SetGraphic(new Sprite("/base/turret.png",FILTER_NONE,12,20));
		turretTR->position = Vector2(30,-34);

		turretBL = new Entity();
		turretBL->rotation = 0;
		turretBL->SetParent(this);
		turretBL->SetGraphic(new Sprite("/base/turret.png",FILTER_NONE,12,20));
		turretBL->position = Vector2(-30,26);

		turretBR = new Entity();
		turretBR->rotation = 0;
		turretBR->SetParent(this);
		turretBR->SetGraphic(new Sprite("/base/turret.png",FILTER_NONE,12,20));
		turretBR->position = Vector2(30,26);

		curDir = RIGHT;
		float dir = Random::Percent();
		if(dir < 1.0/4.0) curDir = UP;
		if(dir >= 1.0/4.0 && dir < 1.0/2.0) curDir = DOWN;
		if(dir >=1.0/2.0 && dir < 3.0/4.0) curDir = LEFT;

		//distanceLeft = 100000.0f;
	}

	void baseShip::Update(){
		if(scene->hitBeat && health <= 0){
			Die();
			return;
		}

		Vector2 scaledVel = velocity * Monocle::deltaTime;
		position += scaledVel;

		float gridChangeY = (position.y+64.0f)/128.0f;
		float gridChangeX = (position.x+64.0f)/128.0f;
		currentGrid = Vector2(floor(scene->City->centerX+gridChangeX),floor(scene->City->centerY+gridChangeY));

		//Debug::Log(currentGrid);

		if(lastGrid != currentGrid){
			Vector2 curGridCen = Vector2((currentGrid.x - scene->City->centerX) * 128.0f,(currentGrid.y - scene->City->centerY) * 128.0f); 
			if((curGridCen - position).GetMagnitude()<0.5f){
				lastGrid = currentGrid;
				if(lastGrid.x < 0 || lastGrid.x > 31 || lastGrid.y < 0 || lastGrid.y > 31) {
					health = -100;
					return;
				}
				tileType type = scene->City->tiles[(int)currentGrid.x][(int)currentGrid.y]->type;
				if(type == roadIntersection){
					curDir = RIGHT;
					float dir = Random::Percent();
					if(dir < 1.0/4.0) curDir = UP;
					if(dir >= 1.0/4.0 && dir < 1.0/2.0) curDir = DOWN;
					if(dir >=1.0/2.0 && dir < 3.0/4.0) curDir = LEFT;
				}
			
				if(type == roadNEW){
					curDir = RIGHT;
					float dir = Random::Percent();
					if(dir < 1.0/3.0) curDir = UP;
					if(dir >= 1.0/3.0 && dir < 2.0/3.0) curDir = LEFT;
				}
				if(type == roadNSE){
					curDir = RIGHT;
					float dir = Random::Percent();
					if(dir < 1.0/3.0) curDir = UP;
					if(dir >= 1.0/3.0 && dir < 2.0/3.0) curDir = DOWN;
				}
				if(type == roadSEW){
					curDir = RIGHT;
					float dir = Random::Percent();
					if(dir < 1.0/3.0) curDir = DOWN;
					if(dir >= 1.0/3.0 && dir < 2.0/3.0) curDir = LEFT;
				}
				if(type == roadNSW){
					curDir = LEFT;
					float dir = Random::Percent();
					if(dir < 1.0/3.0) curDir = UP;
					if(dir >= 1.0/3.0 && dir < 2.0/3.0) curDir = DOWN;
				}

				if(type == roadENcorner){
					curDir = Random::Percent()>=0.5f?RIGHT:UP;
				}
				if(type == roadEScorner){
					curDir = Random::Percent()>=0.5f?RIGHT:DOWN;
				}
				if(type == roadWNcorner){
					curDir = Random::Percent()>=0.5f?LEFT:UP;
				}
				if(type == roadWScorner){
					curDir = Random::Percent()>=0.5f?LEFT:DOWN;
				}
			}
		}

		Entity::Update();

		wheelTL->Update();
		wheelBL->Update();
		wheelTR->Update();
		wheelBR->Update();

		turretBR->Update();
		turretBL->Update();
		turretTR->Update();
		turretTL->Update();

		if(scene->City->colorShift){
			color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		}

		float maxColor = MAX( MAX(color.r,color.g) , color.b);
		float amplifier = 1 / maxColor;//scene->City->colorAmp / maxColor;
		color.r *= amplifier;
		color.g *= amplifier;
		color.b *= amplifier;

		wheelTL->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		wheelBL->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		wheelTR->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		wheelBR->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);

		turretBR->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		turretBL->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		turretTR->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);
		turretTL->color = Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f);

		turretBR->rotation += Random::Float(-180,180) * Monocle::deltaTime;
		turretBL->rotation += Random::Float(-180,180) * Monocle::deltaTime;
		turretTR->rotation += Random::Float(-180,180) * Monocle::deltaTime;
		turretTL->rotation += Random::Float(-180,180) * Monocle::deltaTime;

		if(curDir == UP){
			velocity = Vector2(0,-20);
			wheelTL->rotation -= 90 * Monocle::deltaTime;
			wheelTR->rotation += 90 * Monocle::deltaTime;
			wheelBL->rotation -= 90 * Monocle::deltaTime;
			wheelBR->rotation += 90 * Monocle::deltaTime;

		}
		else if(curDir == DOWN){
			velocity = Vector2(0,20);
			wheelTL->rotation += 90 * Monocle::deltaTime;
			wheelTR->rotation -= 90 * Monocle::deltaTime;
			wheelBL->rotation += 90 * Monocle::deltaTime;
			wheelBR->rotation -= 90 * Monocle::deltaTime;
		}
		else if(curDir == LEFT){
			velocity = Vector2(-20,0);
			wheelTL->rotation += 90 * Monocle::deltaTime;
			wheelTR->rotation += 90 * Monocle::deltaTime;
			wheelBL->rotation -= 90 * Monocle::deltaTime;
			wheelBR->rotation -= 90 * Monocle::deltaTime;
		}
		else{
			velocity = Vector2(20,0);
			wheelTL->rotation -= 90 * Monocle::deltaTime;
			wheelTR->rotation -= 90 * Monocle::deltaTime;
			wheelBL->rotation += 90 * Monocle::deltaTime;
			wheelBR->rotation += 90 * Monocle::deltaTime;
		}

		if(currentGrid.x == scene->pShip->currentGrid.x || currentGrid.y == scene->pShip->currentGrid.y ){
			float turret = Random::Percent();
			if(turret < 0.25f){
				Vector2 aim = scene->pShip->position - turretBR->GetWorldPosition();
				turretBR->rotation = aim.GetAngleDegrees()+90;
				if(scene->hitBeat){
					scene->Add(new Projectile(turretBR->GetWorldPosition(),aim.GetNormalized(600.f) + Vector2::Random() * 30.0f, currentGrid, turretBR->rotation, Vector2(3.5f,7.5f), 1.5f, "enemy"));
				}
			}
			else if(turret >= 0.25f && turret < 0.5f){
				Vector2 aim = scene->pShip->position - turretBL->GetWorldPosition();
				turretBL->rotation = aim.GetAngleDegrees()+90;
				if(scene->hitBeat){
					scene->Add(new Projectile(turretBL->GetWorldPosition(),aim.GetNormalized(600.f) + Vector2::Random() * 30.0f, currentGrid, turretBL->rotation, Vector2(3.5f,7.5f), 1.5f, "enemy"));
				}
			}
			else if(turret >= 0.5f && turret < 0.75f){
				Vector2 aim = scene->pShip->position - turretTR->GetWorldPosition();
				turretTR->rotation = aim.GetAngleDegrees()+90;
				if(scene->hitBeat){
					scene->Add(new Projectile(turretTR->GetWorldPosition(),aim.GetNormalized(600.f) + Vector2::Random() * 30.0f, currentGrid, turretTR->rotation, Vector2(3.5f,7.5f), 1.5f, "enemy"));
				}
			}
			else{
				Vector2 aim = scene->pShip->position - turretTL->GetWorldPosition();
				turretTL->rotation = aim.GetAngleDegrees()+90;
				if(scene->hitBeat){
					scene->Add(new Projectile(turretTL->GetWorldPosition(),aim.GetNormalized(600.f) + Vector2::Random() * 30.0f, currentGrid, turretTL->rotation, Vector2(3.5f,7.5f), 1.5f, "enemy"));
				}
			}
		}

	}

	void baseShip::Die(){
		Audio::PlaySound(Assets::RequestAudio("exploBig.ogg"));
		scene->shakeMulti = Vector2(10,10);
		for(int i =0; i < 400; i++){
			scene->EmitParticle( 
				position + Vector2::Random() * Random::Float(0,8), 
				Vector2::Random() * Random::Float(10,200),
				Vector2(3,3),
				Vector2(40,40),
				Random::Float(0,360),
				Random::Float(-720,720),
				currentGrid,
				10,
				1.0f,
				Color(Random::Float(.8,1),Random::Float(.1,.2),Random::Float(.1,.2),1.0f),
				Color(Random::Percent(),Random::Percent(),Random::Percent(),1.0f));
		}
		scene->baseShips.remove(this);
		RemoveSelf();
	}

	void baseShip::Render(){
		wheelTL->Render();
		wheelBL->Render();
		wheelTR->Render();
		wheelBR->Render();
		Entity::Render();
		turretBR->Render();
		turretBL->Render();
		turretTR->Render();
		turretTL->Render();
	}
}
