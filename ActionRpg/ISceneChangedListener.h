#pragma once

namespace nScene {
	enum eSceneKind {
		None,
		Title,
		Game,
		Config,
		Howto,
		GameClear,
		GameOver
	};
	class Message {
	public:
		Message() {
			_stageNum = 1;
		}
		int _stageNum;
	};
}

//シーンチェンジ用リスナー
class ISceneChangedListener {
public:
	virtual ~ISceneChangedListener() = default;
	virtual void changeScene(const nScene::eSceneKind&, const nScene::Message&) = 0;
};