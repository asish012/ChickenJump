#ifndef __PAUSELAYER_H__
#define __PAUSELAYER_H__

#include "cocos2d.h"
#include <UIWidget.h>

using namespace cocos2d;

class PauseLayer : public cocos2d::LayerColor
{
public:
    virtual bool init();
    CREATE_FUNC(PauseLayer);
    
private:
    void createMenus();
    void createAdLayout();
    void addResumeButton();
    void addRestartButton();
    void addMainMenuButton();
    void addSoundButton();
    void addMusicButton();

    void mainMenuClicked(const Ref* ref, const cocos2d::ui::Widget::TouchEventType& eEventType);
    void restartClicked(const Ref* ref, const cocos2d::ui::Widget::TouchEventType& eEventType);
    void toggleSound(const Ref* ref, const cocos2d::ui::Widget::TouchEventType& eEventType);
    void toggleMusic(const Ref* ref, const cocos2d::ui::Widget::TouchEventType& eEventType);

private:
    Vec2 _origin;
    Size _visibleSize;
};


#endif // __PAUSELAYER_H__
