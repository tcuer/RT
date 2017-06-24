/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:28:13 by cluciani          #+#    #+#             */
/*   Updated: 2017/04/25 17:24:55 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "parse.h"
# include "get_next_line.h"
# define WIDTH 1024
# define HEIGHT 768

# define O_EYE 0
# define O_SPHERE 1
# define O_CONE 2
# define O_CYLINDER 3
# define O_PLAN 4
# define O_LIGHT 5
# define O_CUBE 6
# define O_HOUR 7
# define O_GLASS 8
# define O_HYPER 9
# define O_CYLINDER2 10
# define O_SPHERE2 11
# define O_HYPER2 12
# define O_CONE2 13

# define MIN(x, y) ((x)<(y) ? (x) :(y))
# define DBL_MAX 1.7976931348623158e+308

typedef	struct		s_perlin
{
	int				i;
	int				j;
	int				k;
	double			x;
	double			y;
	double			z;
	double			g000;
	double			g001;
	double			g010;
	double			g100;
	double			g101;
	double			g011;
	double			g110;
	double			g111;
	double			u;
	double			v;
	double			w;
	double			x00;
	double			x01;
	double			x10;
	double			x11;
	double			xy0;
	double			xy1;
	double			xyz;
}					t_perlin;
typedef	struct		s_img
{

	int				bits;
	int				size;
	int				endian;
	char			*info;
}					t_img;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*ptri;
	int				bpp;
	int				size;
	int				endian;
	char			*im;
}					t_mlx;

typedef	struct		s_delta
{
	double			a;
	double			b;
	double			c;
	double			delta;
	double			t;
	double			t1;
	double			t2;
}					t_delta;

typedef	struct		s_scene
{
	t_list			*obj;
	t_list			*light;
	t_eye			eye;
	double			ambient;

}					t_scene;

typedef	struct		s_inter
{
	void			*object;
	t_vec			pos;
	t_vec			normal;
	double			reflection;
	double			refraction;
	double			distance;
}					t_inter;

typedef	struct		s_ray
{
	t_inter			inter;
	t_vec			dir;
	t_vec			pos;
}					t_ray;

typedef	struct		s_env
{
	t_mlx			mlx;
	t_scene			scene;
	t_ray			ray;
	int				error;
	double			shadow;
	int				count;
	double			countl;
	int				reflection;
	int				refraction;
	int				hit;
	int				sepia;
	int				perc;
	int				nb_lights;
	double			dist;
	int				ole;
}					t_env;

t_vec				where_pos_c(t_cylinder c);
t_vec				where_pos_s(t_cylinder c);
t_object			*check_cone3(t_cylinder cylinder,
	t_object *object, t_env *e);
t_object			*check_sphere3(t_cylinder cylinder,
	t_object *object, t_env *e);
t_object			*check_cylinder3(t_cylinder cylinder,
	t_object *object, t_env *e);
t_object			*ft_check_cylinder2(t_env *e, t_var *v, int i);
t_object			*ft_check_cone2(t_env *e, t_var *v, int i);
t_object			*ft_check_sphere2(t_env *e, t_var *v, int i);
t_object			*ft_check_hyper2(t_env *e, t_var *v, int i);
double				hyper_limit3(t_hyper *hyper, t_delta delta);
t_hyper				*hyper_limit2(t_hyper *hyper);
t_hyper				*hyper_limit(t_vec ray, t_vec origin, t_hyper *hyper,
	double delta);
int					hyper_limit4(t_hyper *hyper);
t_inter				hyper_inter_ret(t_object *object, t_hyper *hyper, t_ray ray,
	double delta);
t_vec				get_hyper_normal(t_hyper *hyper, t_inter inter);
t_delta				get_hyper_delta2(t_delta delta, t_object *obj);
t_delta				get_hyper_delta(t_hyper *hyper, t_vec ray, t_vec origin);
t_inter				hyper_inter(t_object *object, t_ray ray);
t_cylinder			cylinder_pos2(t_cylinder c);
t_cylinder			*cylinder_pos(t_cylinder *c);
t_object			*ft_check_sphere(t_env *e, t_var *v, int i);
t_object			*ft_check_cone(t_env *e, t_var *v, int i);
t_object			*ft_check_cylinder(t_env *e, t_var *v, int i);
t_object			*ft_check_plan(t_env *e, t_var *v, int i);
t_object			*ft_check_light(t_env *e, t_var *v, int i);
t_object			*ft_check_cube(t_env *e, t_var *v, int i);
t_object			*ft_check_hour(t_env *e, t_var *v, int i);
t_object			*ft_check_glass(t_env *e, t_var *v, int i);
t_object			*ft_check_hyper(t_env *e, t_var *v, int i);
t_inter				sphere_inter(t_object *obj, t_ray ray);
t_inter				plan_inter(t_object *obj, t_ray ray);
t_inter				new_inter(void);
t_inter				get_inter(t_object *obj, t_ray ray);
t_inter				cylinder_inter(t_object *object, t_ray ray);
t_inter				cone_inter(t_object *object, t_ray ray);
t_inter				hole_inter(t_object *obj, t_vec ray, t_vec origin);
t_inter				spot2_inter(t_object *obj, t_vec ray, t_vec origin);
t_color				get_obj_color(char *buffer, t_env *e);
t_color				get_color(t_env *e, t_ray ray, t_object object);
t_color				throwing_ray(t_env *e, t_ray ray, void *data);
t_color				new_t_color(int r, int g, int b);
t_color				get_norm(t_object *object, t_vec inter_pos, t_env *e);
t_color				get_textu(t_object *object, t_vec inter_pos, t_env *e);
t_color				no_light(t_env *e, t_object object);
t_color				add_color(t_color color1, t_color color2);
t_color				add_light_color(t_color color, t_color light, int i);
t_color				ft_shadow(double i, t_color color, t_env *e, t_inter inter);
t_color				sepia_filter(t_color color);
t_color				set_env_light1(t_env *e);
t_color				dont_overflow(t_color color);
t_color				t_ray2(t_env *e, t_ray ray, void *data, t_object *obj);
t_cone				*cone_limit2(t_cone *cone);
t_cone				*cone_limit3(t_cone *cone);
t_text				parse_textu(t_env *e, t_object *obj);
t_text				parse_normal(t_env *e, t_object *obj);
t_vec				vec_rev_sign(t_vec vec);
t_vec				vec_cross_product(t_vec a, t_vec b);
t_vec				vec_add(t_vec a, t_vec b);
t_vec				vec_multiply(t_vec a, double r);
t_vec				new_vec(double x, double y, double z);
t_vec				get_vec_from_t(t_vec pos, t_vec raydir, double t);
t_vec				vec_minus(t_vec a, t_vec b);
t_vec				vec_normalize(t_vec vec);
t_vec				vec_plus(t_vec a, double b, t_vec dir);
t_vec				ft_check_pos(char *buffer, t_env *e);
t_vec				check_posof(t_cone cone, t_cylinder *cylinder);
t_vec				vec_change(t_vec a, t_vec b);
t_vec				get_cone_normal(t_cone *cone, t_inter inter);
t_vec				ft_rotate_x(t_vec vec, double i);
t_vec				ft_rotate_y(t_vec vec, double i);
t_vec				ft_rotate_z(t_vec vec, double i);
t_eye				ft_check_eye(t_var *v);
t_env				*ft_put_to_image(t_env *e, int x, int y, t_color color);
double				vec_square_norm(t_vec vec);
double				vec_dot_product(t_vec a, t_vec b);
double				dist3d(t_vec a, t_vec b);
double				vec_norm(t_vec vec);
double				double_mult(double a, double b);
double				ft_check_rayon(char *buffer, t_env *e);
double				ft_check_intensity(char *buffer, t_env *e);
double				ft_set_shadow(double i, t_env *e);
double				pow2(double a);
double				quintic_poly(const double t);
double				linear_interpolate(double a, double b, double t);
void				ft_init_mlx(t_env *e);
void				ft_init_render(t_env *e);
void				ft_parse(t_env *e, t_var *v);
void				raytracing(t_env *e);
void				loading_bar(t_env *e);
void				loading(int x, int y, t_env *e);
void				mlx_pixel_img(void *img, int x, int y, t_color tcolor);
void				set_env_light2(t_env *e);
void				ft_check_numbers(char *str, t_env *e);
void				put_obj(t_object *obj, t_env *e);
int					ft_object_id(t_env *e, t_var *v);
int					uptade(t_env *e);
int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);
int					ft_list_object(t_env *e, t_object *obj);
int					ft_list_lights(t_env *e, t_object *obj);
int					get_pixel(int x, int y, char *img, int dim_x);
int					cone_limit4(t_cone *cone);
t_color				ft_convert(int color);
int					get_pixel(int x, int y, char *img, int dim_x);
int					cylinder_limit2(t_cylinder *c);
int					*get_grad(int x, int y, int z);
t_cylinder			*cylinder_limit(t_vec ray, t_vec o, t_cylinder *c,
	double d);
t_color				compute_light(t_inter inter, t_light light,
	t_color color, t_env *e);
t_color				reflect_color(t_color ret, t_color mirror_object_color,
	double reflection);
t_color				refraction3(t_color ret, t_color transparent_color,
	double refraction);
t_color				check_reflection(t_ray ray, t_env *e, t_object object,
	t_color mirror_object_color);
t_color				check_refraction(t_ray ray, t_env *e, t_object object,
	t_color transparent_color);
t_color				apply_color_lighting(t_env *e, t_object object,
	t_light light, t_ray ray);
t_color				throwing_light_ray(t_env *e, t_ray ray, t_object object,
	t_vec light_pos);
t_color				init_lights(t_ray *ray, t_light light, t_env *e,
	t_object object);
t_delta				get_cone_delta(t_cone *cone, t_vec ray, t_vec origin);
t_cone				*cone_limit(t_vec ray, t_vec origin, t_cone *cone,
	double delta);
double				fast_dot(const int *v, const double x,
	const double y, const double z);
int					int_and_frac(double value, int integer_part,
	double *fractional_part);
t_object			*check_sphere2(t_cylinder cylinder,
	t_object *object, t_env *e);
t_color				specular_light(t_inter in, t_light li,
	t_color col, t_object obj);
t_vec				bump_aply(t_vec reflect_ray, t_object *object,
	t_vec inter_pos, t_env *e);
int					ft_plan_fuck(t_vec dir);
#endif
