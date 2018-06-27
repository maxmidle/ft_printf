#include <stdio.h>
#include "libft.h"

int main()
{
	char *av;
	char *ap;

	av = ft_strdup("avant");
	ap = ft_strdup("apres");
	ft_strbackconc(&ap, av);
	printf("%s", ap);
	free(av);
	free(ap);
getchar();
}
