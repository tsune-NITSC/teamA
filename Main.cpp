# include <Siv3D.hpp> // OpenSiv3D v0.6.4

//ランダムな座標を出力
Vec2 randomPos(){
	return RandomVec2({ 100,1000 },-10);
	}


void Main() {

	Window::SetStyle(WindowStyle::Sizable);
	Window::Maximize();

	//敵の画像を読み込む
	const Texture enemystyle{ U"C:/Users/tsune/OneDrive/デスクトップ/シューティングゲーム/enemy.png" };
	//自機の画像を読み込む
	const Texture playerstyle{ U"C:/Users/tsune/OneDrive/デスクトップ/シューティングゲーム/player.png" };

	double enemytime = 0.0;

	Array<Vec2> enemies = { randomPos() };

	//自機の初期ポジ
	Vec2 playerPos = { 640,600 };


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
			enemy.y += 3;//敵の速度
			
		}

		//自機の移動
		if (KeyRight.pressed())
		{
			playerPos.x += 6;
		}
		else
		if (KeyD.pressed())
		{
			playerPos.x += 6;
		}

		if (KeyLeft.pressed())
		{
			playerPos.x -= 6;
		}else
		if (KeyA.pressed())
		{
			playerPos.x -= 6;
		}

		if (KeyUp.pressed())
		{
			playerPos.y -= 6;
		}else
		if (KeyW.pressed())
		{
			playerPos.y -= 6;
		}

		if (KeyDown.pressed())
		{
			playerPos.y += 6;
		}else
		if (KeyS.pressed())
		{
			playerPos.y += 6;
		}

		//自機が画面外に出ないようにする
		if (playerPos.x > 1280)
		{
			playerPos.x = 1280;
		}
		if (playerPos.y>729)
		{
			playerPos.y = 729;
		}
		if (playerPos.x <0)
		{
			playerPos.x = 0;
		}
		if (playerPos.y <0)
		{
			playerPos.y =0;
		}



		//敵が画面外に出たら削除する
		enemies.remove_if([](const Vec2& v) {return(1000/*←この値が画面の縦pxより大きくなるようにする*/ < v.y); });

		//敵を描画
		for (const auto& enemy :enemies)
		{
			enemystyle.scaled(0.5).drawAt(enemy);
		}

		//自機を描画

		playerstyle.scaled(0.5).drawAt(playerPos);

	}

}
