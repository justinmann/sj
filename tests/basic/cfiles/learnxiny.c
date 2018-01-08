#include <lib/sj-lib-common/common.h>

struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string1 = { 1, 13, 12, "Hello World!"};
struct {
    int refcount;
    int size;
    int count;
    char data[36];
} sjg_string10 = { 1, 36, 35, "Printing on a new line?\nNo Problem!"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string11 = { 1, 38, 37, "Do you want to add a tab?\tNo Problem!"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string12 = { 1, 13, 12, "Strings can "};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string13 = { 1, 17, 16, "be concatenated "};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string14 = { 1, 16, 15, "via + operator."};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string15 = { 1, 16, 15, "intArray1 @ 0: "};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string16 = { 1, 16, 15, "intArray2 @ 1: "};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string17 = { 1, 6, 5, "hello"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string18 = { 1, 4, 3, "bye"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string19 = { 1, 4, 3, "bob"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string2 = { 1, 10, 9, "Integer: "};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string20 = { 1, 4, 3, "foo"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string21 = { 1, 7, 6, "1+2 = "};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string22 = { 1, 7, 6, "2-1 = "};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string23 = { 1, 7, 6, "2*1 = "};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string24 = { 1, 7, 6, "1/2 = "};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string25 = { 1, 9, 8, "1/2.0 = "};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string26 = { 1, 8, 7, "11%3 = "};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string27 = { 1, 9, 8, "3 == 2? "};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string28 = { 1, 9, 8, "3 != 2? "};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string29 = { 1, 8, 7, "3 > 2? "};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string3 = { 1, 10, 9, " Double: "};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string30 = { 1, 8, 7, "3 < 2? "};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string31 = { 1, 9, 8, "2 <= 2? "};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string32 = { 1, 9, 8, "2 >= 2? "};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string33 = { 1, 17, 16, "3 > 2 && 2 > 3? "};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string34 = { 1, 17, 16, "3 > 2 || 2 > 3? "};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string35 = { 1, 12, 11, "!(3 == 2)? "};
struct {
    int refcount;
    int size;
    int count;
    char data[23];
} sjg_string36 = { 1, 23, 22, "\n->Inc/Dec-rementation"};
struct {
    int refcount;
    int size;
    int count;
    char data[22];
} sjg_string37 = { 1, 22, 21, "\n->Control Structures"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string38 = { 1, 13, 12, "I also don't"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string39 = { 1, 8, 7, "I don't"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string4 = { 1, 11, 10, " Boolean: "};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string40 = { 1, 14, 13, "I get printed"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string41 = { 1, 17, 16, "fooWhile Value: "};
struct {
    int refcount;
    int size;
    int count;
    char data[1];
} sjg_string42 = { 1, 1, 0, ""};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string43 = { 1, 8, 7, "January"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string44 = { 1, 9, 8, "February"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string45 = { 1, 6, 5, "March"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string46 = { 1, 17, 16, "Some other month"};
struct {
    int refcount;
    int size;
    int count;
    char data[21];
} sjg_string47 = { 1, 21, 20, "Switch Case Result: "};
struct {
    int refcount;
    int size;
    int count;
    char data[23];
} sjg_string48 = { 1, 23, 22, "\n->Classes & Functions"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string49 = { 1, 10, 9, "Bontrager"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string5 = { 1, 6, 5, "false"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string50 = { 1, 12, 11, "trek info: "};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string51 = { 1, 7, 6, "gear: "};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string52 = { 1, 11, 10, " cadence: "};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string53 = { 1, 9, 8, " speed: "};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string54 = { 1, 8, 7, " name: "};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string55 = { 1, 17, 16, "Mondays are bad."};
struct {
    int refcount;
    int size;
    int count;
    char data[20];
} sjg_string56 = { 1, 20, 19, "Fridays are better."};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string57 = { 1, 19, 18, "Weekends are best."};
struct {
    int refcount;
    int size;
    int count;
    char data[24];
} sjg_string58 = { 1, 24, 23, "Midweek days are so-so."};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string6 = { 1, 5, 4, "true"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string7 = { 1, 7, 6, "Hello "};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string8 = { 1, 6, 5, "World"};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string9 = { 1, 19, 18, "My String Is Here!"};

struct {
    int refcount;
    int size;
    int count;
    char data[1];
} g_empty = { 1, 1, 0, "" };
#define sjs_hash_type_bool_typeId 16
#define sjs_log_typeId 21
#define sjs_array_char_typeId 24
#define sjs_string_typeId 22
#define sjs_array_i32_typeId 44
#define sjs_obj_typeId 46
#define sjs_array_obj_typeId 47
#define sjs_array_string_typeId 52
#define sjs_list_string_typeId 51
#define sjs_hash_string_i32_typeId 60
#define cb_i32_void_typeId 68
#define cb_i32_void_heap_typeId 68
#define sjs_lambda1_typeId 69
#define sjs_bicycle_typeId 71
#define sjs_enumtest_typeId 75

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_obj sjs_obj;
typedef struct td_sjs_array_obj sjs_array_obj;
typedef struct td_sjs_array_string sjs_array_string;
typedef struct td_sjs_list_string sjs_list_string;
typedef struct td_sjs_hash_string_i32 sjs_hash_string_i32;
typedef struct td_cb_i32_void cb_i32_void;
typedef struct td_cb_i32_void_heap cb_i32_void_heap;
typedef struct td_sjs_lambda1 sjs_lambda1;
typedef struct td_sjs_bicycle sjs_bicycle;
typedef struct td_sjs_enumtest sjs_enumtest;

struct td_sjs_hash_type_bool {
    int _refCount;
    void* _hash;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
    sjs_hash_type_bool traceincludes;
    sjs_hash_type_bool debugincludes;
    sjs_hash_type_bool infoincludes;
    sjs_hash_type_bool warnincludes;
    sjs_hash_type_bool errorincludes;
    sjs_hash_type_bool fatalincludes;
};

struct td_sjs_array_char {
    int _refCount;
    void* v;
};

struct td_sjs_string {
    int _refCount;
    int32_t offset;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

struct td_sjs_array_i32 {
    int _refCount;
    void* v;
};

struct td_sjs_obj {
    int _refCount;
};

struct td_sjs_array_obj {
    int _refCount;
    void* v;
};

struct td_sjs_array_string {
    int _refCount;
    void* v;
};

struct td_sjs_list_string {
    int _refCount;
    sjs_array_string arr;
};

struct td_sjs_hash_string_i32 {
    int _refCount;
    void* _hash;
};

struct td_cb_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t);
};

struct td_cb_i32_void_heap {
    cb_i32_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_lambda1 {
    int _refCount;
};

struct td_sjs_bicycle {
    int _refCount;
    int32_t cadence;
    int32_t gear;
    sjs_string name;
    int32_t _speed;
};

struct td_sjs_enumtest {
    int _refCount;
    int32_t day;
};

#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
char* string_char(sjs_string* str);
#ifndef string_i32_hash_typedef
#define string_i32_hash_typedef
KHASH_INIT_TYPEDEF(string_i32_hash_type, sjs_string, int32_t)
#endif
#ifndef string_i32_hash_typedef
#define string_i32_hash_typedef
KHASH_INIT_TYPEDEF(string_i32_hash_type, sjs_string, int32_t)
#endif
int32_t g_day_friday;
int32_t g_day_monday;
int32_t g_day_saturday;
int32_t g_day_sunday;
int32_t g_day_thursday;
int32_t g_day_tuesday;
int32_t g_day_wednesday;
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;

int32_t foofor;
bool g_barboolean;
int32_t g_barint;
sjs_string g_barstring = { -1 };
int32_t g_bazint;
sjs_string g_bazstring = { -1 };
int32_t g_clocks_per_sec;
float g_f32_pi;
sjs_enumtest g_firstday = { -1 };
bool g_fooboolean;
char g_foochar;
double g_foodouble;
float g_foofloat;
sjs_array_i32 g_foolist = { -1 };
int64_t g_foolong;
sjs_string g_foostring = { -1 };
int32_t g_foowhile;
sjs_hash_string_i32 g_h = { -1 };
int32_t g_i;
int32_t g_i1;
int32_t g_i2;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_array_i32 g_intarray1 = { -1 };
sjs_array_i32 g_intarray2 = { -1 };
int32_t g_j;
sjs_list_string g_l = { -1 };
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
int32_t g_month;
sjs_string g_monthstring = { -1 };
sjs_string g_name = { -1 };
bool g_numbool;
double g_numdouble;
float g_numfloat;
int32_t g_numint;
sjs_array_obj g_objarray = { -1 };
sjs_string g_plusconcatenated = { -1 };
sjs_enumtest g_thirdday = { -1 };
sjs_bicycle g_trek = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
int32_t result3;
bool result4;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call10 = { -1 };
sjs_string sjt_call11 = { -1 };
sjs_string sjt_call12 = { -1 };
sjs_string sjt_call13 = { -1 };
sjs_string sjt_call14 = { -1 };
sjs_string sjt_call16 = { -1 };
sjs_string sjt_call17 = { -1 };
sjs_string sjt_call18 = { -1 };
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_obj sjt_call20 = { -1 };
sjs_obj sjt_call21 = { -1 };
sjs_string sjt_call22 = { -1 };
sjs_string sjt_call23 = { -1 };
sjs_string sjt_call24 = { -1 };
sjs_string sjt_call25 = { -1 };
sjs_string sjt_call26 = { -1 };
sjs_string sjt_call27 = { -1 };
sjs_string sjt_call28 = { -1 };
sjs_string sjt_call29 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call30 = { -1 };
sjs_string sjt_call31 = { -1 };
sjs_string sjt_call32 = { -1 };
sjs_string sjt_call33 = { -1 };
sjs_string sjt_call34 = { -1 };
sjs_string sjt_call35 = { -1 };
sjs_string sjt_call36 = { -1 };
sjs_string sjt_call37 = { -1 };
sjs_string sjt_call38 = { -1 };
sjs_string sjt_call39 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call40 = { -1 };
sjs_string sjt_call41 = { -1 };
sjs_string sjt_call42 = { -1 };
sjs_string sjt_call43 = { -1 };
sjs_string sjt_call44 = { -1 };
sjs_string sjt_call45 = { -1 };
sjs_string sjt_call46 = { -1 };
sjs_string sjt_call47 = { -1 };
sjs_string sjt_call48 = { -1 };
sjs_string sjt_call49 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string sjt_call50 = { -1 };
sjs_string sjt_call51 = { -1 };
sjs_string sjt_call52 = { -1 };
sjs_string sjt_call53 = { -1 };
sjs_string sjt_call54 = { -1 };
sjs_string sjt_call55 = { -1 };
sjs_string sjt_call56 = { -1 };
sjs_string sjt_call57 = { -1 };
sjs_string sjt_call58 = { -1 };
sjs_string sjt_call59 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call60 = { -1 };
sjs_string sjt_call61 = { -1 };
sjs_string sjt_call62 = { -1 };
sjs_string sjt_call63 = { -1 };
sjs_string sjt_call64 = { -1 };
sjs_string sjt_call65 = { -1 };
sjs_string sjt_call66 = { -1 };
sjs_string sjt_call67 = { -1 };
sjs_string sjt_call68 = { -1 };
sjs_string sjt_call69 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_string sjt_call70 = { -1 };
sjs_string sjt_call71 = { -1 };
sjs_string sjt_call72 = { -1 };
sjs_string sjt_call73 = { -1 };
sjs_string sjt_call74 = { -1 };
sjs_string sjt_call75 = { -1 };
sjs_string sjt_call76 = { -1 };
sjs_string sjt_call77 = { -1 };
sjs_string sjt_call78 = { -1 };
sjs_string sjt_call79 = { -1 };
sjs_string sjt_call8 = { -1 };
sjs_string sjt_call80 = { -1 };
sjs_string sjt_call81 = { -1 };
sjs_string sjt_call82 = { -1 };
sjs_string sjt_call83 = { -1 };
sjs_string sjt_call84 = { -1 };
sjs_string sjt_call85 = { -1 };
sjs_string sjt_call86 = { -1 };
sjs_string sjt_call88 = { -1 };
sjs_string sjt_call89 = { -1 };
sjs_string sjt_call9 = { -1 };
sjs_string sjt_call90 = { -1 };
sjs_lambda1 sjt_call92 = { -1 };
sjs_string sjt_call94 = { -1 };
sjs_string sjt_call95 = { -1 };
sjs_string sjt_call96 = { -1 };
sjs_string sjt_call97 = { -1 };
sjs_string sjt_call98 = { -1 };
sjs_string sjt_call99 = { -1 };
int32_t sjt_capture12;
int32_option sjt_capture13;
int32_t sjt_cast2;
int32_t sjt_cast3;
int32_t sjt_forEnd5;
int32_t sjt_forStart5;
int32_t sjt_functionParam100;
sjs_string* sjt_functionParam101 = 0;
sjs_string* sjt_functionParam102 = 0;
int32_t sjt_functionParam103;
int32_t sjt_functionParam104;
sjs_string* sjt_functionParam105 = 0;
sjs_string* sjt_functionParam106 = 0;
double sjt_functionParam107;
sjs_string* sjt_functionParam108 = 0;
sjs_string* sjt_functionParam109 = 0;
int32_t sjt_functionParam110;
int32_t sjt_functionParam111;
sjs_string* sjt_functionParam112 = 0;
sjs_string* sjt_functionParam113 = 0;
bool sjt_functionParam114;
sjs_string* sjt_functionParam115 = 0;
sjs_string* sjt_functionParam116 = 0;
bool sjt_functionParam117;
sjs_string* sjt_functionParam118 = 0;
sjs_string* sjt_functionParam119 = 0;
bool sjt_functionParam120;
sjs_string* sjt_functionParam121 = 0;
sjs_string* sjt_functionParam122 = 0;
bool sjt_functionParam123;
sjs_string* sjt_functionParam124 = 0;
sjs_string* sjt_functionParam125 = 0;
bool sjt_functionParam126;
sjs_string* sjt_functionParam127 = 0;
sjs_string* sjt_functionParam128 = 0;
bool sjt_functionParam129;
sjs_string* sjt_functionParam130 = 0;
sjs_string* sjt_functionParam131 = 0;
bool sjt_functionParam132;
sjs_string* sjt_functionParam133 = 0;
sjs_string* sjt_functionParam134 = 0;
bool sjt_functionParam135;
sjs_string* sjt_functionParam136 = 0;
sjs_string* sjt_functionParam137 = 0;
bool sjt_functionParam138;
sjs_string* sjt_functionParam139 = 0;
sjs_string* sjt_functionParam140 = 0;
int32_t sjt_functionParam141;
int32_t sjt_functionParam142;
sjs_string* sjt_functionParam143 = 0;
int32_t sjt_functionParam144;
int32_t sjt_functionParam145;
sjs_string* sjt_functionParam146 = 0;
sjs_string* sjt_functionParam153 = 0;
sjs_string* sjt_functionParam154 = 0;
int32_t sjt_functionParam155;
int32_t sjt_functionParam156;
int32_t sjt_functionParam160;
int32_t sjt_functionParam161;
int32_t sjt_functionParam162;
int32_t sjt_functionParam163;
int32_t sjt_functionParam164;
int32_t sjt_functionParam165;
int32_t sjt_functionParam166;
int32_t sjt_functionParam167;
int32_t sjt_functionParam168;
int32_t sjt_functionParam169;
int32_t sjt_functionParam170;
int32_t sjt_functionParam171;
int32_t sjt_functionParam172;
int32_t sjt_functionParam173;
int32_t sjt_functionParam174;
int32_t sjt_functionParam175;
int32_t sjt_functionParam176;
int32_t sjt_functionParam177;
cb_i32_void sjt_functionParam180;
sjs_string* sjt_functionParam184 = 0;
sjs_string* sjt_functionParam185 = 0;
sjs_string* sjt_functionParam186 = 0;
int32_t sjt_functionParam187;
int32_t sjt_functionParam188;
sjs_string* sjt_functionParam189 = 0;
sjs_string* sjt_functionParam190 = 0;
sjs_string* sjt_functionParam25 = 0;
int32_t sjt_functionParam26;
int32_t sjt_functionParam27;
sjs_string* sjt_functionParam28 = 0;
sjs_string* sjt_functionParam29 = 0;
double sjt_functionParam30;
sjs_string* sjt_functionParam31 = 0;
sjs_string* sjt_functionParam32 = 0;
bool sjt_functionParam33;
sjs_string* sjt_functionParam34 = 0;
sjs_string* sjt_functionParam35 = 0;
sjs_string* sjt_functionParam36 = 0;
sjs_string* sjt_functionParam37 = 0;
sjs_string* sjt_functionParam38 = 0;
sjs_string* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam40 = 0;
sjs_string* sjt_functionParam41 = 0;
sjs_string* sjt_functionParam42 = 0;
sjs_string* sjt_functionParam43 = 0;
sjs_string* sjt_functionParam44 = 0;
sjs_string* sjt_functionParam45 = 0;
sjs_string* sjt_functionParam46 = 0;
int32_t sjt_functionParam47;
int32_t sjt_functionParam48;
int32_t sjt_functionParam49;
sjs_string* sjt_functionParam5 = 0;
int32_t sjt_functionParam50;
int32_t sjt_functionParam51;
int32_t sjt_functionParam52;
int32_t sjt_functionParam53;
int32_t sjt_functionParam54;
int32_t sjt_functionParam55;
sjs_obj* sjt_functionParam56 = 0;
int32_t sjt_functionParam57;
sjs_obj* sjt_functionParam58 = 0;
sjs_string* sjt_functionParam59 = 0;
sjs_string* sjt_functionParam60 = 0;
int32_t sjt_functionParam61;
int32_t sjt_functionParam62;
int32_t sjt_functionParam63;
int32_t sjt_functionParam64;
int32_t sjt_functionParam65;
sjs_string* sjt_functionParam66 = 0;
sjs_string* sjt_functionParam67 = 0;
int32_t sjt_functionParam68;
int32_t sjt_functionParam69;
int32_t sjt_functionParam70;
sjs_string* sjt_functionParam78 = 0;
sjs_string* sjt_functionParam79 = 0;
int32_t sjt_functionParam80;
sjs_string* sjt_functionParam81 = 0;
int32_t sjt_functionParam82;
sjs_string* sjt_functionParam83 = 0;
int32_t sjt_functionParam84;
sjs_string* sjt_functionParam85 = 0;
int32_t sjt_functionParam86;
sjs_string* sjt_functionParam87 = 0;
sjs_string* sjt_functionParam89 = 0;
sjs_string* sjt_functionParam90 = 0;
int32_t sjt_functionParam91;
int32_t sjt_functionParam92;
sjs_string* sjt_functionParam93 = 0;
sjs_string* sjt_functionParam94 = 0;
int32_t sjt_functionParam95;
int32_t sjt_functionParam96;
sjs_string* sjt_functionParam97 = 0;
sjs_string* sjt_functionParam98 = 0;
int32_t sjt_functionParam99;
sjs_enumtest* sjt_parent100 = 0;
sjs_enumtest* sjt_parent101 = 0;
sjs_string* sjt_parent21 = 0;
sjs_string* sjt_parent22 = 0;
sjs_string* sjt_parent23 = 0;
sjs_string* sjt_parent24 = 0;
sjs_string* sjt_parent25 = 0;
sjs_string* sjt_parent28 = 0;
sjs_string* sjt_parent29 = 0;
sjs_array_i32* sjt_parent30 = 0;
sjs_array_i32* sjt_parent31 = 0;
sjs_array_i32* sjt_parent32 = 0;
sjs_array_obj* sjt_parent33 = 0;
sjs_array_obj* sjt_parent34 = 0;
sjs_string* sjt_parent35 = 0;
sjs_array_i32* sjt_parent36 = 0;
sjs_array_i32* sjt_parent37 = 0;
sjs_string* sjt_parent38 = 0;
sjs_array_i32* sjt_parent39 = 0;
sjs_list_string* sjt_parent47 = 0;
sjs_list_string* sjt_parent48 = 0;
sjs_list_string* sjt_parent49 = 0;
sjs_hash_string_i32* sjt_parent50 = 0;
sjs_hash_string_i32* sjt_parent51 = 0;
sjs_hash_string_i32* sjt_parent52 = 0;
sjs_hash_string_i32* sjt_parent53 = 0;
sjs_string* sjt_parent55 = 0;
sjs_string* sjt_parent56 = 0;
sjs_string* sjt_parent57 = 0;
sjs_string* sjt_parent58 = 0;
sjs_string* sjt_parent59 = 0;
sjs_string* sjt_parent60 = 0;
sjs_string* sjt_parent61 = 0;
sjs_string* sjt_parent62 = 0;
sjs_string* sjt_parent63 = 0;
sjs_string* sjt_parent64 = 0;
sjs_string* sjt_parent65 = 0;
sjs_string* sjt_parent66 = 0;
sjs_string* sjt_parent67 = 0;
sjs_string* sjt_parent68 = 0;
sjs_string* sjt_parent69 = 0;
sjs_string* sjt_parent70 = 0;
sjs_array_i32* sjt_parent71 = 0;
sjs_array_i32* sjt_parent72 = 0;
sjs_array_i32* sjt_parent73 = 0;
sjs_array_i32* sjt_parent74 = 0;
sjs_array_i32* sjt_parent75 = 0;
sjs_array_i32* sjt_parent76 = 0;
sjs_array_i32* sjt_parent77 = 0;
sjs_array_i32* sjt_parent78 = 0;
sjs_array_i32* sjt_parent79 = 0;
sjs_array_i32* sjt_parent80 = 0;
sjs_string* sjt_parent81 = 0;
sjs_bicycle* sjt_parent82 = 0;
sjs_bicycle* sjt_parent83 = 0;
sjs_string* sjt_parent84 = 0;
sjs_bicycle* sjt_parent99 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
int32_t sjt_void1;
int32_t sjt_void2;
bool sjt_while1;
int32_t underscore1;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_getsize(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_create_i32(int32_t size, int32_t item, sjs_array_i32* _return);
void sjf_array_create_i32_heap(int32_t size, int32_t item, sjs_array_i32** _return);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_obj(sjs_array_obj* _this);
void sjf_array_obj_copy(sjs_array_obj* _this, sjs_array_obj* _from);
void sjf_array_obj_destroy(sjs_array_obj* _this);
void sjf_array_obj_heap(sjs_array_obj* _this);
void sjf_array_obj_initat(sjs_array_obj* _parent, int32_t index, sjs_obj* item);
void sjf_array_string(sjs_array_string* _this);
void sjf_array_string_clone(sjs_array_string* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_string* _return);
void sjf_array_string_clone_heap(sjs_array_string* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_string** _return);
void sjf_array_string_copy(sjs_array_string* _this, sjs_array_string* _from);
void sjf_array_string_destroy(sjs_array_string* _this);
void sjf_array_string_getcount(sjs_array_string* _parent, int32_t* _return);
void sjf_array_string_getsize(sjs_array_string* _parent, int32_t* _return);
void sjf_array_string_heap(sjs_array_string* _this);
void sjf_array_string_initat(sjs_array_string* _parent, int32_t index, sjs_string* item);
void sjf_bicycle(sjs_bicycle* _this);
void sjf_bicycle_asstring(sjs_bicycle* _parent, sjs_string* _return);
void sjf_bicycle_asstring_heap(sjs_bicycle* _parent, sjs_string** _return);
void sjf_bicycle_copy(sjs_bicycle* _this, sjs_bicycle* _from);
void sjf_bicycle_destroy(sjs_bicycle* _this);
void sjf_bicycle_heap(sjs_bicycle* _this);
void sjf_bicycle_setcadence(sjs_bicycle* _parent, int32_t newvalue, int32_t* _return);
void sjf_bicycle_speedup(sjs_bicycle* _parent, int32_t increment, int32_t* _return);
void sjf_bool_asstring(bool val, sjs_string* _return);
void sjf_bool_asstring_heap(bool val, sjs_string** _return);
void sjf_console_readline(sjs_string* _return);
void sjf_console_readline_heap(sjs_string** _return);
void sjf_console_write(sjs_string* data);
void sjf_console_writeline(sjs_string* data);
void sjf_enumtest(sjs_enumtest* _this);
void sjf_enumtest_copy(sjs_enumtest* _this, sjs_enumtest* _from);
void sjf_enumtest_destroy(sjs_enumtest* _this);
void sjf_enumtest_heap(sjs_enumtest* _this);
void sjf_enumtest_tellitlikeitis(sjs_enumtest* _parent);
void sjf_f64_asstring(double val, sjs_string* _return);
void sjf_f64_asstring_heap(double val, sjs_string** _return);
void sjf_hash_string_i32(sjs_hash_string_i32* _this);
void sjf_hash_string_i32__weakptrremovekey(sjs_hash_string_i32* _parent, sjs_string* key);
void sjf_hash_string_i32__weakptrremovevalue(sjs_hash_string_i32* _parent, int32_t val);
void sjf_hash_string_i32_copy(sjs_hash_string_i32* _this, sjs_hash_string_i32* _from);
void sjf_hash_string_i32_destroy(sjs_hash_string_i32* _this);
void sjf_hash_string_i32_getat(sjs_hash_string_i32* _parent, sjs_string* key, int32_option* _return);
void sjf_hash_string_i32_heap(sjs_hash_string_i32* _this);
void sjf_hash_string_i32_setat(sjs_hash_string_i32* _parent, sjs_string* key, int32_t val);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_lambda1(sjs_lambda1* _this);
void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from);
void sjf_lambda1_destroy(sjs_lambda1* _this);
void sjf_lambda1_heap(sjs_lambda1* _this);
void sjf_lambda1_invoke(sjs_lambda1* _parent, int32_t _1);
void sjf_list_string(sjs_list_string* _this);
void sjf_list_string_add(sjs_list_string* _parent, sjs_string* item);
void sjf_list_string_copy(sjs_list_string* _this, sjs_list_string* _from);
void sjf_list_string_destroy(sjs_list_string* _this);
void sjf_list_string_heap(sjs_list_string* _this);
void sjf_list_string_removeat(sjs_list_string* _parent, int32_t index);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_obj(sjs_obj* _this);
void sjf_obj_copy(sjs_obj* _this, sjs_obj* _from);
void sjf_obj_destroy(sjs_obj* _this);
void sjf_obj_heap(sjs_obj* _this);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_asbool(sjs_string* text, bool* _return);
void sjf_string_asf32(sjs_string* text, float* _return);
void sjf_string_asf64(sjs_string* text, double* _return);
void sjf_string_asi32(sjs_string* text, int32_t* _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
void main_destroy(void);

#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
char* string_char(sjs_string* str) {
    sjf_string_nullterminate(str);
    return ((sjs_array*)str->data.v)->data;
}
#include <lib/sj-lib-common/common.cpp>
#ifndef string_i32_hash_function
#define string_i32_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_i32_hash_type, sjs_string, int32_t, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_i32_hash_type, sjs_string, int32_t, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_i32_hash_function
#define string_i32_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_i32_hash_type, sjs_string, int32_t, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_i32_hash_type, sjs_string, int32_t, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
void sjf_array_char(sjs_array_char* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(char));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    char* p = (char*)arr->data + offset;
#line 188
    char* newp = (char*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if true
#line 195
    memcpy(newp, p, sizeof(char) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        #line 171 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 199
    }
#line 200
    #endif
#line 200
    _return->_refCount = 1;
#line 202
    _return->v = newv;
#line 202
    sjf_array_char(_return);
}

void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(char));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    char* p = (char*)arr->data + offset;
#line 188
    char* newp = (char*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if true
#line 195
    memcpy(newp, p, sizeof(char) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        #line 171 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 199
    }
#line 200
    #endif
#line 200
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 200
    (*_return)->_refCount = 1;
#line 202
    (*_return)->v = newv;
#line 202
    sjf_array_char_heap((*_return));
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 365
    sjs_array* arr = (sjs_array*)_this->v;
#line 366
    arr->refcount++;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 370 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 371
    arr->refcount--;
#line 372
    if (arr->refcount == 0) {
#line 373
        #if !true && !false
#line 374
        char* p = (char*)arr->data;
#line 375
        for (int i = 0; i < arr->count; i++) {
#line 376
            ;
#line 377
        }
#line 378
        #endif
#line 379
        free(arr);
#line 380
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    char* p = (char*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_char_getsize(sjs_array_char* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    char* p = (char*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_create_i32(int32_t size, int32_t item, sjs_array_i32* _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(int32_t) * size);
#line 6
    int32_t* p = (int32_t*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        #line 2 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    _return->_refCount = 1;
#line 13
    _return->v = v;
#line 13
    sjf_array_i32(_return);
}

void sjf_array_create_i32_heap(int32_t size, int32_t item, sjs_array_i32** _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(int32_t) * size);
#line 6
    int32_t* p = (int32_t*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        #line 2 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    (*_return) = (sjs_array_i32*)malloc(sizeof(sjs_array_i32));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->v = v;
#line 13
    sjf_array_i32_heap((*_return));
}

void sjf_array_i32(sjs_array_i32* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 365
    sjs_array* arr = (sjs_array*)_this->v;
#line 366
    arr->refcount++;
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 370 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 371
    arr->refcount--;
#line 372
    if (arr->refcount == 0) {
#line 373
        #if !true && !false
#line 374
        int32_t* p = (int32_t*)arr->data;
#line 375
        for (int i = 0; i < arr->count; i++) {
#line 376
            ;
#line 377
        }
#line 378
        #endif
#line 379
        free(arr);
#line 380
    }
}

void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb) {
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;

#line 110 "lib/sj-lib-common/array.sj"
    sjt_forStart6 = 0;
#line 110
    sjf_array_i32_getcount(_parent, &sjt_forEnd6);
#line 110
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        int32_t sjt_functionParam178;
        int32_t sjt_functionParam179;

#line 110 "lib/sj-lib-common/array.sj"
        sjt_functionParam179 = i;
#line 110
        sjf_array_i32_getat(_parent, sjt_functionParam179, &sjt_functionParam178);
#line 110
        cb._cb(cb._parent, sjt_functionParam178);
#line 110
        i++;
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    int32_t* p = (int32_t*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    int32_t* p = (int32_t*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    int32_t* p = (int32_t*)arr->data;
#line 76
    ;
#line 77
    #line 68 "lib/sj-lib-common/array.sj"
p[index] = item;
;
}

void sjf_array_obj(sjs_array_obj* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_obj_copy(sjs_array_obj* _this, sjs_array_obj* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 365
    sjs_array* arr = (sjs_array*)_this->v;
#line 366
    arr->refcount++;
}

void sjf_array_obj_destroy(sjs_array_obj* _this) {
#line 370 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 371
    arr->refcount--;
#line 372
    if (arr->refcount == 0) {
#line 373
        #if !false && !true
#line 374
        sjs_obj* p = (sjs_obj*)arr->data;
#line 375
        for (int i = 0; i < arr->count; i++) {
#line 376
            ;
#line 377
        }
#line 378
        #endif
#line 379
        free(arr);
#line 380
    }
}

void sjf_array_obj_heap(sjs_array_obj* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_obj_initat(sjs_array_obj* _parent, int32_t index, sjs_obj* item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sjs_obj* p = (sjs_obj*)arr->data;
#line 63
    p[index]._refCount = 1;
#line 52 "lib/sj-lib-common/array.sj"
sjf_obj_copy(&p[index], item);
;
#line 64
    arr->count = index + 1;
}

void sjf_array_string(sjs_array_string* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_string_clone(sjs_array_string* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_string* _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(sjs_string));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    sjs_string* p = (sjs_string*)arr->data + offset;
#line 188
    sjs_string* newp = (sjs_string*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if false
#line 195
    memcpy(newp, p, sizeof(sjs_string) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        newp[i]._refCount = 1;
#line 171 "lib/sj-lib-common/array.sj"
sjf_string_copy(&newp[i], &p[i]);
;
#line 199
    }
#line 200
    #endif
#line 200
    _return->_refCount = 1;
#line 202
    _return->v = newv;
#line 202
    sjf_array_string(_return);
}

void sjf_array_string_clone_heap(sjs_array_string* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_string** _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(sjs_string));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    sjs_string* p = (sjs_string*)arr->data + offset;
#line 188
    sjs_string* newp = (sjs_string*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if false
#line 195
    memcpy(newp, p, sizeof(sjs_string) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        newp[i]._refCount = 1;
#line 171 "lib/sj-lib-common/array.sj"
sjf_string_copy(&newp[i], &p[i]);
;
#line 199
    }
#line 200
    #endif
#line 200
    (*_return) = (sjs_array_string*)malloc(sizeof(sjs_array_string));
#line 200
    (*_return)->_refCount = 1;
#line 202
    (*_return)->v = newv;
#line 202
    sjf_array_string_heap((*_return));
}

void sjf_array_string_copy(sjs_array_string* _this, sjs_array_string* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 365
    sjs_array* arr = (sjs_array*)_this->v;
#line 366
    arr->refcount++;
}

void sjf_array_string_destroy(sjs_array_string* _this) {
#line 370 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 371
    arr->refcount--;
#line 372
    if (arr->refcount == 0) {
#line 373
        #if !false && !true
#line 374
        sjs_string* p = (sjs_string*)arr->data;
#line 375
        for (int i = 0; i < arr->count; i++) {
#line 376
            ;
#line 377
        }
#line 378
        #endif
#line 379
        free(arr);
#line 380
    }
}

void sjf_array_string_getcount(sjs_array_string* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_string_getsize(sjs_array_string* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_string_heap(sjs_array_string* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_string_initat(sjs_array_string* _parent, int32_t index, sjs_string* item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sjs_string* p = (sjs_string*)arr->data;
#line 63
    p[index]._refCount = 1;
#line 52 "lib/sj-lib-common/array.sj"
sjf_string_copy(&p[index], item);
;
#line 64
    arr->count = index + 1;
}

void sjf_bicycle(sjs_bicycle* _this) {
}

void sjf_bicycle_asstring(sjs_bicycle* _parent, sjs_string* _return) {
    sjs_string sjt_call100 = { -1 };
    sjs_string sjt_call101 = { -1 };
    sjs_string sjt_call102 = { -1 };
    sjs_string sjt_call103 = { -1 };
    sjs_string sjt_call104 = { -1 };
    sjs_string sjt_call105 = { -1 };
    sjs_string sjt_call106 = { -1 };
    sjs_string sjt_call107 = { -1 };
    sjs_string sjt_call108 = { -1 };
    sjs_string sjt_call109 = { -1 };
    sjs_string sjt_call110 = { -1 };
    sjs_string sjt_call111 = { -1 };
    sjs_string sjt_call112 = { -1 };
    sjs_string* sjt_functionParam191 = 0;
    int32_t sjt_functionParam192;
    int32_t sjt_functionParam193;
    sjs_string* sjt_functionParam194 = 0;
    sjs_string* sjt_functionParam195 = 0;
    int32_t sjt_functionParam196;
    int32_t sjt_functionParam197;
    sjs_string* sjt_functionParam198 = 0;
    sjs_string* sjt_functionParam199 = 0;
    int32_t sjt_functionParam200;
    int32_t sjt_functionParam201;
    sjs_string* sjt_functionParam202 = 0;
    sjs_string* sjt_functionParam203 = 0;
    sjs_string* sjt_parent85 = 0;
    sjs_string* sjt_parent86 = 0;
    sjs_string* sjt_parent87 = 0;
    sjs_string* sjt_parent88 = 0;
    sjs_string* sjt_parent89 = 0;
    sjs_string* sjt_parent90 = 0;
    sjs_string* sjt_parent91 = 0;

    sjt_call106._refCount = 1;
#line 305 "learnxiny.sj"
    sjt_call106.offset = 0;
#line 305
    sjt_call106.count = 6;
#line 305
    sjt_call106.data._refCount = 1;
#line 305
    sjt_call106.data.v = &sjg_string51;
#line 305
    sjf_array_char(&sjt_call106.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call106._isnullterminated = false;
#line 16
    sjf_string(&sjt_call106);
#line 305 "learnxiny.sj"
    sjt_parent91 = &sjt_call106;
#line 305
    sjt_functionParam192 = _parent->gear;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam193 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam192, sjt_functionParam193, &sjt_call107);
#line 305 "learnxiny.sj"
    sjt_functionParam191 = &sjt_call107;
#line 305
    sjf_string_add(sjt_parent91, sjt_functionParam191, &sjt_call105);
#line 305
    sjt_parent90 = &sjt_call105;
#line 305
    sjt_call108._refCount = 1;
#line 305
    sjt_call108.offset = 0;
#line 305
    sjt_call108.count = 10;
#line 305
    sjt_call108.data._refCount = 1;
#line 305
    sjt_call108.data.v = &sjg_string52;
#line 305
    sjf_array_char(&sjt_call108.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call108._isnullterminated = false;
#line 16
    sjf_string(&sjt_call108);
#line 305 "learnxiny.sj"
    sjt_functionParam194 = &sjt_call108;
#line 305
    sjf_string_add(sjt_parent90, sjt_functionParam194, &sjt_call104);
#line 305
    sjt_parent89 = &sjt_call104;
#line 305
    sjt_functionParam196 = _parent->cadence;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam197 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam196, sjt_functionParam197, &sjt_call109);
#line 305 "learnxiny.sj"
    sjt_functionParam195 = &sjt_call109;
#line 305
    sjf_string_add(sjt_parent89, sjt_functionParam195, &sjt_call103);
#line 305
    sjt_parent88 = &sjt_call103;
#line 305
    sjt_call110._refCount = 1;
#line 305
    sjt_call110.offset = 0;
#line 305
    sjt_call110.count = 8;
#line 305
    sjt_call110.data._refCount = 1;
#line 305
    sjt_call110.data.v = &sjg_string53;
#line 305
    sjf_array_char(&sjt_call110.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call110._isnullterminated = false;
#line 16
    sjf_string(&sjt_call110);
#line 305 "learnxiny.sj"
    sjt_functionParam198 = &sjt_call110;
#line 305
    sjf_string_add(sjt_parent88, sjt_functionParam198, &sjt_call102);
#line 305
    sjt_parent87 = &sjt_call102;
#line 305
    sjt_functionParam200 = _parent->_speed;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam201 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam200, sjt_functionParam201, &sjt_call111);
#line 305 "learnxiny.sj"
    sjt_functionParam199 = &sjt_call111;
#line 305
    sjf_string_add(sjt_parent87, sjt_functionParam199, &sjt_call101);
#line 305
    sjt_parent86 = &sjt_call101;
#line 305
    sjt_call112._refCount = 1;
#line 305
    sjt_call112.offset = 0;
#line 305
    sjt_call112.count = 7;
#line 305
    sjt_call112.data._refCount = 1;
#line 305
    sjt_call112.data.v = &sjg_string54;
#line 305
    sjf_array_char(&sjt_call112.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call112._isnullterminated = false;
#line 16
    sjf_string(&sjt_call112);
#line 305 "learnxiny.sj"
    sjt_functionParam202 = &sjt_call112;
#line 305
    sjf_string_add(sjt_parent86, sjt_functionParam202, &sjt_call100);
#line 305
    sjt_parent85 = &sjt_call100;
#line 305
    sjt_functionParam203 = &_parent->name;
#line 305
    sjf_string_add(sjt_parent85, sjt_functionParam203, _return);

    if (sjt_call100._refCount == 1) { sjf_string_destroy(&sjt_call100); }
;
    if (sjt_call101._refCount == 1) { sjf_string_destroy(&sjt_call101); }
;
    if (sjt_call102._refCount == 1) { sjf_string_destroy(&sjt_call102); }
;
    if (sjt_call103._refCount == 1) { sjf_string_destroy(&sjt_call103); }
;
    if (sjt_call104._refCount == 1) { sjf_string_destroy(&sjt_call104); }
;
    if (sjt_call105._refCount == 1) { sjf_string_destroy(&sjt_call105); }
;
    if (sjt_call106._refCount == 1) { sjf_string_destroy(&sjt_call106); }
;
    if (sjt_call107._refCount == 1) { sjf_string_destroy(&sjt_call107); }
;
    if (sjt_call108._refCount == 1) { sjf_string_destroy(&sjt_call108); }
;
    if (sjt_call109._refCount == 1) { sjf_string_destroy(&sjt_call109); }
;
    if (sjt_call110._refCount == 1) { sjf_string_destroy(&sjt_call110); }
;
    if (sjt_call111._refCount == 1) { sjf_string_destroy(&sjt_call111); }
;
    if (sjt_call112._refCount == 1) { sjf_string_destroy(&sjt_call112); }
;
}

void sjf_bicycle_asstring_heap(sjs_bicycle* _parent, sjs_string** _return) {
    sjs_string sjt_call113 = { -1 };
    sjs_string sjt_call114 = { -1 };
    sjs_string sjt_call115 = { -1 };
    sjs_string sjt_call116 = { -1 };
    sjs_string sjt_call117 = { -1 };
    sjs_string sjt_call118 = { -1 };
    sjs_string sjt_call119 = { -1 };
    sjs_string sjt_call120 = { -1 };
    sjs_string sjt_call121 = { -1 };
    sjs_string sjt_call122 = { -1 };
    sjs_string sjt_call123 = { -1 };
    sjs_string sjt_call124 = { -1 };
    sjs_string sjt_call125 = { -1 };
    sjs_string* sjt_functionParam204 = 0;
    int32_t sjt_functionParam205;
    int32_t sjt_functionParam206;
    sjs_string* sjt_functionParam207 = 0;
    sjs_string* sjt_functionParam208 = 0;
    int32_t sjt_functionParam209;
    int32_t sjt_functionParam210;
    sjs_string* sjt_functionParam211 = 0;
    sjs_string* sjt_functionParam212 = 0;
    int32_t sjt_functionParam213;
    int32_t sjt_functionParam214;
    sjs_string* sjt_functionParam215 = 0;
    sjs_string* sjt_functionParam216 = 0;
    sjs_string* sjt_parent92 = 0;
    sjs_string* sjt_parent93 = 0;
    sjs_string* sjt_parent94 = 0;
    sjs_string* sjt_parent95 = 0;
    sjs_string* sjt_parent96 = 0;
    sjs_string* sjt_parent97 = 0;
    sjs_string* sjt_parent98 = 0;

    sjt_call119._refCount = 1;
#line 305 "learnxiny.sj"
    sjt_call119.offset = 0;
#line 305
    sjt_call119.count = 6;
#line 305
    sjt_call119.data._refCount = 1;
#line 305
    sjt_call119.data.v = &sjg_string51;
#line 305
    sjf_array_char(&sjt_call119.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call119._isnullterminated = false;
#line 16
    sjf_string(&sjt_call119);
#line 305 "learnxiny.sj"
    sjt_parent98 = &sjt_call119;
#line 305
    sjt_functionParam205 = _parent->gear;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam206 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam205, sjt_functionParam206, &sjt_call120);
#line 305 "learnxiny.sj"
    sjt_functionParam204 = &sjt_call120;
#line 305
    sjf_string_add(sjt_parent98, sjt_functionParam204, &sjt_call118);
#line 305
    sjt_parent97 = &sjt_call118;
#line 305
    sjt_call121._refCount = 1;
#line 305
    sjt_call121.offset = 0;
#line 305
    sjt_call121.count = 10;
#line 305
    sjt_call121.data._refCount = 1;
#line 305
    sjt_call121.data.v = &sjg_string52;
#line 305
    sjf_array_char(&sjt_call121.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call121._isnullterminated = false;
#line 16
    sjf_string(&sjt_call121);
#line 305 "learnxiny.sj"
    sjt_functionParam207 = &sjt_call121;
#line 305
    sjf_string_add(sjt_parent97, sjt_functionParam207, &sjt_call117);
#line 305
    sjt_parent96 = &sjt_call117;
#line 305
    sjt_functionParam209 = _parent->cadence;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam210 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam209, sjt_functionParam210, &sjt_call122);
#line 305 "learnxiny.sj"
    sjt_functionParam208 = &sjt_call122;
#line 305
    sjf_string_add(sjt_parent96, sjt_functionParam208, &sjt_call116);
#line 305
    sjt_parent95 = &sjt_call116;
#line 305
    sjt_call123._refCount = 1;
#line 305
    sjt_call123.offset = 0;
#line 305
    sjt_call123.count = 8;
#line 305
    sjt_call123.data._refCount = 1;
#line 305
    sjt_call123.data.v = &sjg_string53;
#line 305
    sjf_array_char(&sjt_call123.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call123._isnullterminated = false;
#line 16
    sjf_string(&sjt_call123);
#line 305 "learnxiny.sj"
    sjt_functionParam211 = &sjt_call123;
#line 305
    sjf_string_add(sjt_parent95, sjt_functionParam211, &sjt_call115);
#line 305
    sjt_parent94 = &sjt_call115;
#line 305
    sjt_functionParam213 = _parent->_speed;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam214 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam213, sjt_functionParam214, &sjt_call124);
#line 305 "learnxiny.sj"
    sjt_functionParam212 = &sjt_call124;
#line 305
    sjf_string_add(sjt_parent94, sjt_functionParam212, &sjt_call114);
#line 305
    sjt_parent93 = &sjt_call114;
#line 305
    sjt_call125._refCount = 1;
#line 305
    sjt_call125.offset = 0;
#line 305
    sjt_call125.count = 7;
#line 305
    sjt_call125.data._refCount = 1;
#line 305
    sjt_call125.data.v = &sjg_string54;
#line 305
    sjf_array_char(&sjt_call125.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call125._isnullterminated = false;
#line 16
    sjf_string(&sjt_call125);
#line 305 "learnxiny.sj"
    sjt_functionParam215 = &sjt_call125;
#line 305
    sjf_string_add(sjt_parent93, sjt_functionParam215, &sjt_call113);
#line 305
    sjt_parent92 = &sjt_call113;
#line 305
    sjt_functionParam216 = &_parent->name;
#line 305
    sjf_string_add_heap(sjt_parent92, sjt_functionParam216, _return);

    if (sjt_call113._refCount == 1) { sjf_string_destroy(&sjt_call113); }
;
    if (sjt_call114._refCount == 1) { sjf_string_destroy(&sjt_call114); }
;
    if (sjt_call115._refCount == 1) { sjf_string_destroy(&sjt_call115); }
;
    if (sjt_call116._refCount == 1) { sjf_string_destroy(&sjt_call116); }
;
    if (sjt_call117._refCount == 1) { sjf_string_destroy(&sjt_call117); }
;
    if (sjt_call118._refCount == 1) { sjf_string_destroy(&sjt_call118); }
;
    if (sjt_call119._refCount == 1) { sjf_string_destroy(&sjt_call119); }
;
    if (sjt_call120._refCount == 1) { sjf_string_destroy(&sjt_call120); }
;
    if (sjt_call121._refCount == 1) { sjf_string_destroy(&sjt_call121); }
;
    if (sjt_call122._refCount == 1) { sjf_string_destroy(&sjt_call122); }
;
    if (sjt_call123._refCount == 1) { sjf_string_destroy(&sjt_call123); }
;
    if (sjt_call124._refCount == 1) { sjf_string_destroy(&sjt_call124); }
;
    if (sjt_call125._refCount == 1) { sjf_string_destroy(&sjt_call125); }
;
}

void sjf_bicycle_copy(sjs_bicycle* _this, sjs_bicycle* _from) {
#line 267 "learnxiny.sj"
    _this->cadence = _from->cadence;
#line 267
    _this->gear = _from->gear;
#line 267
    _this->name._refCount = 1;
#line 267
    sjf_string_copy(&_this->name, &_from->name);
#line 267
    _this->_speed = _from->_speed;
}

void sjf_bicycle_destroy(sjs_bicycle* _this) {
    if (_this->name._refCount == 1) { sjf_string_destroy(&_this->name); }
;
}

void sjf_bicycle_heap(sjs_bicycle* _this) {
}

void sjf_bicycle_setcadence(sjs_bicycle* _parent, int32_t newvalue, int32_t* _return) {
#line 279 "learnxiny.sj"
    _parent->cadence = newvalue;
#line 280
    (*_return) = _parent->cadence;
}

void sjf_bicycle_speedup(sjs_bicycle* _parent, int32_t increment, int32_t* _return) {
#line 288 "learnxiny.sj"
    _parent->_speed = _parent->_speed + increment;
#line 288
    (*_return) = _parent->_speed;
}

void sjf_bool_asstring(bool val, sjs_string* _return) {
    if (val) {
        _return->_refCount = 1;
#line 3 "lib/sj-lib-common/bool.sj"
        _return->offset = 0;
#line 3
        _return->count = 4;
#line 3
        _return->data._refCount = 1;
#line 3
        _return->data.v = &sjg_string6;
#line 3
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
    } else {
        _return->_refCount = 1;
#line 5 "lib/sj-lib-common/bool.sj"
        _return->offset = 0;
#line 5
        _return->count = 5;
#line 5
        _return->data._refCount = 1;
#line 5
        _return->data.v = &sjg_string5;
#line 5
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
    }
}

void sjf_bool_asstring_heap(bool val, sjs_string** _return) {
    if (val) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 3 "lib/sj-lib-common/bool.sj"
        (*_return)->offset = 0;
#line 3
        (*_return)->count = 4;
#line 3
        (*_return)->data._refCount = 1;
#line 3
        (*_return)->data.v = &sjg_string6;
#line 3
        sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
        (*_return)->_isnullterminated = false;
#line 16
        sjf_string_heap((*_return));
    } else {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 5 "lib/sj-lib-common/bool.sj"
        (*_return)->offset = 0;
#line 5
        (*_return)->count = 5;
#line 5
        (*_return)->data._refCount = 1;
#line 5
        (*_return)->data.v = &sjg_string5;
#line 5
        sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
        (*_return)->_isnullterminated = false;
#line 16
        sjf_string_heap((*_return));
    }
}

void sjf_console_readline(sjs_string* _return) {
    int32_t count;
    void* data;

#line 17 "lib/sj-lib-common/console.sj"
    data = 0;
#line 18
    count = 0;
#line 20
    sjs_array* str = createarray(1024);
#line 21
    int index = 0;
#line 22
    char ch = ' ';
#line 23
    do {
#line 24
        ch = getchar();
#line 25
        if (ch != '\n') {
#line 26
            str->data[index] = ch;
#line 27
            index++;
#line 28
            if (index >= str->size) {
#line 29
                str = reallocarray(str, str->size * 2);
#line 30
            }
#line 31
        }
#line 32
    } while (ch != '\n');
#line 34
    data = (void*)str;
#line 35
    count = index;
#line 35
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 38 "lib/sj-lib-common/console.sj"
    _return->count = count;
#line 38
    _return->data._refCount = 1;
#line 38
    _return->data.v = data;
#line 38
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_console_readline_heap(sjs_string** _return) {
    int32_t count;
    void* data;

#line 17 "lib/sj-lib-common/console.sj"
    data = 0;
#line 18
    count = 0;
#line 20
    sjs_array* str = createarray(1024);
#line 21
    int index = 0;
#line 22
    char ch = ' ';
#line 23
    do {
#line 24
        ch = getchar();
#line 25
        if (ch != '\n') {
#line 26
            str->data[index] = ch;
#line 27
            index++;
#line 28
            if (index >= str->size) {
#line 29
                str = reallocarray(str, str->size * 2);
#line 30
            }
#line 31
        }
#line 32
    } while (ch != '\n');
#line 34
    data = (void*)str;
#line 35
    count = index;
#line 35
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 35
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 38 "lib/sj-lib-common/console.sj"
    (*_return)->count = count;
#line 38
    (*_return)->data._refCount = 1;
#line 38
    (*_return)->data.v = data;
#line 38
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_console_write(sjs_string* data) {
    sjs_string* sjt_parent26 = 0;

#line 2 "lib/sj-lib-common/console.sj"
    sjt_parent26 = data;
#line 2
    sjf_string_nullterminate(sjt_parent26);
#line 5
    printf("%s", string_char(data));
}

void sjf_console_writeline(sjs_string* data) {
    sjs_string* sjt_parent3 = 0;

#line 9 "lib/sj-lib-common/console.sj"
    sjt_parent3 = data;
#line 9
    sjf_string_nullterminate(sjt_parent3);
#line 12
    printf("%s\n", string_char(data));
}

void sjf_enumtest(sjs_enumtest* _this) {
}

void sjf_enumtest_copy(sjs_enumtest* _this, sjs_enumtest* _from) {
#line 354 "learnxiny.sj"
    _this->day = _from->day;
}

void sjf_enumtest_destroy(sjs_enumtest* _this) {
}

void sjf_enumtest_heap(sjs_enumtest* _this) {
}

void sjf_enumtest_tellitlikeitis(sjs_enumtest* _parent) {
    int32_t underscore2;

#line 359 "learnxiny.sj"
    underscore2 = _parent->day;
    if (underscore2 == g_day_monday) {
        sjs_string sjt_call126 = { -1 };
        sjs_string* sjt_functionParam217 = 0;

        sjt_call126._refCount = 1;
#line 361 "learnxiny.sj"
        sjt_call126.offset = 0;
#line 361
        sjt_call126.count = 16;
#line 361
        sjt_call126.data._refCount = 1;
#line 361
        sjt_call126.data.v = &sjg_string55;
#line 361
        sjf_array_char(&sjt_call126.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call126._isnullterminated = false;
#line 16
        sjf_string(&sjt_call126);
#line 361 "learnxiny.sj"
        sjt_functionParam217 = &sjt_call126;
#line 361
        sjf_console_writeline(sjt_functionParam217);

        if (sjt_call126._refCount == 1) { sjf_string_destroy(&sjt_call126); }
;
    } else {
        if (underscore2 == g_day_friday) {
            sjs_string sjt_call127 = { -1 };
            sjs_string* sjt_functionParam218 = 0;

            sjt_call127._refCount = 1;
#line 364 "learnxiny.sj"
            sjt_call127.offset = 0;
#line 364
            sjt_call127.count = 19;
#line 364
            sjt_call127.data._refCount = 1;
#line 364
            sjt_call127.data.v = &sjg_string56;
#line 364
            sjf_array_char(&sjt_call127.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call127._isnullterminated = false;
#line 16
            sjf_string(&sjt_call127);
#line 364 "learnxiny.sj"
            sjt_functionParam218 = &sjt_call127;
#line 364
            sjf_console_writeline(sjt_functionParam218);

            if (sjt_call127._refCount == 1) { sjf_string_destroy(&sjt_call127); }
;
        } else {
            if ((underscore2 == g_day_saturday) || (underscore2 == g_day_sunday)) {
                sjs_string sjt_call128 = { -1 };
                sjs_string* sjt_functionParam219 = 0;

                sjt_call128._refCount = 1;
#line 367 "learnxiny.sj"
                sjt_call128.offset = 0;
#line 367
                sjt_call128.count = 18;
#line 367
                sjt_call128.data._refCount = 1;
#line 367
                sjt_call128.data.v = &sjg_string57;
#line 367
                sjf_array_char(&sjt_call128.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call128._isnullterminated = false;
#line 16
                sjf_string(&sjt_call128);
#line 367 "learnxiny.sj"
                sjt_functionParam219 = &sjt_call128;
#line 367
                sjf_console_writeline(sjt_functionParam219);

                if (sjt_call128._refCount == 1) { sjf_string_destroy(&sjt_call128); }
;
            } else {
                sjs_string sjt_call129 = { -1 };
                sjs_string* sjt_functionParam220 = 0;

                sjt_call129._refCount = 1;
#line 370 "learnxiny.sj"
                sjt_call129.offset = 0;
#line 370
                sjt_call129.count = 23;
#line 370
                sjt_call129.data._refCount = 1;
#line 370
                sjt_call129.data.v = &sjg_string58;
#line 370
                sjf_array_char(&sjt_call129.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call129._isnullterminated = false;
#line 16
                sjf_string(&sjt_call129);
#line 370 "learnxiny.sj"
                sjt_functionParam220 = &sjt_call129;
#line 370
                sjf_console_writeline(sjt_functionParam220);

                if (sjt_call129._refCount == 1) { sjf_string_destroy(&sjt_call129); }
;
            }
        }
    }
}

void sjf_f64_asstring(double val, sjs_string* _return) {
    int32_t count;
    void* v;

#line 2 "lib/sj-lib-common/f64.sj"
    v = 0;
#line 3
    count = 0;
#line 5
    sjs_array* arr = createarray(256);
#line 6
    snprintf(arr->data, 256, "%lf", val);
#line 7
    arr->count = (int)strlen(arr->data);
#line 8
    count = arr->count;
#line 9
    v = arr;
#line 9
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 11 "lib/sj-lib-common/f64.sj"
    _return->count = count;
#line 11
    _return->data._refCount = 1;
#line 11
    _return->data.v = v;
#line 11
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_f64_asstring_heap(double val, sjs_string** _return) {
    int32_t count;
    void* v;

#line 2 "lib/sj-lib-common/f64.sj"
    v = 0;
#line 3
    count = 0;
#line 5
    sjs_array* arr = createarray(256);
#line 6
    snprintf(arr->data, 256, "%lf", val);
#line 7
    arr->count = (int)strlen(arr->data);
#line 8
    count = arr->count;
#line 9
    v = arr;
#line 9
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 9
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 11 "lib/sj-lib-common/f64.sj"
    (*_return)->count = count;
#line 11
    (*_return)->data._refCount = 1;
#line 11
    (*_return)->data.v = v;
#line 11
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_hash_string_i32(sjs_hash_string_i32* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_i32_hash_type);
}

void sjf_hash_string_i32__weakptrremovekey(sjs_hash_string_i32* _parent, sjs_string* key) {
#line 180 "lib/sj-lib-common/hash.sj"
    #if false
#line 181
    khash_t(string_i32_hash_type)* p = (khash_t(string_i32_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(string_i32_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(string_i32_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_string_i32__weakptrremovevalue(sjs_hash_string_i32* _parent, int32_t val) {
#line 192 "lib/sj-lib-common/hash.sj"
    #if false
#line 193
    khash_t(string_i32_hash_type)* p = (khash_t(string_i32_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            int32_t t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(string_i32_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_string_i32_copy(sjs_hash_string_i32* _this, sjs_hash_string_i32* _from) {
#line 230 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(string_i32_hash_type)* p = (khash_t(string_i32_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_string_i32_destroy(sjs_hash_string_i32* _this) {
#line 236 "lib/sj-lib-common/hash.sj"
    khash_t(string_i32_hash_type)* p = (khash_t(string_i32_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_i32__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if false
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_i32__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                ;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(string_i32_hash_type, (khash_t(string_i32_hash_type)*)_this->_hash);
#line 258
    }
}

void sjf_hash_string_i32_getat(sjs_hash_string_i32* _parent, sjs_string* key, int32_option* _return) {
#line 23 "lib/sj-lib-common/hash.sj"
    khash_t(string_i32_hash_type)* p = (khash_t(string_i32_hash_type)*)_parent->_hash;
#line 25
    #if true
#line 26
    khiter_t k = kh_get(string_i32_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(string_i32_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = int32_empty;
return;
#line 33
    }
#line 34
    #line 22 "lib/sj-lib-common/hash.sj"
_return->isvalid = true;
#line 22
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_string_i32_heap(sjs_hash_string_i32* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_i32_hash_type);
}

void sjf_hash_string_i32_setat(sjs_hash_string_i32* _parent, sjs_string* key, int32_t val) {
#line 40 "lib/sj-lib-common/hash.sj"
    khash_t(string_i32_hash_type)* p = (khash_t(string_i32_hash_type)*)_parent->_hash;
#line 42
    #if true
#line 43
    khiter_t k = kh_get(string_i32_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(string_i32_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    ;
#line 50
}
#line 52
int ret;
#line 53
#if true
#line 54
k = kh_put(string_i32_hash_type, p, *key, &ret);
#line 55
#else
#line 56
k = kh_put(string_i32_hash_type, p, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(string_i32_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_i32__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
sjs_string t;
#line 66
t._refCount = 1;
#line 38 "lib/sj-lib-common/hash.sj"
sjf_string_copy(&t, key);
;
#line 67
#endif
#line 69
#if false
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_i32__weakptrremovevalue };
#line 71
weakptr_cb_add(val, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/sj-lib-common/hash.sj"
kh_val(p, k) = val;
;
#line 75
#endif
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 180 "lib/sj-lib-common/hash.sj"
    #if false
#line 181
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(type_bool_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 192 "lib/sj-lib-common/hash.sj"
    #if false
#line 193
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            bool t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(type_bool_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 230 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 236 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if false
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                ;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(type_bool_hash_type, (khash_t(type_bool_hash_type)*)_this->_hash);
#line 258
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    _return->count = count;
#line 64
    _return->data._refCount = 1;
#line 64
    _return->data.v = vresult;
#line 64
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 62
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    (*_return)->count = count;
#line 64
    (*_return)->data._refCount = 1;
#line 64
    (*_return)->data.v = vresult;
#line 64
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    if (a < b) {
#line 6 "lib/sj-lib-common/i32.sj"
        (*_return) = b;
    } else {
#line 6 "lib/sj-lib-common/i32.sj"
        (*_return) = a;
    }
}

void sjf_lambda1(sjs_lambda1* _this) {
}

void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from) {
}

void sjf_lambda1_destroy(sjs_lambda1* _this) {
}

void sjf_lambda1_heap(sjs_lambda1* _this) {
}

void sjf_lambda1_invoke(sjs_lambda1* _parent, int32_t _1) {
    sjs_string sjt_call93 = { -1 };
    sjs_string* sjt_functionParam181 = 0;
    int32_t sjt_functionParam182;
    int32_t sjt_functionParam183;

#line 221 "learnxiny.sj"
    sjt_functionParam182 = _1;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam183 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam182, sjt_functionParam183, &sjt_call93);
#line 222 "learnxiny.sj"
    sjt_functionParam181 = &sjt_call93;
#line 222
    sjf_console_writeline(sjt_functionParam181);

    if (sjt_call93._refCount == 1) { sjf_string_destroy(&sjt_call93); }
;
}

void sjf_list_string(sjs_list_string* _this) {
}

void sjf_list_string_add(sjs_list_string* _parent, sjs_string* item) {
    int32_t sjt_capture10;
    int32_t sjt_capture9;
    sjs_array_string sjt_funcold2 = { -1 };
    int32_t sjt_functionParam76;
    sjs_string* sjt_functionParam77 = 0;
    sjs_array_string* sjt_parent40 = 0;
    sjs_array_string* sjt_parent41 = 0;
    sjs_array_string* sjt_parent45 = 0;
    sjs_array_string* sjt_parent46 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent40 = &_parent->arr;
#line 29
    sjf_array_string_getcount(sjt_parent40, &sjt_capture9);
#line 35
    sjt_parent41 = &_parent->arr;
#line 35
    sjf_array_string_getsize(sjt_parent41, &sjt_capture10);
    if (sjt_capture9 == sjt_capture10) {
        int32_t sjt_capture11;
        int32_t sjt_functionParam71;
        int32_t sjt_functionParam72;
        int32_t sjt_functionParam73;
        int32_t sjt_functionParam74;
        int32_t sjt_functionParam75;
        sjs_array_string* sjt_parent42 = 0;
        sjs_array_string* sjt_parent43 = 0;
        sjs_array_string* sjt_parent44 = 0;

        sjt_funcold2._refCount = 1;
#line 169 "lib/sj-lib-common/array.sj"
        sjf_array_string_copy(&sjt_funcold2, &_parent->arr);
#line 169
        sjt_parent42 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam71 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent43 = &_parent->arr;
#line 29
        sjf_array_string_getcount(sjt_parent43, &sjt_functionParam72);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam74 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent44 = &_parent->arr;
#line 35
        sjf_array_string_getsize(sjt_parent44, &sjt_capture11);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam75 = sjt_capture11 * 2;
#line 46
        sjf_i32_max(sjt_functionParam74, sjt_functionParam75, &sjt_functionParam73);
#line 46
        sjf_array_string_clone(sjt_parent42, sjt_functionParam71, sjt_functionParam72, sjt_functionParam73, &sjt_funcold2);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_string_destroy(&_parent->arr); }
;
#line 169 "lib/sj-lib-common/array.sj"
        sjf_array_string_copy(&_parent->arr, &sjt_funcold2);
    }

#line 52
    sjt_parent45 = &_parent->arr;
#line 29
    sjt_parent46 = &_parent->arr;
#line 29
    sjf_array_string_getcount(sjt_parent46, &sjt_functionParam76);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam77 = item;
#line 44
    sjf_array_string_initat(sjt_parent45, sjt_functionParam76, sjt_functionParam77);

    if (sjt_funcold2._refCount == 1) { sjf_array_string_destroy(&sjt_funcold2); }
;
}

void sjf_list_string_copy(sjs_list_string* _this, sjs_list_string* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_string_copy(&_this->arr, &_from->arr);
}

void sjf_list_string_destroy(sjs_list_string* _this) {
    if (_this->arr._refCount == 1) { sjf_array_string_destroy(&_this->arr); }
;
}

void sjf_list_string_heap(sjs_list_string* _this) {
}

void sjf_list_string_removeat(sjs_list_string* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= ((sjs_array*)_parent->arr.v)->count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, ((sjs_array*)_parent->arr.v)->count);
#line 57
    }
#line 58
    sjs_string* p = (sjs_string*)((sjs_array*)_parent->arr.v)->data;
#line 59
    ;
#line 60
    if (index != ((sjs_array*)_parent->arr.v)->count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (((sjs_array*)_parent->arr.v)->count - index - 1) * sizeof(sjs_string));
#line 62
    }
#line 63
    ((sjs_array*)_parent->arr.v)->count--;
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
#line 13 "lib/sj-lib-common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption7);
    } else {
        _this->fatalincludes._refCount = -1;
    }
}

void sjf_log_destroy(sjs_log* _this) {
    if (_this->traceincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->traceincludes); }
;
    if (_this->debugincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->debugincludes); }
;
    if (_this->infoincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->infoincludes); }
;
    if (_this->warnincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->warnincludes); }
;
    if (_this->errorincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->errorincludes); }
;
    if (_this->fatalincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->fatalincludes); }
;
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_obj(sjs_obj* _this) {
}

void sjf_obj_copy(sjs_obj* _this, sjs_obj* _from) {
}

void sjf_obj_destroy(sjs_obj* _this) {
}

void sjf_obj_heap(sjs_obj* _this) {
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy(_return, _parent);
    } else {
        bool sjt_capture2;
        int32_t sjt_capture3;
        sjs_array_char* sjt_parent4 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent4 = &_parent->data;
#line 35
        sjf_array_char_getsize(sjt_parent4, &sjt_capture3);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture3) {
            int32_t sjt_capture4;
            sjs_array_char* sjt_parent5 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent5 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent5, &sjt_capture4);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture2 = ((_parent->offset + _parent->count) == sjt_capture4);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture2 = false;
        }

        if (sjt_capture2) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd1;
            int32_t sjt_forStart1;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart1 = 0;
#line 27
            sjt_forEnd1 = item->count;
#line 27
            i = sjt_forStart1;
            while (i < sjt_forEnd1) {
                int32_t sjt_functionParam6;
                char sjt_functionParam7;
                int32_t sjt_functionParam9;
                sjs_array_char* sjt_parent6 = 0;
                sjs_string* sjt_parent8 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent6 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam6 = newcount;
#line 18
                sjt_parent8 = item;
#line 27
                sjt_functionParam9 = i;
#line 27
                sjf_string_getat(sjt_parent8, sjt_functionParam9, &sjt_functionParam7);
#line 27
                sjf_array_char_initat(sjt_parent6, sjt_functionParam6, sjt_functionParam7);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            _return->_refCount = 1;
#line 32
            _return->offset = _parent->offset;
#line 32
            _return->count = newcount;
#line 32
            _return->data._refCount = 1;
#line 32
            sjf_array_char_copy(&_return->data, &_parent->data);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd2;
            int32_t sjt_forStart2;
            int32_t sjt_functionParam10;
            int32_t sjt_functionParam11;
            int32_t sjt_functionParam12;
            sjs_array_char* sjt_parent10 = 0;
            sjs_array_char* sjt_parent9 = 0;

#line 169 "lib/sj-lib-common/array.sj"
            sjt_parent9 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam10 = _parent->offset;
#line 34
            sjt_functionParam11 = _parent->count;
#line 34
            sjt_functionParam12 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent9, sjt_functionParam10, sjt_functionParam11, sjt_functionParam12, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent10 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent10, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart2 = 0;
#line 37
            sjt_forEnd2 = item->count;
#line 37
            i = sjt_forStart2;
            while (i < sjt_forEnd2) {
                int32_t sjt_functionParam13;
                char sjt_functionParam14;
                int32_t sjt_functionParam15;
                sjs_array_char* sjt_parent11 = 0;
                sjs_string* sjt_parent12 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent11 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam13 = newcount;
#line 18
                sjt_parent12 = item;
#line 37
                sjt_functionParam15 = i;
#line 37
                sjf_string_getat(sjt_parent12, sjt_functionParam15, &sjt_functionParam14);
#line 37
                sjf_array_char_initat(sjt_parent11, sjt_functionParam13, sjt_functionParam14);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            _return->_refCount = 1;
#line 42
            _return->offset = 0;
#line 42
            _return->count = newcount;
#line 42
            _return->data._refCount = 1;
#line 42
            sjf_array_char_copy(&_return->data, &newdata);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy((*_return), _parent);
    } else {
        bool sjt_capture5;
        int32_t sjt_capture6;
        sjs_array_char* sjt_parent13 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent13 = &_parent->data;
#line 35
        sjf_array_char_getsize(sjt_parent13, &sjt_capture6);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture6) {
            int32_t sjt_capture7;
            sjs_array_char* sjt_parent14 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent14 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent14, &sjt_capture7);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture5 = ((_parent->offset + _parent->count) == sjt_capture7);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture5 = false;
        }

        if (sjt_capture5) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd3;
            int32_t sjt_forStart3;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart3 = 0;
#line 27
            sjt_forEnd3 = item->count;
#line 27
            i = sjt_forStart3;
            while (i < sjt_forEnd3) {
                int32_t sjt_functionParam16;
                char sjt_functionParam17;
                int32_t sjt_functionParam18;
                sjs_array_char* sjt_parent15 = 0;
                sjs_string* sjt_parent16 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent15 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam16 = newcount;
#line 18
                sjt_parent16 = item;
#line 27
                sjt_functionParam18 = i;
#line 27
                sjf_string_getat(sjt_parent16, sjt_functionParam18, &sjt_functionParam17);
#line 27
                sjf_array_char_initat(sjt_parent15, sjt_functionParam16, sjt_functionParam17);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 27
            (*_return)->_refCount = 1;
#line 32
            (*_return)->offset = _parent->offset;
#line 32
            (*_return)->count = newcount;
#line 32
            (*_return)->data._refCount = 1;
#line 32
            sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd4;
            int32_t sjt_forStart4;
            int32_t sjt_functionParam19;
            int32_t sjt_functionParam20;
            int32_t sjt_functionParam21;
            sjs_array_char* sjt_parent17 = 0;
            sjs_array_char* sjt_parent18 = 0;

#line 169 "lib/sj-lib-common/array.sj"
            sjt_parent17 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam19 = _parent->offset;
#line 34
            sjt_functionParam20 = _parent->count;
#line 34
            sjt_functionParam21 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent17, sjt_functionParam19, sjt_functionParam20, sjt_functionParam21, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent18 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent18, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart4 = 0;
#line 37
            sjt_forEnd4 = item->count;
#line 37
            i = sjt_forStart4;
            while (i < sjt_forEnd4) {
                int32_t sjt_functionParam22;
                char sjt_functionParam23;
                int32_t sjt_functionParam24;
                sjs_array_char* sjt_parent19 = 0;
                sjs_string* sjt_parent20 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent19 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam22 = newcount;
#line 18
                sjt_parent20 = item;
#line 37
                sjt_functionParam24 = i;
#line 37
                sjf_string_getat(sjt_parent20, sjt_functionParam24, &sjt_functionParam23);
#line 37
                sjf_array_char_initat(sjt_parent19, sjt_functionParam22, sjt_functionParam23);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 37
            (*_return)->_refCount = 1;
#line 42
            (*_return)->offset = 0;
#line 42
            (*_return)->count = newcount;
#line 42
            (*_return)->data._refCount = 1;
#line 42
            sjf_array_char_copy(&(*_return)->data, &newdata);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_asbool(sjs_string* text, bool* _return) {
    sjs_string sjt_call15 = { -1 };
    bool sjt_capture8;
    sjs_string* sjt_functionParam39 = 0;
    sjs_string* sjt_parent27 = 0;

#line 27 "lib/sj-lib-common/bool.sj"
    sjt_parent27 = text;
#line 27
    sjt_call15._refCount = 1;
#line 28
    sjt_call15.offset = 0;
#line 28
    sjt_call15.count = 4;
#line 28
    sjt_call15.data._refCount = 1;
#line 28
    sjt_call15.data.v = &sjg_string6;
#line 28
    sjf_array_char(&sjt_call15.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call15._isnullterminated = false;
#line 16
    sjf_string(&sjt_call15);
#line 28 "lib/sj-lib-common/bool.sj"
    sjt_functionParam39 = &sjt_call15;
#line 28
    sjf_string_isequal(sjt_parent27, sjt_functionParam39, &sjt_capture8);
    if (sjt_capture8) {
#line 29 "lib/sj-lib-common/bool.sj"
        (*_return) = true;
    } else {
#line 31 "lib/sj-lib-common/bool.sj"
        (*_return) = false;
    }

    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
}

void sjf_string_asf32(sjs_string* text, float* _return) {
    float x;

#line 107 "lib/sj-lib-common/f32.sj"
    x = 0.0f;
#line 109
    char* e;
#line 110
    float v = strtof(string_char(text), &e);
#line 112
    if (*e != '\0') {
#line 113
        x = 0.0f;
#line 114
    }
#line 115
    else {
#line 116
        x = v;
#line 117
    }
#line 106
    (*_return) = x;
}

void sjf_string_asf64(sjs_string* text, double* _return) {
    double x;

#line 15 "lib/sj-lib-common/f64.sj"
    x = 0.0;
#line 17
    char* e;
#line 18
    double v = strtod(string_char(text), &e);
#line 20
    if (*e != '\0') {
#line 21
        x = 0.0f;
#line 22
    }
#line 23
    else {
#line 24
        x = v;
#line 25
    }
#line 14
    (*_return) = x;
}

void sjf_string_asi32(sjs_string* text, int32_t* _return) {
    int32_t x;

#line 86 "lib/sj-lib-common/i32.sj"
    x = 0;
#line 88
    char* e;
#line 89
    int v = (int)strtol(string_char(text), &e, 10);
#line 91
    if (*e != '\0') {
#line 92
        x = 0;
#line 93
    }
#line 94
    else {
#line 95
        x = v;
#line 96
    }
#line 85
    (*_return) = x;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 12 "lib/sj-lib-common/string.sj"
    _this->offset = _from->offset;
#line 12
    _this->count = _from->count;
#line 12
    _this->data._refCount = 1;
#line 12
    sjf_array_char_copy(&_this->data, &_from->data);
#line 12
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam8;
    sjs_array_char* sjt_parent7 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent7 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam8 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent7, sjt_functionParam8, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
#line 73 "lib/sj-lib-common/string.sj"
    sjs_array* arr1 = (sjs_array*)_parent->data.v;
#line 74
    sjs_array* arr2 = (sjs_array*)test->data.v;
#line 75
    if (_parent->count != test->count) {
#line 76
        #line 72 "lib/sj-lib-common/string.sj"
(*_return) = false;
return;;      
#line 77
    }
#line 78
    bool result = memcmp(arr1->data + _parent->offset, arr2->data + test->offset, _parent->count) == 0;
#line 79
    #line 72 "lib/sj-lib-common/string.sj"
(*_return) = result;
return;;      
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    sjs_array_char sjt_funcold1 = { -1 };

#line 133 "lib/sj-lib-common/string.sj"
    result2 = !_parent->_isnullterminated;
    if (result2) {
        int32_t sjt_capture1;
        sjs_array_char* sjt_parent1 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent1 = &_parent->data;
#line 35
        sjf_array_char_getsize(sjt_parent1, &sjt_capture1);
        if ((_parent->count + 1) > sjt_capture1) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent2 = 0;

            sjt_funcold1._refCount = 1;
#line 169 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 169
            sjt_parent2 = &_parent->data;
#line 135 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->offset;
#line 135
            sjt_functionParam2 = _parent->count;
#line 135
            sjt_functionParam3 = _parent->count + 1;
#line 135
            sjf_array_char_clone(sjt_parent2, sjt_functionParam1, sjt_functionParam2, sjt_functionParam3, &sjt_funcold1);
#line 135
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 169 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
#line 136 "lib/sj-lib-common/string.sj"
            _parent->offset = 0;
        }

#line 139 "lib/sj-lib-common/string.sj"
        ((sjs_array*)_parent->data.v)->data[_parent->count] = 0;
#line 141
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/sj-lib-common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/sj-lib-common/type.sj"
    (*_return) = l == r;
}

int main(int argc, char** argv) {
#line 1 "lib/sj-lib-common/log.sj"
    g_loglevel_trace = 0;
#line 1
    g_loglevel_debug = 1;
#line 1
    g_loglevel_info = 2;
#line 1
    g_loglevel_warn = 3;
#line 1
    g_loglevel_error = 4;
#line 1
    g_loglevel_fatal = 5;
#line 343 "learnxiny.sj"
    g_day_sunday = 0;
#line 343
    g_day_monday = 1;
#line 343
    g_day_tuesday = 2;
#line 343
    g_day_wednesday = 3;
#line 343
    g_day_thursday = 4;
#line 343
    g_day_friday = 5;
#line 343
    g_day_saturday = 6;
#line 1 "lib/sj-lib-common/f32.sj"
    g_f32_pi = 3.14159265358979323846f;
#line 1 "lib/sj-lib-common/i32.sj"
    g_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    g_i32_maxvalue = result1 - 2147483647;
#line 4
    g_i32_minvalue = 2147483647;
#line 10 "lib/sj-lib-common/log.sj"
    g_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        g_log_excludeall._refCount = 1;
#line 11 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log_excludeall, copyoption1);
    } else {
        g_log_excludeall._refCount = -1;
    }

#line 11
    g_log._refCount = 1;
#line 13
    g_log.minlevel = g_loglevel_warn;
#line 13
    sjs_hash_type_bool* copyoption8 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption8 != 0) {
        g_log.traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.traceincludes, copyoption8);
    } else {
        g_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption9 != 0) {
        g_log.debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.debugincludes, copyoption9);
    } else {
        g_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption10 != 0) {
        g_log.infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.infoincludes, copyoption10);
    } else {
        g_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption11 != 0) {
        g_log.warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.warnincludes, copyoption11);
    } else {
        g_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption12 != 0) {
        g_log.errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.errorincludes, copyoption12);
    } else {
        g_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption13 != 0) {
        g_log.fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.fatalincludes, copyoption13);
    } else {
        g_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&g_log);
#line 2 "lib/sj-lib-common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/sj-lib-common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    sjt_call1._refCount = 1;
#line 16 "learnxiny.sj"
    sjt_call1.offset = 0;
#line 16
    sjt_call1.count = 12;
#line 16
    sjt_call1.data._refCount = 1;
#line 16
    sjt_call1.data.v = &sjg_string1;
#line 16
    sjf_array_char(&sjt_call1.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call1._isnullterminated = false;
#line 16
    sjf_string(&sjt_call1);
#line 16 "learnxiny.sj"
    sjt_functionParam4 = &sjt_call1;
#line 16
    sjf_console_writeline(sjt_functionParam4);
#line 16
    sjt_call7._refCount = 1;
#line 18
    sjt_call7.offset = 0;
#line 18
    sjt_call7.count = 9;
#line 18
    sjt_call7.data._refCount = 1;
#line 18
    sjt_call7.data.v = &sjg_string2;
#line 18
    sjf_array_char(&sjt_call7.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call7._isnullterminated = false;
#line 16
    sjf_string(&sjt_call7);
#line 18 "learnxiny.sj"
    sjt_parent25 = &sjt_call7;
#line 18
    sjt_functionParam26 = 10;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam27 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam26, sjt_functionParam27, &sjt_call8);
#line 18 "learnxiny.sj"
    sjt_functionParam25 = &sjt_call8;
#line 18
    sjf_string_add(sjt_parent25, sjt_functionParam25, &sjt_call6);
#line 18
    sjt_parent24 = &sjt_call6;
#line 18
    sjt_call9._refCount = 1;
#line 18
    sjt_call9.offset = 0;
#line 18
    sjt_call9.count = 9;
#line 18
    sjt_call9.data._refCount = 1;
#line 18
    sjt_call9.data.v = &sjg_string3;
#line 18
    sjf_array_char(&sjt_call9.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call9._isnullterminated = false;
#line 16
    sjf_string(&sjt_call9);
#line 18 "learnxiny.sj"
    sjt_functionParam28 = &sjt_call9;
#line 18
    sjf_string_add(sjt_parent24, sjt_functionParam28, &sjt_call5);
#line 18
    sjt_parent23 = &sjt_call5;
#line 18
    sjt_functionParam30 = 3.14;
#line 18
    sjf_f64_asstring(sjt_functionParam30, &sjt_call10);
#line 18
    sjt_functionParam29 = &sjt_call10;
#line 18
    sjf_string_add(sjt_parent23, sjt_functionParam29, &sjt_call4);
#line 18
    sjt_parent22 = &sjt_call4;
#line 18
    sjt_call11._refCount = 1;
#line 18
    sjt_call11.offset = 0;
#line 18
    sjt_call11.count = 10;
#line 18
    sjt_call11.data._refCount = 1;
#line 18
    sjt_call11.data.v = &sjg_string4;
#line 18
    sjf_array_char(&sjt_call11.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call11._isnullterminated = false;
#line 16
    sjf_string(&sjt_call11);
#line 18 "learnxiny.sj"
    sjt_functionParam31 = &sjt_call11;
#line 18
    sjf_string_add(sjt_parent22, sjt_functionParam31, &sjt_call3);
#line 18
    sjt_parent21 = &sjt_call3;
#line 18
    sjt_functionParam33 = true;
#line 18
    sjf_bool_asstring(sjt_functionParam33, &sjt_call12);
#line 18
    sjt_functionParam32 = &sjt_call12;
#line 18
    sjf_string_add(sjt_parent21, sjt_functionParam32, &sjt_call2);
#line 18
    sjt_functionParam5 = &sjt_call2;
#line 18
    sjf_console_writeline(sjt_functionParam5);
#line 18
    sjt_call13._refCount = 1;
#line 22
    sjt_call13.offset = 0;
#line 22
    sjt_call13.count = 6;
#line 22
    sjt_call13.data._refCount = 1;
#line 22
    sjt_call13.data.v = &sjg_string7;
#line 22
    sjf_array_char(&sjt_call13.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call13._isnullterminated = false;
#line 16
    sjf_string(&sjt_call13);
#line 22 "learnxiny.sj"
    sjt_functionParam34 = &sjt_call13;
#line 22
    sjf_console_write(sjt_functionParam34);
#line 22
    sjt_call14._refCount = 1;
#line 23
    sjt_call14.offset = 0;
#line 23
    sjt_call14.count = 5;
#line 23
    sjt_call14.data._refCount = 1;
#line 23
    sjt_call14.data.v = &sjg_string8;
#line 23
    sjf_array_char(&sjt_call14.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call14._isnullterminated = false;
#line 16
    sjf_string(&sjt_call14);
#line 23 "learnxiny.sj"
    sjt_functionParam35 = &sjt_call14;
#line 23
    sjf_console_write(sjt_functionParam35);
#line 23
    sjf_console_readline(&g_name);
#line 32
    sjt_functionParam36 = &g_name;
#line 32
    sjf_string_asi32(sjt_functionParam36, &g_numint);
#line 35
    sjt_functionParam37 = &g_name;
#line 35
    sjf_string_asf32(sjt_functionParam37, &g_numfloat);
#line 38
    sjt_functionParam38 = &g_name;
#line 38
    sjf_string_asf64(sjt_functionParam38, &g_numdouble);
#line 41
    sjt_functionParam40 = &g_name;
#line 41
    sjf_string_asbool(sjt_functionParam40, &g_numbool);
#line 51
    g_barint = 1;
#line 58
    g_foochar = '4';
#line 62
    g_bazint = 1;
#line 66
    g_foolong = 100000ll;
#line 72
    g_foofloat = 234.5f;
#line 78
    g_foodouble = 123.4;
#line 81
    g_fooboolean = true;
#line 82
    g_barboolean = false;
#line 82
    g_foostring._refCount = 1;
#line 85
    g_foostring.offset = 0;
#line 85
    g_foostring.count = 18;
#line 85
    g_foostring.data._refCount = 1;
#line 85
    g_foostring.data.v = &sjg_string9;
#line 85
    sjf_array_char(&g_foostring.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_foostring._isnullterminated = false;
#line 16
    sjf_string(&g_foostring);
#line 16
    g_barstring._refCount = 1;
#line 88 "learnxiny.sj"
    g_barstring.offset = 0;
#line 88
    g_barstring.count = 35;
#line 88
    g_barstring.data._refCount = 1;
#line 88
    g_barstring.data.v = &sjg_string10;
#line 88
    sjf_array_char(&g_barstring.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_barstring._isnullterminated = false;
#line 16
    sjf_string(&g_barstring);
#line 16
    g_bazstring._refCount = 1;
#line 90 "learnxiny.sj"
    g_bazstring.offset = 0;
#line 90
    g_bazstring.count = 37;
#line 90
    g_bazstring.data._refCount = 1;
#line 90
    g_bazstring.data.v = &sjg_string11;
#line 90
    sjf_array_char(&g_bazstring.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_bazstring._isnullterminated = false;
#line 16
    sjf_string(&g_bazstring);
#line 91 "learnxiny.sj"
    sjt_functionParam41 = &g_foostring;
#line 91
    sjf_console_writeline(sjt_functionParam41);
#line 92
    sjt_functionParam42 = &g_barstring;
#line 92
    sjf_console_writeline(sjt_functionParam42);
#line 93
    sjt_functionParam43 = &g_bazstring;
#line 93
    sjf_console_writeline(sjt_functionParam43);
#line 93
    sjt_call17._refCount = 1;
#line 97
    sjt_call17.offset = 0;
#line 97
    sjt_call17.count = 12;
#line 97
    sjt_call17.data._refCount = 1;
#line 97
    sjt_call17.data.v = &sjg_string12;
#line 97
    sjf_array_char(&sjt_call17.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call17._isnullterminated = false;
#line 16
    sjf_string(&sjt_call17);
#line 97 "learnxiny.sj"
    sjt_parent29 = &sjt_call17;
#line 97
    sjt_call18._refCount = 1;
#line 97
    sjt_call18.offset = 0;
#line 97
    sjt_call18.count = 16;
#line 97
    sjt_call18.data._refCount = 1;
#line 97
    sjt_call18.data.v = &sjg_string13;
#line 97
    sjf_array_char(&sjt_call18.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call18._isnullterminated = false;
#line 16
    sjf_string(&sjt_call18);
#line 97 "learnxiny.sj"
    sjt_functionParam44 = &sjt_call18;
#line 97
    sjf_string_add(sjt_parent29, sjt_functionParam44, &sjt_call16);
#line 97
    sjt_parent28 = &sjt_call16;
#line 97
    sjt_call19._refCount = 1;
#line 97
    sjt_call19.offset = 0;
#line 97
    sjt_call19.count = 15;
#line 97
    sjt_call19.data._refCount = 1;
#line 97
    sjt_call19.data.v = &sjg_string14;
#line 97
    sjf_array_char(&sjt_call19.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call19._isnullterminated = false;
#line 16
    sjf_string(&sjt_call19);
#line 97 "learnxiny.sj"
    sjt_functionParam45 = &sjt_call19;
#line 97
    sjf_string_add(sjt_parent28, sjt_functionParam45, &g_plusconcatenated);
#line 98
    sjt_functionParam46 = &g_plusconcatenated;
#line 98
    sjf_console_writeline(sjt_functionParam46);
#line 103
    sjt_functionParam47 = 10;
#line 103
    result3 = -1;
#line 103
    sjt_functionParam48 = result3;
#line 103
    sjf_array_create_i32(sjt_functionParam47, sjt_functionParam48, &g_intarray1);
#line 103
    g_intarray2._refCount = 1;
#line 106
    g_intarray2.v = createarray(3 * sizeof(int32_t));
#line 106
    sjf_array_i32(&g_intarray2);
#line 106
    sjs_array_i32* array1;
#line 106
    array1 = &g_intarray2;
#line 106
    sjt_parent30 = array1;
#line 106
    sjt_functionParam49 = 0;
#line 106
    sjt_functionParam50 = 1;
#line 106
    sjf_array_i32_initat(sjt_parent30, sjt_functionParam49, sjt_functionParam50);
#line 106
    sjt_parent31 = array1;
#line 106
    sjt_functionParam51 = 1;
#line 106
    sjt_functionParam52 = 2;
#line 106
    sjf_array_i32_initat(sjt_parent31, sjt_functionParam51, sjt_functionParam52);
#line 106
    sjt_parent32 = array1;
#line 106
    sjt_functionParam53 = 2;
#line 106
    sjt_functionParam54 = 3;
#line 106
    sjf_array_i32_initat(sjt_parent32, sjt_functionParam53, sjt_functionParam54);
#line 106
    g_objarray._refCount = 1;
#line 111
    g_objarray.v = createarray(2 * sizeof(sjs_obj));
#line 111
    sjf_array_obj(&g_objarray);
#line 111
    sjs_array_obj* array2;
#line 111
    array2 = &g_objarray;
#line 111
    sjt_parent33 = array2;
#line 111
    sjt_functionParam55 = 0;
#line 111
    sjt_call20._refCount = 1;
#line 111
    sjf_obj(&sjt_call20);
#line 111
    sjt_functionParam56 = &sjt_call20;
#line 111
    sjf_array_obj_initat(sjt_parent33, sjt_functionParam55, sjt_functionParam56);
#line 111
    sjt_parent34 = array2;
#line 111
    sjt_functionParam57 = 1;
#line 111
    sjt_call21._refCount = 1;
#line 111
    sjf_obj(&sjt_call21);
#line 111
    sjt_functionParam58 = &sjt_call21;
#line 111
    sjf_array_obj_initat(sjt_parent34, sjt_functionParam57, sjt_functionParam58);
#line 111
    sjt_call23._refCount = 1;
#line 114
    sjt_call23.offset = 0;
#line 114
    sjt_call23.count = 15;
#line 114
    sjt_call23.data._refCount = 1;
#line 114
    sjt_call23.data.v = &sjg_string15;
#line 114
    sjf_array_char(&sjt_call23.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call23._isnullterminated = false;
#line 16
    sjf_string(&sjt_call23);
#line 114 "learnxiny.sj"
    sjt_parent35 = &sjt_call23;
#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent36 = &g_intarray1;
#line 114 "learnxiny.sj"
    sjt_functionParam62 = 0;
#line 114
    sjf_array_i32_getat(sjt_parent36, sjt_functionParam62, &sjt_functionParam61);
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam63 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam61, sjt_functionParam63, &sjt_call24);
#line 114 "learnxiny.sj"
    sjt_functionParam60 = &sjt_call24;
#line 114
    sjf_string_add(sjt_parent35, sjt_functionParam60, &sjt_call22);
#line 114
    sjt_functionParam59 = &sjt_call22;
#line 114
    sjf_console_writeline(sjt_functionParam59);
#line 68 "lib/sj-lib-common/array.sj"
    sjt_parent37 = &g_intarray2;
#line 117 "learnxiny.sj"
    sjt_functionParam64 = 1;
#line 117
    sjt_functionParam65 = 1;
#line 117
    sjf_array_i32_setat(sjt_parent37, sjt_functionParam64, sjt_functionParam65);
#line 117
    sjt_call26._refCount = 1;
#line 118
    sjt_call26.offset = 0;
#line 118
    sjt_call26.count = 15;
#line 118
    sjt_call26.data._refCount = 1;
#line 118
    sjt_call26.data.v = &sjg_string16;
#line 118
    sjf_array_char(&sjt_call26.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call26._isnullterminated = false;
#line 16
    sjf_string(&sjt_call26);
#line 118 "learnxiny.sj"
    sjt_parent38 = &sjt_call26;
#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent39 = &g_intarray2;
#line 118 "learnxiny.sj"
    sjt_functionParam69 = 1;
#line 118
    sjf_array_i32_getat(sjt_parent39, sjt_functionParam69, &sjt_functionParam68);
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam70 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam68, sjt_functionParam70, &sjt_call27);
#line 118 "learnxiny.sj"
    sjt_functionParam67 = &sjt_call27;
#line 118
    sjf_string_add(sjt_parent38, sjt_functionParam67, &sjt_call25);
#line 118
    sjt_functionParam66 = &sjt_call25;
#line 118
    sjf_console_writeline(sjt_functionParam66);
#line 118
    g_l._refCount = 1;
#line 118
    g_l.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    g_l.arr.v = 0;
#line 27
    sjf_array_string(&g_l.arr);
#line 27
    sjf_list_string(&g_l);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent47 = &g_l;
#line 44
    sjt_call28._refCount = 1;
#line 122 "learnxiny.sj"
    sjt_call28.offset = 0;
#line 122
    sjt_call28.count = 5;
#line 122
    sjt_call28.data._refCount = 1;
#line 122
    sjt_call28.data.v = &sjg_string17;
#line 122
    sjf_array_char(&sjt_call28.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call28._isnullterminated = false;
#line 16
    sjf_string(&sjt_call28);
#line 122 "learnxiny.sj"
    sjt_functionParam78 = &sjt_call28;
#line 122
    sjf_list_string_add(sjt_parent47, sjt_functionParam78);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent48 = &g_l;
#line 44
    sjt_call29._refCount = 1;
#line 123 "learnxiny.sj"
    sjt_call29.offset = 0;
#line 123
    sjt_call29.count = 3;
#line 123
    sjt_call29.data._refCount = 1;
#line 123
    sjt_call29.data.v = &sjg_string18;
#line 123
    sjf_array_char(&sjt_call29.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call29._isnullterminated = false;
#line 16
    sjf_string(&sjt_call29);
#line 123 "learnxiny.sj"
    sjt_functionParam79 = &sjt_call29;
#line 123
    sjf_list_string_add(sjt_parent48, sjt_functionParam79);
#line 53 "lib/sj-lib-common/list.sj"
    sjt_parent49 = &g_l;
#line 124 "learnxiny.sj"
    sjt_functionParam80 = 0;
#line 124
    sjf_list_string_removeat(sjt_parent49, sjt_functionParam80);
#line 124
    g_h._refCount = 1;
#line 124
    sjf_hash_string_i32(&g_h);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent50 = &g_h;
#line 38
    sjt_call30._refCount = 1;
#line 128 "learnxiny.sj"
    sjt_call30.offset = 0;
#line 128
    sjt_call30.count = 3;
#line 128
    sjt_call30.data._refCount = 1;
#line 128
    sjt_call30.data.v = &sjg_string19;
#line 128
    sjf_array_char(&sjt_call30.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call30._isnullterminated = false;
#line 16
    sjf_string(&sjt_call30);
#line 128 "learnxiny.sj"
    sjt_functionParam81 = &sjt_call30;
#line 128
    sjt_functionParam82 = 1;
#line 128
    sjf_hash_string_i32_setat(sjt_parent50, sjt_functionParam81, sjt_functionParam82);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent51 = &g_h;
#line 38
    sjt_call31._refCount = 1;
#line 129 "learnxiny.sj"
    sjt_call31.offset = 0;
#line 129
    sjt_call31.count = 3;
#line 129
    sjt_call31.data._refCount = 1;
#line 129
    sjt_call31.data.v = &sjg_string20;
#line 129
    sjf_array_char(&sjt_call31.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call31._isnullterminated = false;
#line 16
    sjf_string(&sjt_call31);
#line 129 "learnxiny.sj"
    sjt_functionParam83 = &sjt_call31;
#line 129
    sjt_functionParam84 = 2;
#line 129
    sjf_hash_string_i32_setat(sjt_parent51, sjt_functionParam83, sjt_functionParam84);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent52 = &g_h;
#line 38
    sjt_call32._refCount = 1;
#line 130 "learnxiny.sj"
    sjt_call32.offset = 0;
#line 130
    sjt_call32.count = 3;
#line 130
    sjt_call32.data._refCount = 1;
#line 130
    sjt_call32.data.v = &sjg_string20;
#line 130
    sjf_array_char(&sjt_call32.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call32._isnullterminated = false;
#line 16
    sjf_string(&sjt_call32);
#line 130 "learnxiny.sj"
    sjt_functionParam85 = &sjt_call32;
#line 21 "lib/sj-lib-common/hash.sj"
    sjt_parent53 = &g_h;
#line 21
    sjt_call33._refCount = 1;
#line 130 "learnxiny.sj"
    sjt_call33.offset = 0;
#line 130
    sjt_call33.count = 3;
#line 130
    sjt_call33.data._refCount = 1;
#line 130
    sjt_call33.data.v = &sjg_string19;
#line 130
    sjf_array_char(&sjt_call33.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call33._isnullterminated = false;
#line 16
    sjf_string(&sjt_call33);
#line 130 "learnxiny.sj"
    sjt_functionParam87 = &sjt_call33;
#line 130
    sjf_hash_string_i32_getat(sjt_parent53, sjt_functionParam87, &sjt_capture13);
    if (sjt_capture13.isvalid) {
        sjs_string* sjt_functionParam88 = 0;
        int32_option sjt_getValue1;
        sjs_hash_string_i32* sjt_parent54 = 0;

#line 21 "lib/sj-lib-common/hash.sj"
        sjt_parent54 = &g_h;
#line 21
        sjt_call34._refCount = 1;
#line 130 "learnxiny.sj"
        sjt_call34.offset = 0;
#line 130
        sjt_call34.count = 3;
#line 130
        sjt_call34.data._refCount = 1;
#line 130
        sjt_call34.data.v = &sjg_string19;
#line 130
        sjf_array_char(&sjt_call34.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call34._isnullterminated = false;
#line 16
        sjf_string(&sjt_call34);
#line 130 "learnxiny.sj"
        sjt_functionParam88 = &sjt_call34;
#line 130
        sjf_hash_string_i32_getat(sjt_parent54, sjt_functionParam88, &sjt_getValue1);
#line 130
        sjt_capture12 = sjt_getValue1.value;
    } else {
#line 130 "learnxiny.sj"
        sjt_capture12 = (int32_t)0;
    }

#line 130
    sjt_functionParam86 = sjt_capture12 + 1;
#line 130
    sjf_hash_string_i32_setat(sjt_parent52, sjt_functionParam85, sjt_functionParam86);
#line 135
    g_i1 = 1;
#line 136
    g_i2 = 2;
#line 136
    sjt_call36._refCount = 1;
#line 139
    sjt_call36.offset = 0;
#line 139
    sjt_call36.count = 6;
#line 139
    sjt_call36.data._refCount = 1;
#line 139
    sjt_call36.data.v = &sjg_string21;
#line 139
    sjf_array_char(&sjt_call36.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call36._isnullterminated = false;
#line 16
    sjf_string(&sjt_call36);
#line 139 "learnxiny.sj"
    sjt_parent55 = &sjt_call36;
#line 139
    sjt_functionParam91 = g_i1 + g_i2;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam92 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam91, sjt_functionParam92, &sjt_call37);
#line 139 "learnxiny.sj"
    sjt_functionParam90 = &sjt_call37;
#line 139
    sjf_string_add(sjt_parent55, sjt_functionParam90, &sjt_call35);
#line 139
    sjt_functionParam89 = &sjt_call35;
#line 139
    sjf_console_writeline(sjt_functionParam89);
#line 139
    sjt_call39._refCount = 1;
#line 140
    sjt_call39.offset = 0;
#line 140
    sjt_call39.count = 6;
#line 140
    sjt_call39.data._refCount = 1;
#line 140
    sjt_call39.data.v = &sjg_string22;
#line 140
    sjf_array_char(&sjt_call39.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call39._isnullterminated = false;
#line 16
    sjf_string(&sjt_call39);
#line 140 "learnxiny.sj"
    sjt_parent56 = &sjt_call39;
#line 140
    sjt_functionParam95 = g_i2 - g_i1;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam96 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam95, sjt_functionParam96, &sjt_call40);
#line 140 "learnxiny.sj"
    sjt_functionParam94 = &sjt_call40;
#line 140
    sjf_string_add(sjt_parent56, sjt_functionParam94, &sjt_call38);
#line 140
    sjt_functionParam93 = &sjt_call38;
#line 140
    sjf_console_writeline(sjt_functionParam93);
#line 140
    sjt_call42._refCount = 1;
#line 141
    sjt_call42.offset = 0;
#line 141
    sjt_call42.count = 6;
#line 141
    sjt_call42.data._refCount = 1;
#line 141
    sjt_call42.data.v = &sjg_string23;
#line 141
    sjf_array_char(&sjt_call42.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call42._isnullterminated = false;
#line 16
    sjf_string(&sjt_call42);
#line 141 "learnxiny.sj"
    sjt_parent57 = &sjt_call42;
#line 141
    sjt_functionParam99 = g_i2 * g_i1;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam100 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam99, sjt_functionParam100, &sjt_call43);
#line 141 "learnxiny.sj"
    sjt_functionParam98 = &sjt_call43;
#line 141
    sjf_string_add(sjt_parent57, sjt_functionParam98, &sjt_call41);
#line 141
    sjt_functionParam97 = &sjt_call41;
#line 141
    sjf_console_writeline(sjt_functionParam97);
#line 141
    sjt_call45._refCount = 1;
#line 142
    sjt_call45.offset = 0;
#line 142
    sjt_call45.count = 6;
#line 142
    sjt_call45.data._refCount = 1;
#line 142
    sjt_call45.data.v = &sjg_string24;
#line 142
    sjf_array_char(&sjt_call45.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call45._isnullterminated = false;
#line 16
    sjf_string(&sjt_call45);
#line 142 "learnxiny.sj"
    sjt_parent58 = &sjt_call45;
#line 142
    sjt_functionParam103 = g_i1 / g_i2;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam104 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam103, sjt_functionParam104, &sjt_call46);
#line 142 "learnxiny.sj"
    sjt_functionParam102 = &sjt_call46;
#line 142
    sjf_string_add(sjt_parent58, sjt_functionParam102, &sjt_call44);
#line 142
    sjt_functionParam101 = &sjt_call44;
#line 142
    sjf_console_writeline(sjt_functionParam101);
#line 142
    sjt_call48._refCount = 1;
#line 143
    sjt_call48.offset = 0;
#line 143
    sjt_call48.count = 8;
#line 143
    sjt_call48.data._refCount = 1;
#line 143
    sjt_call48.data.v = &sjg_string25;
#line 143
    sjf_array_char(&sjt_call48.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call48._isnullterminated = false;
#line 16
    sjf_string(&sjt_call48);
#line 143 "learnxiny.sj"
    sjt_parent59 = &sjt_call48;
#line 143
    sjt_cast2 = g_i1;
#line 143
    sjt_cast3 = g_i2;
#line 143
    sjt_functionParam107 = (double)sjt_cast2 / (double)sjt_cast3;
#line 143
    sjf_f64_asstring(sjt_functionParam107, &sjt_call49);
#line 143
    sjt_functionParam106 = &sjt_call49;
#line 143
    sjf_string_add(sjt_parent59, sjt_functionParam106, &sjt_call47);
#line 143
    sjt_functionParam105 = &sjt_call47;
#line 143
    sjf_console_writeline(sjt_functionParam105);
#line 143
    sjt_call51._refCount = 1;
#line 146
    sjt_call51.offset = 0;
#line 146
    sjt_call51.count = 7;
#line 146
    sjt_call51.data._refCount = 1;
#line 146
    sjt_call51.data.v = &sjg_string26;
#line 146
    sjf_array_char(&sjt_call51.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call51._isnullterminated = false;
#line 16
    sjf_string(&sjt_call51);
#line 146 "learnxiny.sj"
    sjt_parent60 = &sjt_call51;
#line 146
    sjt_functionParam110 = 11 % 3;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam111 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam110, sjt_functionParam111, &sjt_call52);
#line 146 "learnxiny.sj"
    sjt_functionParam109 = &sjt_call52;
#line 146
    sjf_string_add(sjt_parent60, sjt_functionParam109, &sjt_call50);
#line 146
    sjt_functionParam108 = &sjt_call50;
#line 146
    sjf_console_writeline(sjt_functionParam108);
#line 146
    sjt_call54._refCount = 1;
#line 149
    sjt_call54.offset = 0;
#line 149
    sjt_call54.count = 8;
#line 149
    sjt_call54.data._refCount = 1;
#line 149
    sjt_call54.data.v = &sjg_string27;
#line 149
    sjf_array_char(&sjt_call54.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call54._isnullterminated = false;
#line 16
    sjf_string(&sjt_call54);
#line 149 "learnxiny.sj"
    sjt_parent61 = &sjt_call54;
#line 149
    sjt_functionParam114 = 3 == 2;
#line 149
    sjf_bool_asstring(sjt_functionParam114, &sjt_call55);
#line 149
    sjt_functionParam113 = &sjt_call55;
#line 149
    sjf_string_add(sjt_parent61, sjt_functionParam113, &sjt_call53);
#line 149
    sjt_functionParam112 = &sjt_call53;
#line 149
    sjf_console_writeline(sjt_functionParam112);
#line 149
    sjt_call57._refCount = 1;
#line 150
    sjt_call57.offset = 0;
#line 150
    sjt_call57.count = 8;
#line 150
    sjt_call57.data._refCount = 1;
#line 150
    sjt_call57.data.v = &sjg_string28;
#line 150
    sjf_array_char(&sjt_call57.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call57._isnullterminated = false;
#line 16
    sjf_string(&sjt_call57);
#line 150 "learnxiny.sj"
    sjt_parent62 = &sjt_call57;
#line 150
    sjt_functionParam117 = 3 != 2;
#line 150
    sjf_bool_asstring(sjt_functionParam117, &sjt_call58);
#line 150
    sjt_functionParam116 = &sjt_call58;
#line 150
    sjf_string_add(sjt_parent62, sjt_functionParam116, &sjt_call56);
#line 150
    sjt_functionParam115 = &sjt_call56;
#line 150
    sjf_console_writeline(sjt_functionParam115);
#line 150
    sjt_call60._refCount = 1;
#line 151
    sjt_call60.offset = 0;
#line 151
    sjt_call60.count = 7;
#line 151
    sjt_call60.data._refCount = 1;
#line 151
    sjt_call60.data.v = &sjg_string29;
#line 151
    sjf_array_char(&sjt_call60.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call60._isnullterminated = false;
#line 16
    sjf_string(&sjt_call60);
#line 151 "learnxiny.sj"
    sjt_parent63 = &sjt_call60;
#line 151
    sjt_functionParam120 = 3 > 2;
#line 151
    sjf_bool_asstring(sjt_functionParam120, &sjt_call61);
#line 151
    sjt_functionParam119 = &sjt_call61;
#line 151
    sjf_string_add(sjt_parent63, sjt_functionParam119, &sjt_call59);
#line 151
    sjt_functionParam118 = &sjt_call59;
#line 151
    sjf_console_writeline(sjt_functionParam118);
#line 151
    sjt_call63._refCount = 1;
#line 152
    sjt_call63.offset = 0;
#line 152
    sjt_call63.count = 7;
#line 152
    sjt_call63.data._refCount = 1;
#line 152
    sjt_call63.data.v = &sjg_string30;
#line 152
    sjf_array_char(&sjt_call63.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call63._isnullterminated = false;
#line 16
    sjf_string(&sjt_call63);
#line 152 "learnxiny.sj"
    sjt_parent64 = &sjt_call63;
#line 152
    sjt_functionParam123 = 3 < 2;
#line 152
    sjf_bool_asstring(sjt_functionParam123, &sjt_call64);
#line 152
    sjt_functionParam122 = &sjt_call64;
#line 152
    sjf_string_add(sjt_parent64, sjt_functionParam122, &sjt_call62);
#line 152
    sjt_functionParam121 = &sjt_call62;
#line 152
    sjf_console_writeline(sjt_functionParam121);
#line 152
    sjt_call66._refCount = 1;
#line 153
    sjt_call66.offset = 0;
#line 153
    sjt_call66.count = 8;
#line 153
    sjt_call66.data._refCount = 1;
#line 153
    sjt_call66.data.v = &sjg_string31;
#line 153
    sjf_array_char(&sjt_call66.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call66._isnullterminated = false;
#line 16
    sjf_string(&sjt_call66);
#line 153 "learnxiny.sj"
    sjt_parent65 = &sjt_call66;
#line 153
    sjt_functionParam126 = 2 <= 2;
#line 153
    sjf_bool_asstring(sjt_functionParam126, &sjt_call67);
#line 153
    sjt_functionParam125 = &sjt_call67;
#line 153
    sjf_string_add(sjt_parent65, sjt_functionParam125, &sjt_call65);
#line 153
    sjt_functionParam124 = &sjt_call65;
#line 153
    sjf_console_writeline(sjt_functionParam124);
#line 153
    sjt_call69._refCount = 1;
#line 154
    sjt_call69.offset = 0;
#line 154
    sjt_call69.count = 8;
#line 154
    sjt_call69.data._refCount = 1;
#line 154
    sjt_call69.data.v = &sjg_string32;
#line 154
    sjf_array_char(&sjt_call69.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call69._isnullterminated = false;
#line 16
    sjf_string(&sjt_call69);
#line 154 "learnxiny.sj"
    sjt_parent66 = &sjt_call69;
#line 154
    sjt_functionParam129 = 2 >= 2;
#line 154
    sjf_bool_asstring(sjt_functionParam129, &sjt_call70);
#line 154
    sjt_functionParam128 = &sjt_call70;
#line 154
    sjf_string_add(sjt_parent66, sjt_functionParam128, &sjt_call68);
#line 154
    sjt_functionParam127 = &sjt_call68;
#line 154
    sjf_console_writeline(sjt_functionParam127);
#line 154
    sjt_call72._refCount = 1;
#line 157
    sjt_call72.offset = 0;
#line 157
    sjt_call72.count = 16;
#line 157
    sjt_call72.data._refCount = 1;
#line 157
    sjt_call72.data.v = &sjg_string33;
#line 157
    sjf_array_char(&sjt_call72.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call72._isnullterminated = false;
#line 16
    sjf_string(&sjt_call72);
#line 157 "learnxiny.sj"
    sjt_parent67 = &sjt_call72;
    if (3 > 2) {
#line 157 "learnxiny.sj"
        sjt_functionParam132 = (2 > 3);
    } else {
#line 157 "learnxiny.sj"
        sjt_functionParam132 = false;
    }

#line 157
    sjf_bool_asstring(sjt_functionParam132, &sjt_call73);
#line 157
    sjt_functionParam131 = &sjt_call73;
#line 157
    sjf_string_add(sjt_parent67, sjt_functionParam131, &sjt_call71);
#line 157
    sjt_functionParam130 = &sjt_call71;
#line 157
    sjf_console_writeline(sjt_functionParam130);
#line 157
    sjt_call75._refCount = 1;
#line 158
    sjt_call75.offset = 0;
#line 158
    sjt_call75.count = 16;
#line 158
    sjt_call75.data._refCount = 1;
#line 158
    sjt_call75.data.v = &sjg_string34;
#line 158
    sjf_array_char(&sjt_call75.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call75._isnullterminated = false;
#line 16
    sjf_string(&sjt_call75);
#line 158 "learnxiny.sj"
    sjt_parent68 = &sjt_call75;
#line 158
    sjt_functionParam135 = (3 > 2) || (2 > 3);
#line 158
    sjf_bool_asstring(sjt_functionParam135, &sjt_call76);
#line 158
    sjt_functionParam134 = &sjt_call76;
#line 158
    sjf_string_add(sjt_parent68, sjt_functionParam134, &sjt_call74);
#line 158
    sjt_functionParam133 = &sjt_call74;
#line 158
    sjf_console_writeline(sjt_functionParam133);
#line 158
    sjt_call78._refCount = 1;
#line 159
    sjt_call78.offset = 0;
#line 159
    sjt_call78.count = 11;
#line 159
    sjt_call78.data._refCount = 1;
#line 159
    sjt_call78.data.v = &sjg_string35;
#line 159
    sjf_array_char(&sjt_call78.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call78._isnullterminated = false;
#line 16
    sjf_string(&sjt_call78);
#line 159 "learnxiny.sj"
    sjt_parent69 = &sjt_call78;
#line 159
    result4 = !(3 == 2);
#line 159
    sjt_functionParam138 = result4;
#line 159
    sjf_bool_asstring(sjt_functionParam138, &sjt_call79);
#line 159
    sjt_functionParam137 = &sjt_call79;
#line 159
    sjf_string_add(sjt_parent69, sjt_functionParam137, &sjt_call77);
#line 159
    sjt_functionParam136 = &sjt_call77;
#line 159
    sjf_console_writeline(sjt_functionParam136);
#line 173
    g_i = 0;
#line 173
    sjt_call80._refCount = 1;
#line 174
    sjt_call80.offset = 0;
#line 174
    sjt_call80.count = 22;
#line 174
    sjt_call80.data._refCount = 1;
#line 174
    sjt_call80.data.v = &sjg_string36;
#line 174
    sjf_array_char(&sjt_call80.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call80._isnullterminated = false;
#line 16
    sjf_string(&sjt_call80);
#line 174 "learnxiny.sj"
    sjt_functionParam139 = &sjt_call80;
#line 174
    sjf_console_writeline(sjt_functionParam139);
#line 176
    g_i = g_i + 1;
#line 177
    sjt_functionParam141 = g_i;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam142 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam141, sjt_functionParam142, &sjt_call81);
#line 177 "learnxiny.sj"
    sjt_functionParam140 = &sjt_call81;
#line 177
    sjf_console_writeline(sjt_functionParam140);
#line 178
    g_i = g_i - 1;
#line 179
    sjt_functionParam144 = g_i;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam145 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam144, sjt_functionParam145, &sjt_call82);
#line 179 "learnxiny.sj"
    sjt_functionParam143 = &sjt_call82;
#line 179
    sjf_console_writeline(sjt_functionParam143);
#line 179
    sjt_call83._refCount = 1;
#line 184
    sjt_call83.offset = 0;
#line 184
    sjt_call83.count = 21;
#line 184
    sjt_call83.data._refCount = 1;
#line 184
    sjt_call83.data.v = &sjg_string37;
#line 184
    sjf_array_char(&sjt_call83.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call83._isnullterminated = false;
#line 16
    sjf_string(&sjt_call83);
#line 184 "learnxiny.sj"
    sjt_functionParam146 = &sjt_call83;
#line 184
    sjf_console_writeline(sjt_functionParam146);
#line 187
    g_j = 10;
    if (g_j == 10) {
        sjs_string* sjt_functionParam147 = 0;

        sjt_call84._refCount = 1;
#line 189 "learnxiny.sj"
        sjt_call84.offset = 0;
#line 189
        sjt_call84.count = 13;
#line 189
        sjt_call84.data._refCount = 1;
#line 189
        sjt_call84.data.v = &sjg_string40;
#line 189
        sjf_array_char(&sjt_call84.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call84._isnullterminated = false;
#line 16
        sjf_string(&sjt_call84);
#line 189 "learnxiny.sj"
        sjt_functionParam147 = &sjt_call84;
#line 189
        sjf_console_writeline(sjt_functionParam147);
    } else {
        if (g_j > 10) {
            sjs_string* sjt_functionParam148 = 0;

            sjt_call85._refCount = 1;
#line 191 "learnxiny.sj"
            sjt_call85.offset = 0;
#line 191
            sjt_call85.count = 7;
#line 191
            sjt_call85.data._refCount = 1;
#line 191
            sjt_call85.data.v = &sjg_string39;
#line 191
            sjf_array_char(&sjt_call85.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call85._isnullterminated = false;
#line 16
            sjf_string(&sjt_call85);
#line 191 "learnxiny.sj"
            sjt_functionParam148 = &sjt_call85;
#line 191
            sjf_console_writeline(sjt_functionParam148);
        } else {
            sjs_string* sjt_functionParam149 = 0;

            sjt_call86._refCount = 1;
#line 193 "learnxiny.sj"
            sjt_call86.offset = 0;
#line 193
            sjt_call86.count = 12;
#line 193
            sjt_call86.data._refCount = 1;
#line 193
            sjt_call86.data.v = &sjg_string38;
#line 193
            sjf_array_char(&sjt_call86.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call86._isnullterminated = false;
#line 16
            sjf_string(&sjt_call86);
#line 193 "learnxiny.sj"
            sjt_functionParam149 = &sjt_call86;
#line 193
            sjf_console_writeline(sjt_functionParam149);
        }
    }

#line 197
    g_foowhile = 0;
#line 198
    sjt_while1 = g_foowhile < 100;
    while (sjt_while1) {
        sjs_string sjt_call87 = { -1 };
        sjs_string* sjt_functionParam150 = 0;
        int32_t sjt_functionParam151;
        int32_t sjt_functionParam152;

#line 199 "learnxiny.sj"
        sjt_functionParam151 = g_foowhile;
#line 22 "lib/sj-lib-common/i32.sj"
        sjt_functionParam152 = 10;
#line 22
        sjf_i32_asstring(sjt_functionParam151, sjt_functionParam152, &sjt_call87);
#line 199 "learnxiny.sj"
        sjt_functionParam150 = &sjt_call87;
#line 199
        sjf_console_writeline(sjt_functionParam150);
#line 202
        g_foowhile = g_foowhile + 1;
#line 198
        sjt_while1 = g_foowhile < 100;

        if (sjt_call87._refCount == 1) { sjf_string_destroy(&sjt_call87); }
;
    }

#line 198
    sjt_call89._refCount = 1;
#line 204
    sjt_call89.offset = 0;
#line 204
    sjt_call89.count = 16;
#line 204
    sjt_call89.data._refCount = 1;
#line 204
    sjt_call89.data.v = &sjg_string41;
#line 204
    sjf_array_char(&sjt_call89.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call89._isnullterminated = false;
#line 16
    sjf_string(&sjt_call89);
#line 204 "learnxiny.sj"
    sjt_parent70 = &sjt_call89;
#line 204
    sjt_functionParam155 = g_foowhile;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam156 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam155, sjt_functionParam156, &sjt_call90);
#line 204 "learnxiny.sj"
    sjt_functionParam154 = &sjt_call90;
#line 204
    sjf_string_add(sjt_parent70, sjt_functionParam154, &sjt_call88);
#line 204
    sjt_functionParam153 = &sjt_call88;
#line 204
    sjf_console_writeline(sjt_functionParam153);
#line 208
    sjt_forStart5 = 0;
#line 208
    sjt_forEnd5 = 10;
#line 208
    foofor = sjt_forStart5;
    while (foofor < sjt_forEnd5) {
        sjs_string sjt_call91 = { -1 };
        sjs_string* sjt_functionParam157 = 0;
        int32_t sjt_functionParam158;
        int32_t sjt_functionParam159;

#line 208 "learnxiny.sj"
        sjt_functionParam158 = foofor;
#line 22 "lib/sj-lib-common/i32.sj"
        sjt_functionParam159 = 10;
#line 22
        sjf_i32_asstring(sjt_functionParam158, sjt_functionParam159, &sjt_call91);
#line 209 "learnxiny.sj"
        sjt_functionParam157 = &sjt_call91;
#line 209
        sjf_console_writeline(sjt_functionParam157);
#line 208
        foofor++;

        if (sjt_call91._refCount == 1) { sjf_string_destroy(&sjt_call91); }
;
    }

#line 208
    g_foolist._refCount = 1;
#line 216
    g_foolist.v = createarray(9 * sizeof(int32_t));
#line 216
    sjf_array_i32(&g_foolist);
#line 216
    sjs_array_i32* array3;
#line 216
    array3 = &g_foolist;
#line 216
    sjt_parent71 = array3;
#line 216
    sjt_functionParam160 = 0;
#line 216
    sjt_functionParam161 = 1;
#line 216
    sjf_array_i32_initat(sjt_parent71, sjt_functionParam160, sjt_functionParam161);
#line 216
    sjt_parent72 = array3;
#line 216
    sjt_functionParam162 = 1;
#line 216
    sjt_functionParam163 = 2;
#line 216
    sjf_array_i32_initat(sjt_parent72, sjt_functionParam162, sjt_functionParam163);
#line 216
    sjt_parent73 = array3;
#line 216
    sjt_functionParam164 = 2;
#line 216
    sjt_functionParam165 = 3;
#line 216
    sjf_array_i32_initat(sjt_parent73, sjt_functionParam164, sjt_functionParam165);
#line 216
    sjt_parent74 = array3;
#line 216
    sjt_functionParam166 = 3;
#line 216
    sjt_functionParam167 = 4;
#line 216
    sjf_array_i32_initat(sjt_parent74, sjt_functionParam166, sjt_functionParam167);
#line 216
    sjt_parent75 = array3;
#line 216
    sjt_functionParam168 = 4;
#line 216
    sjt_functionParam169 = 5;
#line 216
    sjf_array_i32_initat(sjt_parent75, sjt_functionParam168, sjt_functionParam169);
#line 216
    sjt_parent76 = array3;
#line 216
    sjt_functionParam170 = 5;
#line 216
    sjt_functionParam171 = 6;
#line 216
    sjf_array_i32_initat(sjt_parent76, sjt_functionParam170, sjt_functionParam171);
#line 216
    sjt_parent77 = array3;
#line 216
    sjt_functionParam172 = 6;
#line 216
    sjt_functionParam173 = 7;
#line 216
    sjf_array_i32_initat(sjt_parent77, sjt_functionParam172, sjt_functionParam173);
#line 216
    sjt_parent78 = array3;
#line 216
    sjt_functionParam174 = 7;
#line 216
    sjt_functionParam175 = 8;
#line 216
    sjf_array_i32_initat(sjt_parent78, sjt_functionParam174, sjt_functionParam175);
#line 216
    sjt_parent79 = array3;
#line 216
    sjt_functionParam176 = 8;
#line 216
    sjt_functionParam177 = 9;
#line 216
    sjf_array_i32_initat(sjt_parent79, sjt_functionParam176, sjt_functionParam177);
#line 109 "lib/sj-lib-common/array.sj"
    sjt_parent80 = &g_foolist;
#line 221 "learnxiny.sj"
    sjs_lambda1* lambainit1;
#line 221
    sjt_call92._refCount = 1;
#line 221
    sjf_lambda1(&sjt_call92);
#line 221
    lambainit1 = &sjt_call92;
#line 221
    sjt_functionParam180._parent = (sjs_object*)lambainit1;
#line 221
    sjt_functionParam180._cb = (void(*)(sjs_object*,int32_t))sjf_lambda1_invoke;
#line 221
    sjf_array_i32_each(sjt_parent80, sjt_functionParam180);
#line 234
    g_month = 3;
#line 234
    g_monthstring._refCount = 1;
#line 235
    g_monthstring.offset = 0;
#line 235
    g_monthstring.count = 0;
#line 235
    g_monthstring.data._refCount = 1;
#line 235
    g_monthstring.data.v = &sjg_string42;
#line 235
    sjf_array_char(&g_monthstring.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_monthstring._isnullterminated = false;
#line 16
    sjf_string(&g_monthstring);
#line 236 "learnxiny.sj"
    underscore1 = g_month;
    if (underscore1 == 1) {
        sjs_string sjt_funcold3 = { -1 };

        sjt_funcold3._refCount = 1;
#line 12 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&sjt_funcold3, &g_monthstring);
#line 12
        sjt_funcold3._refCount = 1;
#line 237 "learnxiny.sj"
        sjt_funcold3.offset = 0;
#line 237
        sjt_funcold3.count = 7;
#line 237
        sjt_funcold3.data._refCount = 1;
#line 237
        sjt_funcold3.data.v = &sjg_string43;
#line 237
        sjf_array_char(&sjt_funcold3.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_funcold3._isnullterminated = false;
#line 16
        sjf_string(&sjt_funcold3);
#line 16
        if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 12
        sjf_string_copy(&g_monthstring, &sjt_funcold3);

        if (sjt_funcold3._refCount == 1) { sjf_string_destroy(&sjt_funcold3); }
;
    } else {
        if (underscore1 == 2) {
            sjs_string sjt_funcold4 = { -1 };

            sjt_funcold4._refCount = 1;
#line 12 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&sjt_funcold4, &g_monthstring);
#line 12
            sjt_funcold4._refCount = 1;
#line 238 "learnxiny.sj"
            sjt_funcold4.offset = 0;
#line 238
            sjt_funcold4.count = 8;
#line 238
            sjt_funcold4.data._refCount = 1;
#line 238
            sjt_funcold4.data.v = &sjg_string44;
#line 238
            sjf_array_char(&sjt_funcold4.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_funcold4._isnullterminated = false;
#line 16
            sjf_string(&sjt_funcold4);
#line 16
            if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 12
            sjf_string_copy(&g_monthstring, &sjt_funcold4);

            if (sjt_funcold4._refCount == 1) { sjf_string_destroy(&sjt_funcold4); }
;
        } else {
            if (underscore1 == 3) {
                sjs_string sjt_funcold5 = { -1 };

                sjt_funcold5._refCount = 1;
#line 12 "lib/sj-lib-common/string.sj"
                sjf_string_copy(&sjt_funcold5, &g_monthstring);
#line 12
                sjt_funcold5._refCount = 1;
#line 239 "learnxiny.sj"
                sjt_funcold5.offset = 0;
#line 239
                sjt_funcold5.count = 5;
#line 239
                sjt_funcold5.data._refCount = 1;
#line 239
                sjt_funcold5.data.v = &sjg_string45;
#line 239
                sjf_array_char(&sjt_funcold5.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_funcold5._isnullterminated = false;
#line 16
                sjf_string(&sjt_funcold5);
#line 16
                if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 12
                sjf_string_copy(&g_monthstring, &sjt_funcold5);

                if (sjt_funcold5._refCount == 1) { sjf_string_destroy(&sjt_funcold5); }
;
            } else {
                sjs_string sjt_funcold6 = { -1 };

                sjt_funcold6._refCount = 1;
#line 12 "lib/sj-lib-common/string.sj"
                sjf_string_copy(&sjt_funcold6, &g_monthstring);
#line 12
                sjt_funcold6._refCount = 1;
#line 240 "learnxiny.sj"
                sjt_funcold6.offset = 0;
#line 240
                sjt_funcold6.count = 16;
#line 240
                sjt_funcold6.data._refCount = 1;
#line 240
                sjt_funcold6.data.v = &sjg_string46;
#line 240
                sjf_array_char(&sjt_funcold6.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_funcold6._isnullterminated = false;
#line 16
                sjf_string(&sjt_funcold6);
#line 16
                if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 12
                sjf_string_copy(&g_monthstring, &sjt_funcold6);

                if (sjt_funcold6._refCount == 1) { sjf_string_destroy(&sjt_funcold6); }
;
            }
        }
    }

#line 236
    sjt_call95._refCount = 1;
#line 242
    sjt_call95.offset = 0;
#line 242
    sjt_call95.count = 20;
#line 242
    sjt_call95.data._refCount = 1;
#line 242
    sjt_call95.data.v = &sjg_string47;
#line 242
    sjf_array_char(&sjt_call95.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call95._isnullterminated = false;
#line 16
    sjf_string(&sjt_call95);
#line 242 "learnxiny.sj"
    sjt_parent81 = &sjt_call95;
#line 242
    sjt_functionParam185 = &g_monthstring;
#line 242
    sjf_string_add(sjt_parent81, sjt_functionParam185, &sjt_call94);
#line 242
    sjt_functionParam184 = &sjt_call94;
#line 242
    sjf_console_writeline(sjt_functionParam184);
#line 242
    sjt_call96._refCount = 1;
#line 248
    sjt_call96.offset = 0;
#line 248
    sjt_call96.count = 22;
#line 248
    sjt_call96.data._refCount = 1;
#line 248
    sjt_call96.data.v = &sjg_string48;
#line 248
    sjf_array_char(&sjt_call96.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call96._isnullterminated = false;
#line 16
    sjf_string(&sjt_call96);
#line 248 "learnxiny.sj"
    sjt_functionParam186 = &sjt_call96;
#line 248
    sjf_console_writeline(sjt_functionParam186);
#line 248
    g_trek._refCount = 1;
#line 269
    g_trek.cadence = 50;
#line 270
    g_trek.gear = 1;
#line 270
    g_trek.name._refCount = 1;
#line 271
    g_trek.name.offset = 0;
#line 271
    g_trek.name.count = 9;
#line 271
    g_trek.name.data._refCount = 1;
#line 271
    g_trek.name.data.v = &sjg_string49;
#line 271
    sjf_array_char(&g_trek.name.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_trek.name._isnullterminated = false;
#line 16
    sjf_string(&g_trek.name);
#line 272 "learnxiny.sj"
    g_trek._speed = 5;
#line 272
    sjf_bicycle(&g_trek);
#line 287
    sjt_parent82 = &g_trek;
#line 256
    sjt_functionParam187 = 3;
#line 256
    sjf_bicycle_speedup(sjt_parent82, sjt_functionParam187, &sjt_void1);
#line 279
    sjt_parent83 = &g_trek;
#line 257
    sjt_functionParam188 = 100;
#line 257
    sjf_bicycle_setcadence(sjt_parent83, sjt_functionParam188, &sjt_void2);
#line 257
    sjt_call98._refCount = 1;
#line 260
    sjt_call98.offset = 0;
#line 260
    sjt_call98.count = 11;
#line 260
    sjt_call98.data._refCount = 1;
#line 260
    sjt_call98.data.v = &sjg_string50;
#line 260
    sjf_array_char(&sjt_call98.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call98._isnullterminated = false;
#line 16
    sjf_string(&sjt_call98);
#line 260 "learnxiny.sj"
    sjt_parent84 = &sjt_call98;
#line 304
    sjt_parent99 = &g_trek;
#line 304
    sjf_bicycle_asstring(sjt_parent99, &sjt_call99);
#line 260
    sjt_functionParam190 = &sjt_call99;
#line 260
    sjf_string_add(sjt_parent84, sjt_functionParam190, &sjt_call97);
#line 260
    sjt_functionParam189 = &sjt_call97;
#line 260
    sjf_console_writeline(sjt_functionParam189);
#line 260
    g_firstday._refCount = 1;
#line 377
    g_firstday.day = g_day_monday;
#line 377
    sjf_enumtest(&g_firstday);
#line 358
    sjt_parent100 = &g_firstday;
#line 358
    sjf_enumtest_tellitlikeitis(sjt_parent100);
#line 358
    g_thirdday._refCount = 1;
#line 379
    g_thirdday.day = g_day_wednesday;
#line 379
    sjf_enumtest(&g_thirdday);
#line 358
    sjt_parent101 = &g_thirdday;
#line 358
    sjf_enumtest_tellitlikeitis(sjt_parent101);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_barstring._refCount == 1) { sjf_string_destroy(&g_barstring); }
;
    if (g_bazstring._refCount == 1) { sjf_string_destroy(&g_bazstring); }
;
    if (g_firstday._refCount == 1) { sjf_enumtest_destroy(&g_firstday); }
;
    if (g_foolist._refCount == 1) { sjf_array_i32_destroy(&g_foolist); }
;
    if (g_foostring._refCount == 1) { sjf_string_destroy(&g_foostring); }
;
    if (g_h._refCount == 1) { sjf_hash_string_i32_destroy(&g_h); }
;
    if (g_intarray1._refCount == 1) { sjf_array_i32_destroy(&g_intarray1); }
;
    if (g_intarray2._refCount == 1) { sjf_array_i32_destroy(&g_intarray2); }
;
    if (g_l._refCount == 1) { sjf_list_string_destroy(&g_l); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
    if (g_name._refCount == 1) { sjf_string_destroy(&g_name); }
;
    if (g_objarray._refCount == 1) { sjf_array_obj_destroy(&g_objarray); }
;
    if (g_plusconcatenated._refCount == 1) { sjf_string_destroy(&g_plusconcatenated); }
;
    if (g_thirdday._refCount == 1) { sjf_enumtest_destroy(&g_thirdday); }
;
    if (g_trek._refCount == 1) { sjf_bicycle_destroy(&g_trek); }
;
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
;
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
    if (sjt_call20._refCount == 1) { sjf_obj_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_obj_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_string_destroy(&sjt_call25); }
;
    if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
;
    if (sjt_call27._refCount == 1) { sjf_string_destroy(&sjt_call27); }
;
    if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
;
    if (sjt_call29._refCount == 1) { sjf_string_destroy(&sjt_call29); }
;
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call30._refCount == 1) { sjf_string_destroy(&sjt_call30); }
;
    if (sjt_call31._refCount == 1) { sjf_string_destroy(&sjt_call31); }
;
    if (sjt_call32._refCount == 1) { sjf_string_destroy(&sjt_call32); }
;
    if (sjt_call33._refCount == 1) { sjf_string_destroy(&sjt_call33); }
;
    if (sjt_call34._refCount == 1) { sjf_string_destroy(&sjt_call34); }
;
    if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
;
    if (sjt_call36._refCount == 1) { sjf_string_destroy(&sjt_call36); }
;
    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    if (sjt_call38._refCount == 1) { sjf_string_destroy(&sjt_call38); }
;
    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
;
    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
    if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
;
    if (sjt_call43._refCount == 1) { sjf_string_destroy(&sjt_call43); }
;
    if (sjt_call44._refCount == 1) { sjf_string_destroy(&sjt_call44); }
;
    if (sjt_call45._refCount == 1) { sjf_string_destroy(&sjt_call45); }
;
    if (sjt_call46._refCount == 1) { sjf_string_destroy(&sjt_call46); }
;
    if (sjt_call47._refCount == 1) { sjf_string_destroy(&sjt_call47); }
;
    if (sjt_call48._refCount == 1) { sjf_string_destroy(&sjt_call48); }
;
    if (sjt_call49._refCount == 1) { sjf_string_destroy(&sjt_call49); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
    if (sjt_call50._refCount == 1) { sjf_string_destroy(&sjt_call50); }
;
    if (sjt_call51._refCount == 1) { sjf_string_destroy(&sjt_call51); }
;
    if (sjt_call52._refCount == 1) { sjf_string_destroy(&sjt_call52); }
;
    if (sjt_call53._refCount == 1) { sjf_string_destroy(&sjt_call53); }
;
    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
;
    if (sjt_call55._refCount == 1) { sjf_string_destroy(&sjt_call55); }
;
    if (sjt_call56._refCount == 1) { sjf_string_destroy(&sjt_call56); }
;
    if (sjt_call57._refCount == 1) { sjf_string_destroy(&sjt_call57); }
;
    if (sjt_call58._refCount == 1) { sjf_string_destroy(&sjt_call58); }
;
    if (sjt_call59._refCount == 1) { sjf_string_destroy(&sjt_call59); }
;
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjt_call60._refCount == 1) { sjf_string_destroy(&sjt_call60); }
;
    if (sjt_call61._refCount == 1) { sjf_string_destroy(&sjt_call61); }
;
    if (sjt_call62._refCount == 1) { sjf_string_destroy(&sjt_call62); }
;
    if (sjt_call63._refCount == 1) { sjf_string_destroy(&sjt_call63); }
;
    if (sjt_call64._refCount == 1) { sjf_string_destroy(&sjt_call64); }
;
    if (sjt_call65._refCount == 1) { sjf_string_destroy(&sjt_call65); }
;
    if (sjt_call66._refCount == 1) { sjf_string_destroy(&sjt_call66); }
;
    if (sjt_call67._refCount == 1) { sjf_string_destroy(&sjt_call67); }
;
    if (sjt_call68._refCount == 1) { sjf_string_destroy(&sjt_call68); }
;
    if (sjt_call69._refCount == 1) { sjf_string_destroy(&sjt_call69); }
;
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    if (sjt_call70._refCount == 1) { sjf_string_destroy(&sjt_call70); }
;
    if (sjt_call71._refCount == 1) { sjf_string_destroy(&sjt_call71); }
;
    if (sjt_call72._refCount == 1) { sjf_string_destroy(&sjt_call72); }
;
    if (sjt_call73._refCount == 1) { sjf_string_destroy(&sjt_call73); }
;
    if (sjt_call74._refCount == 1) { sjf_string_destroy(&sjt_call74); }
;
    if (sjt_call75._refCount == 1) { sjf_string_destroy(&sjt_call75); }
;
    if (sjt_call76._refCount == 1) { sjf_string_destroy(&sjt_call76); }
;
    if (sjt_call77._refCount == 1) { sjf_string_destroy(&sjt_call77); }
;
    if (sjt_call78._refCount == 1) { sjf_string_destroy(&sjt_call78); }
;
    if (sjt_call79._refCount == 1) { sjf_string_destroy(&sjt_call79); }
;
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjt_call80._refCount == 1) { sjf_string_destroy(&sjt_call80); }
;
    if (sjt_call81._refCount == 1) { sjf_string_destroy(&sjt_call81); }
;
    if (sjt_call82._refCount == 1) { sjf_string_destroy(&sjt_call82); }
;
    if (sjt_call83._refCount == 1) { sjf_string_destroy(&sjt_call83); }
;
    if (sjt_call84._refCount == 1) { sjf_string_destroy(&sjt_call84); }
;
    if (sjt_call85._refCount == 1) { sjf_string_destroy(&sjt_call85); }
;
    if (sjt_call86._refCount == 1) { sjf_string_destroy(&sjt_call86); }
;
    if (sjt_call88._refCount == 1) { sjf_string_destroy(&sjt_call88); }
;
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
;
    if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
    if (sjt_call90._refCount == 1) { sjf_string_destroy(&sjt_call90); }
;
    if (sjt_call92._refCount == 1) { sjf_lambda1_destroy(&sjt_call92); }
;
    if (sjt_call94._refCount == 1) { sjf_string_destroy(&sjt_call94); }
;
    if (sjt_call95._refCount == 1) { sjf_string_destroy(&sjt_call95); }
;
    if (sjt_call96._refCount == 1) { sjf_string_destroy(&sjt_call96); }
;
    if (sjt_call97._refCount == 1) { sjf_string_destroy(&sjt_call97); }
;
    if (sjt_call98._refCount == 1) { sjf_string_destroy(&sjt_call98); }
;
    if (sjt_call99._refCount == 1) { sjf_string_destroy(&sjt_call99); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
