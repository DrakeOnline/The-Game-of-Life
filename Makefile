all:
	g++ -std=c++17 main.cpp source/AssetManager.cpp source/Game.cpp source/InputManager.cpp source/SplashState.cpp source/StateMachine.cpp source/GameState.cpp source/Grid.cpp source/Cell.cpp -o main.exe -static-libgcc -static-libstdc++ -DSFML_STATIC -I C:\SFML\include -L C:\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
	main
