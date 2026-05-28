subdirs = main foo
all: $(subdirs)
main: foo
.PHONY: all clean install $(subdirs)
.ONESHELL:
$(subdirs): ; @$(MAKE) -C $@

clean:
	@for dir in $(subdirs)
	do
		$(MAKE) -C $$dir $@
	done
