all: ./modules/al_init_all.cpp ./modules/window_manager.cpp ./modules/draw.cpp ./modules/enemy.cpp ./modules/engine.cpp ./modules/file.cpp ./modules/levels.cpp ./modules/musique.cpp ./modules/main.cpp
	g++ ./modules/al_init_all.cpp ./modules/window_manager.cpp ./modules/draw.cpp ./modules/enemy.cpp ./modules/engine.cpp ./modules/file.cpp ./modules/levels.cpp ./modules/musique.cpp ./modules/main.cpp -o main.exe -I./allegro/include/allegro5 -L./allegro/lib -lallegro -lallegro_font -lallegro_audio -lallegro_image -lallegro_acodec