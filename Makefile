TARGET = plugin.plg
SRC = source/main.cpp
CTRPF_PATH = CTRPluginFramework

all:
	$(CTRPF_PATH)/tools/ctrpf-plg/ctrpf-plg .

clean:
	rm -f plugin.plg
