Documentation for what to alter for the CMakeLists.txt has been added.


To compile the code, open the folder containing CMakeLists.txt in a console
	capable of running Make, CMake, and gcov.

	!!! I HAVE NO IDEA WHY BUT IT ONLY WORKS ON MY WSL INSTALL !!!
	
	Have yet to genuinely TRY making it work on windows


Then run the following commands in this order:

1)
	cmake -S . -B build

2)
	cmake --build build

3)
	cd build && make gcov



Due to the functionality of gcov, adding a new test will not immediately be added to
	the gcov record files upon compilation.
	
Instead, there is a command that has been added to the CMakeLists.txt file. Upon
	adding the new tests to the cpp file, we must run this command:

	make scrub

This will reconstruct the gcov files so that they're fresh and accurate regarding
	the project. After running make scrub, we are able to recompile properly:

	make gcov