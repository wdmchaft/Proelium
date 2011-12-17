//
// Polycode template. Write your code here.
//

#import "PolycodeView.h"
#include "Polycode.h"
#include "Player.h"
#include "Enemy.h"
//For convertIntToString
#include <sstream>

using namespace Polycode;

class ProeliumApp : public EventHandler {
public:
    ProeliumApp(PolycodeView *view);
    ~ProeliumApp();
    
    void handleEvent(Event *e);
    
    bool Update();
    
    Screen *screen;
    Scene *scene;
    Player *player;
private:
    Core *core;
};