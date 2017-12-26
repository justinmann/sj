void _object_init(sjs_object* obj, int typeid, char* funcname);
void _object_retain(sjs_object* obj, char* funcname);
void _object_release(sjs_object* obj, char* funcname);
void _object_report(void);