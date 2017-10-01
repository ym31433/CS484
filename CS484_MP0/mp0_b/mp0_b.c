#include "timers.h"
#include "mp0_b.h"


int main(int argc, char **argv)
{
	
	//test1();
	
	//test2_version1();
	
	//test2_version2();

	//test3_version1();
	
	//test3_version2();

	//test4();  
	/*
	test5(15);
	test5(16);
	test5(17);

	test5(63);
	test5(64);
	test5(65);

	test5(255);
	test5(256);
	test5(257);

	test5(1023);
	test5(1024);
	test5(1025);

	test5(1031);
	test5(1032);
	test5(1033);
	*/

	for(int i = 16; i != 512; i*=2) {
		test5(1023+i);
		test5(1024+i);
		test5(1025+i);
	}

	//test5(1535);
	//test5(1536);
	//test5(1537);
	return 0;
}

