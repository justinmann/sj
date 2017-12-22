#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#define OBJ_FILENAME_LENGTH 500
#define MATERIAL_NAME_SIZE 255
#define OBJ_LINE_SIZE 500
#define MAX_VERTEX_COUNT 4 //can only handle quads or triangles

char strequal(const char *s1, const char *s2);
char contains(const char *haystack, const char *needle);

typedef struct
{
	int item_count;
	int current_max_size;
	char growable;

	void **items;
	char **names;	
} list;

void list_make(list *listo, int size, char growable);
int list_add_item(list *listo, void *item, char *name);
char* list_print_items(list *listo);
void* list_get_name(list *listo, char *name);
void* list_get_index(list *listo, int indx);
void* list_get_item(list *listo, void *item_to_find);
int list_find(list *listo, char *name_to_find);
void list_delete_index(list *listo, int indx);
void list_delete_name(list *listo, char *name);
void list_delete_item(list *listo, void *item);
void list_delete_all(list *listo);
void list_print_list(list *listo);
void list_free(list *listo);

void test_list();

typedef struct 
{
	int vertex_index[MAX_VERTEX_COUNT];
	int normal_index[MAX_VERTEX_COUNT];
	int texture_index[MAX_VERTEX_COUNT];
	int vertex_count;
	int material_index;
} obj_face;

typedef struct 
{
	int pos_index;
	int up_normal_index;
	int equator_normal_index;
	int texture_index[MAX_VERTEX_COUNT];
	int material_index;
} obj_sphere;

typedef struct 
{
	int pos_index;
	int normal_index;
	int rotation_normal_index;
	int texture_index[MAX_VERTEX_COUNT];
	int material_index;
} obj_plane;

typedef struct 
{
	double e[3];
} obj_vector;

typedef struct 
{
	char name[MATERIAL_NAME_SIZE];
	char texture_filename[OBJ_FILENAME_LENGTH];
	double amb[3];
	double diff[3];
	double spec[3];
	double reflect;
	double refract;
	double trans;
	double shiny;
	double glossy;
	double refract_index;
} obj_material;

typedef struct 
{
	int camera_pos_index;
	int camera_look_point_index;
	int camera_up_norm_index;
} obj_camera;

typedef struct 
{
	int pos_index;
	int material_index;
} obj_light_point;

typedef struct 
{
	int pos_index;
	int normal_index;
	int material_index;
} obj_light_disc;

typedef struct 
{
	int vertex_index[MAX_VERTEX_COUNT];
	int material_index;
} obj_light_quad;

typedef struct 
{
//	vector extreme_dimensions[2];
	char scene_filename[OBJ_FILENAME_LENGTH];
	char material_filename[OBJ_FILENAME_LENGTH];
	
	list vertex_list;
	list vertex_normal_list;
	list vertex_texture_list;
	
	list face_list;
	list sphere_list;
	list plane_list;
	
	list light_point_list;
	list light_quad_list;
	list light_disc_list;
	
	list material_list;
	
	obj_camera *camera;
} obj_growable_scene_data;

typedef struct 
{
	obj_vector **vertex_list;
	obj_vector **vertex_normal_list;
	obj_vector **vertex_texture_list;
	
	obj_face **face_list;
	obj_sphere **sphere_list;
	obj_plane **plane_list;
	
	obj_light_point **light_point_list;
	obj_light_quad **light_quad_list;
	obj_light_disc **light_disc_list;
	
	obj_material **material_list;
	
	int vertex_count;
	int vertex_normal_count;
	int vertex_texture_count;

	int face_count;
	int sphere_count;
	int plane_count;

	int light_point_count;
	int light_quad_count;
	int light_disc_count;

	int material_count;

	obj_camera *camera;
} obj_scene_data;

int parse_obj_scene(obj_scene_data *data_out, char *filename);
void delete_obj_data(obj_scene_data *data_out);

#endif
