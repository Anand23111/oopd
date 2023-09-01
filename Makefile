all: debug optimize

debug: 111indiamain_debug 111spainmain_debug

main_debug: 111indiamain.cpp
	g++ -g -o main_debug 111indiamain.cpp
	./111indiamain_debug

spainmain_debug: 111spainmain.cpp
	g++ -g -o 111spainmain_debug 111spainmain.cpp
	./111spainmain_debug

optimize: 111indiamain_optimize 111spainmain_optimize				

main_optimize: 111indiamain.cpp
	g++ -O3 -o main_optimize 111indiamain.cpp
#	./111indiamain_optimize

spainmain_optimize: 111spainmain.cpp
	g++ -O3 -o 111spainmain_optimize 111spainmain.cpp
#	./111spainmain_optimize

clean:
	rm -f 111indiamain_debug 111indiamain_optimize 111spainmain_debug 111spainmain_optimize