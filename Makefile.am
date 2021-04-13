GENRBOPT = -s ./res -d .
res/root.res: res/root.txt
	genrb -d res res/root.txt

res/hi.res: res/hi.txt
	genrb -d res res/hi.txt

res/es.res: res/es.txt
	genrb -d res res/es.txt

SUBDIRS = src
dist_doc_DATA = README

all: res/root.res res/hi.res res/es.res

