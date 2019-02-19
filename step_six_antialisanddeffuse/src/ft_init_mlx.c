#include "../include/rtv.h"

int			ft_init_mlx(t_win *wind)
{
	wind->mlx = mlx_init();
	wind->win = mlx_new_window(wind->mlx, SCREEN_W, SCREEN_H, "RTv1");
	wind->img = mlx_new_image(wind->mlx, SCREEN_W, SCREEN_H);
	wind->img2 = mlx_get_data_addr(wind->img, &(wind->bps), \
	&(wind->size), &(wind->endian));
	printf("WINDSIZE: %d\n", wind->size);
	printf("WINDENDIAN:%d\n", wind->endian);
	printf("WINDBPS:%d\n", wind->bps);
	return (1);
}
