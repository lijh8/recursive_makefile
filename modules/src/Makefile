subdirs = main foo
all: $(subdirs)
main: foo
$(subdirs): ; @$(MAKE) -C $@

clean:
	@for dir in $(subdirs); do \
		$(MAKE) -C $$dir $@; \
	done
.PHONY: all clean $(subdirs)
