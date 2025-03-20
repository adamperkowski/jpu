# jpu
# Copyright 2025 Adam Perkowski.
# Use of this source code is governed by the BSD 3-Clause License.
# See the LICENSE file for details.

JULEC = julec

BINARY = jpu

JULECFLAGS = -o build/$(BINARY)

all: build

build:
	mkdir -p build
	$(JULEC) $(JULECFLAGS) src

run: build
	./build/$(BINARY)

test:
	$(JULEC) test src

format:
	julefmt -w src

clean:
	rm -rf build bin dist

.PHONY: all build run test format clean
