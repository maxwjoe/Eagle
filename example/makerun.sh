cd ..
make >/dev/null
cp lib/libEagle.a example
cd example
gcc  -I../include -o obj/example.o testBed.c calc.c -L. -leagle
./obj/example.o