#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer2.hpp>
#include <windows.h>
#include <string>

using namespace cocos2d;

auto director = CCDirector::sharedDirector();
auto winSize = director->getWinSize();

class $modify(CODEBREAK_Layer, SecretLayer2) {
	bool init() {
		if (!SecretLayer2::init()) {
			return false;
		}

		auto sprite = CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png");
		
		auto label = CCLabelBMFont::create("Cod3breaker\n    code    ", "bigFont.fnt");
		label->setPosition(45, 85);
		label->setScale(0.3f);
		this->addChild(label);

		auto btn = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(CODEBREAK_Layer::onCodeBreak));

		auto menu = CCMenu::create();
		menu->setPosition(45, 45);
		menu->addChild(btn);

		this->addChild(menu);
		return true;
	}

	void onCodeBreak(CCObject*) {
		auto GM = GameManager::sharedState();
		auto code = "The <cr>Cod3Breaker</c> code is: <cy>" + std::to_string(GM->m_secretNumber * -1);
		FLAlertLayer::create("Cod3breaker", code, "OK")->show();

		geode::utils::clipboard::write(std::to_string(GM->m_secretNumber * -1));
	}
};
