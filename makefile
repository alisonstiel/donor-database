#
# Specifiy the target
all:	CA1

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
CA1:	CA1.o Donor.o DonorDatabase.o
	g++  CA1.o Donor.o DonorDatabase.o  -o Donate.exe

# Specify how the object files should be created from source files
CA1.o:	CA1.cpp
	g++ -c CA1.cpp

Donor.o:   Donor.cpp
	g++ -c Donor.cpp

DonorDatabase.o:   DonorDatabase.cpp
	g++ -c DonorDatabase.cpp	
	
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Donate.exe
