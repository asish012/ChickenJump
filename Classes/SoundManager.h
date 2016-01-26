#ifndef __SOUNDMANAGER__
#define __SOUNDMANAGER__

#include <cocos2d.h>

class SoundManager {
public:
    SoundManager();
    
    static float IsSoundActive();
    static float IsMusicActive();
    static void Play(std::string const& sound);
    static void ToggleMusic();
    static void ToggleSound();

    static std::string soundStart;
    static std::string soundJump;
    static std::string soundPickupCoin;
    static std::string soundPickupFood;
    static std::string soundLifeup;
    static std::string soundExplosion;
    static std::string soundDead;
    static std::string soundWin;
};

#endif // __SOUNDMANAGER__
