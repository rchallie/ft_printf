
#include <stdio.h>
#include <stdlib.h>
#include "main_printf.h"

int main()
{
	system("echo \"\x1b[33m\"");

	printf("---------------------------------- SIMPLE --------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire une phrase symple !\n");
	ft_printf("> ft_printf : Ecrire une phrase symple !\n");

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n----------------------------------- CHAR ---------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire un char : [%c]\n", 'a');
	ft_printf("> ft_printf : Ecrire un char : [%c] \n", 'a');
	printf(">    printf : Ecrire un char : [%20c]\n", 'b');
	ft_printf("> ft_printf : Ecrire un char : [%20c]\n", 'b');
	printf(">    printf : Ecrire un char : [%c20]\n", 'd');
	ft_printf("> ft_printf : Ecrire un char : [%c20]\n", 'd');
	printf(">    printf : Ecrire un char : [%-20c]\n", 'c');
	ft_printf("> ft_printf : Ecrire un char : [%-20c]\n", 'c');

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n----------------------------------- STRING ---------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire une string : [%s] && Second test : [%s]\n", "test1", "test2");
	ft_printf("> ft_printf : Ecrire une string : [%s] && Second test : [%s]\n", "test1", "test2");
	printf(">    printf : Ecrire une string : [%10s] && Second test : [%5s]\n", "test1", "test2");
	ft_printf("> ft_printf : Ecrire une string : [%10s] && Second test : [%5s]\n", "test1", "test2");
	printf(">    printf : Ecrire une string : [%2s] && Second test : [%6s]\n", "test1", "test2");
	ft_printf("> ft_printf : Ecrire une string : [%2s] && Second test : [%6s]\n", "test1", "test2");
	printf(">    printf : Ecrire une string : [%-5s] && Second test : [%-12s]\n", "test1", "test2");
	ft_printf("> ft_printf : Ecrire une string : [%-5s] && Second test : [%-12s]\n", "test1", "test2");

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n----------------------------------- INT ----------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire un int : [%d]\n", 0);
	ft_printf("> ft_printf : Ecrire un int : [%d]\n", 0);
	printf(">    printf : Ecrire un int : [%d]\n", 120);
	ft_printf("> ft_printf : Ecrire un int : [%d]\n", 120);
	printf(">    printf : Ecrire un int : [%d]\n", -120);
	ft_printf("> ft_printf : Ecrire un int : [%d]\n", -120);
	printf(">    printf : Ecrire un int : [%d]\n", 2147483647);
	ft_printf("> ft_printf : Ecrire un int : [%d]\n", 2147483647);
	printf(">    printf : Ecrire un int : [%20d]\n", 2147483647);
	ft_printf("> ft_printf : Ecrire un int : [%20d]\n", 2147483647);
	printf(">    printf : Ecrire un int : [%012d]\n", 3658);
	ft_printf("> ft_printf : Ecrire un int : [%012d]\n", 3658);
	printf(">    printf : Ecrire un int : [%-20d]\n", 2147483647);
	ft_printf("> ft_printf : Ecrire un int : [%-20d]\n", 2147483647);

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n----------------------------------- U INT ----------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire un unsigned int : [%u]\n", 0);
	ft_printf("> ft_printf : Ecrire un unsigned int : [%u]\n", 0);
	printf(">    printf : Ecrire un unsigned int : [%u]\n", 120);
	ft_printf("> ft_printf : Ecrire un unsigned int : [%u]\n", 120);
	printf(">    printf : Ecrire un unsigned int : [%u]\n", -120);
	ft_printf("> ft_printf : Ecrire un unsigned int : [%u]\n", -120);
	printf(">    printf : Ecrire un unsigned int : [%20u]\n", 120);
	ft_printf("> ft_printf : Ecrire un unsigned int : [%20u]\n", 120);
	printf(">    printf : Ecrire un unsigned int : [%012u]\n", 89635);
	ft_printf("> ft_printf : Ecrire un unsigned int : [%012u]\n", 89635);
	printf(">    printf : Ecrire un unsigned int : [%-8u]\n", 14579);
	ft_printf("> ft_printf : Ecrire un unsigned int : [%-8u]\n", 14579);

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n----------------------------------- POINTER ----------------------------------------\n");

	system("echo \"\x1b[36m\"");

	char *test = "PLOP";
	
	printf(">    printf : Ecrire un pointer : [%p]\n", &test);
	ft_printf("> ft_printf : Ecrire un pointer : [%p]\n", &test);
	printf(">    printf : Ecrire un pointer : [%15p]\n", &test);
	ft_printf("> ft_printf : Ecrire un pointer : [%15p]\n", &test);
	printf(">    printf : Ecrire un pointer : [%-18p]\n", &test);
	ft_printf("> ft_printf : Ecrire un pointer : [%-18p]\n", &test);

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n----------------------------------- %% ----------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire un pourcent : [%%]\n");
	ft_printf("> ft_printf : Ecrire un pourcent : [%%]\n");
	printf(">    printf : Ecrire un pourcent : [%20%]\n");
	ft_printf("> ft_printf : Ecrire un pourcent : [%20%]\n");
	printf(">    printf : Ecrire un pourcent : [%012%]\n");
	ft_printf("> ft_printf : Ecrire un pourcent : [%012%]\n");
	printf(">    printf : Ecrire un pourcent : [%-12%]\n");
	ft_printf("> ft_printf : Ecrire un pourcent : [%-12%]\n");

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n--------------------------------- Hexa (min) --------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire un hexa : [%x]\n", 15045161);
	ft_printf("> ft_printf : Ecrire un hexa : [%x]\n", 15045161);
	printf(">    printf : Ecrire un hexa : [%x]\n", 0xfa58b);
	ft_printf("> ft_printf : Ecrire un hexa : [%x]\n", 0xfa58b);
	printf(">    printf : Ecrire un hexa : [%13x]\n", 5843);
	ft_printf("> ft_printf : Ecrire un hexa : [%13x]\n", 5843);
	printf(">    printf : Ecrire un hexa : [%018x]\n", 987);
	ft_printf("> ft_printf : Ecrire un hexa : [%018x]\n", 987);
	printf(">    printf : Ecrire un hexa : [%-12x]\n", 0xa4e8);
	ft_printf("> ft_printf : Ecrire un hexa : [%-12x]\n", 0xa4e8);

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	ft_printf("\n--------------------------------- Hexa (maj) --------------------------------------\n");

	system("echo \"\x1b[36m\"");
	
	printf(">    printf : Ecrire un hexa : [%X]\n", 15045161);
	ft_printf("> ft_printf : Ecrire un hexa : [%X]\n", 15045161);
	printf(">    printf : Ecrire un hexa : [%X]\n", 0xfa58b);
	ft_printf("> ft_printf : Ecrire un hexa : [%X]\n", 0xfa58b);
	printf(">    printf : Ecrire un hexa : [%13X]\n", 58438);
	ft_printf("> ft_printf : Ecrire un hexa : [%13X]\n", 58438);
	printf(">    printf : Ecrire un hexa : [%018X]\n", 987);
	ft_printf("> ft_printf : Ecrire un hexa : [%018X]\n", 987);
	printf(">    printf : Ecrire un hexa : [%-6X]\n", 987);
	ft_printf("> ft_printf : Ecrire un hexa : [%-6X]\n", 987);

	system("echo \"\x1b[33m\"");

	ft_printf("--------------------------------------------------------------------------------\n");
	
	// Tester combi - et 0 : 
	return (0);
}