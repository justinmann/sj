#include <lib/sj-lib-common/common.h>

const char* sjg_string1 = "Hello World!";
const char* sjg_string10 = "Printing on a new line?\nNo Problem!";
const char* sjg_string11 = "Do you want to add a tab?\tNo Problem!";
const char* sjg_string12 = "Strings can ";
const char* sjg_string13 = "be concatenated ";
const char* sjg_string14 = "via + operator.";
const char* sjg_string15 = "intArray @ 0: ";
const char* sjg_string16 = "intArray2 @ 1: ";
const char* sjg_string17 = "hello";
const char* sjg_string18 = "bye";
const char* sjg_string19 = "bob";
const char* sjg_string2 = "Integer: ";
const char* sjg_string20 = "foo";
const char* sjg_string21 = "1+2 = ";
const char* sjg_string22 = "2-1 = ";
const char* sjg_string23 = "2*1 = ";
const char* sjg_string24 = "1/2 = ";
const char* sjg_string25 = "1/2.0 = ";
const char* sjg_string26 = "11%3 = ";
const char* sjg_string27 = "3 == 2? ";
const char* sjg_string28 = "3 != 2? ";
const char* sjg_string29 = "3 > 2? ";
const char* sjg_string3 = " Double: ";
const char* sjg_string30 = "3 < 2? ";
const char* sjg_string31 = "2 <= 2? ";
const char* sjg_string32 = "2 >= 2? ";
const char* sjg_string33 = "3 > 2 && 2 > 3? ";
const char* sjg_string34 = "3 > 2 || 2 > 3? ";
const char* sjg_string35 = "!(3 == 2)? ";
const char* sjg_string36 = "\n->Inc/Dec-rementation";
const char* sjg_string37 = "\n->Control Structures";
const char* sjg_string38 = "I also don't";
const char* sjg_string39 = "I don't";
const char* sjg_string4 = " Boolean: ";
const char* sjg_string40 = "I get printed";
const char* sjg_string41 = "fooWhile Value: ";
const char* sjg_string42 = "";
const char* sjg_string43 = "January";
const char* sjg_string44 = "February";
const char* sjg_string45 = "March";
const char* sjg_string46 = "Some other month";
const char* sjg_string47 = "Switch Case Result: ";
const char* sjg_string48 = "\n->Classes & Functions";
const char* sjg_string49 = "Bontrager";
const char* sjg_string5 = "false";
const char* sjg_string50 = "trek info: ";
const char* sjg_string51 = "gear: ";
const char* sjg_string52 = " cadence: ";
const char* sjg_string53 = " speed: ";
const char* sjg_string54 = " name: ";
const char* sjg_string55 = "Mondays are bad.";
const char* sjg_string56 = "Fridays are better.";
const char* sjg_string57 = "Weekends are best.";
const char* sjg_string58 = "Midweek days are so-so.";
const char* sjg_string6 = "true";
const char* sjg_string7 = "Hello ";
const char* sjg_string8 = "World";
const char* sjg_string9 = "My String Is Here!";

#define sjs_hash_type_bool_typeId 16
#define sjs_log_typeId 21
#define sjs_array_char_typeId 25
#define sjs_string_typeId 23
#define sjs_array_i32_typeId 42
#define sjs_obj_typeId 45
#define sjs_array_obj_typeId 46
#define sjs_array_string_typeId 51
#define sjs_list_string_typeId 50
#define sjs_hash_string_i32_typeId 57
#define cb_i32_void_typeId 64
#define cb_i32_void_heap_typeId 64
#define sjs_lambda1_typeId 65
#define sjs_bicycle_typeId 67
#define sjs_enumtest_typeId 71

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
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_obj {
    int _refCount;
};

