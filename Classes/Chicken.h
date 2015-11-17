#ifndef __CHICKEN_SPRITE__
#define __CHICKEN_SPRITE__

#include <cocos2d.h>

using namespace cocos2d;

typedef enum
{
    start,
    jumping,
    falling,
    dying

} PlayerState;


class Chicken {
public:
    Chicken(void);
    void addPhysicsBody();
    void applySpeedX(float speed);
    void createChicken(cocos2d::Layer* layer);
    void decreaseVectorX();
    Sprite* getChicken() { return _chicken; }
    Vec2 getPosition() { return _chicken->getPosition(); }
    PlayerState getState();
    float getVectorX();
    Vec2* getVector() { return &_vector; }
    void increaseSpriteSize();
    void increaseVectorX();
//    void moveToFinishingPosition();
//    void runFinishingMove();
    void setAnimation();
    void setState(PlayerState state);
    void setVector(Vec2 vector) { _vector = vector; }
    void update(float dt);

private:
    Vec2 _origin;
    Size _visibleSize;
    Sprite* _chicken;
    PlayerState _state;
    Vec2 _vector;
    float _weight;
    float _scale;
    
    void increaseWeight();
    
    std::string const _imageFile = "playerfly_1.png";
};



#endif /* __CHICKEN_SPRITE__ */
