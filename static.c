int f()
{

static int a = 0;
int b = 0;
a++;
b++;

printf("a %d\n,b %d\n", a,b);
}


int main()
{
f();
f();
f();
//printf("a %d\n,b %d\n", a,b);
return 0;
}
