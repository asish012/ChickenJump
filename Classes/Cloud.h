#ifndef __CLOUD_SPRITE__
#define __CLOUD_SPRITE__

#include <cocos2d.h>

using namespace cocos2d;

class Cloud {
public:
    Cloud(void);
    void spawn(cocos2d::Layer* layer);
    
private:
    Sprite* _cloud;
    Layer* _layer;
    
    Vec2 _origin;
    Size _visibleSize;
    
//    std::string const _spriteImage = "tree_br.png";
};


#endif /* __CLOUD_SPRITE__ */
