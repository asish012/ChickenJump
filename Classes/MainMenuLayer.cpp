#include "MainMenuLayer.h"

#include "Constants.h"
#include "GameLayer.h"

using namespace cocos2d;

Scene* MainMenuLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    MainMenuLayer *layer = MainMenuLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuLayer::init()
{
    // 1. super init first
    if ( !Layer::init() ) {
        return false;
    }
    
    // 2. origin & window size
    _origin = Director::getInstance()->getVisibleOrigin();
    _visibleSize = Director::getInstance()->getVisibleSize();
    
    // Add background
    {
        auto background = Sprite::create("blank.png");
        background->setPosition(Point(_visibleSize.width / 2 + _origin.x, _visibleSize.height / 2 + _origin.y));
        this->addChild(background);
    }
    
    // Play Menu Item
    {
        Label* selectLevel = Label::createWithTTF("Select Level", "Marker Felt.ttf", _visibleSize.height * SCORE_FONT_SIZE);
        if (selectLevel) {
            selectLevel->setColor(Color3B::WHITE);
            selectLevel->setPosition(_visibleSize.width * 0.5, _visibleSize.height * 0.7);
            this->addChild(selectLevel);
        }
    }
    
    // Select Levels
    {
        MenuItem* france = MenuItemImage::create("france.png", "france.png", CC_CALLBACK_1(MainMenuLayer::menuSelectFrance, this));
        MenuItem* england = MenuItemImage::create("england.png", "england.png", CC_CALLBACK_1(MainMenuLayer::menuSelectEngland, this));
        MenuItem* spain = MenuItemImage::create("spain.png", "spain.png", CC_CALLBACK_1(MainMenuLayer::menuSelectSpain, this));
        MenuItem* italy = MenuItemImage::create("italy.png", "italy.png", CC_CALLBACK_1(MainMenuLayer::menuSelectItaly, this));
        
        Menu* menu = Menu::create(france, england, spain, italy, NULL);
        menu->alignItemsHorizontallyWithPadding(25);
        menu->setPosition(_visibleSize.width * 0.5, _visibleSize.height * 0.4);
        this->addChild(menu);
    }
    
    
    return true;
}

void MainMenuLayer::gotoGamePlayLayer(cocos2d::Ref* sender)
{
    auto scene = GameLayer::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}



static Size smallResource  = Size(480, 320); // "iphone"
static Size mediumResource = Size(1024, 768); // "ipad"
static Size largeResource  = Size(2048, 1536); // "ipadhd"
static Size designResolution = Size(480, 320);

void MainMenuLayer::menuSelectFrance(cocos2d::Ref* sender) {
    selectLevel("france");
    gotoGamePlayLayer(this);
}

void MainMenuLayer::menuSelectEngland(cocos2d::Ref* sender) {
    selectLevel("england");
    gotoGamePlayLayer(this);
}

void MainMenuLayer::menuSelectSpain(cocos2d::Ref* sender) {
    selectLevel("spain");
    gotoGamePlayLayer(this);
}

void MainMenuLayer::menuSelectItaly(cocos2d::Ref* sender) {
    selectLevel("italy");
    gotoGamePlayLayer(this);
}

void MainMenuLayer::selectLevel(std::string level) {
    Size screenSize = Director::getInstance()->getOpenGLView()->getFrameSize();
    std::vector<std::string> searchPaths;
    
    if (screenSize.height > mediumResource.height) {
        searchPaths.push_back("ipadhd");
        searchPaths.push_back("ipadhd/" + level);
    }
    else if (screenSize.width > smallResource.width) {
        searchPaths.push_back("ipad");
        searchPaths.push_back("ipad/" + level);
    }
    else {
        searchPaths.push_back("iphone");
        searchPaths.push_back("iphone/" + level);
    }
    auto fileUtils = FileUtils::getInstance();
    fileUtils->setSearchPaths(searchPaths);
    
}



