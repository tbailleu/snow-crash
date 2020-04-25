#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_des(char *src)
{
  unsigned int	i;
  char			*res;
  int			offset;

  res = strdup(src);
  offset = '0';
  i = -1;
  while (++i < strlen(res))
  {
    res[i] = (((i & 1) == 0 ? -offset : offset) + res[i] + 63) % 95 + 32;
    if (++offset == '6')
      offset = '0';
  }
  return (res);
}

int		main(void)
{
	char	*token;

	token = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
	printf("your token is %s\n", token);
	free(token);
	return (0);
}
