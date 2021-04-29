DOXY_FILE = SeatHeater
BUILD_FILE = html

ifdef OS
	FixPath = $(subst /,\,$1)
	RM = del /q
else
	ifeq ($(shell uname), Linux)
		RM = rm -rf
		FixPath = $1
	endif	
endif

doc:
	doxygen $(call FixPath,./$(DOXY_FILE))

clean:
	$(RM) $(call FixPath,$(BUILD_FILE))