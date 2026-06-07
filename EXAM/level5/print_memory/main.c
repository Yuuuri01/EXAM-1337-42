// # include <unistd.h>

// void	print_memory(const void *addr, size_t size);

// int	main(void)
// {
// 	int	tab[10] = {0, 23, 150, 255,
// 	              12, 16,  21, 42};

// 	print_memory(tab, sizeof(tab));
// 	return (0);
// }

#include <unistd.h>

void	print_memory(const void *addr, size_t size);

int		main(void)
{
    // int tab[1] = {3772900067};
	int		tab[15] = {3772900067, 58597, 59111,
		59625, 60139, 60653, 61167, 61681, 62195, 62709, 63223, 63737, 64251,
	64765, 65279};

	print_memory(tab, sizeof(tab));
	return (0);
}

// e3e2 e1e0 e5e4 0000 e7e6 0000 e9e8 0000 ................
// ebea 0000 edec 0000 efee 0000 f1f0 0000 ................
// f3f2 0000 f5f4 0000 f7f6 0000 f9f8 0000 ................
// fbfa 0000 fdfc 0000 fffe 0000           ............
