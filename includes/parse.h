/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:46:29 by tcuer             #+#    #+#             */
/*   Updated: 2017/03/02 15:22:57 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_text
{
	char			*im;
	int				size;
	int				bpp;
	int				endian;
	int				height;
	int				width;
	double			x;
	double			y;
}					t_text;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_nb_type
{
	int				type;
	int				pos;
	int				dir;
	int				radius;
	int				color;
	int				reflexion;
	int				refraction;
	int				ambient;
	int				intensity;
	int				length;
	int				path;
	int				path2;
	int				freq;
	int				simple;
	int				hole;
}					t_nb_type;

typedef struct		s_limit
{
	t_vec			f1;
	t_vec			f2;
	t_vec			f3;
	t_vec			f4;
	t_vec			f5;
	t_vec			f6;
	double			t1;
	double			t2;
	double			t3;
	double			t4;
	double			t5;
	double			t6;
}					t_limit;

typedef struct		s_sphere
{
	char			*name;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	t_nb_type		nb;
	t_limit			limit;
	double			rayon;
	double			refraction;
	double			reflexion;
	char			*path;
	char			*path2;
	double			freq;
}					t_sphere;

typedef struct		s_cylinder
{
	char			*name;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	t_nb_type		nb;
	t_limit			limit;
	double			rayon;
	double			refraction;
	double			reflexion;
	double			length;
	char			*path;
	char			*path2;
	double			freq;
}					t_cylinder;

typedef struct		s_cone
{
	char			*name;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	t_nb_type		nb;
	t_limit			limit;
	double			alpha;
	double			refraction;
	double			reflexion;
	double			length;
	char			*path;
	char			*path2;
	double			freq;
	int				simple;
}					t_cone;

typedef struct		s_hyper
{
	char			*name;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	t_nb_type		nb;
	t_limit			limit;
	double			alpha;
	double			refraction;
	double			reflexion;
	double			length;
	char			*path;
	char			*path2;
	double			freq;
	int				simple;
}					t_hyper;

typedef struct		s_plan
{
	char			*name;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	t_nb_type		nb;
	double			refraction;
	double			reflexion;
	char			*path;
	char			*path2;
	double			freq;
	int				hole;
}					t_plan;

typedef struct		s_glass
{
	char			*name;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	t_nb_type		nb;
	t_limit			limit;
	double			radius;
	double			refraction;
	double			reflexion;
	double			length;
	char			*path;
	char			*path2;
	double			freq;
	int				simple;
}					t_glass;

typedef struct		s_object
{
	void			*data;
	int				id;
	int				tt;
	int				nn;
	double			freq;
	t_color			color;
	t_text			text;
	t_text			norm;
	char			*path;
	char			*path2;
}					t_object;

typedef struct		s_eye
{
	t_vec			pos;
	t_vec			dir;
	t_nb_type		nb;
	int				plane_dist;
}					t_eye;

typedef struct		s_light
{
	char			*name;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	t_nb_type		nb;
	double			intensity;
}					t_light;

typedef	struct		s_count
{
	int				sp;
	int				pl;
	int				co;
	int				cy;
	int				li;
	int				gl;
	int				hy;
}					t_count;

typedef	struct		s_number
{
	int				sphere;
	int				plan;
	int				cone;
	int				cylinder;
	int				light;
	int				glass;
	int				hyper;
}					t_number;

typedef	struct		s_var
{
	t_eye			eye;
	t_sphere		*sphere;
	t_plan			*plan;
	t_cylinder		*cylinder;
	t_cone			*cone;
	t_glass			*glass;
	t_hyper			*hyper;
	t_light			*light;
	t_number		number;
	double			ambient;
}					t_var;

typedef struct		s_parse
{
	int				i;
	int				j;
	int				l;
	int				k;
	t_count			c;
	double			*nb;
	char			*var;
	char			*name;
	char			*obj;
	char			*type;
	char			*class;
	char			*class2;
	char			*path;
	char			*type_list[15];
	char			*name_list[7];
	char			*class_list[4];
	int				nb_class[3];
	char			*tab[2];
	t_nb_type		n;
}					t_parse;

int					get_next_line(int const fd, char **line);
void				get_name(char *parse, t_parse *p);
void				get_var(char *parse, t_parse *p);
void				get_type(char *parse, t_parse *p);
void				get_class(char *parse, t_parse *p);
void				var_init(t_var *v, t_parse *p, char **parse, int i);
int					nbr_obj(char **parse, char *name, int i);
void				fill_var(t_parse *p, t_var *v);
void				fill_pos(t_parse *p, t_var *v);
void				fill_name(t_parse *p, t_var *v);
void				fill_pos_obj(t_parse *p, t_var *v);
void				fill_dir(t_parse *p, t_var *v);
void				fill_dir_obj(t_parse *p, t_var *v);
void				fill_color(t_parse *p, t_var *v);
void				parse_init(char *parse, t_parse *p);
void				parse(char *file, t_var *v);
void				parse_pos(char **parse, t_var *v, t_parse *p);
void				parse_pos2(char *parse, t_var *v, t_parse *p);
void				free_parse(t_parse *p, char **parse, int i);
void				ft_print_parse(t_parse *p);
void				ft_print_var(int *tab, t_var *v);
void				nbr_init(t_var *v, char **parse, int i);
unsigned int		ft_color_conv(t_color color);
int					ft_error(char *error, char *str);
double				ft_atof(char *str);
int					ft_check_class(char *parse);
void				ft_check_scene(char **parse, int i);
void				ft_check_symbol(char *parse, t_parse *p, int *j, int l);
void				ft_check_nb_class(t_parse *p, char **parse, int i);
void				get_class(char *parse, t_parse *p);
int					ft_check_type(t_parse *p);
int					ft_check_name(t_parse *p);
void				fill_refraction(t_parse *p, t_var *v);
void				fill_reflexion(t_parse *p, t_var *v);
void				ft_init_type(t_parse *p);
void				ft_init_name(t_parse *p);
void				ft_init_class_and_count(t_parse *p);
void				ft_count_type(t_parse *p);
void				get_class2(t_parse *p, char *class, char *class2, int i);
void				count_sphere(t_parse *p, int comp);
void				count_plan(t_parse *p, int comp);
void				count_cylinder(t_parse *p, int comp);
void				count_cone(t_parse *p, int comp);
void				count_type(t_parse *p);
void				count_cube(t_parse *p, int comp);
void				count_spot2(t_parse *p, int comp);
void				count_hyper(t_parse *p, int comp);
void				init_type(t_parse *p);
void				ft_too_many_types(t_parse *p);
void				fill_path(t_parse *p, t_var *v);
void				fill_path2(t_parse *p, t_var *v);
void				fill_freq(t_parse *p, t_var *v);
void				count_hour(t_parse *p, int comp);
void				count_glass(t_parse *p, int comp);
void				increment_object(t_parse *p);
void				ft_check_count(t_parse *p);
void				count_hole(t_parse *p, int comp);
int					ft_check_class(char *parse);
void				ft_check_error(char **parse, int i);
void				more_or_less_color(t_parse *p);
void				fill_length(t_parse *p, t_var *v);
#endif
