PACKAGE_NAME = uresb
TARGETS = root.res hi.res es.res

GENRBOPT = -s ./res -d .

all: $(TARGETS)
    @echo All Targets are up to date

clean:
    -erase $(TARGETS)

root.res    : root.txt
                $(GENRB) $(GENRBOPT) root.txt

hi.res      : hi.txt
                $(GENRB) $(GENRBOPT) hi.txt

es.res      : es.txt
                $(GENRB) $(GENRBOPT) es.txt
                