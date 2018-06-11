/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_start_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 22:01:39 by efedoryc          #+#    #+#             */
/*   Updated: 2018/06/09 22:01:41 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	camera_init_start(t_camera *camera)
{
	camera->location = init_vec3(-101.0f, 2.0f, 13.0f);
	camera->rotation = init_vec3(0.0f, 0.0f, 0.0f);
	camera->fov = 45.0f;
}

void	light_init_start(t_light *light)
{
	light->type = 0;
	light->location = init_vec3(0.0f, 0.0f, 0.0f);
	light->emission = init_vec3(0.0f, 0.0f, 0.0f);
	light->dir = init_vec3(1.0f, 1.0f, 1.0f);
	light->angle = 0.0f;
}

void	object_init_start(t_object *obj)
{
	obj->id = 0;
	obj->type = 0;
	obj->hidden = CL_FALSE;
	obj->capped = CL_FALSE;
	obj->operand = init_int2(-1, -1);
	obj->location = init_vec3(0.0f, 0.0f, 0.0f);
	obj->rotation = init_vec3(0.0f, 0.0f, 0.0f);
	obj->scale = init_vec3(1.0f, 1.0f, 1.0f);
	obj->color = init_vec3(0.5f, 0.5f, 0.5f);
	obj->diffuse = 1.0f;
	obj->specular = 0.0f;
	obj->spec_exp = 1.0f;
	obj->kr = 0.0f;
	obj->ior = 1.0f;
}