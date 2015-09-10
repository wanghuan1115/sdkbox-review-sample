#include "HelloWorldScene.h"

#include "cocostudio/CocoStudio.h"
#include "PluginReview/PluginReview.h"


USING_NS_CC;

class PluginReviewListenerCpp: public sdkbox::ReviewListener {
public:
    virtual void didDisplayAlert() {
        CCLOG("reivew dialog show");
    };
    virtual void didDeclineToRate() {
        CCLOG("user decline to rate my app");
    };
    virtual void didToRate() {
        CCLOG("user did rate my app");
    };
    virtual void didToRemindLater() {
        CCLOG("user want be remind later");
    };
};

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    FileUtils::getInstance()->addSearchPath("res/Default/");
    
    sdkbox::PluginReview::setListener(new PluginReviewListenerCpp());
    sdkbox::PluginReview::init();
    
    newButtonRate();
    newButtonIncrease();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::newButtonRate() {
    auto label = Label::createWithTTF("Rate the App", "fonts/arial.ttf", 12.0f);
    auto btn = new MenuItemLabel();
    btn->initWithLabel(label, CC_CALLBACK_1(HelloWorld::onRateClicked, this));
    btn->setPosition(Vec2(200, 200));
    auto menu = Menu::create(btn, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    _btnRate = btn;
}

void HelloWorld::newButtonIncrease() {
    auto label = Label::createWithTTF("Insrease User Event", "fonts/arial.ttf", 12.0f);
    auto btn = new MenuItemLabel();
    btn->initWithLabel(label, CC_CALLBACK_1(HelloWorld::onIncreaseClicked, this));
    btn->setPosition(Vec2(200, 150));
    auto menu = Menu::create(btn, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    _btnRate = btn;
}


void HelloWorld::onRateClicked(cocos2d::Ref* pSender) {
    sdkbox::PluginReview::forceToShowPrompt();
}

void HelloWorld::onIncreaseClicked(cocos2d::Ref* pSender) {
    sdkbox::PluginReview::userDidSignificantEvent(false);
}
