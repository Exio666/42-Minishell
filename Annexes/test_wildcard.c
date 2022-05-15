
/*
int main()
{
    test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	
	test7();
	test8();
	
	test9();
	test10();
	test11();
	
	test12();
    return 0;
}

void test0(void)
{
 	char pattern[] = "a";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test1(void)
{
 	char pattern[] = "a*";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test2(void)
{
 	char pattern[] = "*a";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test3(void)
{
 	char pattern[] = "*a*";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test4(void)
{
 	char pattern[] = "a*b";
    char str[] = "acb";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test5(void)
{
 	char pattern[] = "a*b*c";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test6(void)
{
 	char pattern[] = "a*bc";
    char str[] = "ajbjc";
	printf("EXPECT NO MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test7(void)
{
 	char pattern[] = "a*b*";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test8(void)
{
 	char pattern[] = "a*b";
    char str[] = "ajbjc";

	printf("EXPECT NO MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test9(void)
{
 	char pattern[] = "**c";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test10(void)
{
 	char pattern[] = "*";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test11(void)
{
 	char pattern[] = "a*c";
    char str[] = "ajbvrgregerhrehhrjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test12(void)
{
 	char pattern[] = "a*b*cefewfew";
    char str[] = "ajbjc";
	printf("EXPECT NO MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
*/
