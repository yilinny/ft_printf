#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
	int counted;
	int expected;

	//test no %
	printf("hello world!\n");
	counted = ft_printf("hello world!\n");
	printf("Digits printed: 13 (expected)  %d (actual)\n", counted);

	//test % % 
	printf("%%\n");
	counted = ft_printf("%%\n");
	printf("Digits printed: 2 (expected)	%d (actual)\n", counted);

	//test %c 
	printf("hi%c\n", 'a');
	counted = ft_printf("hi%c\n", 'a');
	printf("Digits printed: 4 (expected)  %d (actual)\n", counted);

	//test %c, %s 
	printf("hi%c%s\n", 'a', " world");
	counted = ft_printf("hi%c%s\n", 'a', " world");
	printf("Digits printed: 10 (expected)  %d (actual)\n", counted);

	//test  %s 
	char *null = NULL;
	expected = printf("%s\n",null);
	counted = ft_printf("%s\n", null);
	printf("Digits printed: %d (expected)  %d (actual)\n", expected, counted);
	//test %p
	expected = printf("%p\n", NULL);
	counted = ft_printf("%p\n", NULL); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %p
	expected = printf("%p\n", &expected);
	counted = ft_printf("%p\n", &counted); //format ?? check w testers
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %d
	expected = printf("%d\n", 12324);
	counted = ft_printf("%d\n", 12324); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);
	//test %i
	expected = printf("Testing INT MAX: %i\n", INT_MAX);
	counted = ft_printf("Testing INT MAX: %i\n", INT_MAX); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);
	//test %d
	expected = printf("%d\n", INT_MIN);
	counted = ft_printf("%d\n", INT_MIN); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %i
	expected = printf("Testing octal: %i\n", 0752);
	counted = ft_printf("Testing octal: %i\n", 0752); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %u
	expected = printf("Testing unsigned 0: %u\n", 0);
	counted = ft_printf("Testing unsigned 0: %u\n", 0); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %u
	expected = printf("Testing: %u\n",12345);
	counted = ft_printf("Testing: %u\n", 12345); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %u
	expected = printf("Testing INT MAX: %u\n",UINT_MAX);
	counted = ft_printf("Testing INT MAX: %u\n", UINT_MAX); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %X
	expected = printf("Testing: %x\n", 0x15A);
	counted = ft_printf("Testing: %x\n", 0x15A); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %x 
	expected = printf("Testing INT MAX in hex: %x\n",UINT_MAX);
	counted = ft_printf("Testing INT MAX in hex: %x\n",UINT_MAX); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %x 
	expected = printf("Testing INT MAX in heX: %X\n",UINT_MAX);
	counted = ft_printf("Testing INT MAX in heX: %X\n", UINT_MAX); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

	//test %X
	expected = printf("Testing hex 0: %x\n", 0);
	counted = ft_printf("Testing hex 0: %x\n", 0); 
	printf("Digits printed: %d (expected) \t %d (actual)\n", expected, counted);

}
