#include "Collectable.h"

#include "Constants.h"


// 1:egg 2:pizza 3:bomb
//static const int pattern[] = {1, 2, 3, 1, 1, 2, 3, 3, 1, 2, 1, 2, 3, 1, 1, 2, 3, 1, 3, 2};
static const int pattern[] = {2, 2, 2};
static const std::vector<int> collectablePattern(pattern, pattern + sizeof(pattern) / sizeof(int));
static int currentPatternIndex = 0;

Collectable::Collectable(void){
    _origin = Director::getInstance()->getVisibleOrigin();
    _visibleSize = Director::getInstance()->getVisibleSize();
}

void Collectable::spawn(cocos2d::Layer* layer, std::vector<Sprite*>& collectables, int pattern) {
    if (not layer) { return; }
    
    const float distanceBetweenCollectables = 0.001;
    int numberOfCollectable = 0;
    int degree = 0;
    float radius = 0.0;
    
    switch (pattern) {
        case 0:
            return;
        case 1:
            numberOfCollectable = 5;
            degree = 45;
            radius = 0.075;
            break;
        case 2:
            numberOfCollectable = 7;
            degree = 30;
            radius = 0.15;
            break;
        case 3:
            numberOfCollectable = 3;
            degree = 90;
            radius = 0.05;
            break;
            
        default:
            return;
    }
    
    int collectableType = collectablePattern.at(currentPatternIndex++ % collectablePattern.size());
    
    int heightRange = _visibleSize.height * 0.25;
    int minHeight = (_visibleSize.height * 0.4);
    int minPosY = CCRANDOM_0_1() * heightRange + minHeight;
    
    float positionX = _visibleSize.width;
    float positionY;
    for (int i = 0; i < numberOfCollectable; ++i) {
        Sprite* collectable = Sprite::create(String::createWithFormat("egg%i.png", collectableType)->getCString());
        collectable->setTag(collectableType); // used as CollectableType:: 1:egg 2:pizza 3:bomb
        
        positionX += _visibleSize.width * distanceBetweenCollectables; // distance between collectables
        positionY = (_visibleSize.width * radius) * sin(degree2radian(i * degree)); // y = radius * sin(angle) // bigger radius = higher parabola
        collectable->setPosition(Vec2(positionX, minPosY + positionY));
        
        auto body = PhysicsBody::createCircle(collectable->getContentSize().width / 2, PhysicsMaterial(0.1f, 1.0f, 0.0f));
        body->setCategoryBitmask(CATEGORY_BITMASK_COLLECTABLE);
        // body->setCollisionBitmask(1);
        body->setContactTestBitmask(CATEGORY_BITMASK_CHICKEN);
        body->setDynamic(false);
        collectable->setPhysicsBody(body);
        
        layer->addChild(collectable, BackgroundLayer::layerChicken);
        collectables.push_back(collectable);
        
        positionX += collectable->getContentSize().width * 1.5; // distance must be atleast 1.5 collectable width
    }
}









