#################################
# HAM Makefile
#################################

include $(HAMDIR)/system/master.ma

#
# Set the name of your desired GBA image name here
#
PROGNAME = airtaxi

#
# Set a list of files you want to compile 
# 
OFILES += main.o Jsprite.o JsuperCub.o Jworld.o Jmap.o Jmenu.o Jmission.o

######################################
# Standard Makefile targets start here
######################################

all : $(PROGNAME).$(EXT) 
#clean - this was on the end of the above

#
# Most Makefile targets are predefined for you, suchas
# vba, clean ... in the following file
#
include $(HAMDIR)/system/standard-targets.ma

######################################
# custom  Makefile targets start here
######################################
	



