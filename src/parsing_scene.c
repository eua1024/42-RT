#include <stdio.h>
#include "rt.h"

void		scene_init(char *strJSON, t_scene *scene)
{
	cJSON *cj_root;

	cj_root = cJSON_Parse(strJSON);
	if (!cj_root)
	{
		printf("[-] JSON Error: %s\n", cJSON_GetErrorPtr());
		exit(0);
	}
	camera_init(cj_root, scene);
	lights_init(cj_root, scene);
	objects_init(cj_root, scene);

	cJSON_Delete(cj_root);
}

void		parse_scene(char *scene_path, t_scene *scene)
{
	char    *scene_str;
    int     fd;
    int     i;

    if ((fd = open(scene_path, O_RDONLY)) < 0 || read(fd, 0, 0) < 0)
    {
        // Проверить можем ли мы использовать perror
        perror("[-] Read Scene Error");
        close(fd);
        exit(EXIT_FAILURE);
    }

    scene_str = (char *)malloc(MAX_SOURCE_SIZE);
    read(fd, scene_str, MAX_SOURCE_SIZE);
	close(fd);

    if (scene_str[0] != '{') {
        printf("[-] Read Scene Error\n");
        exit(EXIT_FAILURE);
    }

	scene_init(scene_str, scene);

    i = 0;
    while (i < scene->num_objects)
        obj_transform_mats(&scene->objects[i++]);
	free(scene_str);
	scene_str = NULL;
}