ELECTRON_VERSION = $(shell node ../../../scripts/negatron-version-string.js)

ifeq ($(OS),Windows_NT)
GYP=..\..\..\node_modules\.bin\node-gyp
CONFIG = build/binding.sln
else
GYP=../../../node_modules/.bin/node-gyp
CONFIG = build/Makefile
ENV = JOBS=4 HOME=~/.electron-gyp
endif

ifeq ($(NODE_ENV),development)
GYP += --debug
endif

all: $(CONFIG)
	$(ENV) $(GYP) build --target=$(ELECTRON_VERSION) \
		--arch=x64 --dist-url=https://atom.io/download/electron

$(CONFIG):
	$(ENV) $(GYP) configure --target=$(ELECTRON_VERSION) \
		--arch=x64 --dist-url=https://atom.io/download/electron

clean:
	@$(GYP) clean

fmt:
	@clang-format -i *.cpp

.PHONY: all clean fmt
