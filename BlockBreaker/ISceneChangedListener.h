#pragma once

namespace nScene{
	enum eScenKind {
		None,
		Game,
		Title,
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

//�V�[���`�F���W�p���X�i�[
class ISceneChangedListener {
protected:
public:
	virtual ~ISceneChangedListener() = default;
	virtual void changeScene(const nScene::eScenKind&, const nScene::Message&) = 0;
};