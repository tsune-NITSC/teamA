# include <Siv3D.hpp> // OpenSiv3D v0.6.4

//ランダムな座標を出力
Vec2 randomPos(){
	return RandomVec2({ 100,700 },200);
	}


void Main() {

	Window::SetStyle(WindowStyle::Sizable);
	Window::Maximize();

	//敵の画像を読み込む
	const Texture enemystyle{ U"C:/Users/tsune/OneDrive/デスクトップ/シューティングゲーム/enemy.jpg" };

	double enemytime = 0.0;

	Array<Vec2> enemies = { randomPos() };


	while (System::Update())
	{
		//ゲームの経過時間（３秒たったら０になる）
		enemytime += Scene::DeltaTime();

		//三秒ごとに敵を出現させる
		while (enemytime>=3.0)
		{

			enemies << randomPos();

			enemytime = 0.0;

		}

		//敵を下に移動
		for (auto & enemy:enemies)
		{
			enemy.y += 1;
			
		}

		//敵が画面外に出たら削除する
		enemies.remove_if([](const Vec2& v) {return(1000/*←この値が画面の縦pxより大きくなるようにする*/ < v.y); });

		//敵を描画
		for (const auto& enemy :enemies)
		{
			enemystyle.scaled(0.5).drawAt(enemy);
		}

	}

}