struct td_sjs_array_obj {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_array_string {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_list_string {
    int _refCount;
    sjs_array_string array;
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
void* g_emptystringdata;
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
sjs_array_i32 g_intarray = { -1 };
sjs_array_i32 g_intarray2 = { -1 };
sjs_array_i32 g_intarray3 = { -1 };
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
int32_t result4;
bool result5;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call10 = { -1 };
sjs_string sjt_call100 = { -1 };
sjs_string sjt_call11 = { -1 };
sjs_string sjt_call12 = { -1 };
sjs_string sjt_call13 = { -1 };
sjs_string sjt_call14 = { -1 };
sjs_string sjt_call16 = { -1 };
sjs_string sjt_call17 = { -1 };
sjs_string sjt_call18 = { -1 };
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_array_i32 sjt_call20 = { -1 };
sjs_obj sjt_call21 = { -1 };
sjs_obj sjt_call22 = { -1 };
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
sjs_string sjt_call87 = { -1 };
sjs_string sjt_call89 = { -1 };
sjs_string sjt_call9 = { -1 };
sjs_string sjt_call90 = { -1 };
sjs_string sjt_call91 = { -1 };
sjs_lambda1 sjt_call93 = { -1 };
sjs_string sjt_call95 = { -1 };
sjs_string sjt_call96 = { -1 };
sjs_string sjt_call97 = { -1 };
sjs_string sjt_call98 = { -1 };
sjs_string sjt_call99 = { -1 };
int32_t sjt_capture3;
int32_option sjt_capture4;
int32_t sjt_cast2;
int32_t sjt_cast3;
int32_t sjt_forEnd3;
int32_t sjt_forStart3;
int32_t sjt_functionParam100;
int32_t sjt_functionParam101;
sjs_string* sjt_functionParam102 = 0;
sjs_string* sjt_functionParam103 = 0;
bool sjt_functionParam104;
sjs_string* sjt_functionParam105 = 0;
sjs_string* sjt_functionParam106 = 0;
bool sjt_functionParam107;
sjs_string* sjt_functionParam108 = 0;
sjs_string* sjt_functionParam109 = 0;
bool sjt_functionParam110;
sjs_string* sjt_functionParam111 = 0;
sjs_string* sjt_functionParam112 = 0;
bool sjt_functionParam113;
sjs_string* sjt_functionParam114 = 0;
sjs_string* sjt_functionParam115 = 0;
bool sjt_functionParam116;
sjs_string* sjt_functionParam117 = 0;
sjs_string* sjt_functionParam118 = 0;
bool sjt_functionParam119;
sjs_string* sjt_functionParam120 = 0;
sjs_string* sjt_functionParam121 = 0;
bool sjt_functionParam122;
sjs_string* sjt_functionParam123 = 0;
sjs_string* sjt_functionParam124 = 0;
bool sjt_functionParam125;
sjs_string* sjt_functionParam126 = 0;
sjs_string* sjt_functionParam127 = 0;
bool sjt_functionParam128;
sjs_string* sjt_functionParam129 = 0;
sjs_string* sjt_functionParam130 = 0;
int32_t sjt_functionParam131;
int32_t sjt_functionParam132;
sjs_string* sjt_functionParam133 = 0;
int32_t sjt_functionParam134;
int32_t sjt_functionParam135;
sjs_string* sjt_functionParam136 = 0;
sjs_string* sjt_functionParam143 = 0;
sjs_string* sjt_functionParam144 = 0;
int32_t sjt_functionParam145;
int32_t sjt_functionParam146;
sjs_string* sjt_functionParam15 = 0;
int32_t sjt_functionParam150;
int32_t sjt_functionParam151;
int32_t sjt_functionParam152;
int32_t sjt_functionParam153;
int32_t sjt_functionParam154;
int32_t sjt_functionParam155;
int32_t sjt_functionParam156;
int32_t sjt_functionParam157;
int32_t sjt_functionParam158;
int32_t sjt_functionParam159;
int32_t sjt_functionParam16;
int32_t sjt_functionParam160;
int32_t sjt_functionParam161;
int32_t sjt_functionParam162;
int32_t sjt_functionParam163;
int32_t sjt_functionParam164;
int32_t sjt_functionParam165;
int32_t sjt_functionParam166;
int32_t sjt_functionParam167;
int32_t sjt_functionParam17;
cb_i32_void sjt_functionParam170;
sjs_string* sjt_functionParam174 = 0;
sjs_string* sjt_functionParam175 = 0;
sjs_string* sjt_functionParam176 = 0;
int32_t sjt_functionParam177;
int32_t sjt_functionParam178;
sjs_string* sjt_functionParam179 = 0;
sjs_string* sjt_functionParam18 = 0;
sjs_string* sjt_functionParam180 = 0;
sjs_string* sjt_functionParam19 = 0;
double sjt_functionParam20;
sjs_string* sjt_functionParam21 = 0;
sjs_string* sjt_functionParam22 = 0;
bool sjt_functionParam23;
sjs_string* sjt_functionParam24 = 0;
sjs_string* sjt_functionParam25 = 0;
sjs_string* sjt_functionParam26 = 0;
sjs_string* sjt_functionParam27 = 0;
sjs_string* sjt_functionParam28 = 0;
sjs_string* sjt_functionParam31 = 0;
sjs_string* sjt_functionParam32 = 0;
sjs_string* sjt_functionParam33 = 0;
sjs_string* sjt_functionParam34 = 0;
sjs_string* sjt_functionParam35 = 0;
sjs_string* sjt_functionParam36 = 0;
sjs_string* sjt_functionParam37 = 0;
int32_t sjt_functionParam38;
int32_t sjt_functionParam39;
sjs_string* sjt_functionParam4 = 0;
int32_t sjt_functionParam40;
int32_t sjt_functionParam41;
int32_t sjt_functionParam42;
int32_t sjt_functionParam43;
int32_t sjt_functionParam44;
int32_t sjt_functionParam45;
int32_t sjt_functionParam46;
int32_t sjt_functionParam47;
sjs_obj* sjt_functionParam48 = 0;
int32_t sjt_functionParam49;
sjs_string* sjt_functionParam5 = 0;
sjs_obj* sjt_functionParam50 = 0;
sjs_string* sjt_functionParam51 = 0;
sjs_string* sjt_functionParam52 = 0;
int32_t sjt_functionParam53;
int32_t sjt_functionParam54;
int32_t sjt_functionParam55;
int32_t sjt_functionParam56;
int32_t sjt_functionParam57;
sjs_string* sjt_functionParam58 = 0;
sjs_string* sjt_functionParam59 = 0;
int32_t sjt_functionParam60;
int32_t sjt_functionParam61;
int32_t sjt_functionParam62;
sjs_string* sjt_functionParam68 = 0;
sjs_string* sjt_functionParam69 = 0;
int32_t sjt_functionParam70;
sjs_string* sjt_functionParam71 = 0;
int32_t sjt_functionParam72;
sjs_string* sjt_functionParam73 = 0;
int32_t sjt_functionParam74;
sjs_string* sjt_functionParam75 = 0;
int32_t sjt_functionParam76;
sjs_string* sjt_functionParam77 = 0;
sjs_string* sjt_functionParam79 = 0;
sjs_string* sjt_functionParam80 = 0;
int32_t sjt_functionParam81;
int32_t sjt_functionParam82;
sjs_string* sjt_functionParam83 = 0;
sjs_string* sjt_functionParam84 = 0;
int32_t sjt_functionParam85;
int32_t sjt_functionParam86;
sjs_string* sjt_functionParam87 = 0;
sjs_string* sjt_functionParam88 = 0;
int32_t sjt_functionParam89;
int32_t sjt_functionParam90;
sjs_string* sjt_functionParam91 = 0;
sjs_string* sjt_functionParam92 = 0;
int32_t sjt_functionParam93;
int32_t sjt_functionParam94;
sjs_string* sjt_functionParam95 = 0;
sjs_string* sjt_functionParam96 = 0;
double sjt_functionParam97;
sjs_string* sjt_functionParam98 = 0;
sjs_string* sjt_functionParam99 = 0;
sjs_string* sjt_parent11 = 0;
sjs_string* sjt_parent12 = 0;
sjs_string* sjt_parent13 = 0;
sjs_string* sjt_parent14 = 0;
sjs_string* sjt_parent15 = 0;
sjs_string* sjt_parent19 = 0;
sjs_string* sjt_parent20 = 0;
sjs_array_i32* sjt_parent21 = 0;
sjs_array_i32* sjt_parent22 = 0;
sjs_array_i32* sjt_parent23 = 0;
sjs_array_i32* sjt_parent24 = 0;
sjs_array_i32* sjt_parent25 = 0;
sjs_array_obj* sjt_parent26 = 0;
sjs_array_obj* sjt_parent27 = 0;
sjs_string* sjt_parent28 = 0;
sjs_array_i32* sjt_parent29 = 0;
sjs_array_i32* sjt_parent30 = 0;
sjs_string* sjt_parent31 = 0;
sjs_array_i32* sjt_parent32 = 0;
sjs_list_string* sjt_parent35 = 0;
sjs_list_string* sjt_parent36 = 0;
sjs_list_string* sjt_parent37 = 0;
sjs_hash_string_i32* sjt_parent38 = 0;
sjs_hash_string_i32* sjt_parent39 = 0;
sjs_hash_string_i32* sjt_parent40 = 0;
sjs_hash_string_i32* sjt_parent41 = 0;
sjs_string* sjt_parent43 = 0;
sjs_string* sjt_parent44 = 0;
sjs_string* sjt_parent45 = 0;
sjs_string* sjt_parent46 = 0;
sjs_string* sjt_parent47 = 0;
sjs_string* sjt_parent48 = 0;
sjs_string* sjt_parent49 = 0;
sjs_string* sjt_parent50 = 0;
sjs_string* sjt_parent51 = 0;
sjs_string* sjt_parent52 = 0;
sjs_string* sjt_parent53 = 0;
sjs_string* sjt_parent54 = 0;
sjs_string* sjt_parent55 = 0;
sjs_string* sjt_parent56 = 0;
sjs_string* sjt_parent57 = 0;
sjs_string* sjt_parent58 = 0;
sjs_array_i32* sjt_parent59 = 0;
sjs_array_i32* sjt_parent60 = 0;
sjs_array_i32* sjt_parent61 = 0;
sjs_array_i32* sjt_parent62 = 0;
sjs_array_i32* sjt_parent63 = 0;
sjs_array_i32* sjt_parent64 = 0;
sjs_array_i32* sjt_parent65 = 0;
sjs_array_i32* sjt_parent66 = 0;
sjs_array_i32* sjt_parent67 = 0;
sjs_array_i32* sjt_parent68 = 0;
sjs_string* sjt_parent69 = 0;
sjs_bicycle* sjt_parent70 = 0;
sjs_bicycle* sjt_parent71 = 0;
sjs_string* sjt_parent72 = 0;
sjs_bicycle* sjt_parent87 = 0;
sjs_enumtest* sjt_parent88 = 0;
sjs_enumtest* sjt_parent89 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
int32_t sjt_void1;
int32_t sjt_void2;
bool sjt_while1;
int32_t underscore1;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_init(sjs_array_i32* _parent, int32_t item, sjs_array_i32* _return);
void sjf_array_i32_init_heap(sjs_array_i32* _parent, int32_t item, sjs_array_i32** _return);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_obj(sjs_array_obj* _this);
void sjf_array_obj_copy(sjs_array_obj* _this, sjs_array_obj* _from);
void sjf_array_obj_destroy(sjs_array_obj* _this);
void sjf_array_obj_heap(sjs_array_obj* _this);
void sjf_array_obj_initat(sjs_array_obj* _parent, int32_t index, sjs_obj* item);
void sjf_array_string(sjs_array_string* _this);
void sjf_array_string_copy(sjs_array_string* _this, sjs_array_string* _from);
void sjf_array_string_destroy(sjs_array_string* _this);
void sjf_array_string_grow(sjs_array_string* _parent, int32_t newsize, sjs_array_string* _return);
void sjf_array_string_grow_heap(sjs_array_string* _parent, int32_t newsize, sjs_array_string** _return);
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
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 1 "lib/sj-lib-common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 333 "lib/sj-lib-common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !true && !false
#line 338
            char* p = (char*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 9 "lib/sj-lib-common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    char* p = (char*)_parent->data;
#line 14
    #line 8 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* newdata;

#line 135 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    _return->_refCount = 1;
#line 134
    _return->datasize = newsize;
#line 164
    _return->data = newdata;
#line 4
    _return->isglobal = false;
#line 164
    _return->count = _parent->count;
#line 164
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* newdata;

#line 135 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 162
    (*_return)->_refCount = 1;
#line 134
    (*_return)->datasize = newsize;
#line 164
    (*_return)->data = newdata;
#line 4
    (*_return)->isglobal = false;
#line 164
    (*_return)->count = _parent->count;
#line 164
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 36 "lib/sj-lib-common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    char* p = (char*)_parent->data;
#line 44
    #line 34 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
#line 271 "lib/sj-lib-common/array.sj"
    if (_parent->count != test->count) {
#line 272
        *_return = false;
#line 273
    }
#line 275
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
#line 276
    #line 270 "lib/sj-lib-common/array.sj"
(*_return) = result;
return;;      
}

void sjf_array_i32(sjs_array_i32* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 1 "lib/sj-lib-common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 333 "lib/sj-lib-common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !true && !false
#line 338
            int32_t* p = (int32_t*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

#line 75 "lib/sj-lib-common/array.sj"
    sjt_forStart4 = 0;
#line 75
    sjt_forEnd4 = _parent->count;
#line 75
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        int32_t sjt_functionParam168;
        int32_t sjt_functionParam169;

#line 75 "lib/sj-lib-common/array.sj"
        sjt_functionParam169 = i;
#line 75
        sjf_array_i32_getat(_parent, sjt_functionParam169, &sjt_functionParam168);
#line 75
        cb._cb(cb._parent, sjt_functionParam168);
#line 75
        i++;
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 9 "lib/sj-lib-common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    int32_t* p = (int32_t*)_parent->data;
#line 14
    #line 8 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_i32_init(sjs_array_i32* _parent, int32_t item, sjs_array_i32* _return) {
#line 20 "lib/sj-lib-common/array.sj"
    if (0 != _parent->count) {
#line 21
        halt("init: can only initialize a completely uninitialized list\n");     
#line 22
    }
#line 24
    int32_t* p = (int32_t*)_parent->data;
#line 25
    int count = _parent->datasize;
#line 26
    for (int i = 0; i < count; i++) {
#line 27
        #line 18 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 28
    }
#line 29
    _parent->count = _parent->datasize;  
#line 29
    _return->_refCount = 1;
#line 31
    sjf_array_i32_copy(_return, _parent);
}

void sjf_array_i32_init_heap(sjs_array_i32* _parent, int32_t item, sjs_array_i32** _return) {
#line 20 "lib/sj-lib-common/array.sj"
    if (0 != _parent->count) {
#line 21
        halt("init: can only initialize a completely uninitialized list\n");     
#line 22
    }
#line 24
    int32_t* p = (int32_t*)_parent->data;
#line 25
    int count = _parent->datasize;
#line 26
    for (int i = 0; i < count; i++) {
#line 27
        #line 18 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 28
    }
#line 29
    _parent->count = _parent->datasize;  
#line 29
    (*_return) = (sjs_array_i32*)malloc(sizeof(sjs_array_i32));
#line 29
    (*_return)->_refCount = 1;
#line 31
    sjf_array_i32_copy((*_return), _parent);
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 36 "lib/sj-lib-common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    int32_t* p = (int32_t*)_parent->data;
#line 44
    #line 34 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 51 "lib/sj-lib-common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 52
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
#line 53
    }
#line 55
    int32_t* p = (int32_t*)_parent->data;
#line 56
    ;
#line 57
    #line 49 "lib/sj-lib-common/array.sj"
p[index] = item;
;
}

void sjf_array_obj(sjs_array_obj* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_obj) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_obj_copy(sjs_array_obj* _this, sjs_array_obj* _from) {
#line 1 "lib/sj-lib-common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_obj_destroy(sjs_array_obj* _this) {
#line 333 "lib/sj-lib-common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !true
#line 338
            sjs_obj* p = (sjs_obj*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_obj_heap(sjs_array_obj* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_obj) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_obj_initat(sjs_array_obj* _parent, int32_t index, sjs_obj* item) {
#line 36 "lib/sj-lib-common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    sjs_obj* p = (sjs_obj*)_parent->data;
#line 44
    p[index]._refCount = 1;
#line 34 "lib/sj-lib-common/array.sj"
sjf_obj_copy(&p[index], item);
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_string(sjs_array_string* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_string) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_string_copy(sjs_array_string* _this, sjs_array_string* _from) {
#line 1 "lib/sj-lib-common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_string_destroy(sjs_array_string* _this) {
#line 333 "lib/sj-lib-common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !true
#line 338
            sjs_string* p = (sjs_string*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_string_grow(sjs_array_string* _parent, int32_t newsize, sjs_array_string* _return) {
    void* newdata;

#line 135 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_string))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        sjs_string* p = (sjs_string*)_parent->data;
#line 151
        sjs_string* newp = (sjs_string*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if false
#line 156
        memcpy(newp, p, sizeof(sjs_string) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            newp[i]._refCount = 1;
#line 136 "lib/sj-lib-common/array.sj"
sjf_string_copy(&newp[i], &p[i]);
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    _return->_refCount = 1;
#line 134
    _return->datasize = newsize;
#line 164
    _return->data = newdata;
#line 4
    _return->isglobal = false;
#line 164
    _return->count = _parent->count;
#line 164
    sjf_array_string(_return);
}

void sjf_array_string_grow_heap(sjs_array_string* _parent, int32_t newsize, sjs_array_string** _return) {
    void* newdata;

#line 135 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_string))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        sjs_string* p = (sjs_string*)_parent->data;
#line 151
        sjs_string* newp = (sjs_string*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if false
#line 156
        memcpy(newp, p, sizeof(sjs_string) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            newp[i]._refCount = 1;
#line 136 "lib/sj-lib-common/array.sj"
sjf_string_copy(&newp[i], &p[i]);
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    (*_return) = (sjs_array_string*)malloc(sizeof(sjs_array_string));
#line 162
    (*_return)->_refCount = 1;
#line 134
    (*_return)->datasize = newsize;
#line 164
    (*_return)->data = newdata;
#line 4
    (*_return)->isglobal = false;
#line 164
    (*_return)->count = _parent->count;
#line 164
    sjf_array_string_heap((*_return));
}

void sjf_array_string_heap(sjs_array_string* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_string) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_string_initat(sjs_array_string* _parent, int32_t index, sjs_string* item) {
#line 36 "lib/sj-lib-common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    sjs_string* p = (sjs_string*)_parent->data;
#line 44
    p[index]._refCount = 1;
#line 34 "lib/sj-lib-common/array.sj"
sjf_string_copy(&p[index], item);
;
#line 45
    _parent->count = index + 1;
}

void sjf_bicycle(sjs_bicycle* _this) {
}

void sjf_bicycle_asstring(sjs_bicycle* _parent, sjs_string* _return) {
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
    sjs_string sjt_call113 = { -1 };
    sjs_string* sjt_functionParam181 = 0;
    int32_t sjt_functionParam182;
    int32_t sjt_functionParam183;
    sjs_string* sjt_functionParam184 = 0;
    sjs_string* sjt_functionParam185 = 0;
    int32_t sjt_functionParam186;
    int32_t sjt_functionParam187;
    sjs_string* sjt_functionParam188 = 0;
    sjs_string* sjt_functionParam189 = 0;
    int32_t sjt_functionParam190;
    int32_t sjt_functionParam191;
    sjs_string* sjt_functionParam192 = 0;
    sjs_string* sjt_functionParam193 = 0;
    sjs_string* sjt_parent73 = 0;
    sjs_string* sjt_parent74 = 0;
    sjs_string* sjt_parent75 = 0;
    sjs_string* sjt_parent76 = 0;
    sjs_string* sjt_parent77 = 0;
    sjs_string* sjt_parent78 = 0;
    sjs_string* sjt_parent79 = 0;

    sjt_call107._refCount = 1;
#line 311 "learnxiny.sj"
    sjt_call107.count = 6;
#line 311
    sjt_call107.data._refCount = 1;
#line 311
    sjt_call107.data.datasize = 6;
#line 311
    sjt_call107.data.data = (void*)sjg_string51;
#line 311
    sjt_call107.data.isglobal = true;
#line 311
    sjt_call107.data.count = 6;
#line 311
    sjf_array_char(&sjt_call107.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call107._isnullterminated = false;
#line 14
    sjf_string(&sjt_call107);
#line 311 "learnxiny.sj"
    sjt_parent79 = &sjt_call107;
#line 311
    sjt_functionParam182 = _parent->gear;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam183 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam182, sjt_functionParam183, &sjt_call108);
#line 311 "learnxiny.sj"
    sjt_functionParam181 = &sjt_call108;
#line 311
    sjf_string_add(sjt_parent79, sjt_functionParam181, &sjt_call106);
#line 311
    sjt_parent78 = &sjt_call106;
#line 311
    sjt_call109._refCount = 1;
#line 311
    sjt_call109.count = 10;
#line 311
    sjt_call109.data._refCount = 1;
#line 311
    sjt_call109.data.datasize = 10;
#line 311
    sjt_call109.data.data = (void*)sjg_string52;
#line 311
    sjt_call109.data.isglobal = true;
#line 311
    sjt_call109.data.count = 10;
#line 311
    sjf_array_char(&sjt_call109.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call109._isnullterminated = false;
#line 14
    sjf_string(&sjt_call109);
#line 311 "learnxiny.sj"
    sjt_functionParam184 = &sjt_call109;
#line 311
    sjf_string_add(sjt_parent78, sjt_functionParam184, &sjt_call105);
#line 311
    sjt_parent77 = &sjt_call105;
#line 311
    sjt_functionParam186 = _parent->cadence;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam187 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam186, sjt_functionParam187, &sjt_call110);
#line 311 "learnxiny.sj"
    sjt_functionParam185 = &sjt_call110;
#line 311
    sjf_string_add(sjt_parent77, sjt_functionParam185, &sjt_call104);
#line 311
    sjt_parent76 = &sjt_call104;
#line 311
    sjt_call111._refCount = 1;
#line 311
    sjt_call111.count = 8;
#line 311
    sjt_call111.data._refCount = 1;
#line 311
    sjt_call111.data.datasize = 8;
#line 311
    sjt_call111.data.data = (void*)sjg_string53;
#line 311
    sjt_call111.data.isglobal = true;
#line 311
    sjt_call111.data.count = 8;
#line 311
    sjf_array_char(&sjt_call111.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call111._isnullterminated = false;
#line 14
    sjf_string(&sjt_call111);
#line 311 "learnxiny.sj"
    sjt_functionParam188 = &sjt_call111;
#line 311
    sjf_string_add(sjt_parent76, sjt_functionParam188, &sjt_call103);
#line 311
    sjt_parent75 = &sjt_call103;
#line 311
    sjt_functionParam190 = _parent->_speed;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam191 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam190, sjt_functionParam191, &sjt_call112);
#line 311 "learnxiny.sj"
    sjt_functionParam189 = &sjt_call112;
#line 311
    sjf_string_add(sjt_parent75, sjt_functionParam189, &sjt_call102);
#line 311
    sjt_parent74 = &sjt_call102;
#line 311
    sjt_call113._refCount = 1;
#line 311
    sjt_call113.count = 7;
#line 311
    sjt_call113.data._refCount = 1;
#line 311
    sjt_call113.data.datasize = 7;
#line 311
    sjt_call113.data.data = (void*)sjg_string54;
#line 311
    sjt_call113.data.isglobal = true;
#line 311
    sjt_call113.data.count = 7;
#line 311
    sjf_array_char(&sjt_call113.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call113._isnullterminated = false;
#line 14
    sjf_string(&sjt_call113);
#line 311 "learnxiny.sj"
    sjt_functionParam192 = &sjt_call113;
#line 311
    sjf_string_add(sjt_parent74, sjt_functionParam192, &sjt_call101);
#line 311
    sjt_parent73 = &sjt_call101;
#line 311
    sjt_functionParam193 = &_parent->name;
#line 311
    sjf_string_add(sjt_parent73, sjt_functionParam193, _return);

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
    if (sjt_call113._refCount == 1) { sjf_string_destroy(&sjt_call113); }
;
}

void sjf_bicycle_asstring_heap(sjs_bicycle* _parent, sjs_string** _return) {
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
    sjs_string sjt_call126 = { -1 };
    sjs_string* sjt_functionParam194 = 0;
    int32_t sjt_functionParam195;
    int32_t sjt_functionParam196;
    sjs_string* sjt_functionParam197 = 0;
    sjs_string* sjt_functionParam198 = 0;
    int32_t sjt_functionParam199;
    int32_t sjt_functionParam200;
    sjs_string* sjt_functionParam201 = 0;
    sjs_string* sjt_functionParam202 = 0;
    int32_t sjt_functionParam203;
    int32_t sjt_functionParam204;
    sjs_string* sjt_functionParam205 = 0;
    sjs_string* sjt_functionParam206 = 0;
    sjs_string* sjt_parent80 = 0;
    sjs_string* sjt_parent81 = 0;
    sjs_string* sjt_parent82 = 0;
    sjs_string* sjt_parent83 = 0;
    sjs_string* sjt_parent84 = 0;
    sjs_string* sjt_parent85 = 0;
    sjs_string* sjt_parent86 = 0;

    sjt_call120._refCount = 1;
#line 311 "learnxiny.sj"
    sjt_call120.count = 6;
#line 311
    sjt_call120.data._refCount = 1;
#line 311
    sjt_call120.data.datasize = 6;
#line 311
    sjt_call120.data.data = (void*)sjg_string51;
#line 311
    sjt_call120.data.isglobal = true;
#line 311
    sjt_call120.data.count = 6;
#line 311
    sjf_array_char(&sjt_call120.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call120._isnullterminated = false;
#line 14
    sjf_string(&sjt_call120);
#line 311 "learnxiny.sj"
    sjt_parent86 = &sjt_call120;
#line 311
    sjt_functionParam195 = _parent->gear;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam196 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam195, sjt_functionParam196, &sjt_call121);
#line 311 "learnxiny.sj"
    sjt_functionParam194 = &sjt_call121;
#line 311
    sjf_string_add(sjt_parent86, sjt_functionParam194, &sjt_call119);
#line 311
    sjt_parent85 = &sjt_call119;
#line 311
    sjt_call122._refCount = 1;
#line 311
    sjt_call122.count = 10;
#line 311
    sjt_call122.data._refCount = 1;
#line 311
    sjt_call122.data.datasize = 10;
#line 311
    sjt_call122.data.data = (void*)sjg_string52;
#line 311
    sjt_call122.data.isglobal = true;
#line 311
    sjt_call122.data.count = 10;
#line 311
    sjf_array_char(&sjt_call122.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call122._isnullterminated = false;
#line 14
    sjf_string(&sjt_call122);
#line 311 "learnxiny.sj"
    sjt_functionParam197 = &sjt_call122;
#line 311
    sjf_string_add(sjt_parent85, sjt_functionParam197, &sjt_call118);
#line 311
    sjt_parent84 = &sjt_call118;
#line 311
    sjt_functionParam199 = _parent->cadence;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam200 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam199, sjt_functionParam200, &sjt_call123);
#line 311 "learnxiny.sj"
    sjt_functionParam198 = &sjt_call123;
#line 311
    sjf_string_add(sjt_parent84, sjt_functionParam198, &sjt_call117);
#line 311
    sjt_parent83 = &sjt_call117;
#line 311
    sjt_call124._refCount = 1;
#line 311
    sjt_call124.count = 8;
#line 311
    sjt_call124.data._refCount = 1;
#line 311
    sjt_call124.data.datasize = 8;
#line 311
    sjt_call124.data.data = (void*)sjg_string53;
#line 311
    sjt_call124.data.isglobal = true;
#line 311
    sjt_call124.data.count = 8;
#line 311
    sjf_array_char(&sjt_call124.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call124._isnullterminated = false;
#line 14
    sjf_string(&sjt_call124);
#line 311 "learnxiny.sj"
    sjt_functionParam201 = &sjt_call124;
#line 311
    sjf_string_add(sjt_parent83, sjt_functionParam201, &sjt_call116);
#line 311
    sjt_parent82 = &sjt_call116;
#line 311
    sjt_functionParam203 = _parent->_speed;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam204 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam203, sjt_functionParam204, &sjt_call125);
#line 311 "learnxiny.sj"
    sjt_functionParam202 = &sjt_call125;
#line 311
    sjf_string_add(sjt_parent82, sjt_functionParam202, &sjt_call115);
#line 311
    sjt_parent81 = &sjt_call115;
#line 311
    sjt_call126._refCount = 1;
#line 311
    sjt_call126.count = 7;
#line 311
    sjt_call126.data._refCount = 1;
#line 311
    sjt_call126.data.datasize = 7;
#line 311
    sjt_call126.data.data = (void*)sjg_string54;
#line 311
    sjt_call126.data.isglobal = true;
#line 311
    sjt_call126.data.count = 7;
#line 311
    sjf_array_char(&sjt_call126.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call126._isnullterminated = false;
#line 14
    sjf_string(&sjt_call126);
#line 311 "learnxiny.sj"
    sjt_functionParam205 = &sjt_call126;
#line 311
    sjf_string_add(sjt_parent81, sjt_functionParam205, &sjt_call114);
#line 311
    sjt_parent80 = &sjt_call114;
#line 311
    sjt_functionParam206 = &_parent->name;
#line 311
    sjf_string_add_heap(sjt_parent80, sjt_functionParam206, _return);

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
    if (sjt_call126._refCount == 1) { sjf_string_destroy(&sjt_call126); }
;
}

void sjf_bicycle_copy(sjs_bicycle* _this, sjs_bicycle* _from) {
#line 273 "learnxiny.sj"
    _this->cadence = _from->cadence;
#line 273
    _this->gear = _from->gear;
#line 273
    _this->name._refCount = 1;
#line 273
    sjf_string_copy(&_this->name, &_from->name);
#line 273
    _this->_speed = _from->_speed;
}

void sjf_bicycle_destroy(sjs_bicycle* _this) {
    if (_this->name._refCount == 1) { sjf_string_destroy(&_this->name); }
;
}

void sjf_bicycle_heap(sjs_bicycle* _this) {
}

void sjf_bicycle_setcadence(sjs_bicycle* _parent, int32_t newvalue, int32_t* _return) {
#line 285 "learnxiny.sj"
    _parent->cadence = newvalue;
#line 286
    (*_return) = _parent->cadence;
}

void sjf_bicycle_speedup(sjs_bicycle* _parent, int32_t increment, int32_t* _return) {
#line 294 "learnxiny.sj"
    _parent->_speed = _parent->_speed + increment;
#line 294
    (*_return) = _parent->_speed;
}

void sjf_bool_asstring(bool val, sjs_string* _return) {
    if (val) {
        _return->_refCount = 1;
#line 3 "lib/sj-lib-common/bool.sj"
        _return->count = 4;
#line 3
        _return->data._refCount = 1;
#line 3
        _return->data.datasize = 4;
#line 3
        _return->data.data = (void*)sjg_string6;
#line 3
        _return->data.isglobal = true;
#line 3
        _return->data.count = 4;
#line 3
        sjf_array_char(&_return->data);
#line 14 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        _return->_refCount = 1;
#line 5 "lib/sj-lib-common/bool.sj"
        _return->count = 5;
#line 5
        _return->data._refCount = 1;
#line 5
        _return->data.datasize = 5;
#line 5
        _return->data.data = (void*)sjg_string5;
#line 5
        _return->data.isglobal = true;
#line 5
        _return->data.count = 5;
#line 5
        sjf_array_char(&_return->data);
#line 14 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    }
}

void sjf_bool_asstring_heap(bool val, sjs_string** _return) {
    if (val) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 3 "lib/sj-lib-common/bool.sj"
        (*_return)->count = 4;
#line 3
        (*_return)->data._refCount = 1;
#line 3
        (*_return)->data.datasize = 4;
#line 3
        (*_return)->data.data = (void*)sjg_string6;
#line 3
        (*_return)->data.isglobal = true;
#line 3
        (*_return)->data.count = 4;
#line 3
        sjf_array_char(&(*_return)->data);
#line 14 "lib/sj-lib-common/string.sj"
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    } else {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 5 "lib/sj-lib-common/bool.sj"
        (*_return)->count = 5;
#line 5
        (*_return)->data._refCount = 1;
#line 5
        (*_return)->data.datasize = 5;
#line 5
        (*_return)->data.data = (void*)sjg_string5;
#line 5
        (*_return)->data.isglobal = true;
#line 5
        (*_return)->data.count = 5;
#line 5
        sjf_array_char(&(*_return)->data);
#line 14 "lib/sj-lib-common/string.sj"
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    }
}

void sjf_console_readline(sjs_string* _return) {
    void* data;
    int32_t datasize;

#line 17 "lib/sj-lib-common/console.sj"
    data = 0;
#line 18
    datasize = 1024;
#line 20
    char* str = (char*)malloc(datasize);
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
            str[index] = ch;
#line 27
            index++;
#line 28
            if (index >= datasize) {
#line 29
                datasize *= 2;
#line 30
                str = (char*)realloc(str, datasize);
#line 31
            }
#line 32
        }
#line 33
    } while (ch != '\n');
#line 35
    data = (void*)str;
#line 36
    datasize = index;
#line 36
    _return->_refCount = 1;
#line 39
    _return->count = datasize;
#line 39
    _return->data._refCount = 1;
#line 39
    _return->data.datasize = datasize;
#line 39
    _return->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    _return->data.isglobal = false;
#line 39 "lib/sj-lib-common/console.sj"
    _return->data.count = datasize;
#line 39
    sjf_array_char(&_return->data);
#line 14 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_console_readline_heap(sjs_string** _return) {
    void* data;
    int32_t datasize;

#line 17 "lib/sj-lib-common/console.sj"
    data = 0;
#line 18
    datasize = 1024;
#line 20
    char* str = (char*)malloc(datasize);
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
            str[index] = ch;
#line 27
            index++;
#line 28
            if (index >= datasize) {
#line 29
                datasize *= 2;
#line 30
                str = (char*)realloc(str, datasize);
#line 31
            }
#line 32
        }
#line 33
    } while (ch != '\n');
#line 35
    data = (void*)str;
#line 36
    datasize = index;
#line 36
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 36
    (*_return)->_refCount = 1;
#line 39
    (*_return)->count = datasize;
#line 39
    (*_return)->data._refCount = 1;
#line 39
    (*_return)->data.datasize = datasize;
#line 39
    (*_return)->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    (*_return)->data.isglobal = false;
#line 39 "lib/sj-lib-common/console.sj"
    (*_return)->data.count = datasize;
#line 39
    sjf_array_char(&(*_return)->data);
#line 14 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_console_write(sjs_string* data) {
    sjs_string* sjt_parent16 = 0;

#line 2 "lib/sj-lib-common/console.sj"
    sjt_parent16 = data;
#line 2
    sjf_string_nullterminate(sjt_parent16);
#line 5
    printf("%s", (char*)data->data.data);
}

void sjf_console_writeline(sjs_string* data) {
    sjs_string* sjt_parent3 = 0;

#line 9 "lib/sj-lib-common/console.sj"
    sjt_parent3 = data;
#line 9
    sjf_string_nullterminate(sjt_parent3);
#line 12
    printf("%s\n", (char*)data->data.data);
}

void sjf_enumtest(sjs_enumtest* _this) {
}

void sjf_enumtest_copy(sjs_enumtest* _this, sjs_enumtest* _from) {
#line 360 "learnxiny.sj"
    _this->day = _from->day;
}

void sjf_enumtest_destroy(sjs_enumtest* _this) {
}

void sjf_enumtest_heap(sjs_enumtest* _this) {
}

void sjf_enumtest_tellitlikeitis(sjs_enumtest* _parent) {
    int32_t underscore2;

#line 365 "learnxiny.sj"
    underscore2 = _parent->day;
    if (underscore2 == g_day_monday) {
        sjs_string sjt_call127 = { -1 };
        sjs_string* sjt_functionParam207 = 0;

        sjt_call127._refCount = 1;
#line 367 "learnxiny.sj"
        sjt_call127.count = 16;
#line 367
        sjt_call127.data._refCount = 1;
#line 367
        sjt_call127.data.datasize = 16;
#line 367
        sjt_call127.data.data = (void*)sjg_string55;
#line 367
        sjt_call127.data.isglobal = true;
#line 367
        sjt_call127.data.count = 16;
#line 367
        sjf_array_char(&sjt_call127.data);
#line 14 "lib/sj-lib-common/string.sj"
        sjt_call127._isnullterminated = false;
#line 14
        sjf_string(&sjt_call127);
#line 367 "learnxiny.sj"
        sjt_functionParam207 = &sjt_call127;
#line 367
        sjf_console_writeline(sjt_functionParam207);

        if (sjt_call127._refCount == 1) { sjf_string_destroy(&sjt_call127); }
;
    } else {
        if (underscore2 == g_day_friday) {
            sjs_string sjt_call128 = { -1 };
            sjs_string* sjt_functionParam208 = 0;

            sjt_call128._refCount = 1;
#line 370 "learnxiny.sj"
            sjt_call128.count = 19;
#line 370
            sjt_call128.data._refCount = 1;
#line 370
            sjt_call128.data.datasize = 19;
#line 370
            sjt_call128.data.data = (void*)sjg_string56;
#line 370
            sjt_call128.data.isglobal = true;
#line 370
            sjt_call128.data.count = 19;
#line 370
            sjf_array_char(&sjt_call128.data);
#line 14 "lib/sj-lib-common/string.sj"
            sjt_call128._isnullterminated = false;
#line 14
            sjf_string(&sjt_call128);
#line 370 "learnxiny.sj"
            sjt_functionParam208 = &sjt_call128;
#line 370
            sjf_console_writeline(sjt_functionParam208);

            if (sjt_call128._refCount == 1) { sjf_string_destroy(&sjt_call128); }
;
        } else {
            if ((underscore2 == g_day_saturday) || (underscore2 == g_day_sunday)) {
                sjs_string sjt_call129 = { -1 };
                sjs_string* sjt_functionParam209 = 0;

                sjt_call129._refCount = 1;
#line 373 "learnxiny.sj"
                sjt_call129.count = 18;
#line 373
                sjt_call129.data._refCount = 1;
#line 373
                sjt_call129.data.datasize = 18;
#line 373
                sjt_call129.data.data = (void*)sjg_string57;
#line 373
                sjt_call129.data.isglobal = true;
#line 373
                sjt_call129.data.count = 18;
#line 373
                sjf_array_char(&sjt_call129.data);
#line 14 "lib/sj-lib-common/string.sj"
                sjt_call129._isnullterminated = false;
#line 14
                sjf_string(&sjt_call129);
#line 373 "learnxiny.sj"
                sjt_functionParam209 = &sjt_call129;
#line 373
                sjf_console_writeline(sjt_functionParam209);

                if (sjt_call129._refCount == 1) { sjf_string_destroy(&sjt_call129); }
;
            } else {
                sjs_string sjt_call130 = { -1 };
                sjs_string* sjt_functionParam210 = 0;

                sjt_call130._refCount = 1;
#line 376 "learnxiny.sj"
                sjt_call130.count = 23;
#line 376
                sjt_call130.data._refCount = 1;
#line 376
                sjt_call130.data.datasize = 23;
#line 376
                sjt_call130.data.data = (void*)sjg_string58;
#line 376
                sjt_call130.data.isglobal = true;
#line 376
                sjt_call130.data.count = 23;
#line 376
                sjf_array_char(&sjt_call130.data);
#line 14 "lib/sj-lib-common/string.sj"
                sjt_call130._isnullterminated = false;
#line 14
                sjf_string(&sjt_call130);
#line 376 "learnxiny.sj"
                sjt_functionParam210 = &sjt_call130;
#line 376
                sjf_console_writeline(sjt_functionParam210);

                if (sjt_call130._refCount == 1) { sjf_string_destroy(&sjt_call130); }
;
            }
        }
    }
}

void sjf_f64_asstring(double val, sjs_string* _return) {
    int32_t count;
    void* data;

#line 2 "lib/sj-lib-common/f64.sj"
    count = 0;
#line 3
    data = 0;
#line 5
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 6
    int* refcount = (int*)data - 1;
#line 7
    *refcount = 1;
#line 8
    snprintf((char*)data, 256, "%lf", val);
#line 9
    count = (int)strlen((char*)data);
#line 9
    _return->_refCount = 1;
#line 11
    _return->count = count;
#line 11
    _return->data._refCount = 1;
#line 11
    _return->data.datasize = count;
#line 11
    _return->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    _return->data.isglobal = false;
#line 11 "lib/sj-lib-common/f64.sj"
    _return->data.count = count;
#line 11
    sjf_array_char(&_return->data);
#line 14 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_f64_asstring_heap(double val, sjs_string** _return) {
    int32_t count;
    void* data;

#line 2 "lib/sj-lib-common/f64.sj"
    count = 0;
#line 3
    data = 0;
#line 5
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 6
    int* refcount = (int*)data - 1;
#line 7
    *refcount = 1;
#line 8
    snprintf((char*)data, 256, "%lf", val);
#line 9
    count = (int)strlen((char*)data);
#line 9
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 9
    (*_return)->_refCount = 1;
#line 11
    (*_return)->count = count;
#line 11
    (*_return)->data._refCount = 1;
#line 11
    (*_return)->data.datasize = count;
#line 11
    (*_return)->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    (*_return)->data.isglobal = false;
#line 11 "lib/sj-lib-common/f64.sj"
    (*_return)->data.count = count;
#line 11
    sjf_array_char(&(*_return)->data);
#line 14 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
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
    void* data;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    data = 0;
#line 26
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)data + 128;
#line 31
    char *tp = (char*)data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    count = len;
#line 63
    _return->_refCount = 1;
#line 65
    _return->count = count;
#line 65
    _return->data._refCount = 1;
#line 65
    _return->data.datasize = 256;
#line 65
    _return->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    _return->data.isglobal = false;
#line 65 "lib/sj-lib-common/i32.sj"
    _return->data.count = count;
#line 65
    sjf_array_char(&_return->data);
#line 14 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* data;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    data = 0;
#line 26
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)data + 128;
#line 31
    char *tp = (char*)data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    count = len;
#line 63
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 63
    (*_return)->_refCount = 1;
#line 65
    (*_return)->count = count;
#line 65
    (*_return)->data._refCount = 1;
#line 65
    (*_return)->data.datasize = 256;
#line 65
    (*_return)->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    (*_return)->data.isglobal = false;
#line 65 "lib/sj-lib-common/i32.sj"
    (*_return)->data.count = count;
#line 65
    sjf_array_char(&(*_return)->data);
#line 14 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
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
    sjs_string sjt_call94 = { -1 };
    sjs_string* sjt_functionParam171 = 0;
    int32_t sjt_functionParam172;
    int32_t sjt_functionParam173;

#line 227 "learnxiny.sj"
    sjt_functionParam172 = _1;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam173 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam172, sjt_functionParam173, &sjt_call94);
#line 228 "learnxiny.sj"
    sjt_functionParam171 = &sjt_call94;
#line 228
    sjf_console_writeline(sjt_functionParam171);

    if (sjt_call94._refCount == 1) { sjf_string_destroy(&sjt_call94); }
;
}

void sjf_list_string(sjs_list_string* _this) {
}

void sjf_list_string_add(sjs_list_string* _parent, sjs_string* item) {
    sjs_array_string sjt_funcold2 = { -1 };
    int32_t sjt_functionParam66;
    sjs_string* sjt_functionParam67 = 0;
    sjs_array_string* sjt_parent34 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam63;
        int32_t sjt_functionParam64;
        int32_t sjt_functionParam65;
        sjs_array_string* sjt_parent33 = 0;

        sjt_funcold2._refCount = 1;
#line 134 "lib/sj-lib-common/array.sj"
        sjf_array_string_copy(&sjt_funcold2, &_parent->array);
#line 134
        sjt_parent33 = &_parent->array;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam64 = 10;
#line 46
        sjt_functionParam65 = (&_parent->array)->datasize * 2;
#line 46
        sjf_i32_max(sjt_functionParam64, sjt_functionParam65, &sjt_functionParam63);
#line 46
        sjf_array_string_grow(sjt_parent33, sjt_functionParam63, &sjt_funcold2);
#line 46
        if (_parent->array._refCount == 1) { sjf_array_string_destroy(&_parent->array); }
;
#line 134 "lib/sj-lib-common/array.sj"
        sjf_array_string_copy(&_parent->array, &sjt_funcold2);
    }

#line 34 "lib/sj-lib-common/array.sj"
    sjt_parent34 = &_parent->array;
#line 50 "lib/sj-lib-common/list.sj"
    sjt_functionParam66 = (&_parent->array)->count;
#line 44
    sjt_functionParam67 = item;
#line 44
    sjf_array_string_initat(sjt_parent34, sjt_functionParam66, sjt_functionParam67);

    if (sjt_funcold2._refCount == 1) { sjf_array_string_destroy(&sjt_funcold2); }
;
}

void sjf_list_string_copy(sjs_list_string* _this, sjs_list_string* _from) {
    _this->array._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_string_copy(&_this->array, &_from->array);
}

void sjf_list_string_destroy(sjs_list_string* _this) {
    if (_this->array._refCount == 1) { sjf_array_string_destroy(&_this->array); }
;
}

void sjf_list_string_heap(sjs_list_string* _this) {
}

void sjf_list_string_removeat(sjs_list_string* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= _parent->array.count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
#line 57
    }
#line 58
    sjs_string* p = (sjs_string*)_parent->array.data;
#line 59
    ;
#line 60
    if (index != _parent->array.count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(sjs_string));
#line 62
    }
#line 63
    _parent->array.count--;
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
#line 18 "lib/sj-lib-common/string.sj"
        _return->count = _parent->count;
#line 18
        _return->data._refCount = 1;
#line 18
        sjf_array_char_copy(&_return->data, &_parent->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t newcount;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam6;
            sjs_array_char* sjt_parent4 = 0;

#line 134 "lib/sj-lib-common/array.sj"
            sjt_parent4 = &_parent->data;
#line 21 "lib/sj-lib-common/string.sj"
            sjt_functionParam6 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent4, sjt_functionParam6, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/sj-lib-common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart1 = 0;
#line 27
        sjt_forEnd1 = item->count;
#line 27
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam10;
            int32_t sjt_functionParam7;
            char sjt_functionParam8;
            sjs_array_char* sjt_parent5 = 0;
            sjs_string* sjt_parent7 = 0;

#line 34 "lib/sj-lib-common/array.sj"
            sjt_parent5 = &newdata;
#line 28 "lib/sj-lib-common/string.sj"
            sjt_functionParam7 = newcount;
#line 16
            sjt_parent7 = item;
#line 27
            sjt_functionParam10 = i;
#line 27
            sjf_string_getat(sjt_parent7, sjt_functionParam10, &sjt_functionParam8);
#line 27
            sjf_array_char_initat(sjt_parent5, sjt_functionParam7, sjt_functionParam8);
#line 29
            newcount = newcount + 1;
#line 27
            i++;
        }

#line 27
        _return->_refCount = 1;
#line 32
        _return->count = newcount;
#line 32
        _return->data._refCount = 1;
#line 32
        sjf_array_char_copy(&_return->data, &newdata);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 18 "lib/sj-lib-common/string.sj"
        (*_return)->count = _parent->count;
#line 18
        (*_return)->data._refCount = 1;
#line 18
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t newcount;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam11;
            sjs_array_char* sjt_parent8 = 0;

#line 134 "lib/sj-lib-common/array.sj"
            sjt_parent8 = &_parent->data;
#line 21 "lib/sj-lib-common/string.sj"
            sjt_functionParam11 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent8, sjt_functionParam11, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/sj-lib-common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart2 = 0;
#line 27
        sjt_forEnd2 = item->count;
#line 27
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam12;
            char sjt_functionParam13;
            int32_t sjt_functionParam14;
            sjs_string* sjt_parent10 = 0;
            sjs_array_char* sjt_parent9 = 0;

#line 34 "lib/sj-lib-common/array.sj"
            sjt_parent9 = &newdata;
#line 28 "lib/sj-lib-common/string.sj"
            sjt_functionParam12 = newcount;
#line 16
            sjt_parent10 = item;
#line 27
            sjt_functionParam14 = i;
#line 27
            sjf_string_getat(sjt_parent10, sjt_functionParam14, &sjt_functionParam13);
#line 27
            sjf_array_char_initat(sjt_parent9, sjt_functionParam12, sjt_functionParam13);
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
        (*_return)->count = newcount;
#line 32
        (*_return)->data._refCount = 1;
#line 32
        sjf_array_char_copy(&(*_return)->data, &newdata);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_asbool(sjs_string* text, bool* _return) {
    sjs_string sjt_call15 = { -1 };
    bool sjt_capture2;
    sjs_string* sjt_functionParam30 = 0;
    sjs_string* sjt_parent18 = 0;

#line 27 "lib/sj-lib-common/bool.sj"
    sjt_parent18 = text;
#line 27
    sjt_call15._refCount = 1;
#line 28
    sjt_call15.count = 4;
#line 28
    sjt_call15.data._refCount = 1;
#line 28
    sjt_call15.data.datasize = 4;
#line 28
    sjt_call15.data.data = (void*)sjg_string6;
#line 28
    sjt_call15.data.isglobal = true;
#line 28
    sjt_call15.data.count = 4;
#line 28
    sjf_array_char(&sjt_call15.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call15._isnullterminated = false;
#line 14
    sjf_string(&sjt_call15);
#line 28 "lib/sj-lib-common/bool.sj"
    sjt_functionParam30 = &sjt_call15;
#line 28
    sjf_string_isequal(sjt_parent18, sjt_functionParam30, &sjt_capture2);
    if (sjt_capture2) {
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
    float v = strtof((char*)text->data.data, &e);
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
    double v = strtod((char*)text->data.data, &e);
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

#line 87 "lib/sj-lib-common/i32.sj"
    x = 0;
#line 89
    char* e;
#line 90
    int v = (int)strtol((char*)text->data.data, &e, 10);
#line 92
    if (*e != '\0') {
#line 93
        x = 0;
#line 94
    }
#line 95
    else {
#line 96
        x = v;
#line 97
    }
#line 86
    (*_return) = x;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 6 "lib/sj-lib-common/string.sj"
    _this->count = _from->count;
#line 6
    _this->data._refCount = 1;
#line 6
    sjf_array_char_copy(&_this->data, &_from->data);
#line 6
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam9;
    sjs_array_char* sjt_parent6 = 0;

#line 7 "lib/sj-lib-common/array.sj"
    sjt_parent6 = &_parent->data;
#line 36 "lib/sj-lib-common/string.sj"
    sjt_functionParam9 = index;
#line 36
    sjf_array_char_getat(sjt_parent6, sjt_functionParam9, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
#line 85 "lib/sj-lib-common/string.sj"
    #line 84 "lib/sj-lib-common/string.sj"
(*_return) = kh_str_hash_func((char*)_parent->data.data);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* sjt_functionParam29 = 0;
    sjs_array_char* sjt_parent17 = 0;

#line 269 "lib/sj-lib-common/array.sj"
    sjt_parent17 = &_parent->data;
#line 45 "lib/sj-lib-common/string.sj"
    sjt_functionParam29 = &test->data;
#line 45
    sjf_array_char_isequal(sjt_parent17, sjt_functionParam29, _return);
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool sjt_capture1;
    sjs_array_char sjt_funcold1 = { -1 };

#line 73 "lib/sj-lib-common/string.sj"
    result2 = !(&_parent->data)->isglobal;
    if (result2) {
        bool result3;

#line 73 "lib/sj-lib-common/string.sj"
        result3 = !_parent->_isnullterminated;
#line 73
        sjt_capture1 = result3;
    } else {
#line 73 "lib/sj-lib-common/string.sj"
        sjt_capture1 = false;
    }

    if (sjt_capture1) {
        int32_t sjt_functionParam2;
        char sjt_functionParam3;
        sjs_array_char* sjt_parent2 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam1;
            sjs_array_char* sjt_parent1 = 0;

            sjt_funcold1._refCount = 1;
#line 134 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 134
            sjt_parent1 = &_parent->data;
#line 75 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent1, sjt_functionParam1, &sjt_funcold1);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

#line 34 "lib/sj-lib-common/array.sj"
        sjt_parent2 = &_parent->data;
#line 77 "lib/sj-lib-common/string.sj"
        sjt_functionParam2 = _parent->count;
#line 77
        sjt_functionParam3 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent2, sjt_functionParam2, sjt_functionParam3);
#line 78
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
#line 349 "learnxiny.sj"
    g_day_sunday = 0;
#line 349
    g_day_monday = 1;
#line 349
    g_day_tuesday = 2;
#line 349
    g_day_wednesday = 3;
#line 349
    g_day_thursday = 4;
#line 349
    g_day_friday = 5;
#line 349
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
#line 1 "lib/sj-lib-common/string.sj"
    g_emptystringdata = 0;
#line 3
    g_emptystringdata = (void*)"";
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
    sjt_call1.count = 12;
#line 16
    sjt_call1.data._refCount = 1;
#line 16
    sjt_call1.data.datasize = 12;
#line 16
    sjt_call1.data.data = (void*)sjg_string1;
#line 16
    sjt_call1.data.isglobal = true;
#line 16
    sjt_call1.data.count = 12;
#line 16
    sjf_array_char(&sjt_call1.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call1._isnullterminated = false;
#line 14
    sjf_string(&sjt_call1);
#line 16 "learnxiny.sj"
    sjt_functionParam4 = &sjt_call1;
#line 16
    sjf_console_writeline(sjt_functionParam4);
#line 16
    sjt_call7._refCount = 1;
#line 18
    sjt_call7.count = 9;
#line 18
    sjt_call7.data._refCount = 1;
#line 18
    sjt_call7.data.datasize = 9;
#line 18
    sjt_call7.data.data = (void*)sjg_string2;
#line 18
    sjt_call7.data.isglobal = true;
#line 18
    sjt_call7.data.count = 9;
#line 18
    sjf_array_char(&sjt_call7.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call7._isnullterminated = false;
#line 14
    sjf_string(&sjt_call7);
#line 18 "learnxiny.sj"
    sjt_parent15 = &sjt_call7;
#line 18
    sjt_functionParam16 = 10;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam17 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam16, sjt_functionParam17, &sjt_call8);
#line 18 "learnxiny.sj"
    sjt_functionParam15 = &sjt_call8;
#line 18
    sjf_string_add(sjt_parent15, sjt_functionParam15, &sjt_call6);
#line 18
    sjt_parent14 = &sjt_call6;
#line 18
    sjt_call9._refCount = 1;
#line 18
    sjt_call9.count = 9;
#line 18
    sjt_call9.data._refCount = 1;
#line 18
    sjt_call9.data.datasize = 9;
#line 18
    sjt_call9.data.data = (void*)sjg_string3;
#line 18
    sjt_call9.data.isglobal = true;
#line 18
    sjt_call9.data.count = 9;
#line 18
    sjf_array_char(&sjt_call9.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call9._isnullterminated = false;
#line 14
    sjf_string(&sjt_call9);
#line 18 "learnxiny.sj"
    sjt_functionParam18 = &sjt_call9;
#line 18
    sjf_string_add(sjt_parent14, sjt_functionParam18, &sjt_call5);
#line 18
    sjt_parent13 = &sjt_call5;
#line 18
    sjt_functionParam20 = 3.14;
#line 18
    sjf_f64_asstring(sjt_functionParam20, &sjt_call10);
#line 18
    sjt_functionParam19 = &sjt_call10;
#line 18
    sjf_string_add(sjt_parent13, sjt_functionParam19, &sjt_call4);
#line 18
    sjt_parent12 = &sjt_call4;
#line 18
    sjt_call11._refCount = 1;
#line 18
    sjt_call11.count = 10;
#line 18
    sjt_call11.data._refCount = 1;
#line 18
    sjt_call11.data.datasize = 10;
#line 18
    sjt_call11.data.data = (void*)sjg_string4;
#line 18
    sjt_call11.data.isglobal = true;
#line 18
    sjt_call11.data.count = 10;
#line 18
    sjf_array_char(&sjt_call11.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call11._isnullterminated = false;
#line 14
    sjf_string(&sjt_call11);
#line 18 "learnxiny.sj"
    sjt_functionParam21 = &sjt_call11;
#line 18
    sjf_string_add(sjt_parent12, sjt_functionParam21, &sjt_call3);
#line 18
    sjt_parent11 = &sjt_call3;
#line 18
    sjt_functionParam23 = true;
#line 18
    sjf_bool_asstring(sjt_functionParam23, &sjt_call12);
#line 18
    sjt_functionParam22 = &sjt_call12;
#line 18
    sjf_string_add(sjt_parent11, sjt_functionParam22, &sjt_call2);
#line 18
    sjt_functionParam5 = &sjt_call2;
#line 18
    sjf_console_writeline(sjt_functionParam5);
#line 18
    sjt_call13._refCount = 1;
#line 22
    sjt_call13.count = 6;
#line 22
    sjt_call13.data._refCount = 1;
#line 22
    sjt_call13.data.datasize = 6;
#line 22
    sjt_call13.data.data = (void*)sjg_string7;
#line 22
    sjt_call13.data.isglobal = true;
#line 22
    sjt_call13.data.count = 6;
#line 22
    sjf_array_char(&sjt_call13.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call13._isnullterminated = false;
#line 14
    sjf_string(&sjt_call13);
#line 22 "learnxiny.sj"
    sjt_functionParam24 = &sjt_call13;
#line 22
    sjf_console_write(sjt_functionParam24);
#line 22
    sjt_call14._refCount = 1;
#line 23
    sjt_call14.count = 5;
#line 23
    sjt_call14.data._refCount = 1;
#line 23
    sjt_call14.data.datasize = 5;
#line 23
    sjt_call14.data.data = (void*)sjg_string8;
#line 23
    sjt_call14.data.isglobal = true;
#line 23
    sjt_call14.data.count = 5;
#line 23
    sjf_array_char(&sjt_call14.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call14._isnullterminated = false;
#line 14
    sjf_string(&sjt_call14);
#line 23 "learnxiny.sj"
    sjt_functionParam25 = &sjt_call14;
#line 23
    sjf_console_write(sjt_functionParam25);
#line 23
    sjf_console_readline(&g_name);
#line 32
    sjt_functionParam26 = &g_name;
#line 32
    sjf_string_asi32(sjt_functionParam26, &g_numint);
#line 35
    sjt_functionParam27 = &g_name;
#line 35
    sjf_string_asf32(sjt_functionParam27, &g_numfloat);
#line 38
    sjt_functionParam28 = &g_name;
#line 38
    sjf_string_asf64(sjt_functionParam28, &g_numdouble);
#line 41
    sjt_functionParam31 = &g_name;
#line 41
    sjf_string_asbool(sjt_functionParam31, &g_numbool);
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
    g_foostring.count = 18;
#line 85
    g_foostring.data._refCount = 1;
#line 85
    g_foostring.data.datasize = 18;
#line 85
    g_foostring.data.data = (void*)sjg_string9;
#line 85
    g_foostring.data.isglobal = true;
#line 85
    g_foostring.data.count = 18;
#line 85
    sjf_array_char(&g_foostring.data);
#line 14 "lib/sj-lib-common/string.sj"
    g_foostring._isnullterminated = false;
#line 14
    sjf_string(&g_foostring);
#line 14
    g_barstring._refCount = 1;
#line 88 "learnxiny.sj"
    g_barstring.count = 36;
#line 88
    g_barstring.data._refCount = 1;
#line 88
    g_barstring.data.datasize = 36;
#line 88
    g_barstring.data.data = (void*)sjg_string10;
#line 88
    g_barstring.data.isglobal = true;
#line 88
    g_barstring.data.count = 36;
#line 88
    sjf_array_char(&g_barstring.data);
#line 14 "lib/sj-lib-common/string.sj"
    g_barstring._isnullterminated = false;
#line 14
    sjf_string(&g_barstring);
#line 14
    g_bazstring._refCount = 1;
#line 90 "learnxiny.sj"
    g_bazstring.count = 38;
#line 90
    g_bazstring.data._refCount = 1;
#line 90
    g_bazstring.data.datasize = 38;
#line 90
    g_bazstring.data.data = (void*)sjg_string11;
#line 90
    g_bazstring.data.isglobal = true;
#line 90
    g_bazstring.data.count = 38;
#line 90
    sjf_array_char(&g_bazstring.data);
#line 14 "lib/sj-lib-common/string.sj"
    g_bazstring._isnullterminated = false;
#line 14
    sjf_string(&g_bazstring);
#line 91 "learnxiny.sj"
    sjt_functionParam32 = &g_foostring;
#line 91
    sjf_console_writeline(sjt_functionParam32);
#line 92
    sjt_functionParam33 = &g_barstring;
#line 92
    sjf_console_writeline(sjt_functionParam33);
#line 93
    sjt_functionParam34 = &g_bazstring;
#line 93
    sjf_console_writeline(sjt_functionParam34);
#line 93
    sjt_call17._refCount = 1;
#line 97
    sjt_call17.count = 12;
#line 97
    sjt_call17.data._refCount = 1;
#line 97
    sjt_call17.data.datasize = 12;
#line 97
    sjt_call17.data.data = (void*)sjg_string12;
#line 97
    sjt_call17.data.isglobal = true;
#line 97
    sjt_call17.data.count = 12;
#line 97
    sjf_array_char(&sjt_call17.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call17._isnullterminated = false;
#line 14
    sjf_string(&sjt_call17);
#line 97 "learnxiny.sj"
    sjt_parent20 = &sjt_call17;
#line 97
    sjt_call18._refCount = 1;
#line 97
    sjt_call18.count = 16;
#line 97
    sjt_call18.data._refCount = 1;
#line 97
    sjt_call18.data.datasize = 16;
#line 97
    sjt_call18.data.data = (void*)sjg_string13;
#line 97
    sjt_call18.data.isglobal = true;
#line 97
    sjt_call18.data.count = 16;
#line 97
    sjf_array_char(&sjt_call18.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call18._isnullterminated = false;
#line 14
    sjf_string(&sjt_call18);
#line 97 "learnxiny.sj"
    sjt_functionParam35 = &sjt_call18;
#line 97
    sjf_string_add(sjt_parent20, sjt_functionParam35, &sjt_call16);
#line 97
    sjt_parent19 = &sjt_call16;
#line 97
    sjt_call19._refCount = 1;
#line 97
    sjt_call19.count = 15;
#line 97
    sjt_call19.data._refCount = 1;
#line 97
    sjt_call19.data.datasize = 15;
#line 97
    sjt_call19.data.data = (void*)sjg_string14;
#line 97
    sjt_call19.data.isglobal = true;
#line 97
    sjt_call19.data.count = 15;
#line 97
    sjf_array_char(&sjt_call19.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call19._isnullterminated = false;
#line 14
    sjf_string(&sjt_call19);
#line 97 "learnxiny.sj"
    sjt_functionParam36 = &sjt_call19;
#line 97
    sjf_string_add(sjt_parent19, sjt_functionParam36, &g_plusconcatenated);
#line 98
    sjt_functionParam37 = &g_plusconcatenated;
#line 98
    sjf_console_writeline(sjt_functionParam37);
#line 98
    g_intarray._refCount = 1;
#line 104
    g_intarray.datasize = 10;
#line 3 "lib/sj-lib-common/array.sj"
    g_intarray.data = 0;
#line 4
    g_intarray.isglobal = false;
#line 5
    g_intarray.count = 0;
#line 5
    sjf_array_i32(&g_intarray);
#line 34
    sjt_parent21 = &g_intarray;
#line 105 "learnxiny.sj"
    sjt_functionParam38 = 0;
#line 105
    sjt_functionParam39 = 1;
#line 105
    sjf_array_i32_initat(sjt_parent21, sjt_functionParam38, sjt_functionParam39);
#line 105
    sjt_call20._refCount = 1;
#line 109
    sjt_call20.datasize = 10;
#line 3 "lib/sj-lib-common/array.sj"
    sjt_call20.data = 0;
#line 4
    sjt_call20.isglobal = false;
#line 5
    sjt_call20.count = 0;
#line 5
    sjf_array_i32(&sjt_call20);
#line 109 "learnxiny.sj"
    sjt_parent22 = &sjt_call20;
#line 109
    result4 = -1;
#line 109
    sjt_functionParam40 = result4;
#line 109
    sjf_array_i32_init(sjt_parent22, sjt_functionParam40, &g_intarray2);
#line 109
    g_intarray3._refCount = 1;
#line 112
    g_intarray3.datasize = 3;
#line 3 "lib/sj-lib-common/array.sj"
    g_intarray3.data = 0;
#line 4
    g_intarray3.isglobal = false;
#line 5
    g_intarray3.count = 0;
#line 5
    sjf_array_i32(&g_intarray3);
#line 112 "learnxiny.sj"
    sjs_array_i32* array1;
#line 112
    array1 = &g_intarray3;
#line 112
    sjt_parent23 = array1;
#line 112
    sjt_functionParam41 = 0;
#line 112
    sjt_functionParam42 = 1;
#line 112
    sjf_array_i32_initat(sjt_parent23, sjt_functionParam41, sjt_functionParam42);
#line 112
    sjt_parent24 = array1;
#line 112
    sjt_functionParam43 = 1;
#line 112
    sjt_functionParam44 = 2;
#line 112
    sjf_array_i32_initat(sjt_parent24, sjt_functionParam43, sjt_functionParam44);
#line 112
    sjt_parent25 = array1;
#line 112
    sjt_functionParam45 = 2;
#line 112
    sjt_functionParam46 = 3;
#line 112
    sjf_array_i32_initat(sjt_parent25, sjt_functionParam45, sjt_functionParam46);
#line 112
    g_objarray._refCount = 1;
#line 117
    g_objarray.datasize = 2;
#line 3 "lib/sj-lib-common/array.sj"
    g_objarray.data = 0;
#line 4
    g_objarray.isglobal = false;
#line 5
    g_objarray.count = 0;
#line 5
    sjf_array_obj(&g_objarray);
#line 117 "learnxiny.sj"
    sjs_array_obj* array2;
#line 117
    array2 = &g_objarray;
#line 117
    sjt_parent26 = array2;
#line 117
    sjt_functionParam47 = 0;
#line 117
    sjt_call21._refCount = 1;
#line 117
    sjf_obj(&sjt_call21);
#line 117
    sjt_functionParam48 = &sjt_call21;
#line 117
    sjf_array_obj_initat(sjt_parent26, sjt_functionParam47, sjt_functionParam48);
#line 117
    sjt_parent27 = array2;
#line 117
    sjt_functionParam49 = 1;
#line 117
    sjt_call22._refCount = 1;
#line 117
    sjf_obj(&sjt_call22);
#line 117
    sjt_functionParam50 = &sjt_call22;
#line 117
    sjf_array_obj_initat(sjt_parent27, sjt_functionParam49, sjt_functionParam50);
#line 117
    sjt_call24._refCount = 1;
#line 120
    sjt_call24.count = 14;
#line 120
    sjt_call24.data._refCount = 1;
#line 120
    sjt_call24.data.datasize = 14;
#line 120
    sjt_call24.data.data = (void*)sjg_string15;
#line 120
    sjt_call24.data.isglobal = true;
#line 120
    sjt_call24.data.count = 14;
#line 120
    sjf_array_char(&sjt_call24.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call24._isnullterminated = false;
#line 14
    sjf_string(&sjt_call24);
#line 120 "learnxiny.sj"
    sjt_parent28 = &sjt_call24;
#line 7 "lib/sj-lib-common/array.sj"
    sjt_parent29 = &g_intarray;
#line 120 "learnxiny.sj"
    sjt_functionParam54 = 0;
#line 120
    sjf_array_i32_getat(sjt_parent29, sjt_functionParam54, &sjt_functionParam53);
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam55 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam53, sjt_functionParam55, &sjt_call25);
#line 120 "learnxiny.sj"
    sjt_functionParam52 = &sjt_call25;
#line 120
    sjf_string_add(sjt_parent28, sjt_functionParam52, &sjt_call23);
#line 120
    sjt_functionParam51 = &sjt_call23;
#line 120
    sjf_console_writeline(sjt_functionParam51);
#line 49 "lib/sj-lib-common/array.sj"
    sjt_parent30 = &g_intarray2;
#line 123 "learnxiny.sj"
    sjt_functionParam56 = 1;
#line 123
    sjt_functionParam57 = 1;
#line 123
    sjf_array_i32_setat(sjt_parent30, sjt_functionParam56, sjt_functionParam57);
#line 123
    sjt_call27._refCount = 1;
#line 124
    sjt_call27.count = 15;
#line 124
    sjt_call27.data._refCount = 1;
#line 124
    sjt_call27.data.datasize = 15;
#line 124
    sjt_call27.data.data = (void*)sjg_string16;
#line 124
    sjt_call27.data.isglobal = true;
#line 124
    sjt_call27.data.count = 15;
#line 124
    sjf_array_char(&sjt_call27.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call27._isnullterminated = false;
#line 14
    sjf_string(&sjt_call27);
#line 124 "learnxiny.sj"
    sjt_parent31 = &sjt_call27;
#line 7 "lib/sj-lib-common/array.sj"
    sjt_parent32 = &g_intarray2;
#line 124 "learnxiny.sj"
    sjt_functionParam61 = 1;
#line 124
    sjf_array_i32_getat(sjt_parent32, sjt_functionParam61, &sjt_functionParam60);
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam62 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam60, sjt_functionParam62, &sjt_call28);
#line 124 "learnxiny.sj"
    sjt_functionParam59 = &sjt_call28;
#line 124
    sjf_string_add(sjt_parent31, sjt_functionParam59, &sjt_call26);
#line 124
    sjt_functionParam58 = &sjt_call26;
#line 124
    sjf_console_writeline(sjt_functionParam58);
#line 124
    g_l._refCount = 1;
#line 124
    g_l.array._refCount = 1;
#line 2 "lib/sj-lib-common/list.sj"
    g_l.array.datasize = 0;
#line 3 "lib/sj-lib-common/array.sj"
    g_l.array.data = 0;
#line 4
    g_l.array.isglobal = false;
#line 5
    g_l.array.count = 0;
#line 5
    sjf_array_string(&g_l.array);
#line 5
    sjf_list_string(&g_l);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent35 = &g_l;
#line 44
    sjt_call29._refCount = 1;
#line 128 "learnxiny.sj"
    sjt_call29.count = 5;
#line 128
    sjt_call29.data._refCount = 1;
#line 128
    sjt_call29.data.datasize = 5;
#line 128
    sjt_call29.data.data = (void*)sjg_string17;
#line 128
    sjt_call29.data.isglobal = true;
#line 128
    sjt_call29.data.count = 5;
#line 128
    sjf_array_char(&sjt_call29.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call29._isnullterminated = false;
#line 14
    sjf_string(&sjt_call29);
#line 128 "learnxiny.sj"
    sjt_functionParam68 = &sjt_call29;
#line 128
    sjf_list_string_add(sjt_parent35, sjt_functionParam68);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent36 = &g_l;
#line 44
    sjt_call30._refCount = 1;
#line 129 "learnxiny.sj"
    sjt_call30.count = 3;
#line 129
    sjt_call30.data._refCount = 1;
#line 129
    sjt_call30.data.datasize = 3;
#line 129
    sjt_call30.data.data = (void*)sjg_string18;
#line 129
    sjt_call30.data.isglobal = true;
#line 129
    sjt_call30.data.count = 3;
#line 129
    sjf_array_char(&sjt_call30.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call30._isnullterminated = false;
#line 14
    sjf_string(&sjt_call30);
#line 129 "learnxiny.sj"
    sjt_functionParam69 = &sjt_call30;
#line 129
    sjf_list_string_add(sjt_parent36, sjt_functionParam69);
#line 53 "lib/sj-lib-common/list.sj"
    sjt_parent37 = &g_l;
#line 130 "learnxiny.sj"
    sjt_functionParam70 = 0;
#line 130
    sjf_list_string_removeat(sjt_parent37, sjt_functionParam70);
#line 130
    g_h._refCount = 1;
#line 130
    sjf_hash_string_i32(&g_h);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent38 = &g_h;
#line 38
    sjt_call31._refCount = 1;
#line 134 "learnxiny.sj"
    sjt_call31.count = 3;
#line 134
    sjt_call31.data._refCount = 1;
#line 134
    sjt_call31.data.datasize = 3;
#line 134
    sjt_call31.data.data = (void*)sjg_string19;
#line 134
    sjt_call31.data.isglobal = true;
#line 134
    sjt_call31.data.count = 3;
#line 134
    sjf_array_char(&sjt_call31.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call31._isnullterminated = false;
#line 14
    sjf_string(&sjt_call31);
#line 134 "learnxiny.sj"
    sjt_functionParam71 = &sjt_call31;
#line 134
    sjt_functionParam72 = 1;
#line 134
    sjf_hash_string_i32_setat(sjt_parent38, sjt_functionParam71, sjt_functionParam72);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent39 = &g_h;
#line 38
    sjt_call32._refCount = 1;
#line 135 "learnxiny.sj"
    sjt_call32.count = 3;
#line 135
    sjt_call32.data._refCount = 1;
#line 135
    sjt_call32.data.datasize = 3;
#line 135
    sjt_call32.data.data = (void*)sjg_string20;
#line 135
    sjt_call32.data.isglobal = true;
#line 135
    sjt_call32.data.count = 3;
#line 135
    sjf_array_char(&sjt_call32.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call32._isnullterminated = false;
#line 14
    sjf_string(&sjt_call32);
#line 135 "learnxiny.sj"
    sjt_functionParam73 = &sjt_call32;
#line 135
    sjt_functionParam74 = 2;
#line 135
    sjf_hash_string_i32_setat(sjt_parent39, sjt_functionParam73, sjt_functionParam74);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent40 = &g_h;
#line 38
    sjt_call33._refCount = 1;
#line 136 "learnxiny.sj"
    sjt_call33.count = 3;
#line 136
    sjt_call33.data._refCount = 1;
#line 136
    sjt_call33.data.datasize = 3;
#line 136
    sjt_call33.data.data = (void*)sjg_string20;
#line 136
    sjt_call33.data.isglobal = true;
#line 136
    sjt_call33.data.count = 3;
#line 136
    sjf_array_char(&sjt_call33.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call33._isnullterminated = false;
#line 14
    sjf_string(&sjt_call33);
#line 136 "learnxiny.sj"
    sjt_functionParam75 = &sjt_call33;
#line 21 "lib/sj-lib-common/hash.sj"
    sjt_parent41 = &g_h;
#line 21
    sjt_call34._refCount = 1;
#line 136 "learnxiny.sj"
    sjt_call34.count = 3;
#line 136
    sjt_call34.data._refCount = 1;
#line 136
    sjt_call34.data.datasize = 3;
#line 136
    sjt_call34.data.data = (void*)sjg_string19;
#line 136
    sjt_call34.data.isglobal = true;
#line 136
    sjt_call34.data.count = 3;
#line 136
    sjf_array_char(&sjt_call34.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call34._isnullterminated = false;
#line 14
    sjf_string(&sjt_call34);
#line 136 "learnxiny.sj"
    sjt_functionParam77 = &sjt_call34;
#line 136
    sjf_hash_string_i32_getat(sjt_parent41, sjt_functionParam77, &sjt_capture4);
    if (sjt_capture4.isvalid) {
        sjs_string* sjt_functionParam78 = 0;
        int32_option sjt_getValue1;
        sjs_hash_string_i32* sjt_parent42 = 0;

#line 21 "lib/sj-lib-common/hash.sj"
        sjt_parent42 = &g_h;
#line 21
        sjt_call35._refCount = 1;
#line 136 "learnxiny.sj"
        sjt_call35.count = 3;
#line 136
        sjt_call35.data._refCount = 1;
#line 136
        sjt_call35.data.datasize = 3;
#line 136
        sjt_call35.data.data = (void*)sjg_string19;
#line 136
        sjt_call35.data.isglobal = true;
#line 136
        sjt_call35.data.count = 3;
#line 136
        sjf_array_char(&sjt_call35.data);
#line 14 "lib/sj-lib-common/string.sj"
        sjt_call35._isnullterminated = false;
#line 14
        sjf_string(&sjt_call35);
#line 136 "learnxiny.sj"
        sjt_functionParam78 = &sjt_call35;
#line 136
        sjf_hash_string_i32_getat(sjt_parent42, sjt_functionParam78, &sjt_getValue1);
#line 136
        sjt_capture3 = sjt_getValue1.value;
    } else {
#line 136 "learnxiny.sj"
        sjt_capture3 = (int32_t)0;
    }

#line 136
    sjt_functionParam76 = sjt_capture3 + 1;
#line 136
    sjf_hash_string_i32_setat(sjt_parent40, sjt_functionParam75, sjt_functionParam76);
#line 141
    g_i1 = 1;
#line 142
    g_i2 = 2;
#line 142
    sjt_call37._refCount = 1;
#line 145
    sjt_call37.count = 6;
#line 145
    sjt_call37.data._refCount = 1;
#line 145
    sjt_call37.data.datasize = 6;
#line 145
    sjt_call37.data.data = (void*)sjg_string21;
#line 145
    sjt_call37.data.isglobal = true;
#line 145
    sjt_call37.data.count = 6;
#line 145
    sjf_array_char(&sjt_call37.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call37._isnullterminated = false;
#line 14
    sjf_string(&sjt_call37);
#line 145 "learnxiny.sj"
    sjt_parent43 = &sjt_call37;
#line 145
    sjt_functionParam81 = g_i1 + g_i2;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam82 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam81, sjt_functionParam82, &sjt_call38);
#line 145 "learnxiny.sj"
    sjt_functionParam80 = &sjt_call38;
#line 145
    sjf_string_add(sjt_parent43, sjt_functionParam80, &sjt_call36);
#line 145
    sjt_functionParam79 = &sjt_call36;
#line 145
    sjf_console_writeline(sjt_functionParam79);
#line 145
    sjt_call40._refCount = 1;
#line 146
    sjt_call40.count = 6;
#line 146
    sjt_call40.data._refCount = 1;
#line 146
    sjt_call40.data.datasize = 6;
#line 146
    sjt_call40.data.data = (void*)sjg_string22;
#line 146
    sjt_call40.data.isglobal = true;
#line 146
    sjt_call40.data.count = 6;
#line 146
    sjf_array_char(&sjt_call40.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call40._isnullterminated = false;
#line 14
    sjf_string(&sjt_call40);
#line 146 "learnxiny.sj"
    sjt_parent44 = &sjt_call40;
#line 146
    sjt_functionParam85 = g_i2 - g_i1;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam86 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam85, sjt_functionParam86, &sjt_call41);
#line 146 "learnxiny.sj"
    sjt_functionParam84 = &sjt_call41;
#line 146
    sjf_string_add(sjt_parent44, sjt_functionParam84, &sjt_call39);
#line 146
    sjt_functionParam83 = &sjt_call39;
#line 146
    sjf_console_writeline(sjt_functionParam83);
#line 146
    sjt_call43._refCount = 1;
#line 147
    sjt_call43.count = 6;
#line 147
    sjt_call43.data._refCount = 1;
#line 147
    sjt_call43.data.datasize = 6;
#line 147
    sjt_call43.data.data = (void*)sjg_string23;
#line 147
    sjt_call43.data.isglobal = true;
#line 147
    sjt_call43.data.count = 6;
#line 147
    sjf_array_char(&sjt_call43.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call43._isnullterminated = false;
#line 14
    sjf_string(&sjt_call43);
#line 147 "learnxiny.sj"
    sjt_parent45 = &sjt_call43;
#line 147
    sjt_functionParam89 = g_i2 * g_i1;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam90 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam89, sjt_functionParam90, &sjt_call44);
#line 147 "learnxiny.sj"
    sjt_functionParam88 = &sjt_call44;
#line 147
    sjf_string_add(sjt_parent45, sjt_functionParam88, &sjt_call42);
#line 147
    sjt_functionParam87 = &sjt_call42;
#line 147
    sjf_console_writeline(sjt_functionParam87);
#line 147
    sjt_call46._refCount = 1;
#line 148
    sjt_call46.count = 6;
#line 148
    sjt_call46.data._refCount = 1;
#line 148
    sjt_call46.data.datasize = 6;
#line 148
    sjt_call46.data.data = (void*)sjg_string24;
#line 148
    sjt_call46.data.isglobal = true;
#line 148
    sjt_call46.data.count = 6;
#line 148
    sjf_array_char(&sjt_call46.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call46._isnullterminated = false;
#line 14
    sjf_string(&sjt_call46);
#line 148 "learnxiny.sj"
    sjt_parent46 = &sjt_call46;
#line 148
    sjt_functionParam93 = g_i1 / g_i2;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam94 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam93, sjt_functionParam94, &sjt_call47);
#line 148 "learnxiny.sj"
    sjt_functionParam92 = &sjt_call47;
#line 148
    sjf_string_add(sjt_parent46, sjt_functionParam92, &sjt_call45);
#line 148
    sjt_functionParam91 = &sjt_call45;
#line 148
    sjf_console_writeline(sjt_functionParam91);
#line 148
    sjt_call49._refCount = 1;
#line 149
    sjt_call49.count = 8;
#line 149
    sjt_call49.data._refCount = 1;
#line 149
    sjt_call49.data.datasize = 8;
#line 149
    sjt_call49.data.data = (void*)sjg_string25;
#line 149
    sjt_call49.data.isglobal = true;
#line 149
    sjt_call49.data.count = 8;
#line 149
    sjf_array_char(&sjt_call49.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call49._isnullterminated = false;
#line 14
    sjf_string(&sjt_call49);
#line 149 "learnxiny.sj"
    sjt_parent47 = &sjt_call49;
#line 149
    sjt_cast2 = g_i1;
#line 149
    sjt_cast3 = g_i2;
#line 149
    sjt_functionParam97 = (double)sjt_cast2 / (double)sjt_cast3;
#line 149
    sjf_f64_asstring(sjt_functionParam97, &sjt_call50);
#line 149
    sjt_functionParam96 = &sjt_call50;
#line 149
    sjf_string_add(sjt_parent47, sjt_functionParam96, &sjt_call48);
#line 149
    sjt_functionParam95 = &sjt_call48;
#line 149
    sjf_console_writeline(sjt_functionParam95);
#line 149
    sjt_call52._refCount = 1;
#line 152
    sjt_call52.count = 7;
#line 152
    sjt_call52.data._refCount = 1;
#line 152
    sjt_call52.data.datasize = 7;
#line 152
    sjt_call52.data.data = (void*)sjg_string26;
#line 152
    sjt_call52.data.isglobal = true;
#line 152
    sjt_call52.data.count = 7;
#line 152
    sjf_array_char(&sjt_call52.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call52._isnullterminated = false;
#line 14
    sjf_string(&sjt_call52);
#line 152 "learnxiny.sj"
    sjt_parent48 = &sjt_call52;
#line 152
    sjt_functionParam100 = 11 % 3;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam101 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam100, sjt_functionParam101, &sjt_call53);
#line 152 "learnxiny.sj"
    sjt_functionParam99 = &sjt_call53;
#line 152
    sjf_string_add(sjt_parent48, sjt_functionParam99, &sjt_call51);
#line 152
    sjt_functionParam98 = &sjt_call51;
#line 152
    sjf_console_writeline(sjt_functionParam98);
#line 152
    sjt_call55._refCount = 1;
#line 155
    sjt_call55.count = 8;
#line 155
    sjt_call55.data._refCount = 1;
#line 155
    sjt_call55.data.datasize = 8;
#line 155
    sjt_call55.data.data = (void*)sjg_string27;
#line 155
    sjt_call55.data.isglobal = true;
#line 155
    sjt_call55.data.count = 8;
#line 155
    sjf_array_char(&sjt_call55.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call55._isnullterminated = false;
#line 14
    sjf_string(&sjt_call55);
#line 155 "learnxiny.sj"
    sjt_parent49 = &sjt_call55;
#line 155
    sjt_functionParam104 = 3 == 2;
#line 155
    sjf_bool_asstring(sjt_functionParam104, &sjt_call56);
#line 155
    sjt_functionParam103 = &sjt_call56;
#line 155
    sjf_string_add(sjt_parent49, sjt_functionParam103, &sjt_call54);
#line 155
    sjt_functionParam102 = &sjt_call54;
#line 155
    sjf_console_writeline(sjt_functionParam102);
#line 155
    sjt_call58._refCount = 1;
#line 156
    sjt_call58.count = 8;
#line 156
    sjt_call58.data._refCount = 1;
#line 156
    sjt_call58.data.datasize = 8;
#line 156
    sjt_call58.data.data = (void*)sjg_string28;
#line 156
    sjt_call58.data.isglobal = true;
#line 156
    sjt_call58.data.count = 8;
#line 156
    sjf_array_char(&sjt_call58.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call58._isnullterminated = false;
#line 14
    sjf_string(&sjt_call58);
#line 156 "learnxiny.sj"
    sjt_parent50 = &sjt_call58;
#line 156
    sjt_functionParam107 = 3 != 2;
#line 156
    sjf_bool_asstring(sjt_functionParam107, &sjt_call59);
#line 156
    sjt_functionParam106 = &sjt_call59;
#line 156
    sjf_string_add(sjt_parent50, sjt_functionParam106, &sjt_call57);
#line 156
    sjt_functionParam105 = &sjt_call57;
#line 156
    sjf_console_writeline(sjt_functionParam105);
#line 156
    sjt_call61._refCount = 1;
#line 157
    sjt_call61.count = 7;
#line 157
    sjt_call61.data._refCount = 1;
#line 157
    sjt_call61.data.datasize = 7;
#line 157
    sjt_call61.data.data = (void*)sjg_string29;
#line 157
    sjt_call61.data.isglobal = true;
#line 157
    sjt_call61.data.count = 7;
#line 157
    sjf_array_char(&sjt_call61.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call61._isnullterminated = false;
#line 14
    sjf_string(&sjt_call61);
#line 157 "learnxiny.sj"
    sjt_parent51 = &sjt_call61;
#line 157
    sjt_functionParam110 = 3 > 2;
#line 157
    sjf_bool_asstring(sjt_functionParam110, &sjt_call62);
#line 157
    sjt_functionParam109 = &sjt_call62;
#line 157
    sjf_string_add(sjt_parent51, sjt_functionParam109, &sjt_call60);
#line 157
    sjt_functionParam108 = &sjt_call60;
#line 157
    sjf_console_writeline(sjt_functionParam108);
#line 157
    sjt_call64._refCount = 1;
#line 158
    sjt_call64.count = 7;
#line 158
    sjt_call64.data._refCount = 1;
#line 158
    sjt_call64.data.datasize = 7;
#line 158
    sjt_call64.data.data = (void*)sjg_string30;
#line 158
    sjt_call64.data.isglobal = true;
#line 158
    sjt_call64.data.count = 7;
#line 158
    sjf_array_char(&sjt_call64.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call64._isnullterminated = false;
#line 14
    sjf_string(&sjt_call64);
#line 158 "learnxiny.sj"
    sjt_parent52 = &sjt_call64;
#line 158
    sjt_functionParam113 = 3 < 2;
#line 158
    sjf_bool_asstring(sjt_functionParam113, &sjt_call65);
#line 158
    sjt_functionParam112 = &sjt_call65;
#line 158
    sjf_string_add(sjt_parent52, sjt_functionParam112, &sjt_call63);
#line 158
    sjt_functionParam111 = &sjt_call63;
#line 158
    sjf_console_writeline(sjt_functionParam111);
#line 158
    sjt_call67._refCount = 1;
#line 159
    sjt_call67.count = 8;
#line 159
    sjt_call67.data._refCount = 1;
#line 159
    sjt_call67.data.datasize = 8;
#line 159
    sjt_call67.data.data = (void*)sjg_string31;
#line 159
    sjt_call67.data.isglobal = true;
#line 159
    sjt_call67.data.count = 8;
#line 159
    sjf_array_char(&sjt_call67.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call67._isnullterminated = false;
#line 14
    sjf_string(&sjt_call67);
#line 159 "learnxiny.sj"
    sjt_parent53 = &sjt_call67;
#line 159
    sjt_functionParam116 = 2 <= 2;
#line 159
    sjf_bool_asstring(sjt_functionParam116, &sjt_call68);
#line 159
    sjt_functionParam115 = &sjt_call68;
#line 159
    sjf_string_add(sjt_parent53, sjt_functionParam115, &sjt_call66);
#line 159
    sjt_functionParam114 = &sjt_call66;
#line 159
    sjf_console_writeline(sjt_functionParam114);
#line 159
    sjt_call70._refCount = 1;
#line 160
    sjt_call70.count = 8;
#line 160
    sjt_call70.data._refCount = 1;
#line 160
    sjt_call70.data.datasize = 8;
#line 160
    sjt_call70.data.data = (void*)sjg_string32;
#line 160
    sjt_call70.data.isglobal = true;
#line 160
    sjt_call70.data.count = 8;
#line 160
    sjf_array_char(&sjt_call70.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call70._isnullterminated = false;
#line 14
    sjf_string(&sjt_call70);
#line 160 "learnxiny.sj"
    sjt_parent54 = &sjt_call70;
#line 160
    sjt_functionParam119 = 2 >= 2;
#line 160
    sjf_bool_asstring(sjt_functionParam119, &sjt_call71);
#line 160
    sjt_functionParam118 = &sjt_call71;
#line 160
    sjf_string_add(sjt_parent54, sjt_functionParam118, &sjt_call69);
#line 160
    sjt_functionParam117 = &sjt_call69;
#line 160
    sjf_console_writeline(sjt_functionParam117);
#line 160
    sjt_call73._refCount = 1;
#line 163
    sjt_call73.count = 16;
#line 163
    sjt_call73.data._refCount = 1;
#line 163
    sjt_call73.data.datasize = 16;
#line 163
    sjt_call73.data.data = (void*)sjg_string33;
#line 163
    sjt_call73.data.isglobal = true;
#line 163
    sjt_call73.data.count = 16;
#line 163
    sjf_array_char(&sjt_call73.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call73._isnullterminated = false;
#line 14
    sjf_string(&sjt_call73);
#line 163 "learnxiny.sj"
    sjt_parent55 = &sjt_call73;
    if (3 > 2) {
#line 163 "learnxiny.sj"
        sjt_functionParam122 = (2 > 3);
    } else {
#line 163 "learnxiny.sj"
        sjt_functionParam122 = false;
    }

#line 163
    sjf_bool_asstring(sjt_functionParam122, &sjt_call74);
#line 163
    sjt_functionParam121 = &sjt_call74;
#line 163
    sjf_string_add(sjt_parent55, sjt_functionParam121, &sjt_call72);
#line 163
    sjt_functionParam120 = &sjt_call72;
#line 163
    sjf_console_writeline(sjt_functionParam120);
#line 163
    sjt_call76._refCount = 1;
#line 164
    sjt_call76.count = 16;
#line 164
    sjt_call76.data._refCount = 1;
#line 164
    sjt_call76.data.datasize = 16;
#line 164
    sjt_call76.data.data = (void*)sjg_string34;
#line 164
    sjt_call76.data.isglobal = true;
#line 164
    sjt_call76.data.count = 16;
#line 164
    sjf_array_char(&sjt_call76.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call76._isnullterminated = false;
#line 14
    sjf_string(&sjt_call76);
#line 164 "learnxiny.sj"
    sjt_parent56 = &sjt_call76;
#line 164
    sjt_functionParam125 = (3 > 2) || (2 > 3);
#line 164
    sjf_bool_asstring(sjt_functionParam125, &sjt_call77);
#line 164
    sjt_functionParam124 = &sjt_call77;
#line 164
    sjf_string_add(sjt_parent56, sjt_functionParam124, &sjt_call75);
#line 164
    sjt_functionParam123 = &sjt_call75;
#line 164
    sjf_console_writeline(sjt_functionParam123);
#line 164
    sjt_call79._refCount = 1;
#line 165
    sjt_call79.count = 11;
#line 165
    sjt_call79.data._refCount = 1;
#line 165
    sjt_call79.data.datasize = 11;
#line 165
    sjt_call79.data.data = (void*)sjg_string35;
#line 165
    sjt_call79.data.isglobal = true;
#line 165
    sjt_call79.data.count = 11;
#line 165
    sjf_array_char(&sjt_call79.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call79._isnullterminated = false;
#line 14
    sjf_string(&sjt_call79);
#line 165 "learnxiny.sj"
    sjt_parent57 = &sjt_call79;
#line 165
    result5 = !(3 == 2);
#line 165
    sjt_functionParam128 = result5;
#line 165
    sjf_bool_asstring(sjt_functionParam128, &sjt_call80);
#line 165
    sjt_functionParam127 = &sjt_call80;
#line 165
    sjf_string_add(sjt_parent57, sjt_functionParam127, &sjt_call78);
#line 165
    sjt_functionParam126 = &sjt_call78;
#line 165
    sjf_console_writeline(sjt_functionParam126);
#line 179
    g_i = 0;
#line 179
    sjt_call81._refCount = 1;
#line 180
    sjt_call81.count = 23;
#line 180
    sjt_call81.data._refCount = 1;
#line 180
    sjt_call81.data.datasize = 23;
#line 180
    sjt_call81.data.data = (void*)sjg_string36;
#line 180
    sjt_call81.data.isglobal = true;
#line 180
    sjt_call81.data.count = 23;
#line 180
    sjf_array_char(&sjt_call81.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call81._isnullterminated = false;
#line 14
    sjf_string(&sjt_call81);
#line 180 "learnxiny.sj"
    sjt_functionParam129 = &sjt_call81;
#line 180
    sjf_console_writeline(sjt_functionParam129);
#line 182
    g_i = g_i + 1;
#line 183
    sjt_functionParam131 = g_i;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam132 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam131, sjt_functionParam132, &sjt_call82);
#line 183 "learnxiny.sj"
    sjt_functionParam130 = &sjt_call82;
#line 183
    sjf_console_writeline(sjt_functionParam130);
#line 184
    g_i = g_i - 1;
#line 185
    sjt_functionParam134 = g_i;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam135 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam134, sjt_functionParam135, &sjt_call83);
#line 185 "learnxiny.sj"
    sjt_functionParam133 = &sjt_call83;
#line 185
    sjf_console_writeline(sjt_functionParam133);
#line 185
    sjt_call84._refCount = 1;
#line 190
    sjt_call84.count = 22;
#line 190
    sjt_call84.data._refCount = 1;
#line 190
    sjt_call84.data.datasize = 22;
#line 190
    sjt_call84.data.data = (void*)sjg_string37;
#line 190
    sjt_call84.data.isglobal = true;
#line 190
    sjt_call84.data.count = 22;
#line 190
    sjf_array_char(&sjt_call84.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call84._isnullterminated = false;
#line 14
    sjf_string(&sjt_call84);
#line 190 "learnxiny.sj"
    sjt_functionParam136 = &sjt_call84;
#line 190
    sjf_console_writeline(sjt_functionParam136);
#line 193
    g_j = 10;
    if (g_j == 10) {
        sjs_string* sjt_functionParam137 = 0;

        sjt_call85._refCount = 1;
#line 195 "learnxiny.sj"
        sjt_call85.count = 13;
#line 195
        sjt_call85.data._refCount = 1;
#line 195
        sjt_call85.data.datasize = 13;
#line 195
        sjt_call85.data.data = (void*)sjg_string40;
#line 195
        sjt_call85.data.isglobal = true;
#line 195
        sjt_call85.data.count = 13;
#line 195
        sjf_array_char(&sjt_call85.data);
#line 14 "lib/sj-lib-common/string.sj"
        sjt_call85._isnullterminated = false;
#line 14
        sjf_string(&sjt_call85);
#line 195 "learnxiny.sj"
        sjt_functionParam137 = &sjt_call85;
#line 195
        sjf_console_writeline(sjt_functionParam137);
    } else {
        if (g_j > 10) {
            sjs_string* sjt_functionParam138 = 0;

            sjt_call86._refCount = 1;
#line 197 "learnxiny.sj"
            sjt_call86.count = 7;
#line 197
            sjt_call86.data._refCount = 1;
#line 197
            sjt_call86.data.datasize = 7;
#line 197
            sjt_call86.data.data = (void*)sjg_string39;
#line 197
            sjt_call86.data.isglobal = true;
#line 197
            sjt_call86.data.count = 7;
#line 197
            sjf_array_char(&sjt_call86.data);
#line 14 "lib/sj-lib-common/string.sj"
            sjt_call86._isnullterminated = false;
#line 14
            sjf_string(&sjt_call86);
#line 197 "learnxiny.sj"
            sjt_functionParam138 = &sjt_call86;
#line 197
            sjf_console_writeline(sjt_functionParam138);
        } else {
            sjs_string* sjt_functionParam139 = 0;

            sjt_call87._refCount = 1;
#line 199 "learnxiny.sj"
            sjt_call87.count = 12;
#line 199
            sjt_call87.data._refCount = 1;
#line 199
            sjt_call87.data.datasize = 12;
#line 199
            sjt_call87.data.data = (void*)sjg_string38;
#line 199
            sjt_call87.data.isglobal = true;
#line 199
            sjt_call87.data.count = 12;
#line 199
            sjf_array_char(&sjt_call87.data);
#line 14 "lib/sj-lib-common/string.sj"
            sjt_call87._isnullterminated = false;
#line 14
            sjf_string(&sjt_call87);
#line 199 "learnxiny.sj"
            sjt_functionParam139 = &sjt_call87;
#line 199
            sjf_console_writeline(sjt_functionParam139);
        }
    }

#line 203
    g_foowhile = 0;
#line 204
    sjt_while1 = g_foowhile < 100;
    while (sjt_while1) {
        sjs_string sjt_call88 = { -1 };
        sjs_string* sjt_functionParam140 = 0;
        int32_t sjt_functionParam141;
        int32_t sjt_functionParam142;

#line 205 "learnxiny.sj"
        sjt_functionParam141 = g_foowhile;
#line 22 "lib/sj-lib-common/i32.sj"
        sjt_functionParam142 = 10;
#line 22
        sjf_i32_asstring(sjt_functionParam141, sjt_functionParam142, &sjt_call88);
#line 205 "learnxiny.sj"
        sjt_functionParam140 = &sjt_call88;
#line 205
        sjf_console_writeline(sjt_functionParam140);
#line 208
        g_foowhile = g_foowhile + 1;
#line 204
        sjt_while1 = g_foowhile < 100;

        if (sjt_call88._refCount == 1) { sjf_string_destroy(&sjt_call88); }
;
    }

#line 204
    sjt_call90._refCount = 1;
#line 210
    sjt_call90.count = 16;
#line 210
    sjt_call90.data._refCount = 1;
#line 210
    sjt_call90.data.datasize = 16;
#line 210
    sjt_call90.data.data = (void*)sjg_string41;
#line 210
    sjt_call90.data.isglobal = true;
#line 210
    sjt_call90.data.count = 16;
#line 210
    sjf_array_char(&sjt_call90.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call90._isnullterminated = false;
#line 14
    sjf_string(&sjt_call90);
#line 210 "learnxiny.sj"
    sjt_parent58 = &sjt_call90;
#line 210
    sjt_functionParam145 = g_foowhile;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam146 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam145, sjt_functionParam146, &sjt_call91);
#line 210 "learnxiny.sj"
    sjt_functionParam144 = &sjt_call91;
#line 210
    sjf_string_add(sjt_parent58, sjt_functionParam144, &sjt_call89);
#line 210
    sjt_functionParam143 = &sjt_call89;
#line 210
    sjf_console_writeline(sjt_functionParam143);
#line 214
    sjt_forStart3 = 0;
#line 214
    sjt_forEnd3 = 10;
#line 214
    foofor = sjt_forStart3;
    while (foofor < sjt_forEnd3) {
        sjs_string sjt_call92 = { -1 };
        sjs_string* sjt_functionParam147 = 0;
        int32_t sjt_functionParam148;
        int32_t sjt_functionParam149;

#line 214 "learnxiny.sj"
        sjt_functionParam148 = foofor;
#line 22 "lib/sj-lib-common/i32.sj"
        sjt_functionParam149 = 10;
#line 22
        sjf_i32_asstring(sjt_functionParam148, sjt_functionParam149, &sjt_call92);
#line 215 "learnxiny.sj"
        sjt_functionParam147 = &sjt_call92;
#line 215
        sjf_console_writeline(sjt_functionParam147);
#line 214
        foofor++;

        if (sjt_call92._refCount == 1) { sjf_string_destroy(&sjt_call92); }
;
    }

#line 214
    g_foolist._refCount = 1;
#line 222
    g_foolist.datasize = 9;
#line 3 "lib/sj-lib-common/array.sj"
    g_foolist.data = 0;
#line 4
    g_foolist.isglobal = false;
#line 5
    g_foolist.count = 0;
#line 5
    sjf_array_i32(&g_foolist);
#line 222 "learnxiny.sj"
    sjs_array_i32* array3;
#line 222
    array3 = &g_foolist;
#line 222
    sjt_parent59 = array3;
#line 222
    sjt_functionParam150 = 0;
#line 222
    sjt_functionParam151 = 1;
#line 222
    sjf_array_i32_initat(sjt_parent59, sjt_functionParam150, sjt_functionParam151);
#line 222
    sjt_parent60 = array3;
#line 222
    sjt_functionParam152 = 1;
#line 222
    sjt_functionParam153 = 2;
#line 222
    sjf_array_i32_initat(sjt_parent60, sjt_functionParam152, sjt_functionParam153);
#line 222
    sjt_parent61 = array3;
#line 222
    sjt_functionParam154 = 2;
#line 222
    sjt_functionParam155 = 3;
#line 222
    sjf_array_i32_initat(sjt_parent61, sjt_functionParam154, sjt_functionParam155);
#line 222
    sjt_parent62 = array3;
#line 222
    sjt_functionParam156 = 3;
#line 222
    sjt_functionParam157 = 4;
#line 222
    sjf_array_i32_initat(sjt_parent62, sjt_functionParam156, sjt_functionParam157);
#line 222
    sjt_parent63 = array3;
#line 222
    sjt_functionParam158 = 4;
#line 222
    sjt_functionParam159 = 5;
#line 222
    sjf_array_i32_initat(sjt_parent63, sjt_functionParam158, sjt_functionParam159);
#line 222
    sjt_parent64 = array3;
#line 222
    sjt_functionParam160 = 5;
#line 222
    sjt_functionParam161 = 6;
#line 222
    sjf_array_i32_initat(sjt_parent64, sjt_functionParam160, sjt_functionParam161);
#line 222
    sjt_parent65 = array3;
#line 222
    sjt_functionParam162 = 6;
#line 222
    sjt_functionParam163 = 7;
#line 222
    sjf_array_i32_initat(sjt_parent65, sjt_functionParam162, sjt_functionParam163);
#line 222
    sjt_parent66 = array3;
#line 222
    sjt_functionParam164 = 7;
#line 222
    sjt_functionParam165 = 8;
#line 222
    sjf_array_i32_initat(sjt_parent66, sjt_functionParam164, sjt_functionParam165);
#line 222
    sjt_parent67 = array3;
#line 222
    sjt_functionParam166 = 8;
#line 222
    sjt_functionParam167 = 9;
#line 222
    sjf_array_i32_initat(sjt_parent67, sjt_functionParam166, sjt_functionParam167);
#line 74 "lib/sj-lib-common/array.sj"
    sjt_parent68 = &g_foolist;
#line 227 "learnxiny.sj"
    sjs_lambda1* lambainit1;
#line 227
    sjt_call93._refCount = 1;
#line 227
    sjf_lambda1(&sjt_call93);
#line 227
    lambainit1 = &sjt_call93;
#line 227
    sjt_functionParam170._parent = (sjs_object*)lambainit1;
#line 227
    sjt_functionParam170._cb = (void(*)(sjs_object*,int32_t))sjf_lambda1_invoke;
#line 227
    sjf_array_i32_each(sjt_parent68, sjt_functionParam170);
#line 240
    g_month = 3;
#line 240
    g_monthstring._refCount = 1;
#line 241
    g_monthstring.count = 0;
#line 241
    g_monthstring.data._refCount = 1;
#line 241
    g_monthstring.data.datasize = 0;
#line 241
    g_monthstring.data.data = (void*)sjg_string42;
#line 241
    g_monthstring.data.isglobal = true;
#line 241
    g_monthstring.data.count = 0;
#line 241
    sjf_array_char(&g_monthstring.data);
#line 14 "lib/sj-lib-common/string.sj"
    g_monthstring._isnullterminated = false;
#line 14
    sjf_string(&g_monthstring);
#line 242 "learnxiny.sj"
    underscore1 = g_month;
    if (underscore1 == 1) {
        sjs_string sjt_funcold3 = { -1 };

        sjt_funcold3._refCount = 1;
#line 6 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&sjt_funcold3, &g_monthstring);
#line 6
        sjt_funcold3._refCount = 1;
#line 243 "learnxiny.sj"
        sjt_funcold3.count = 7;
#line 243
        sjt_funcold3.data._refCount = 1;
#line 243
        sjt_funcold3.data.datasize = 7;
#line 243
        sjt_funcold3.data.data = (void*)sjg_string43;
#line 243
        sjt_funcold3.data.isglobal = true;
#line 243
        sjt_funcold3.data.count = 7;
#line 243
        sjf_array_char(&sjt_funcold3.data);
#line 14 "lib/sj-lib-common/string.sj"
        sjt_funcold3._isnullterminated = false;
#line 14
        sjf_string(&sjt_funcold3);
#line 14
        if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 6
        sjf_string_copy(&g_monthstring, &sjt_funcold3);

        if (sjt_funcold3._refCount == 1) { sjf_string_destroy(&sjt_funcold3); }
;
    } else {
        if (underscore1 == 2) {
            sjs_string sjt_funcold4 = { -1 };

            sjt_funcold4._refCount = 1;
#line 6 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&sjt_funcold4, &g_monthstring);
#line 6
            sjt_funcold4._refCount = 1;
#line 244 "learnxiny.sj"
            sjt_funcold4.count = 8;
#line 244
            sjt_funcold4.data._refCount = 1;
#line 244
            sjt_funcold4.data.datasize = 8;
#line 244
            sjt_funcold4.data.data = (void*)sjg_string44;
#line 244
            sjt_funcold4.data.isglobal = true;
#line 244
            sjt_funcold4.data.count = 8;
#line 244
            sjf_array_char(&sjt_funcold4.data);
#line 14 "lib/sj-lib-common/string.sj"
            sjt_funcold4._isnullterminated = false;
#line 14
            sjf_string(&sjt_funcold4);
#line 14
            if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 6
            sjf_string_copy(&g_monthstring, &sjt_funcold4);

            if (sjt_funcold4._refCount == 1) { sjf_string_destroy(&sjt_funcold4); }
;
        } else {
            if (underscore1 == 3) {
                sjs_string sjt_funcold5 = { -1 };

                sjt_funcold5._refCount = 1;
#line 6 "lib/sj-lib-common/string.sj"
                sjf_string_copy(&sjt_funcold5, &g_monthstring);
#line 6
                sjt_funcold5._refCount = 1;
#line 245 "learnxiny.sj"
                sjt_funcold5.count = 5;
#line 245
                sjt_funcold5.data._refCount = 1;
#line 245
                sjt_funcold5.data.datasize = 5;
#line 245
                sjt_funcold5.data.data = (void*)sjg_string45;
#line 245
                sjt_funcold5.data.isglobal = true;
#line 245
                sjt_funcold5.data.count = 5;
#line 245
                sjf_array_char(&sjt_funcold5.data);
#line 14 "lib/sj-lib-common/string.sj"
                sjt_funcold5._isnullterminated = false;
#line 14
                sjf_string(&sjt_funcold5);
#line 14
                if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 6
                sjf_string_copy(&g_monthstring, &sjt_funcold5);

                if (sjt_funcold5._refCount == 1) { sjf_string_destroy(&sjt_funcold5); }
;
            } else {
                sjs_string sjt_funcold6 = { -1 };

                sjt_funcold6._refCount = 1;
#line 6 "lib/sj-lib-common/string.sj"
                sjf_string_copy(&sjt_funcold6, &g_monthstring);
#line 6
                sjt_funcold6._refCount = 1;
#line 246 "learnxiny.sj"
                sjt_funcold6.count = 16;
#line 246
                sjt_funcold6.data._refCount = 1;
#line 246
                sjt_funcold6.data.datasize = 16;
#line 246
                sjt_funcold6.data.data = (void*)sjg_string46;
#line 246
                sjt_funcold6.data.isglobal = true;
#line 246
                sjt_funcold6.data.count = 16;
#line 246
                sjf_array_char(&sjt_funcold6.data);
#line 14 "lib/sj-lib-common/string.sj"
                sjt_funcold6._isnullterminated = false;
#line 14
                sjf_string(&sjt_funcold6);
#line 14
                if (g_monthstring._refCount == 1) { sjf_string_destroy(&g_monthstring); }
;
#line 6
                sjf_string_copy(&g_monthstring, &sjt_funcold6);

                if (sjt_funcold6._refCount == 1) { sjf_string_destroy(&sjt_funcold6); }
;
            }
        }
    }

#line 242
    sjt_call96._refCount = 1;
#line 248
    sjt_call96.count = 20;
#line 248
    sjt_call96.data._refCount = 1;
#line 248
    sjt_call96.data.datasize = 20;
#line 248
    sjt_call96.data.data = (void*)sjg_string47;
#line 248
    sjt_call96.data.isglobal = true;
#line 248
    sjt_call96.data.count = 20;
#line 248
    sjf_array_char(&sjt_call96.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call96._isnullterminated = false;
#line 14
    sjf_string(&sjt_call96);
#line 248 "learnxiny.sj"
    sjt_parent69 = &sjt_call96;
#line 248
    sjt_functionParam175 = &g_monthstring;
#line 248
    sjf_string_add(sjt_parent69, sjt_functionParam175, &sjt_call95);
#line 248
    sjt_functionParam174 = &sjt_call95;
#line 248
    sjf_console_writeline(sjt_functionParam174);
#line 248
    sjt_call97._refCount = 1;
#line 254
    sjt_call97.count = 23;
#line 254
    sjt_call97.data._refCount = 1;
#line 254
    sjt_call97.data.datasize = 23;
#line 254
    sjt_call97.data.data = (void*)sjg_string48;
#line 254
    sjt_call97.data.isglobal = true;
#line 254
    sjt_call97.data.count = 23;
#line 254
    sjf_array_char(&sjt_call97.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call97._isnullterminated = false;
#line 14
    sjf_string(&sjt_call97);
#line 254 "learnxiny.sj"
    sjt_functionParam176 = &sjt_call97;
#line 254
    sjf_console_writeline(sjt_functionParam176);
#line 254
    g_trek._refCount = 1;
#line 275
    g_trek.cadence = 50;
#line 276
    g_trek.gear = 1;
#line 276
    g_trek.name._refCount = 1;
#line 277
    g_trek.name.count = 9;
#line 277
    g_trek.name.data._refCount = 1;
#line 277
    g_trek.name.data.datasize = 9;
#line 277
    g_trek.name.data.data = (void*)sjg_string49;
#line 277
    g_trek.name.data.isglobal = true;
#line 277
    g_trek.name.data.count = 9;
#line 277
    sjf_array_char(&g_trek.name.data);
#line 14 "lib/sj-lib-common/string.sj"
    g_trek.name._isnullterminated = false;
#line 14
    sjf_string(&g_trek.name);
#line 278 "learnxiny.sj"
    g_trek._speed = 5;
#line 278
    sjf_bicycle(&g_trek);
#line 293
    sjt_parent70 = &g_trek;
#line 262
    sjt_functionParam177 = 3;
#line 262
    sjf_bicycle_speedup(sjt_parent70, sjt_functionParam177, &sjt_void1);
#line 285
    sjt_parent71 = &g_trek;
#line 263
    sjt_functionParam178 = 100;
#line 263
    sjf_bicycle_setcadence(sjt_parent71, sjt_functionParam178, &sjt_void2);
#line 263
    sjt_call99._refCount = 1;
#line 266
    sjt_call99.count = 11;
#line 266
    sjt_call99.data._refCount = 1;
#line 266
    sjt_call99.data.datasize = 11;
#line 266
    sjt_call99.data.data = (void*)sjg_string50;
#line 266
    sjt_call99.data.isglobal = true;
#line 266
    sjt_call99.data.count = 11;
#line 266
    sjf_array_char(&sjt_call99.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call99._isnullterminated = false;
#line 14
    sjf_string(&sjt_call99);
#line 266 "learnxiny.sj"
    sjt_parent72 = &sjt_call99;
#line 310
    sjt_parent87 = &g_trek;
#line 310
    sjf_bicycle_asstring(sjt_parent87, &sjt_call100);
#line 266
    sjt_functionParam180 = &sjt_call100;
#line 266
    sjf_string_add(sjt_parent72, sjt_functionParam180, &sjt_call98);
#line 266
    sjt_functionParam179 = &sjt_call98;
#line 266
    sjf_console_writeline(sjt_functionParam179);
#line 266
    g_firstday._refCount = 1;
#line 383
    g_firstday.day = g_day_monday;
#line 383
    sjf_enumtest(&g_firstday);
#line 364
    sjt_parent88 = &g_firstday;
#line 364
    sjf_enumtest_tellitlikeitis(sjt_parent88);
#line 364
    g_thirdday._refCount = 1;
#line 385
    g_thirdday.day = g_day_wednesday;
#line 385
    sjf_enumtest(&g_thirdday);
#line 364
    sjt_parent89 = &g_thirdday;
#line 364
    sjf_enumtest_tellitlikeitis(sjt_parent89);
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
    if (g_intarray._refCount == 1) { sjf_array_i32_destroy(&g_intarray); }
;
    if (g_intarray2._refCount == 1) { sjf_array_i32_destroy(&g_intarray2); }
;
    if (g_intarray3._refCount == 1) { sjf_array_i32_destroy(&g_intarray3); }
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
    if (sjt_call100._refCount == 1) { sjf_string_destroy(&sjt_call100); }
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
    if (sjt_call20._refCount == 1) { sjf_array_i32_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_obj_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_obj_destroy(&sjt_call22); }
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
    if (sjt_call87._refCount == 1) { sjf_string_destroy(&sjt_call87); }
;
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
;
    if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
    if (sjt_call90._refCount == 1) { sjf_string_destroy(&sjt_call90); }
;
    if (sjt_call91._refCount == 1) { sjf_string_destroy(&sjt_call91); }
;
    if (sjt_call93._refCount == 1) { sjf_lambda1_destroy(&sjt_call93); }
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
