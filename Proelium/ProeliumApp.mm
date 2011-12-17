// Polycode template. Write your code here.
// 

#include "ProeliumApp.h"

Polycode::String convertIntToString(int integer);

ProeliumApp::ProeliumApp(PolycodeView *view) : EventHandler() {
    core = new CocoaCore(view, 640, 480, false, 16, 60);	  
	CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default");

    screen = new Screen();
    
    scene = new Scene();
	ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 5,5);
	ground->loadTexture("stone.png");
    scene->addEntity(ground);
    
	player = new Player();
    player->model->loadTexture("Wood.png");
	player->model->setPosition(0.0, 0.5, 0.0);
	scene->addEntity(player->model);
    
    //Player must be initialised first
    ScreenLabel *label = new ScreenLabel(convertIntToString(player->currentHealth) + "/" + convertIntToString(player->maxHealth), 32);
    screen->addChild(label);
	
	scene->getDefaultCamera()->setPosition(6,4,0);
	scene->getDefaultCamera()->lookAt(Vector3(0,0,0));
    
	core->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);
    
    Enemy* enemy = new Enemy();
    enemy->model->setPosition(1, 0.5, 0);
    scene->addEntity(enemy->model);
    
}

ProeliumApp::~ProeliumApp() {
    //Releasing the global pointers to prevent memory leaks?
    delete screen;
    delete scene;
    delete player;
    delete core;
}

bool ProeliumApp::Update() {
    return core->Update();
}
void ProeliumApp::handleEvent(Event *e) {
	if(e->getDispatcher() == core->getInput()) {
		InputEvent *inputEvent = (InputEvent*)e;
		
		switch(e->getEventCode()) {
			case InputEvent::EVENT_KEYUP:
				switch (inputEvent->key) {
					case Polycode::KEY_w:
                        scene->getDefaultCamera()->setPositionX(scene->getDefaultCamera()->getPosition().x - 1);
                        player->model->setPositionX(player->model->getPosition().x - 1);
                        break;
					case Polycode::KEY_s:
                        scene->getDefaultCamera()->setPositionX(scene->getDefaultCamera()->getPosition().x + 1);
                        player->model->setPositionX(player->model->getPosition().x + 1);
                        break;
                    case Polycode::KEY_a:
                        scene->getDefaultCamera()->setPositionZ(scene->getDefaultCamera()->getPosition().z + 1);
                        player->model->setPositionZ(player->model->getPosition().z + 1);
                        break;
					case Polycode::KEY_d:
                        scene->getDefaultCamera()->setPositionZ(scene->getDefaultCamera()->getPosition().z - 1);
                        player->model->setPositionZ(player->model->getPosition().z - 1);
                        break;	
				}
                break;			
		}
		
	}
}
Polycode::String convertIntToString(int integer)
{
    std::stringstream out;
    out << integer;
    return out.str();
}
