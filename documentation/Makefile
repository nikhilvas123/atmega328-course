DOXY_FILE = SeatHeater
BUILD_FILE = html

ifdef OS
	FixPath = $(subst /,\,$1)
	RM = rm -rf
	EX = doxygen.exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -rf
		FixPath = $1
		EX = doxygen
	endif	
endif

doc:
	$(EX) $(call FixPath,./$(DOXY_FILE))

clean:
	$(RM) $(call FixPath,$(BUILD_FILE))