SUBDIRS = hello2 hello3 hello4 \
	scull scull2 scull3

all : subdirs

subdirs :
	for n in $(SUBDIRS); \
		do $(MAKE) -C $$n || exit 1; \
	done

clean :
	for n in $(SUBDIRS); \
		do $(MAKE) -C $$n clean; \
	done
