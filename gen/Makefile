

# musl-gcc for static linking
CC=musl-gcc
LDFLAGS=-static -lm -lrt

GITVER=$(shell sh -c 'git describe --abbrev=4 --dirty --always')
CCDATE=$(shell sh -c 'date +"%Y-%m-%d"')

CFLAGS=-std=c99 -pedantic -Wall -g -O0 \
  `pkg-config --cflags cairo-svg` \
  -D__GIT_VERSION=\"$(GITVER)\" \
  -D__YYYY_MM_DD__=\"$(CCDATE)\"

# CC=gcc
# LDFLAGS=-Wl,-map,logo.map

#LDLIBS=-static-libgcc -Wl,-Bstatic -lm `pkg-config --libs cairo-svg` -lc
#LDLIBS=-static-libgcc -Wl,-Bstatic -lm `pkg-config --libs cairo-svg` -lc

# CFLAGS=-std=c99 -pedantic -Wall -g -O0 `pkg-config --cflags cairo-svg`
# LDLIBS=-static -lm `pkg-config --static --libs cairo-svg`

all: clean logo

clean:
	@/bin/rm -f *~ logo
