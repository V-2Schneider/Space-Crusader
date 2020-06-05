# Space-Crusader

## Hello!
This is a school project and the first game I've written, using allegro library.
Because of the project requirements I had to restrain myself from using many of C++ functions, but I still managed to make a game.
It's a very basic top-view shooter- the levels are short, there's 3 of them, the save function is a joke etc.
About the code- it's not good too, but like I said before- everyone started somewhere.

## 2019 Update!
I've cleaned up this repo a bit, removed the library and many other unnecessary files!

Graphics are removed now too, but I'll probably bring them back someday, after other cleanup

### Some Problems with the repo
Right now there are some files missing, not to mention that there were still a lot of files that shouldn't even be here! How absurd!

### How to compile it?
uuhh, wait for it, right now I'm using this command:
g++ .\modules\al_init_all.cpp .\modules\draw.cpp .\modules\enemy.cpp .\modules\engine.cpp .\modules\file.cpp .\modules\levels.cpp .\modules\musique.cpp .\modules\main.cpp -o main.exe -Ic:\api\include\allegro5 -Lc:\api\lib -lallegro -lallegro_font -lallegro_audio -lallegro_image -lallegro_acodec
You can see in here where I keep allegro5 header files and libraries but I don't mind- and as you can clearly see, you need to get yourself a copy of allegro5 (easy, it's free)

