# top-level makefile in recursive use
subdirs = main foo
all: $(subdirs)
main: foo
$(subdirs): ; @$(MAKE) -C $@

clean:
	@for dir in $(subdirs); do \
		$(MAKE) -C $$dir $@; \
	done

prefix ?= /usr/local
bindir = $(DESTDIR)$(prefix)/bin
libdir = $(DESTDIR)$(prefix)/lib
includedir = $(DESTDIR)$(prefix)/include
installdirs = $(bindir) $(libdir) $(includedir)
$(installdirs): ; mkdir -p $@

# make DESTDIR=~/myapp prefix=/usr/local install
install: all | $(installdirs)
	cp main/main $(bindir)
	cp -P foo/lib*.so* $(libdir)
	cp foo/lib*.a $(libdir)
	cp foo/foo.h $(includedir)

.PHONY: all clean install $(subdirs)
MAKEFLAGS += --no-print-directory
